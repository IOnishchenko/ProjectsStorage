#include <stdio.h>
#include "driver/i2c.h"
#include "driver/i2s_std.h"
#include "ssd1306-interfaces.h"
#include "lcd-driver.h"
#include "tlv320aic3204-interface.h"

#include "configuration.h"

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
//extern void gui_128x64_thread(void *args);
extern void tlv320aic3204_codec_thread(void * args);

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
extern i2s_chan_handle_t i2s0_tx_handle;
extern i2s_chan_handle_t i2s0_rx_handle;

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
static inline int i2c0_initialize()
{
	i2c_config_t conf =
	{
		.mode = I2C_MODE_MASTER,
		.sda_io_num = I2C0_MASTER_SDA_IO,
		.sda_pullup_en = GPIO_PULLUP_ENABLE,
		.scl_io_num = I2C0_MASTER_SCL_IO,
		.scl_pullup_en = GPIO_PULLUP_ENABLE,
		.master.clk_speed = I2C0_MASTER_FREQ_HZ,
		.clk_flags = I2C_SCLK_SRC_FLAG_FOR_NOMAL /*!< Optional, you can use I2C_SCLK_SRC_FLAG_* flags to choose i2c source clock here. */
	};
	esp_err_t err = i2c_param_config(I2C0_DEVICE_PORT, &conf);
	if(err != ESP_OK)
	{
		printf("I2C0 cannot be initialized!!! Error code: 0x%x\n", err);
		return ESP_FAIL; 
	}
	err = i2c_driver_install(I2C0_DEVICE_PORT, conf.mode, 0, 0, 0);

	if(err != ESP_OK)
	{
		printf("I2C0 cannot be installed. Error code: 0x%X\n", err);
		return ESP_FAIL;
	}
	// set i2c for lcd
	//ssd1306_set_interface(I2C0_DEVICE_PORT);
	tlv320aic3204_set_interface(I2C0_DEVICE_PORT);
	return ESP_OK;
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
static inline int i2s0_initialize()
{
	int res = ESP_OK;
	i2s_chan_config_t chan_cfg =
	{
		.id = I2S_NUM,
		.role = I2S_ROLE_MASTER,
		.dma_desc_num = 4, // DMA buffers number
		.dma_frame_num = RX_IQ_BUFFER_SIZE,
		.auto_clear = false,
	};
	res |= i2s_new_channel(&chan_cfg, &i2s0_tx_handle, &i2s0_rx_handle);

	i2s_std_config_t std_cfg =
	{
		.clk_cfg =
		{
			.sample_rate_hz = I2S_SAMPLE_RATE,
			.clk_src = I2S_CLK_SRC_DEFAULT,
			.mclk_multiple = I2S_MCLK_MULTIPLE_256
		},
		.slot_cfg = 
		{
			.data_bit_width = I2S_DATA_BIT_WIDTH_32BIT,
			.slot_bit_width = I2S_SLOT_BIT_WIDTH_AUTO,
			.slot_mode = I2S_SLOT_MODE_STEREO,
			.slot_mask = I2S_STD_SLOT_BOTH,
			.ws_width = I2S_DATA_BIT_WIDTH_32BIT,
			.ws_pol = false,
			.bit_shift = true,
			.msb_right = false
		},
		.gpio_cfg =
		{
			.mclk = I2S_MCLK,
			.bclk = I2S_BCK_IO,
			.ws = I2S_WS_IO,
			.dout = I2S_DO_IO,
			.din = I2S_DI_IO,
			.invert_flags =
			{
				.mclk_inv = false,
				.bclk_inv = false,
				.ws_inv = false,
			},
		},
	};

	res |= i2s_channel_init_std_mode(i2s0_tx_handle, &std_cfg);
	res |= i2s_channel_init_std_mode(i2s0_rx_handle, &std_cfg);

	return res;
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
static int hw_initialize()
{
	int res = ESP_OK;
	// i2c configuration
	res |= i2c0_initialize();
	// i2s config
	res |= i2s0_initialize();
	return res;
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void app_main(void)
{
	printf("ESP32 Project started!!!\n");
	if(hw_initialize() == ESP_OK)
	{
		//xTaskCreate(gui_128x64_thread, "gui 128x64", 1024 * 2, (void *)0, 10, NULL);
		xTaskCreate(tlv320aic3204_codec_thread, "tlv320aic3204", 1024 * 2, (void *)0, 10, NULL);
	}
}
