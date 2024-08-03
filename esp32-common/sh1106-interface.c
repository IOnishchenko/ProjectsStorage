#include <stdio.h>
#include "sh1106.h"
#include "sh1106-interface.h"
#include "driver/i2c_master.h"

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
static i2c_master_dev_handle_t sh1106_port;
static uint8_t buffer[SH1106_INTERFACE_BUFFER_NUMBER][SH1106_INTERFACE_BUFFER_SIZE];
static uint16_t bindex = 0x00;

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void sh1106_set_interface(i2c_device_t device)
{
	i2c_device_config_t dev_cfg =
	{
		.dev_addr_length = SH1106_I2C_ADDRESS_SIZE,
		.device_address = SH1106_I2C_ADDRESS,
		.scl_speed_hz = 400000u,
	};
	i2c_master_bus_add_device(device, &dev_cfg, &sh1106_port);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
static inline void i2c_transmit(const uint8_t * psrc, size_t size)
{
	i2c_master_transmit(sh1106_port, buffer[bindex], size, -1);
	bindex++;
	if(bindex == SH1106_INTERFACE_BUFFER_NUMBER)
		bindex = 0;
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
static inline void sh1106_write_data(const uint8_t * psrc, uint16_t size, uint8_t dc)
{
	uint16_t index = 0;
	while(size)
	{
		buffer[bindex][index] = (size == 1) ? dc | SH1106_I2C_LAST_BYTE : dc | SH1106_I2C_NOT_LAST_BYTE;
		index++;
		buffer[bindex][index] = *psrc++;
		index++;
		if(index == SH1106_INTERFACE_BUFFER_SIZE)
		{
			i2c_transmit(buffer[bindex], SH1106_INTERFACE_BUFFER_SIZE);
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
void sh1106_write_command(const uint8_t * cmds, uint16_t size)
{
	sh1106_write_data(cmds, size, SH1106_I2C_CMD_BYTE);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void sh1106_write_gdata(const uint8_t * data, uint16_t size)
{
	sh1106_write_data(data, size, SH1106_I2C_DATA_BYTE);
}
