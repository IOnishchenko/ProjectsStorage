#include "tlv320aic3204-interface.h"
#include "driver/i2c.h"

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
static i2c_port_t codec_port;

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void tlv320aic3204_set_interface(i2c_port_t port)
{
	codec_port = port;
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void tlv320aic3204_write_buffer(const uint8_t * pSrc, uint16_t size)
{
	esp_err_t err = i2c_master_write_to_device(codec_port,
		TLV320AIC3204_I2C_ADDRESS, pSrc, size, 1000);

	if(err != ESP_OK)
		printf("tlv320aic3204_write_buffer. Cannot write data: 0x%X\n", err);
	else
		printf("tlv320aic3204_write_buffer. OK\n");

	// i2c_cmd_handle_t link =  i2c_cmd_link_create();
	// i2c_master_start(link);
	// // create address byte
	// i2c_master_write_byte(link, (TLV320AIC3204_I2C_ADDRESS << 1) & 1, true);
	// for(int i = 0; i < size; i++)
	// {
	// 	i2c_master_write_byte(link, *cmds++, true);
	// }
	// i2c_master_stop(link);
	// esp_err_t err = i2c_master_cmd_begin(codec_port, link, 0xffffffff);
	// if()
	// i2c_cmd_link_delete_static(link);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void tlv320aic3204_read_buffer(uint8_t * pDst, uint16_t size)
{
	esp_err_t err = i2c_master_read_from_device(codec_port,
		TLV320AIC3204_I2C_ADDRESS, pDst, size, 1000);
		
	if(err != ESP_OK)
		printf("tlv320aic3204_write_buffer. Cannot write data: 0x%X\n", err);
	else
		printf("tlv320aic3204_read_buffer. OK\n");

	// i2c_cmd_handle_t link =  i2c_cmd_link_create();
	// i2c_master_start(link);
	// // create address byte
	// i2c_master_write_byte(link, (TLV320AIC3204_I2C_ADDRESS << 1) & 1, true);
	// for(int i = 0; i < size; i++)
	// {
	// 	i2c_master_write_byte(link, *cmds++, true);
	// }
	// i2c_master_stop(link);
	// i2c_master_cmd_begin(codec_port, link, 0xffffffff);
	// i2c_cmd_link_delete_static(link);
}