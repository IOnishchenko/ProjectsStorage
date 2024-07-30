#include "stdint.h"
#include "sh1106.h"
#include "sh1106-interface.h"
#include "configuration.h"
#include "lcd-driver.h"

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
static void sh1106_set_region(uint16_t x, uint16_t y, uint16_t w, uint16_t h);

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
static void sh1106_initialize()
{
	
	uint8_t cmd[] =
	{
		0xae, // Display OFF/ON

		0x00, // Set Lower Column Address
		0x10, // Set Higher Column Address
		0x32, // Set Pump voltage value
		0x40, // Set Display Start Line
		
		0x81, // The Contrast Control Mode Set
		0x80,

		0xa0, // Set Segment Re-map - none
		0xa4, // Set Entire Display OFF/ON
		0xa6, // Set Normal/Reverse Display

		0xa8, // Set Multiplex Ration
		0x3f,

		0xad, // Set DC-DC OFF/ON
		0x8b,
		
		0xb0, // Set Page Address
		0xc0, // Set Common Output Scan Direction - none

		0xd3, // Set Display Offset
		0x02,
	};
	sh1106_write_command(cmd, sizeof(cmd));

	// clear gram
	uint8_t data[64] = {0};
	for(int i = 0; i < 8; i++)
	{
		sh1106_set_region(0, i, 0, 0);
		sh1106_write_gdata(data, sizeof(data));
		sh1106_write_gdata(data, sizeof(data));
	}

	// display on
	uint8_t oncmd[] =
	{
		0xaf, // Display OFF/ON
	};
	sh1106_write_command(oncmd, sizeof(oncmd));
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void sh1106_vertical_scroll(uint8_t value)
{
	value &= 0b00111111;
	uint8_t cmd[] =
	{
		0x40 | value
	};
	sh1106_write_command(cmd, sizeof(cmd));
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
static void sh1106_deinitialize()
{

}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
static void sh1106_set_region(uint16_t x, uint16_t y, uint16_t w, uint16_t h)
{
	x += LCD_SH1106_X_OFFSET;
	uint8_t cmd[] =
	{
		0x10 | (x >> 4),
		x & 0x0f,
		0xb0 | y
	};
	sh1106_write_command(cmd, sizeof(cmd));
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
static void sh1106_start_writing_gdata()
{

}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
// static void sh1106_write_gdata(const uint8_t * data, uint16_t size)
// {
// 	sh1106_write_gdata(data, size);
// }

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void sh1106_wait_and_delay(uint32_t ms)
{

}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void sh1106_start_reading_gdata()
{

}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void sh1106_read_gdata(const uint8_t * data, uint16_t size)
{

}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
lcd_driver sh1106 =
{
	.initialize = sh1106_initialize,
	.deinitialize = sh1106_deinitialize,
	.set_region = sh1106_set_region,
	.start_writing_gdata = sh1106_start_writing_gdata,
	.write_gdata = sh1106_write_gdata,
	.wait_and_delay = sh1106_wait_and_delay,
	.start_reading_gdata = sh1106_start_reading_gdata,
	.read_gdata = sh1106_read_gdata,
};