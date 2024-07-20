#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "driver/i2c_master.h"
#include "sh1106-interface.h"
#include "st7789-interface.h"
#include "configuration.h"

#include "lcd-driver.h"

#include "test_pic.h"
#define BUFFER_COUNT (VSPI_QUEUE_SIZE + 1)

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
// extern void tlv320aic3204_codec_thread(void * args);
// extern void gui_thread(void * args);
extern void st7789_pre_transaction_cb(spi_transaction_t *trans);

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
static esp_err_t i2c0_initialize()
{
	i2c_master_bus_config_t bus_config =
	{
		.i2c_port = I2C0_DEVICE_PORT,
		.sda_io_num = I2C0_MASTER_SDA_IO,
		.scl_io_num = I2C0_MASTER_SCL_IO,
		.clk_source = I2C_CLK_SRC_DEFAULT,
		.glitch_ignore_cnt = 7,
		.intr_priority = 0,
		.trans_queue_depth = 0,
		.flags.enable_internal_pullup = true,
	};

	i2c_master_bus_handle_t i2c_bus_handler;
	esp_err_t err = i2c_new_master_bus(&bus_config, &i2c_bus_handler);
	sh1106_set_interface(i2c_bus_handler);
	if(err != ESP_OK)
	{
		printf("I2C0 cannot be installed. Error code: 0x%X\n", err);
		return ESP_FAIL;
	}

	return ESP_OK;
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
	esp_err_t res = i2c0_initialize();
	// hspi config
	res |= spi_initialize();
	// gpio configuration
	res |= gpio_initialize();
	return res;
}

extern void sh1106_vertical_scroll(uint8_t value);

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void gui_thread(void * args)
{
	printf("gui_thread started\n");

	st7789.initialize();
	sh1106.initialize();

	uint8_t scroll = 0;

	sh1106.set_region(10, 1, 0, 0);
	static const uint8_t gdata0[] =
	{
		0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55,
		0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa,
		0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55,
		0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa
	};
	sh1106.write_gdata(&gdata0[0], sizeof(gdata0));

	// // draw picture
	uint16_t * palet_cache = (uint16_t *)malloc(test_pic.palettes->count * 2);
	uint16_t * gdata[BUFFER_COUNT];
	for(int i = 0; i < BUFFER_COUNT; i++)
	{
		gdata[i] = (uint16_t *)malloc(VSPI_MAX_BUFFER_SIZE);
	}

	// calculate palet
	for(int i = 0; i < test_pic.palettes->count; i++)
	{
		uint32_t color = test_pic.palettes->colors[i];
		uint16_t r = (color >> 8) & 0xf800;
		uint16_t g = (color >> 5) & 0x07e0;
		uint16_t b = (color >> 3) & 0x001f;
		palet_cache[i] = ~(r | g | b);
	}

	uint32_t full_size = LCD_VERTICAL_SIZE * LCD_HORIZONTAL_SIZE; // in pixel;
	uint32_t buff_index = 0;
	uint8_t * l8_data = (uint8_t*)test_pic.items[0]->data;

	st7789.set_region(0, 0, LCD_HORIZONTAL_SIZE, LCD_VERTICAL_SIZE);
	st7789.start_writing_gdata();
	while(full_size)
	{
		uint16_t * buffer = gdata[buff_index];
		uint32_t size;
		for(size = 0; (size < (VSPI_MAX_BUFFER_SIZE/2)) && full_size; size++)
		{
			*buffer++ = palet_cache[*l8_data++];
			full_size--;
		}

		st7789.write_gdata((uint8_t*)gdata[buff_index], size*2);

		buff_index++;
		if(buff_index == BUFFER_COUNT)
			buff_index = 0;
	}

	st7789.wait_and_delay(0);
	free(palet_cache);
	for(int i = 0; i < BUFFER_COUNT; i++)
	{
		free(gdata[i]);
	}


	while(1)
	{
		// vTaskDelay(250);
		// sh1106.set_region(0, 1, 0, 0);
		// static const uint8_t gdata0[] =
		// {
		// 	0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55,
		// 	0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa,
		// 	0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55,
		// 	0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa
		// };
		// sh1106.write_gdata(&gdata0[0], sizeof(gdata0));

		vTaskDelay(3);
		scroll += 1;
		scroll &= 0b00111111;
		sh1106_vertical_scroll(scroll);
		// vTaskDelay(250);

		// sh1106.set_region(0, 1, 0, 0);
		// static const uint8_t gdata1[] =
		// {
		// 	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		// 	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		// 	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		// 	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
		// };
		// sh1106.write_gdata(&gdata1[0], sizeof(gdata1)/2);
	}
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

		//Reset the display
		BaseType_t ret1 = xTaskCreate(gui_thread, "guithread", 1024 * 2, (void *)0, 10, NULL);
		printf("gui_thread was created with code %d\n", ret1);
	}
	else
		printf("HW initialization FAILED !!!\n");
}
