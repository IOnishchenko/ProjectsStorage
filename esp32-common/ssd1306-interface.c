#include <stdio.h>
#include "ssd1306.h"
#include "ssd1306-interface.h"
#include "driver/i2c_master.h"

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
static i2c_master_dev_handle_t ssd1306_port;
static uint8_t buffer[SSD1606_INTERFACE_BUFFER_NUMBER][SSD1306_INTERFACE_BUFFER_SIZE];
static uint16_t bindex = 0x00;

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void ssd1306_set_interface(i2c_device_t device)
{
	// esp_err_t err = i2c_master_probe(device, SSD1306_I2C_ADDRESS, 2000);
	// if(err != ESP_OK)
	// {
	// 	printf("SSD1306 devise was not detected. error = 0x%X\n", err);
	// }
	// else
	{
		printf("SSD1306 device detected successfully\n");
		i2c_device_config_t dev_cfg =
		{
			.dev_addr_length = SSD1306_I2C_ADDRESS_SIZE,
			.device_address = SSD1306_I2C_ADDRESS,
			.scl_speed_hz = 400000u,
		};
		esp_err_t err = i2c_master_bus_add_device(device, &dev_cfg, &ssd1306_port);
		if(err != ESP_OK)
			printf("i2c_master_bus_add_device failed. error = 0x%X\n", err);
		else
			printf("i2c_master_bus_add_device success. error = 0x%X\n", err);
	}
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
static inline void i2c_transmit(const uint8_t * psrc, size_t size)
{
	i2c_master_transmit(ssd1306_port, buffer[bindex], size, -1);
	bindex++;
	if(bindex == SSD1606_INTERFACE_BUFFER_NUMBER)
		bindex = 0;
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
static inline void ssd1306_write_data(const uint8_t * psrc, uint16_t size, uint8_t dc)
{
	uint16_t index = 0;
	while(size)
	{
		buffer[bindex][index] = (size == 1) ? dc | SSD1306_I2C_LAST_BYTE : dc | SSD1306_I2C_NOT_LAST_BYTE;
		index++;
		buffer[bindex][index] = *psrc++;
		index++;
		if(index == SSD1306_INTERFACE_BUFFER_SIZE)
		{
			i2c_transmit(buffer[bindex], SSD1306_INTERFACE_BUFFER_SIZE);
			index = 0;
		}
		size--;
	}
	if(index)
		i2c_transmit(buffer[bindex], index);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void ssd1306_write_command(const uint8_t * cmds, uint16_t size)
{
	ssd1306_write_data(cmds, size, SSD1306_I2C_CMD_BYTE);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void ssd1306_write_gdata(const uint8_t * data, uint16_t size)
{
	ssd1306_write_data(data, size, SSD1306_I2C_DATA_BYTE);
}
