#ifndef LCD_DRIVER__LCD_DRIVER_H
#define LCD_DRIVER__LCD_DRIVER_H

#include "stdint.h"

#ifdef __cplusplus
extern "C" {
#endif
/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
extern void lcd_initialize();
extern void lcd_deinitialize();
extern void lcd_set_region(uint16_t x, uint16_t y, uint16_t w, uint16_t h);
extern void lcd_start_writing_gdata();
extern void lcd_write_gdata(const uint8_t * data, uint16_t size);
/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
#ifdef __cplusplus
}
#endif

#endif // LCD_DRIVER__LCD_DRIVER_H
