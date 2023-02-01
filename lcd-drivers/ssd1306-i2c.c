#include "ssd1306-i2c.h"
#include "main.h"
/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
extern I2C_HandleTypeDef hi2c1;
/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
#define SSD1306_I2C_CMD_BUFFER_SIZE		(32u) 	// must be power of 2
#define SSD1306_I2C_CMD_INDEX_MASK		(SSD1306_I2C_CMD_BUFFER_SIZE-1)
#define SSD1306_I2C_CMD_OVER_FLAG		(SSD1306_I2C_CMD_BUFFER_SIZE)
#define SSD1306_I2C_CMD_FLAG_MASK		((SSD1306_I2C_CMD_BUFFER_SIZE<<1)-1)

#define SSD1306_I2C_FRM_BUFFER_SIZE		(32u)	// must be power of 2
#define SSD1306_I2C_FRM_INDEX_MASK		(SSD1306_I2C_FRM_BUFFER_SIZE-1)
#define SSD1306_I2C_FRM_OVER_FLAG		(SSD1306_I2C_FRM_BUFFER_SIZE)
#define SSD1306_I2C_FRM_FLAG_MASK		((SSD1306_I2C_FRM_BUFFER_SIZE<<1)-1)

#define SSD1306_I2C_CBYTE_DATA_Co0		(0x00u)	// last byte expected
#define SSD1306_I2C_CBYTE_DATA_Co1		(0x80u) // next data expected
#define SSD1306_I2C_CBYTE_CMD_Co0		(0x40u) // last byte expected
#define SSD1306_I2C_CBYTE_CMD_Co1		(0xc0u) // next data expected
/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
// buffer to store command bytes
static uint8_t cmdBuffer[SSD1306_I2C_CMD_BUFFER_SIZE];
static uint16_t cmdWrIndex = 0;
static uint16_t cmdRdIndex = 0;

// buffer to store data frames
static ssd1306_i2c_data_item frmBuffer[SSD1306_I2C_FRM_BUFFER_SIZE];
static uint16_t frmWrIndex = 0;
static uint16_t frmRdIndex = 0;

static ssd1306_i2c_status i2c_status = SSD1306_I2C_READY;

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
static inline void createDataFrame(uint8_t * data, uint16_t size, ssd1306_i2c_data_type type);
static void startTransmission();

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void send_commands(const uint8_t * cmds, uint16_t size)
{
	uint16_t wrindex = cmdWrIndex & SSD1306_I2C_CMD_INDEX_MASK;
	// copy commands to internal buffer
	while(size)
	{
		if((cmdWrIndex ^ cmdRdIndex) == SSD1306_I2C_CMD_OVER_FLAG)
		{
			// cmd buffer is full - block this thread
		}

		// copy command to buffer
		cmdBuffer[cmdWrIndex] = *cmds++;
		cmdWrIndex++;
		cmdWrIndex &= SSD1306_I2C_CMD_FLAG_MASK;

		if(!(cmdWrIndex & (~SSD1306_I2C_CMD_INDEX_MASK)))
		{
			// cmd buffer overflow - create frame and add to frame buffer
			createDataFrame(&cmdBuffer[wrindex],
				SSD1306_I2C_CMD_BUFFER_SIZE - wrindex, SSD1306_I2C_COMMAND);
			// update wrindex
			wrindex = cmdWrIndex & SSD1306_I2C_CMD_INDEX_MASK;
			if(i2c_status == SSD1306_I2C_READY)
			{
				// begin transmission if not active
				startTransmission();
			}
		}
	}

	if(wrindex != (cmdWrIndex & SSD1306_I2C_CMD_INDEX_MASK))
	{
		// create frame and add to frame buffer
		createDataFrame(&cmdBuffer[wrindex],
			(cmdWrIndex & SSD1306_I2C_CMD_INDEX_MASK) - wrindex, SSD1306_I2C_COMMAND);
		if(i2c_status == SSD1306_I2C_READY)
		{
			// begin transmission if not active
			startTransmission();
		}
	}

	// send data
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void send_buffer(const uint8_t * data, uint16_t size)
{
	createDataFrame(data, size, SSD1306_I2C_DATA);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
static inline void createDataFrame(uint8_t * data, uint16_t size, ssd1306_i2c_data_type type)
{
	
	if((frmWrIndex ^ frmRdIndex) == SSD1306_I2C_FRM_OVER_FLAG)
	{
		// frame buffer is full - block this thread
	}
	// add frame to buffer
	frmBuffer[frmWrIndex].type = type;
	frmBuffer[frmWrIndex].size = size;
	frmBuffer[frmWrIndex].data = data;
	frmWrIndex++;
	frmWrIndex &= SSD1306_I2C_FRM_FLAG_MASK;
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
static void startTransmission()
{

}

/*-----------------------------------------------------------------//
// This function handles I2C1 event interrupt.
//-----------------------------------------------------------------*/
void I2C1_EV_IRQHandler(void)
{
	static uint8_t 
}

/*-----------------------------------------------------------------//
// This function handles I2C1 error interrupt.
//-----------------------------------------------------------------*/
void I2C1_ER_IRQHandler(void)
{
}