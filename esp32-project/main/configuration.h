#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include "driver/gpio.h"

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
#define I2S_NUM				(0)
#define I2S_MCLK			(GPIO_NUM_NC)
#define I2S_BCK_IO			(GPIO_NUM_0)
#define I2S_WS_IO			(GPIO_NUM_2)
#define I2S_DO_IO			(GPIO_NUM_4)
#define I2S_DI_IO			(GPIO_NUM_16)
#define I2S_SAMPLE_RATE		48000u

/*-----------------------------------------------------------------//
// Receiver data flow parameters
//-----------------------------------------------------------------*/
#define RX_IQ_BUFFER_SIZE	256
#define RX_REAL_DATA_SIZE	(RX_IQ_BUFFER_SIZE/2)

/*-----------------------------------------------------------------//
// Transmitter data flow parameters
//-----------------------------------------------------------------*/


#endif // CONFIGURATION_H