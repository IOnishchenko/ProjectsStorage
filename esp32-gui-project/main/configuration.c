
#include "configuration.h"
#include "driver/gpio.h"
#include "driver/i2c_master.h"
#include "sh1106-interface.h"
#include "st7789-interface.h"
#include "configuration.h"
#include "esp_vfs_fat.h"
#include "sdmmc_cmd.h"

#include "esp_intr_alloc.h"

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
extern void st7789_pre_transaction_cb(spi_transaction_t *trans);
extern void timer_initialization();

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
static inline esp_err_t i2c0_initialize()
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
static inline esp_err_t spi_initialize()
{
	// ----- VSPI CONFIGURATION ------
	spi_bus_config_t buscfgv =
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
	//Initialize the VSPI bus
	esp_err_t ret = spi_bus_initialize(LCD_SPI, &buscfgv, SPI_DMA_CH_AUTO);
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

	// ----- HSPI CONFIGURATIO -----
	spi_bus_config_t buscfgh =
	{
		.mosi_io_num = SD_MOSI,
		.miso_io_num = SD_MISO,
		.sclk_io_num = SD_SCK,
		.quadwp_io_num = GPIO_NUM_NC,
		.quadhd_io_num = GPIO_NUM_NC,
		.data4_io_num = GPIO_NUM_NC,
		.data5_io_num = GPIO_NUM_NC,
		.data6_io_num = GPIO_NUM_NC,
		.data7_io_num = GPIO_NUM_NC,
		.max_transfer_sz = SD_MAX_BUFFER_SIZE,
		.flags = SPICOMMON_BUSFLAG_MASTER,
		.isr_cpu_id = ESP_INTR_CPU_AFFINITY_AUTO,
		.intr_flags = ESP_INTR_FLAG_LEVEL1
	};
	
	//Initialize the HSPI bus
	ret |= spi_bus_initialize(SD_SPI, &buscfgh, SPI_DMA_CH_AUTO);
	ESP_ERROR_CHECK(ret);
	return ret;
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
esp_err_t vfs_initialize()
{
	sdmmc_host_t host = SDSPI_HOST_DEFAULT();
	host.slot = SD_SPI;

	sdspi_device_config_t slot_config = SDSPI_DEVICE_CONFIG_DEFAULT();
	slot_config.gpio_cs = SD_CS;
	slot_config.host_id = host.slot;

	sdmmc_card_t *card;
	const char mount_point[] = MOUNT_POINT;
	esp_vfs_fat_sdmmc_mount_config_t mount_config =
	{
		.format_if_mount_failed = false,
		.max_files = 4,
		.allocation_unit_size = 16 * 1024
	};
	esp_err_t ret = esp_vfs_fat_sdspi_mount(mount_point, &host, &slot_config, &mount_config, &card);
	ESP_ERROR_CHECK(ret);

	// Card has been initialized, print its properties
	sdmmc_card_print_info(stdout, card);
	return ret;
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
static inline esp_err_t gpio_initialize()
{
	gpio_config_t io_conf =
	{
		.pin_bit_mask = ((1ULL << LCD_RST) | (1ULL << LCD_C_D)),
		.mode = GPIO_MODE_OUTPUT,
		.pull_down_en = false,
		.pull_up_en = true,
		.intr_type = GPIO_INTR_DISABLE
	};
	esp_err_t res = gpio_config(&io_conf);

	io_conf.pin_bit_mask = ((1ULL << ENC_CLK) | (1ULL << ENC_DATA) | (1ULL << ENC_BUTTON));
	io_conf.mode = GPIO_MODE_INPUT;
	io_conf.pull_up_en = false;
	io_conf.intr_type = GPIO_INTR_DISABLE;
	res |= gpio_config(&io_conf);
	return res;
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
esp_err_t hw_initialize()
{
	// encoder exti config
	timer_initialization();
	// i2c configuration
	esp_err_t res = i2c0_initialize();
	// hspi config
	res |= spi_initialize();
	// gpio configuration
	res |= gpio_initialize();
	return res;
}