#include <stdio.h>
#include "driver\i2c.h"
#include "ssd1306-interfaces.h"
#include "lcd-driver.h"
#include "tlv320aic3204-interface.h"

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
#define I2C0_MASTER_FREQ_HZ	400000u
#define I2C0_MASTER_SDA_IO	17
#define I2C0_MASTER_SCL_IO	5
#define I2C0_DEVICE_PORT	0x00

#if I2C0_MASTER_SDA_IO == I2C0_MASTER_SCL_IO
	#error "Please set I2C0 GPIO"
#endif

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
extern void gui_128x64_thread(void *args);
extern void tlv320aic3204_codec_thread(void * args);

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
static int hw_initialize()
{
	// i2c configuration
	i2c_config_t conf =
	{
		.mode = I2C_MODE_MASTER,
		.sda_io_num = I2C0_MASTER_SDA_IO,
		.sda_pullup_en = GPIO_PULLUP_ENABLE,
		.scl_io_num = I2C0_MASTER_SCL_IO,
		.scl_pullup_en = GPIO_PULLUP_ENABLE,
		.master.clk_speed = I2C0_MASTER_FREQ_HZ,
		// .clk_flags = 0,          /*!< Optional, you can use I2C_SCLK_SRC_FLAG_* flags to choose i2c source clock here. */
	};
	esp_err_t err = i2c_param_config(I2C0_DEVICE_PORT, &conf);
	if(err != ESP_OK)
	{
		printf("I2C0 cannot be initialized!!! Error code: 0x%x\n", err);
		return 0; 
	}
	err = i2c_driver_install(I2C0_DEVICE_PORT, I2C_MODE_MASTER, 0, 0, 0);

	if(err != ESP_OK)
	{
		printf("I2C0 cannot be installed. Error code: 0x%X\n", err);
		return 0;
	}
	// set i2c for lcd
	//ssd1306_set_interface(I2C0_DEVICE_PORT);
	tlv320aic3204_set_interface(I2C0_DEVICE_PORT);
	return 1;
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void app_main(void)
{
	printf("ESP32 Project started!!!\n");
	if(hw_initialize())
	{
		//xTaskCreate(gui_128x64_thread, "gui 128x64", 1024 * 2, (void *)0, 10, NULL);
		xTaskCreate(tlv320aic3204_codec_thread, "tlv320aic3204", 1024 * 2, (void *)0, 10, NULL);
	}
}
