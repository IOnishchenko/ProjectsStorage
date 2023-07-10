#include "si5351-interface.h"
#include "driver/i2c.h"

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
#define SI5351_TX_TIMEOUT	100u
#define SI5351_RX_TIMEOUT	500u
static i2c_port_t si5351_port;

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void si5351_set_interface(i2c_port_t port)
{
	si5351_port = port;
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void si5351_write_bulk(uint8_t addr, uint8_t bytes, uint8_t *data)
{
	esp_err_t err = ESP_OK;

    i2c_cmd_handle_t handle = i2c_cmd_link_create();
    assert (handle != NULL);

    err = i2c_master_start(handle);
    if (err != ESP_OK) {
        goto end;
    }

    err = i2c_master_write_byte(handle, SI5351_DEVICE_ADDRESS << 1 | I2C_MASTER_WRITE, true);
    if (err != ESP_OK) {
        goto end;
    }

	err = i2c_master_write_byte(handle, addr, true);
    if (err != ESP_OK) {
        goto end;
    }

    err = i2c_master_write(handle, data, bytes, true);
    if (err != ESP_OK) {
        goto end;
    }

    i2c_master_stop(handle);
    err = i2c_master_cmd_begin(si5351_port, handle, SI5351_TX_TIMEOUT * bytes);

end:
    i2c_cmd_link_delete_static(handle);

	if(err != ESP_OK)
		printf("si5351_write_bulk. Cannot write data: 0x%X\n", err);
	else
		printf("si5351_write_bulk. OK\n");
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void si5351_write(uint8_t addr, uint8_t data)
{
	esp_err_t err = ESP_OK;

    i2c_cmd_handle_t handle = i2c_cmd_link_create();
    assert (handle != NULL);

    err = i2c_master_start(handle);
    if (err != ESP_OK) {
        goto end;
    }

    err = i2c_master_write_byte(handle, SI5351_DEVICE_ADDRESS << 1 | I2C_MASTER_WRITE, true);
    if (err != ESP_OK) {
        goto end;
    }

	err = i2c_master_write_byte(handle, addr, true);
    if (err != ESP_OK) {
        goto end;
    }

	err = i2c_master_write_byte(handle, data, true);
    if (err != ESP_OK) {
        goto end;
    }

    i2c_master_stop(handle);
    err = i2c_master_cmd_begin(si5351_port, handle, SI5351_TX_TIMEOUT);

end:
    i2c_cmd_link_delete_static(handle);

	if(err != ESP_OK)
		printf("si5351_write. Cannot write data: 0x%X\n", err);
	else
		printf("si5351_write. OK\n");
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
uint8_t si5351_read(uint8_t addr)
{
	uint8_t res = 0;

	esp_err_t err = i2c_master_write_read_device(si5351_port, SI5351_DEVICE_ADDRESS,
		&addr, 1, &res, 1, SI5351_RX_TIMEOUT);

	if(err != ESP_OK)
		printf("si5351_read. Cannot read data: 0x%X\n", err);
	else
		printf("si5351_read. OK\n");

	return res;
}