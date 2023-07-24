#include "st7789.h"
#include "st7789-interface.h"

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void lcd_initialize()
{
	uint8_t cmd36[] =
	{
		ST7789_START_WRITE_MEMORY_CMD,
		//MY = 0, MX = 0, MV = 1, ML = 0, RGB = 0, MH = 0,
		(1 << 5)
	};
	st7789_write_commands(cmd36, sizeof(cmd36));

	uint8_t cmd3a[] =
	{
		ST7789_INTERFACE_PIXEL_FORMAT_CMD,
		// 5-6-5
		(0b101 << 4)|(0b101 << 0)
	};
	st7789_write_commands(cmd3a, sizeof(cmd3a));

	// TODO fill gram to display picture or color

	uint8_t cmd11[] =
	{
		ST7789_SLEEP_OUT_CMD
	};
	st7789_write_commands(cmd11, sizeof(cmd11));
	st7789_wait(100);

	uint8_t cmd29[] =
	{
		ST7789_DISPLAY_ON_CMD
	};
	st7789_write_commands(cmd29, sizeof(cmd29));
	st7789_wait(100);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void lcd_deinitialize()
{

}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void lcd_set_region(uint16_t x, uint16_t y, uint16_t w, uint16_t h)
{

}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void lcd_write_gdata(const uint8_t * data, uint16_t size)
{

}