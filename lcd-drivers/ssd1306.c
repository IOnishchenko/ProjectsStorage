#include "stdint.h"
#include "ssd1306.h"
#include "ssd1306-interfaces.h"

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void lcd_initialize()
{
	uint8_t data[] =
	{
		// Display OFF
		SSD1306_SET_DISPLAY_OFF_CMD,
		// address mode
		SSD1306_MEM_ADDR_MODE_CMD,
		SSD1306_MEM_ADDR_MODE_VAL,
		// Charge Pump enable
		SSD1306_CHARGE_PUMP_CMD,
		SSD1306_CHARGE_PUMP_VAL,
		// Display ON
		SSD1306_SET_DISPLAY_ON_CMD,

	};
	ssd1306_write_commands(data, sizeof(data));
	// wait

}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void lcd_deinitialize()
{
	uint8_t data[] =
	{
		// Charge Pump enable
		SSD1306_CHARGE_PUMP_CMD,
		0x10,
		// Display OFF
		SSD1306_SET_DISPLAY_OFF_CMD,
	};
	ssd1306_write_commands(data, sizeof(data));
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void lcd_set_region(uint16_t x, uint16_t y, uint16_t w, uint16_t h)
{
	uint8_t data[] =
	{
		// column start and end address
		SSD1306_COLUMN_ADDR_CMD,
		x,
		(x + w - 1),
		// page address
		SSD1306_PAGE_ADDR_CMD, 
		y,
		(y + h - 1)
	};
	ssd1306_write_commands(data, sizeof(data));
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void lcd_write_gdata(const uint8_t * data, uint16_t size)
{
	ssd1306_write_gdata(data, size);
}