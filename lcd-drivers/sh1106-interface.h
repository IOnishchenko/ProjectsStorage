#ifndef SH1106_INTERFACEC_H
#define SH1106_INTERFACEC_H

#include "types.h"
#include "stdint.h"

#ifdef __cplusplus
extern "C" {
#endif
/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
#define SH1106_INTERFACE_BUFFER_SIZE		64u
#define SH1106_INTERFACE_BUFFER_NUMBER		4u
/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
extern void sh1106_set_interface(i2c_device_t device);
extern void sh1106_write_command(const uint8_t * cmds, uint16_t size);
extern void sh1106_write_gdata(const uint8_t * data, uint16_t size);
extern void sh1106_read_gdata(const uint8_t * data, uint16_t size);
/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
#ifdef __cplusplus
}
#endif

#endif // SH1106_INTERFACEC_H