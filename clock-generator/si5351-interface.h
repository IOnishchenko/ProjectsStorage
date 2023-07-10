#ifndef SI5351_INTERFACE_H
#define SI5351_INTERFACE_H

#include "stdint.h"
#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif
/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
#define SI5351_DEVICE_ADDRESS 0x60u
/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
extern void si5351_set_interface(i2c_port_t port);
extern void si5351_write_bulk(uint8_t addr, uint8_t bytes, uint8_t *data);
extern void si5351_write(uint8_t addr, uint8_t data);
extern uint8_t si5351_read(uint8_t addr);

#ifdef __cplusplus
}
#endif

#endif // SI5351_INTERFACE_H