#include "ssd1306-i2c.h"
#include "main.h"
#include "cmsis_os.h"
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

#define SSD1306_I2C_CBYTE_CMD			(0x40u) // command byte expected
#define SSD1306_I2C_CBYTE_Co1			(0x80u) // next byte expected
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

static volatile uint8_t i2c_status = 0;

// thread info
static osThreadId taskId = 0;
static int32_t taskSignal = 0;
/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
static inline void create_data_frame(const uint8_t * data, uint16_t size, ssd1306_i2c_data_type type);
static void start_transmission(void);

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void ssd1306_i2c_initialize(osThreadId id, int32_t signal)
{
	taskId = id;
	taskSignal = signal;
	osSignalClear(id, signal);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void ssd1306_send_commands(const uint8_t * cmds, uint16_t size)
{
	uint16_t wrindex = cmdWrIndex & SSD1306_I2C_CMD_INDEX_MASK;
	uint16_t overflag = cmdWrIndex & SSD1306_I2C_CMD_OVER_FLAG;
	// copy commands to internal buffer
	while(size)
	{
		while((cmdWrIndex ^ cmdRdIndex) == SSD1306_I2C_CMD_OVER_FLAG)
		{
			// cmd buffer is full - block this thread
			i2c_status |= SSD1306_I2C_TASK_BLOCKED;
			osSignalWait(taskSignal, 0);
		}

		// copy command to buffer
		cmdBuffer[cmdWrIndex & SSD1306_I2C_CMD_INDEX_MASK] = *cmds++;
		cmdWrIndex++;
		cmdWrIndex &= SSD1306_I2C_CMD_FLAG_MASK;

		if((cmdWrIndex & SSD1306_I2C_CMD_OVER_FLAG) ^ overflag)
		{
			// cmd buffer overflow - create frame and add to frame buffer
			create_data_frame(&cmdBuffer[wrindex], SSD1306_I2C_CMD_BUFFER_SIZE - wrindex, SSD1306_I2C_COMMAND);
			// begin transmission if not active
			start_transmission();
			// update wrindex
			wrindex = cmdWrIndex & SSD1306_I2C_CMD_INDEX_MASK;
			overflag = cmdWrIndex & SSD1306_I2C_CMD_OVER_FLAG;
		}
	}

	if(wrindex != (cmdWrIndex & SSD1306_I2C_CMD_INDEX_MASK))
	{
		// create frame and add to frame buffer
		create_data_frame(&cmdBuffer[wrindex], (cmdWrIndex & SSD1306_I2C_CMD_INDEX_MASK) - wrindex, SSD1306_I2C_COMMAND);
		// begin transmission if not active
		start_transmission();
	}
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void ssd1306_send_buffer(const uint8_t * data, uint16_t size)
{
	create_data_frame(data, size, SSD1306_I2C_DATA);
	// begin transmission if not active
	start_transmission();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
static inline void create_data_frame(const uint8_t * data, uint16_t size, ssd1306_i2c_data_type type)
{
	while((frmWrIndex ^ frmRdIndex) == SSD1306_I2C_FRM_OVER_FLAG)
	{
		// frame buffer is full - block this thread
		i2c_status |= SSD1306_I2C_TASK_BLOCKED;
		osSignalWait(taskSignal, 0);
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
static void free_data_frame(void)
{
	if(frmBuffer[frmRdIndex].type == SSD1306_I2C_COMMAND)
	{
		// free cmd buffer first
		cmdRdIndex += frmBuffer[frmRdIndex].size;
		cmdRdIndex &= SSD1306_I2C_CMD_FLAG_MASK;
	}

	frmRdIndex++;
	frmRdIndex &= SSD1306_I2C_FRM_FLAG_MASK;
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
static void start_transmission()
{
	if(!(i2c_status & SSD1306_I2C_TRX_ACTIVE))
	{

	}
}

/*-----------------------------------------------------------------//
// This function handles I2C1 event interrupt.
//-----------------------------------------------------------------*/
void I2C1_EV_IRQHandler(void)
{
	static ssd1306_i2c_byte_type btype = SSD1306_I2C_CONTROL_BYTE;
	static uint16_t dindex = 0x00;

	// byte was transmired 
	if(btype == SSD1306_I2C_CONTROL_BYTE)
	{
		// switch data type
		btype = SSD1306_I2C_DATA_BYTE;
		// prepare data
		ssd1306_i2c_data_item * item = &frmBuffer[frmRdIndex & SSD1306_I2C_FRM_INDEX_MASK];
		uint8_t control_byte = SSD1306_I2C_CBYTE_Co1; // several bytes expected
		// send control byte
		if((item->size - dindex) == 1)
		{
			// last data byte of current frame
			uint16_t rdindex = (frmRdIndex + 1) & SSD1306_I2C_FRM_FLAG_MASK;
			if(rdindex == frmWrIndex)
			{
				// last data frame in the queue
				control_byte = 0x00;
			}
		}

		if(item->type == SSD1306_I2C_COMMAND)
		{
			// next byte is command byte
			control_byte |= SSD1306_I2C_CBYTE_CMD;
		}
		// write data to TX reg
		// TXREG = control_byte;
	}
	else
	{
		// switch data type
		btype = SSD1306_I2C_CONTROL_BYTE;
		// send data
		ssd1306_i2c_data_item * item = &frmBuffer[frmRdIndex & SSD1306_I2C_FRM_INDEX_MASK];
		if(dindex == item->size)
		{
			free_data_frame();
			if(frmRdIndex == frmWrIndex)
			{
				// the frame buffer is empty - generate stop
				dindex = 0;
				i2c_status ^= SSD1306_I2C_TRX_ACTIVE;
			}
			else
			{
				item = &frmBuffer[frmRdIndex & SSD1306_I2C_FRM_INDEX_MASK];
				dindex = 0;
				// write data to TX reg
				// TODO
				// TXREG = item->data[bindex];
				// update history
				dindex++;
			}
		}
		else
		{
			// write data to TX reg
			// TODO
			// TXREG = item->data[bindex];
			// update history
			dindex++;
		}
	}
	// unblock thread if needed
	if(i2c_status & SSD1306_I2C_TASK_BLOCKED)
	{
		i2c_status ^= SSD1306_I2C_TASK_BLOCKED;
		osSignalSet(taskId, taskSignal);
	}
}

/*-----------------------------------------------------------------//
// This function handles I2C1 error interrupt.
//-----------------------------------------------------------------*/
void I2C1_ER_IRQHandler(void)
{
}
