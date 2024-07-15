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
static spi_transaction_t * spi_get_transaction();

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
	// transaction collection initialization
	for(int i = 0; i < VSPI_QUEUE_SIZE; i++)
	{
		spi_transaction_t * item = spi_get_transaction();
		item->flags = 0;
		item->cmd = 0;
		item->addr = 0;
		item->length = 0;
		item->rxlength = 0;
		item->user = 0;
		item->tx_buffer = 0;
		item->rx_buffer = 0;
	}
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void st7789_write_command(const uint8_t * cmd, uint16_t size)
{
	spi_transaction_t * command = spi_get_transaction();
	command->flags = SPI_TRANS_USE_TXDATA;
	command->length = VSPI_BYTE_SIZE;
	command->rxlength = 0;
	command->tx_data[0] = cmd[0];
	command->user = (void *)LCD_COMMAND;

	esp_err_t ret = spi_send_data(command);
	ESP_ERROR_CHECK(ret);

	size--;

	if(size)
		st7789_write_data(&cmd[1], size);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void st7789_write_gdata(const uint8_t * data, uint16_t size)
{
	st7789_write_data(data, size);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void st7789_wait_and_delay(uint32_t ms)
{
	while(activ_tx_number != 0)
	{
		spi_transaction_t * transaction;
		esp_err_t ret = spi_device_get_trans_result(spi_port, &transaction, portMAX_DELAY);
		ESP_ERROR_CHECK(ret);
		activ_tx_number--;
	}

	if(ms)
		vTaskDelay(ms / portTICK_PERIOD_MS);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
static inline void st7789_write_data(const uint8_t * data, uint16_t size)
{
	spi_transaction_t * trans = spi_get_transaction();
	trans->length = VSPI_BYTE_SIZE * size;
	trans->rxlength = 0;
	trans->user = (void *)LCD_DATA;

	if(size > sizeof(trans->tx_data))
	{
		trans->flags = 0;
		trans->tx_buffer = data;
	}
	else
	{
		trans->flags = SPI_TRANS_USE_TXDATA;
		memcpy(trans->tx_data, data, size);
	}
	esp_err_t ret = spi_send_data(trans);
	ESP_ERROR_CHECK(ret);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
static inline esp_err_t spi_send_data(spi_transaction_t * tx_data)
{
	activ_tx_number++;
	return spi_device_queue_trans(spi_port, tx_data, portMAX_DELAY);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
static spi_transaction_t * spi_get_transaction()
{
	static uint32_t index = 0;
	static spi_transaction_t transaction_collection[VSPI_QUEUE_SIZE];

	if(activ_tx_number == VSPI_QUEUE_SIZE)
	{
		spi_transaction_t * old_transaction;
		esp_err_t ret = spi_device_get_trans_result(spi_port, &old_transaction, portMAX_DELAY);
		ESP_ERROR_CHECK(ret);
		activ_tx_number--;
	}

	spi_transaction_t * transaction = &transaction_collection[index];
	index = (index == (VSPI_QUEUE_SIZE - 1)) ? 0 : index + 1;
	return transaction;
}