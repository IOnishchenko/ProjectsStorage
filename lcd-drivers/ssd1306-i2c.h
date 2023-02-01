#ifndef SSD1306_I2C_H
#define SSD1306_I2C_H

#include "stdint.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
	SSD1306_I2C_DATA,
	SSD1306_I2C_COMMAND,
} ssd1306_i2c_data_type;

typedef struct
{
	uint8_t address; // when several displays
	ssd1306_i2c_data_type type;
	uint16_t size;
	const uint8_t * data;
} ssd1306_i2c_data_item;

typedef enum
{
	SSD1306_I2C_READY,
	SSD1306_I2C_BUSY,
} ssd1306_i2c_status;

#ifdef __cplusplus
}
#endif
#endif // SSD1306_I2C_H