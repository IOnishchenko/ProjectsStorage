#ifndef I2C_FUNCTIONS_H
#define I2C_FUNCTIONS_H

#include "stdint.h"
#include "driver/i2c.h"

#ifdef __cplusplus
extern "C" {
#endif
/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
extern void i2c_write_data(uint16_t address, uint8_t * data, uint16_t size);

#ifdef __cplusplus
}
#endif

#endif // I2C_FUNCTIONS_H