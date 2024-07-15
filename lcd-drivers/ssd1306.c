#include "stdint.h"
#include "ssd1306.h"
#include "ssd1306-interface.h"
#include "configuration.h"
#include "lcd-driver.h"

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
static void ssd1306_initialize()
{
	vTaskDelay(250);
	uint8_t cmdae[] =
	{
		// Display OFF
		SSD1306_SET_DISPLAY_OFF_CMD,
	};
	ssd1306_write_command(cmdae, sizeof(cmdae));

	uint8_t cmd20[] =
	{
		// address mode
		SSD1306_MEM_ADDR_MODE_CMD,
		0x00//SSD1306_MEM_ADDR_MODE_VAL
	};
	ssd1306_write_command(cmd20, sizeof(cmd20));

	// uint8_t cmda1[] =
	// {
	// 	SSD1306_SET_SEG_REMAP_CMD
	// };
	// ssd1306_write_command(cmda1, sizeof(cmda1));

	// uint8_t cmdd3[] =
	// {
	// 	SSD1306_SET_OFFSET_CMD,
	// 	SSD1306_SET_OFFSET_VAL
	// };
	// ssd1306_write_command(cmdd3, sizeof(cmdd3));

	// uint8_t cmdda[] =
	// {
	// 	SSD1306_SET_CON_PINS_CMD,
	// 	SSD1306_SET_CON_PINS_VAL
	// };
	// ssd1306_write_command(cmdda, sizeof(cmdda));

	// uint8_t cmd8d[] =
	// {
	// 	// Charge Pump enable
	// 	SSD1306_CHARGE_PUMP_CMD,
	// 	SSD1306_CHARGE_PUMP_VAL
	// };
	// ssd1306_write_command(cmd8d, sizeof(cmd8d));

	uint8_t cmda4[] =
	{
		// Display ON
		SSD1306_DISPLAY_RAM_ON_CMD
	};
	ssd1306_write_command(cmda4, sizeof(cmda4));

	uint8_t cmdaf[] =
	{
		// Display ON
		SSD1306_SET_DISPLAY_ON_CMD
	};
	ssd1306_write_command(cmdaf, sizeof(cmdaf));
	vTaskDelay(250);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
static void ssd1306_deinitialize()
{
	uint8_t cmd8d[] =
	{
		// Charge Pump enable
		SSD1306_CHARGE_PUMP_CMD,
		0x10,
	};
	ssd1306_write_command(cmd8d, sizeof(cmd8d));

	uint8_t cmdae[] =
	{
		// Display OFF
		SSD1306_SET_DISPLAY_OFF_CMD,
	};
	ssd1306_write_command(cmdae, sizeof(cmdae));
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void ssd1306_set_region(uint16_t x, uint16_t y, uint16_t w, uint16_t h)
{
	uint8_t cmd20[] =
	{
		// address mode
		SSD1306_MEM_ADDR_MODE_CMD,
		0b01
	};
	ssd1306_write_command(cmd20, sizeof(cmd20));

	uint8_t cmd21[] =
	{
		// column start and end address
		SSD1306_COLUMN_ADDR_CMD,
		x,
		(x + w - 1),
	};
	ssd1306_write_command(cmd21, sizeof(cmd21));

	uint8_t cmd22[] =
	{
		// page address
		SSD1306_PAGE_ADDR_CMD, 
		y,
		(y + h - 1)
	};
	ssd1306_write_command(cmd22, sizeof(cmd22));
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
static void ssd1306_start_writing_gdata()
{

}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
// static void ssd1306_write_gdata(const uint8_t * data, uint16_t size)
// {
// 	ssd1306_write_gdata(data, size);
// }

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void ssd1306_wait_and_delay(uint32_t ms)
{

}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void ssd1306_start_reading_gdata()
{

}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void ssd1306_read_gdata(const uint8_t * data, uint16_t size)
{

}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
lcd_driver ssd1306 =
{
	.initialize = ssd1306_initialize,
	.deinitialize = ssd1306_deinitialize,
	.set_region = ssd1306_set_region,
	.start_writing_gdata = ssd1306_start_writing_gdata,
	.write_gdata = ssd1306_write_gdata,
	.wait_and_delay = ssd1306_wait_and_delay,
	.start_reading_gdata = ssd1306_start_reading_gdata,
	.read_gdata = ssd1306_read_gdata,
};