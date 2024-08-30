
#include "configuration.h"
#include "driver/gpio.h"
#include "driver/gptimer.h"
#include "driver/i2c_master.h"
#include "sh1106-interface.h"
#include "st7789-interface.h"
#include "configuration.h"
#include "esp_vfs_fat.h"
#include "sdmmc_cmd.h"

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
extern void st7789_pre_transaction_cb(spi_transaction_t *trans);
extern bool IRAM_ATTR timer_key_scan_cb(gptimer_handle_t timer,
	const gptimer_alarm_event_data_t *edata, void *user_data);
extern void IRAM_ATTR external_gpio_interrup_cb(void * param);

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
static inline void i2c0_initialize()
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
	ESP_ERROR_CHECK(i2c_new_master_bus(&bus_config, &i2c_bus_handler));

	sh1106_set_interface(i2c_bus_handler);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
static inline void spi_initialize()
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
	ESP_ERROR_CHECK(spi_bus_initialize(LCD_SPI, &buscfgv, SPI_DMA_CH_AUTO));

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
	ESP_ERROR_CHECK(spi_bus_add_device(LCD_SPI, &lcd_dev_cfg, &spi_port));
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
	ESP_ERROR_CHECK(spi_bus_initialize(SD_SPI, &buscfgh, SPI_DMA_CH_AUTO));
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
static void timer_initialization()
{
	gptimer_handle_t gptimer = NULL;
	gptimer_config_t timer_config =
	{
		.clk_src = GPTIMER_CLK_SRC_DEFAULT,
		.direction = GPTIMER_COUNT_UP,
		.resolution_hz = 1000000, // 1MHz, 1 tick=1us
		.intr_priority = 0,
		.flags =
		{
			.intr_shared = false,
			.backup_before_sleep = false,
		}
	};
	ESP_ERROR_CHECK(gptimer_new_timer(&timer_config, &gptimer));

	gptimer_event_callbacks_t cbs =
	{
		.on_alarm = timer_key_scan_cb,
	};
	ESP_ERROR_CHECK(gptimer_register_event_callbacks(gptimer, &cbs, NULL));

	ESP_ERROR_CHECK(gptimer_enable(gptimer));

	gptimer_alarm_config_t alarm_config =
	{
		.alarm_count = 5000, // period = 5ms
		.reload_count = 0,
		.flags =
		{
			.auto_reload_on_alarm = true,
		}, // enable auto-reload
	};
	ESP_ERROR_CHECK(gptimer_set_alarm_action(gptimer, &alarm_config));
	ESP_ERROR_CHECK(gptimer_start(gptimer));
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void vfs_initialize()
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
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
static inline void gpio_initialize()
{
	gpio_config_t io_conf =
	{
		.pin_bit_mask = ((1ULL << LCD_RST) | (1ULL << LCD_C_D)),
		.mode = GPIO_MODE_OUTPUT,
		.pull_down_en = false,
		.pull_up_en = true,
		.intr_type = GPIO_INTR_DISABLE
	};
	gpio_config(&io_conf);

	io_conf.pin_bit_mask = (1ULL << ENC_BUTTON);
	io_conf.mode = GPIO_MODE_INPUT;
	gpio_config(&io_conf);

	io_conf.pin_bit_mask = ((1ULL << ENC_A) | (1ULL << ENC_B));
	io_conf.pull_up_en = false;
	io_conf.intr_type = GPIO_INTR_ANYEDGE;
	gpio_config(&io_conf);

	gpio_install_isr_service(0x00u);
	gpio_isr_handler_add(ENC_A, external_gpio_interrup_cb, (void*)ENC_A);
	gpio_isr_handler_add(ENC_B, external_gpio_interrup_cb, (void*)ENC_B);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void hw_initialize()
{
	// timer configuration
	timer_initialization();

	// i2c configuration
	// i2c0_initialize();

	// vspi and hspi config
	spi_initialize();

	// gpio configuration
	gpio_initialize();
}