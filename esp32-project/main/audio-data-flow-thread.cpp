#include "driver/i2s_std.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "configuration.h"

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
i2s_chan_handle_t i2s0_tx_handle = NULL;
i2s_chan_handle_t i2s0_rx_handle = NULL;

uint32_t audio_data[RX_IQ_BUFFER_SIZE] = {0};

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void audio_data_flow_thread(void * args)
{
	size_t bytes_read = 0;
	size_t bytes_write = 0;
	esp_err_t res = ESP_OK;

	i2s_channel_enable(i2s0_rx_handle);
	i2s_channel_enable(i2s0_tx_handle);

	for(;;)
	{
		res = i2s_channel_read(i2s0_rx_handle, audio_data, RX_IQ_BUFFER_SIZE, &bytes_read, 1000);
		if(res != ESP_OK || (bytes_read != RX_IQ_BUFFER_SIZE))
		{
			printf("audio_data_flow_thread: reading: err = %d, size = %d", res, bytes_read);
		}
		uint32_t * leftWord = audio_data;
		uint32_t * rightWord = &audio_data[1];
		for(int i = 0; i < RX_IQ_BUFFER_SIZE/2; i++)
		{
			*leftWord = *rightWord;
			leftWord += 2;
			rightWord += 2;
		}

		res = i2s_channel_write(i2s0_tx_handle, audio_data, RX_IQ_BUFFER_SIZE, &bytes_write, 1000);
		if(res != ESP_OK || (bytes_write != RX_IQ_BUFFER_SIZE))
		{
			printf("audio_data_flow_thread: writting: err = %d, size = %d", res, bytes_write);
		}
		//vTaskDelay(300);
	}
}