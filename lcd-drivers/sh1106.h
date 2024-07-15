#ifndef SH1106_H
#define SH1106_H
#ifdef __cplusplus
extern "C" {
#endif
/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
#define SH1106_I2C_ADDRESS_SIZE 7
#define SH1106_I2C_ADDRESS 0b0111100 

#define SH1106_I2C_LAST_BYTE		(0 << 7)
#define SH1106_I2C_NOT_LAST_BYTE	(1 << 7)
#define SH1106_I2C_CMD_BYTE			(0 << 6)
#define SH1106_I2C_DATA_BYTE		(1 << 6)

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
#ifdef __cplusplus
}
#endif
#endif // SH1106_H