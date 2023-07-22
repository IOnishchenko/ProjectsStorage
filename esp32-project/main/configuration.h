#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include "driver/gpio.h"
#include "driver/i2c.h"
#include "driver/spi_master.h"

/*-----------------------------------------------------------------//
// I2C configuration
//-----------------------------------------------------------------*/
#define I2C0_MASTER_FREQ_HZ	400000u
#define I2C0_MASTER_SDA_IO	(GPIO_NUM_22)
#define I2C0_MASTER_SCL_IO	(GPIO_NUM_21)
#define I2C0_DEVICE_PORT	0x00

/*-----------------------------------------------------------------//
// I2S configuration
//-----------------------------------------------------------------*/
#define AUDIO_CODEC_DATA_WIDTH	32U
#define I2S_NUM				(I2C_NUM_0)
#define I2S_MCLK			(GPIO_NUM_NC)
#define I2S_BCK_IO			(GPIO_NUM_0)
#define I2S_WS_IO			(GPIO_NUM_2)
#define I2S_DO_IO			(GPIO_NUM_4)
#define I2S_DI_IO			(GPIO_NUM_16)
#define I2S_SAMPLE_RATE		48000u

/*-----------------------------------------------------------------//
// LCD:
// HSPI configuration
// GPIO configuration
//-----------------------------------------------------------------*/
#define LCD_SPI		(VSPI_HOST)
#define LCD_MOSI	(GPIO_NUM_23)
#define LCD_MISO	(GPIO_NUM_NC)
#define LCD_CS		(GPIO_NUM_5)
#define LCD_SCL		(GPIO_NUM_18)

#define LCD_C_D		(GPIO_NUM_19)

/*-----------------------------------------------------------------//
// Receiver data flow parameters
//-----------------------------------------------------------------*/
#define RX_IQ_BUFFER_SIZE	256
#define RX_REAL_DATA_SIZE	(RX_IQ_BUFFER_SIZE/2)

/*-----------------------------------------------------------------//
// Transmitter data flow parameters
//-----------------------------------------------------------------*/

struct iq_measurement
{
	float teta1;
	float teta2;
	float teta3;

	float t1;
	float t2;
	float t3;

	float psi;
};

#endif // CONFIGURATION_H