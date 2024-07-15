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
extern void st7789_set_interface(spi_device_handle_t port);
extern void st7789_write_command(const uint8_t * cmds, uint16_t size);
extern void st7789_write_gdata(const uint8_t * data, uint16_t size);
extern void st7789_wait_and_delay(uint32_t ms);
/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
#ifdef __cplusplus
}
#endif
#endif // ST7789_INTERFACE_H