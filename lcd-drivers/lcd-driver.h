#ifndef LCD_DRIVER__LCD_DRIVER_H
#define LCD_DRIVER__LCD_DRIVER_H

#include "stdint.h"

#ifdef __cplusplus
extern "C" {
#endif
/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
typedef void (*lcd_initialize)();
typedef void (*lcd_deinitialize)();
typedef void (*lcd_set_region)(uint16_t x, uint16_t y, uint16_t w, uint16_t h);
typedef void (*lcd_start_writing_gdata)();
typedef void (*lcd_write_gdata)(const uint8_t * data, uint16_t size);
typedef void (*lcd_wait_and_delay)(uint32_t ms);
typedef void (*lcd_start_reading_gdata)();
typedef void (*lcd_read_gdata)(const uint8_t * data, uint16_t size);

typedef struct lcd_driver
{
	lcd_initialize				initialize;
	lcd_deinitialize 			deinitialize;
	lcd_set_region 				set_region;
	lcd_start_writing_gdata		start_writing_gdata;
	lcd_write_gdata				write_gdata;
	lcd_wait_and_delay			wait_and_delay;
	lcd_start_reading_gdata		start_reading_gdata;
	lcd_read_gdata				read_gdata;
} lcd_driver;

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
#ifdef USE_ST7789_DRIVER
extern lcd_driver st7789;
#endif
#ifdef USE_SSD1306_DRIVER
extern lcd_driver ssd1306;
#endif
#ifdef USE_SH1106_DRIVER
extern lcd_driver sh1106;
#endif

#ifdef __cplusplus
}
#endif

#endif // LCD_DRIVER__LCD_DRIVER_H
