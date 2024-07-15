#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <stdio.h>
#include "driver/gpio.h"
#include "driver/i2c.h"
#include "driver/i2s_std.h"
#include "ssd1306-interface.h"
#include "lcd-driver.h"
#include "tlv320aic3204-interface.h"
#include "si5351-interface.h"
#include "st7789-interface.h"
#include "configuration.h"

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
extern void tlv320aic3204_codec_thread(void * args);
extern void gui_thread(void * args);
extern void st7789_pre_transaction_cb(spi_transaction_t *trans);

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
extern i2s_chan_handle_t i2s0_tx_handle;
extern i2s_chan_handle_t i2s0_rx_handle;

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
static esp_err_t i2c0_initialize()
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
	// tlv320aic3204_set_interface(I2C0_DEVICE_PORT);
	// si5351_set_interface(I2C0_DEVICE_PORT);
	return ESP_OK;
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
static esp_err_t i2s0_initialize()
{
	i2s_chan_config_t chan_cfg =
	{
		.id = I2S_NUM,
		.role = I2S_ROLE_MASTER,
		.dma_desc_num = 4, // DMA buffers number
		.dma_frame_num = RX_IQ_BUFFER_SIZE,
		.auto_clear = true,
	};

	esp_err_t res = i2s_new_channel(&chan_cfg, &i2s0_tx_handle, &i2s0_rx_handle);

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
			.bit_shift = false,
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
static esp_err_t spi_initialize()
{
	spi_bus_config_t buscfg =
	{
		.mosi_io_num = LCD_MOSI,
		.miso_io_num = GPIO_NUM_NC,
		.sclk_io_num = LCD_SCL,
		.quadwp_io_num = GPIO_NUM_NC,
		.quadhd_io_num = GPIO_NUM_NC,
		.data4_io_num = GPIO_NUM_NC,
		.data5_io_num = GPIO_NUM_NC,
		.data6_io_num = GPIO_NUM_NC,
		.data7_io_num = GPIO_NUM_NC,
		.max_transfer_sz = VSPI_MAX_BUFFER_SIZE,
		.flags = SPICOMMON_BUSFLAG_MASTER | SPICOMMON_BUSFLAG_NATIVE_PINS,
		.isr_cpu_id = ESP_INTR_CPU_AFFINITY_AUTO,
		.intr_flags = ESP_INTR_FLAG_LEVEL1
	};
	//Initialize the SPI bus
	esp_err_t ret = spi_bus_initialize(LCD_SPI, &buscfg, SPI_DMA_CH_AUTO);
	ESP_ERROR_CHECK(ret);

	spi_device_interface_config_t lcd_dev_cfg =
	{
		.command_bits = 0,
		.address_bits = 0,
		.dummy_bits = 0,
		.mode = 0,
		.clock_source = SPI_CLK_SRC_DEFAULT,
		.duty_cycle_pos = 128,
		.cs_ena_pretrans = 0,
		.cs_ena_posttrans = 0,
		.clock_speed_hz = LCD_SPI_CLOCK,
		.input_delay_ns = 0,
		.spics_io_num = LCD_CS,
		.flags = SPI_DEVICE_3WIRE,
		.queue_size = VSPI_QUEUE_SIZE,
		.pre_cb = st7789_pre_transaction_cb,
		.post_cb = 0
	};
	//Attach the LCD to the SPI bus
	spi_device_handle_t spi_port;
	ret |= spi_bus_add_device(LCD_SPI, &lcd_dev_cfg, &spi_port);
	ESP_ERROR_CHECK(ret);
	st7789_set_interface(spi_port);
	return ret;
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
static esp_err_t gpio_initialize()
{
	gpio_config_t io_conf =
	{
		.pin_bit_mask = ((1ULL << LCD_RST) | (1ULL << LCD_C_D)),
		.mode = GPIO_MODE_OUTPUT,
		.pull_up_en = true
	};
	return gpio_config(&io_conf);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
static esp_err_t hw_initialize()
{
	// i2c configuration
	// esp_err_t res = i2c0_initialize();
	// i2s config
	// res |= i2s0_initialize();
	// hspi config
	esp_err_t res = spi_initialize();
	// gpio configuration
	res |= gpio_initialize();
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
		//Reset the display
		gpio_set_level(LCD_RST, 0);
		vTaskDelay(100 / portTICK_PERIOD_MS);
		gpio_set_level(LCD_RST, 1);
		vTaskDelay(100 / portTICK_PERIOD_MS);

		// create threads
		//BaseType_t ret0 = xTaskCreate(tlv320aic3204_codec_thread, "tlv320aic3204", 1024 * 2, (void *)0, 10, NULL);
		//printf("tlv320aic3204_codec_thread was created with code %d\n", ret0);

		//Reset the display
		BaseType_t ret1 = xTaskCreate(gui_thread, "guithread", 1024 * 2, (void *)0, 10, NULL);
		printf("gui_thread was created with code %d\n", ret1);
	}
	else
		printf("HW initialization FAILED !!!\n");
}
