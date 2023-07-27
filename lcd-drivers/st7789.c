#include "st7789.h"
#include "st7789-interface.h"
#include "configuration.h"

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
static void lcd_fill_gram();

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void lcd_initialize()
{
	uint8_t cmd36[] =
	{
		ST7789_MEMORY_ACCESS_CMD,
		//MY = 1, MX = 1, MV = 1, ML = 0, RGB = 1, MH = 0,
		(0 << 7) | (1 << 6) | (0 << 5) | (1 << 4) | (0 << 3) | (0 << 2)
	};
	st7789_write_commands(cmd36, sizeof(cmd36));

	uint8_t cmdb0[] =
	{
		ST7789_RAN_CONTROL_CMD,
		// RM = 0, DM1 = DM0 = 0
		(0 << 4)|(0 << 1)|(0 << 0),
		// EPF1 = EPF0 = 1, ENDIAN = 1, RIM = 0, MDT1 = MDT0 = 0 
		(0b11 << 6)|(0b11 << 4)|(1 << 3)
	};
	st7789_write_commands(cmdb0, sizeof(cmdb0));

	uint8_t cmd3a[] =
	{
		ST7789_INTERFACE_PIXEL_FORMAT_CMD,
		// 5-6-5
		(0b101 << 4)|(0b101 << 0)
	};
	st7789_write_commands(cmd3a, sizeof(cmd3a));

	// fill gram
	//lcd_fill_gram();

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
	uint16_t ye = y + h - 1;
	uint8_t cmd2a[] =
	{
		ST7789_COLUMN_ADDRESS_CMD,
		(y >> 8), (y & 0xff), // XS = 0
		(ye >> 8), (ye & 0xff) // XE = 319
	};
	st7789_write_commands(cmd2a, sizeof(cmd2a));

	uint16_t xe = x + w - 1;
	uint8_t cmd2b[] =
	{
		ST7789_ROW_ADDRESS_CMD,
		(x >> 8), (x & 0xff), // YS = 0
		(xe >> 8), (xe & 0xff) // YE = 239
	};
	st7789_write_commands(cmd2b, sizeof(cmd2b));
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void lcd_start_writing_gdata()
{
	uint8_t cmd2c[] =
	{
		ST7789_START_WRITE_MEMORY_CMD
	};
	st7789_write_commands(cmd2c, sizeof(cmd2c));
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void lcd_write_gdata(const uint8_t * data, uint16_t size)
{
	st7789_write_gdata(data, size);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
static void lcd_fill_gram()
{
	// fill gram to display picture or color
	// select region
	lcd_set_region(0, 0, LCD_HORIZONTAL_SIZE, LCD_VERTICAL_SIZE);
	// fill screen
	uint8_t * gdata = heap_caps_malloc(VSPI_MAX_BUFFER_SIZE, MALLOC_CAP_DMA);
	uint32_t byte_count = LCD_VERTICAL_SIZE * LCD_HORIZONTAL_SIZE * 2;
	// fill buffer
	for(int i = 0; i < VSPI_MAX_BUFFER_SIZE; i++)
	{
		gdata[i] = 0b00000111;
		i++;
		gdata[i] = 0b11111111;
	}
	
	// write data to screan
	lcd_start_writing_gdata();
	while(byte_count)
	{
		uint32_t size = VSPI_MAX_BUFFER_SIZE < byte_count ? VSPI_MAX_BUFFER_SIZE : byte_count;
		st7789_write_gdata((uint8_t*)gdata, size);
		byte_count -= size;
	}
	// wait for the transaction has finished to free memory
	st7789_wait(0);
	heap_caps_free(gdata);
}