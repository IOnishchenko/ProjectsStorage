#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "st7789-interface.h"
#include "configuration.h"

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
typedef enum
{
	LCD_COMMAND,
	LCD_DATA
} st7789_data_type;

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
static spi_device_handle_t spi_port;
static uint32_t activ_tx_number = 0;

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
static inline void st7789_write_data(const uint8_t * data, uint16_t size);
static inline esp_err_t spi_send_data(spi_transaction_t * tx_data);

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void st7789_pre_transaction_cb(spi_transaction_t *trans)
{
	gpio_set_level(LCD_C_D,
		(st7789_data_type)trans->user == LCD_COMMAND ? 0 : 1);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void st7789_set_interface(spi_device_handle_t port)
{
	spi_port = port;
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void st7789_write_commands(const uint8_t * cmd, uint16_t size)
{
	spi_transaction_t command =
	{
		.flags = SPI_TRANS_USE_TXDATA;
		.cmd = 0;
		.addr = 0;
		.length = VSPI_BYTE_SIZE;
		.rxlength = 0;
		.tx_data[0] = cmd[0];
		.user = (void *)LCD_COMMAND;
		.rx_buffer = 0;
	};
	esp_err_t ret = spi_send_data(&command);
	ESP_ERROR_CHECK(ret);

	size--;

	if(size)
	{
		st7789_write_data(&cmd[1], size);
	}
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void st7789_write_gdata(const uint8_t * data, uint16_t size)
{

}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void st7789_wait(uint32_t ms)
{
	while(activ_tx_number != 0)
	{
		spi_transaction_t * transaction;
		ESP_ERROR_CHECK(spi_device_get_trans_result(spi_port, &transaction, portMAX_DELAY));
		activ_tx_number--;
	}
	vTaskDelay(ms / portTICK_PERIOD_MS);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
static inline void st7789_write_data(const uint8_t * data, uint16_t size)
{
	spi_transaction_t trans =
	{
		.cmd = 0;
		.addr = 0;
		.length = VSPI_BYTE_SIZE * size;
		.rxlength = 0;
		.user = (void *)LCD_DATA;
		.rx_buffer = 0;
	};

	if(size > sizeof(trans.tx_data))
	{
		trans.flags = 0;
		trans.tx_buffer = data;
	}
	else
	{
		trans.flags = SPI_TRANS_USE_TXDATA;
		memcpy(trans.tx_data, data, size);
	}
	ESP_ERROR_CHECK(spi_send_data(&trans));
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
static inline esp_err_t spi_send_data(spi_transaction_t * tx_data)
{
	if(activ_tx_number == VSPI_QUEUE_SIZE)
	{
		spi_transaction_t * transaction;
		esp_err_t ret = spi_device_get_trans_result(spi_port, &transaction, portMAX_DELAY);
		ESP_ERROR_CHECK(ret);
		activ_tx_number--;
	}
	activ_tx_number++;
	return spi_device_queue_trans(spi_port, tx_data, portMAX_DELAY);
}