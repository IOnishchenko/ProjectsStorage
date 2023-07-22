#ifndef ST7789_INTERFACE_H
#define ST7789_INTERFACE_H

#include "types.h"
#include "stdint.h"

#ifdef __cplusplus
extern "C" {
#endif
/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
extern void ssd1306_set_interface(i2c_device_int port);
extern void ssd1306_write_commands(const uint8_t * cmds, uint16_t size);
extern void ssd1306_write_gdata(const uint8_t * data, uint16_t size);
/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
#ifdef __cplusplus
}
#endif
#endif // ST7789_INTERFACE_H