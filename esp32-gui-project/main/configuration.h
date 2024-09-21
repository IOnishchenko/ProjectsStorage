#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include "driver/gpio.h"
#include "driver/i2c_master.h"
#include "driver/spi_master.h"

#ifdef __cplusplus
extern "C" {
#endif

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
// VSPI configuration
// GPIO configuration
//-----------------------------------------------------------------*/
// lcd parameters
#define LCD_VERTICAL_SIZE	240u
#define LCD_HORIZONTAL_SIZE	320u
#define LCD_DRAW_LINE_PER_TRANSACTION	24
#define LCD_SPI_CLOCK	25000000u // 15MHz is max clock
// lcd pins
#define LCD_SPI		(VSPI_HOST)
#define LCD_MOSI	(GPIO_NUM_23)
#define LCD_MISO	(GPIO_NUM_NC)
#define LCD_CS		(GPIO_NUM_5)
#define LCD_SCL		(GPIO_NUM_18)
#define LCD_C_D		(GPIO_NUM_19)
#define LCD_RST		(GPIO_NUM_17)
// VSPI settings
#define VSPI_BYTE_SIZE			8u 			// bits per byte
#define VSPI_MAX_BUFFER_SIZE	(1024*2)	// max buffer size that can be used for a trasaction
#define VSPI_QUEUE_SIZE			2U
// lcd memory parameters
#define LCD_BUFFER_SIZE_IN_BYTES	(VSPI_MAX_BUFFER_SIZE)
#define LCD_BUFFER_NUMBER			(VSPI_QUEUE_SIZE + 1)

/*-----------------------------------------------------------------//
// SPI (CD card) configuration
// GPIO configuration
//-----------------------------------------------------------------*/
#define SD_SPI	(HSPI_HOST)
#define SD_SCK	(GPIO_NUM_27)
#define SD_MISO	(GPIO_NUM_26)
#define SD_MOSI	(GPIO_NUM_25)
#define SD_CS	(GPIO_NUM_33)

#define SD_MAX_BUFFER_SIZE		4000
#define MOUNT_POINT "/sdcard"

/*-----------------------------------------------------------------//
// LCD:
// SH1106 controller settings
//-----------------------------------------------------------------*/
#define LCD_SH1106_X_OFFSET	2

/*-----------------------------------------------------------------//
// EXTI configuration (encoder)
// GPIO configuration
//-----------------------------------------------------------------*/
#define ENC_A		GPIO_NUM_35
#define ENC_B		GPIO_NUM_34
#define ENC_BUTTON	GPIO_NUM_32

/*-----------------------------------------------------------------//
// types
//-----------------------------------------------------------------*/
typedef uint16_t color_t;

#ifdef __cplusplus
}
#endif

#endif // CONFIGURATION_H