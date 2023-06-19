#include "ssd1306.h"
#include "ssd1306-interfaces.h"
#include "driver/i2c.h"

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
static i2c_port_t ssd1306_port;

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void ssd1306_set_interface(i2c_port_t port)
{
	ssd1306_port = port;
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
static inline void ssd1306_write_buffer(const uint8_t * buffer, uint16_t size, uint8_t cn_byte)
{
	i2c_cmd_handle_t link =  i2c_cmd_link_create();
	i2c_master_start(link);
	for(int i = 0; i < (size - 1); i++)
	{
		i2c_master_write_byte(link, cn_byte, true);
		i2c_master_write_byte(link, *buffer++, true);
	}
	i2c_master_write_byte(link, cn_byte & (~(1 << 7)), true);
	i2c_master_write_byte(link, *buffer, true);
	
	i2c_master_stop(link);
	i2c_master_cmd_begin(ssd1306_port, link, 0xffffffff);
	i2c_cmd_link_delete_static(link);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void ssd1306_write_commands(const uint8_t * cmds, uint16_t size)
{
	ssd1306_write_buffer(cmds, size, SSD1306_I2C_CMD_BYTE);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void ssd1306_write_gdata(const uint8_t * data, uint16_t size)
{
	ssd1306_write_buffer(data, size, SSD1306_I2C_GDATA_BYTE);
}
