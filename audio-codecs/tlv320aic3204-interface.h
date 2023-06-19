#ifndef TLV320AIC3204_INTERFACE_N
#define TLV320AIC3204_INTERFACE_N

#include "stdint.h"
#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif
/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
#define TLV320AIC3204_I2C_ADDRESS	0x18U
/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
extern void tlv320aic3204_set_interface(i2c_device port);
extern void tlv320aic3204_write_buffer(const uint8_t * pSrc, uint16_t size);
extern void tlv320aic3204_read_buffer(uint8_t * pDst, uint16_t size);

#ifdef __cplusplus
}
#endif

#endif // TLV320AIC3204_INTERFACE_N