#ifndef SSD1306_INTERFACEC_H
#define SSD1306_INTERFACEC_H

#include "types.h"
#include "stdint.h"

#ifdef __cplusplus
extern "C" {
#endif
/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
#define SSD1306_INTERFACE_BUFFER_SIZE		64u
#define SSD1606_INTERFACE_BUFFER_NUMBER		4u
/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
extern void ssd1306_set_interface(i2c_device_t device);
extern void ssd1306_write_command(const uint8_t * cmds, uint16_t size);
extern void ssd1306_write_gdata(const uint8_t * data, uint16_t size);
extern void ssd1306_read_gdata(const uint8_t * data, uint16_t size);
/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
#ifdef __cplusplus
}
#endif

#endif // SSD1306_INTERFACEC_H