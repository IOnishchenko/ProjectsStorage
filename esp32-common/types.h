#ifndef TYPES_H
#define TYPES_H

#include "driver/i2c_master.h"
#include "driver/spi_master.h"

#ifdef __cplusplus
extern "C" {
#endif
/*-----------------------------------------------------------------//
// internal types definition
//-----------------------------------------------------------------*/
typedef i2c_master_bus_handle_t i2c_device_t;
typedef spi_device_handle_t spi_device_int;
/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
#ifdef __cplusplus
}
#endif

#endif // TYPES_H