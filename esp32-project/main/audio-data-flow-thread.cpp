#include "driver/i2s_std.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "configuration.h"

#include <math.h>

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
i2s_chan_handle_t i2s0_tx_handle = NULL;
i2s_chan_handle_t i2s0_rx_handle = NULL;

int32_t audio_data[RX_IQ_BUFFER_SIZE] = {0};


/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
#define DSP_INT32_TO_FLOAT32_CONST (4.656612875245796924105750827168e-10f)
static inline int32_t dsp_f32_to_int32(float inValue)
{
	return ((int32_t)(inValue / DSP_INT32_TO_FLOAT32_CONST));
}

static inline  float dsp_int32_to_f32(int32_t inValue)
{
	return (((float)inValue) * DSP_INT32_TO_FLOAT32_CONST);
}

struct dc_filter_instance
{
	const uint32_t size;
	uint32_t index;
	float sum;
	float * history;
};

#define new_filter(name, buffer_size)				\
static struct dc_filter_instance name =				\
{													\
	.size = buffer_size,							\
	.index = 0,										\
	.sum = 0,										\
	.history = 0									\
}

new_filter(am_rx_dc_filter, 8);

static inline float remove_dc_from_sample(float sample, struct dc_filter_instance * inst)
{
	static float oldSample = 0.f;
	static float oldResult = 0.f;
	
	float result = sample - oldSample + 0.995f * oldResult;

	oldResult = result;
	oldSample = sample;

	return result;

	// float * current = &inst->history[inst->index];
	// inst->sum -= *current;
	// *current = sample;
	// inst->index++;
	// inst->index &= (inst->size-1);
	// inst->sum += sample;
	// float result = sample - inst->sum/inst->size;
	// return result;
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/



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
	
	am_rx_dc_filter.history = (float*)malloc(sizeof(float) * 8);

	for(int i = 0; i < 8; i++)
	{
		am_rx_dc_filter.history[i] = 0.f;
	}

	for(;;)
	{
		res = i2s_channel_read(i2s0_rx_handle, audio_data, RX_IQ_BUFFER_SIZE, &bytes_read, 1000);
		if(res != ESP_OK || (bytes_read != RX_IQ_BUFFER_SIZE))
		{
			printf("audio_data_flow_thread: reading: err = %d, size = %d", res, bytes_read);
		}
		 int32_t * leftWord = audio_data;
		 int32_t * rightWord = &audio_data[1];
		 for(int i = 0; i < RX_IQ_BUFFER_SIZE/2; i++)
		 {
			volatile float im = dsp_int32_to_f32(*leftWord);
			volatile float re = dsp_int32_to_f32(*rightWord);
			volatile float res = sqrt(im * im + re * re);
			res = remove_dc_from_sample(res, &am_rx_dc_filter);
			volatile int32_t demod = dsp_f32_to_int32(res);
			*leftWord = demod;
		 	*rightWord = demod;
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