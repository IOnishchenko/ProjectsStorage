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

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
struct dc_filter
{
	float oldSample;
	float oldResult;
};

dc_filter img = {0.f, 0.f}, real = {0.f, 0.f}, dem = {0.f, 0.f};

static inline float remove_dc_from_sample(float sample, dc_filter * filter)
{
	float result = sample - filter->oldSample + 0.995f * filter->oldResult;
	filter->oldResult = result;
	filter->oldSample = sample;
	return result;
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
iq_measurement iq_params =
{
	0.f, 0.f, 0.f,
	0.f, 0.f, 0.f,
	0.f
};

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void convert_int_to_float(const int32_t * pSrc, float * pDst, uint32_t size);
void calculate_iq_error(float *pSrc, uint32_t size);
void do_ddc(float *pSrc, uint32_t size);
void am_demodulate(float *pSrc, int32_t * pDst, uint32_t size);

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void audio_data_flow_thread(void * args)
{
	size_t bytes_read = 0;
	size_t bytes_write = 0;
	uint32_t preload_counter = 0;
	esp_err_t res = ESP_OK;

	// preload
	while(preload_counter != 2)
	{
		// res = i2s_channel_read(i2s0_rx_handle, audio_data, RX_IQ_BUFFER_SIZE, &bytes_read, 10000);
		// if(res != ESP_OK || (bytes_read != RX_IQ_BUFFER_SIZE))
		// {
		// 	printf("audio_data_flow_thread: reading: err = 0x%04x, size = %d\n", res, bytes_read);
		// 	continue;
		// }

		// do_ddc();
		// am_demodulate();

		res = i2s_channel_preload_data(i2s0_tx_handle, audio_data, RX_IQ_BUFFER_SIZE, &bytes_write);
		if(res != ESP_OK || (bytes_write != RX_IQ_BUFFER_SIZE))
		{
			printf("audio_data_flow_thread: preloading: err = 0x%04x, size = %d\n", res, bytes_read);
		}

		preload_counter++;
	}
	
	res = i2s_channel_enable(i2s0_rx_handle);
	printf("i2s_channel_enable: i2s0_rx_handle: err = 0x%04x\n", res);
	res = i2s_channel_enable(i2s0_tx_handle);
	printf("i2s_channel_enable: i2s0_tx_handle: err = 0x%04x\n", res);

	for(;;)
	{
		res = i2s_channel_read(i2s0_rx_handle, audio_data, RX_IQ_BUFFER_SIZE, &bytes_read, 1000);
		if(res != ESP_OK || (bytes_read != RX_IQ_BUFFER_SIZE))
		{
			printf("audio_data_flow_thread: reading: err = 0x%04x, size = %d\n", res, bytes_read);
		}
		
		convert_int_to_float(audio_data, (float*)audio_data, RX_IQ_BUFFER_SIZE);
		calculate_iq_error((float*)audio_data, RX_IQ_BUFFER_SIZE);
		do_ddc((float*)audio_data, RX_IQ_BUFFER_SIZE);
		am_demodulate((float*)audio_data, audio_data, RX_IQ_BUFFER_SIZE);

		res = i2s_channel_write(i2s0_tx_handle, audio_data, RX_IQ_BUFFER_SIZE, &bytes_write, 1000);
		if(res != ESP_OK || (bytes_write != RX_IQ_BUFFER_SIZE))
		{
			printf("audio_data_flow_thread: writting: err = 0x%04x, size = %d\n", res, bytes_write);
		}
	}
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void convert_int_to_float(const int32_t * pSrc, float * pDst, uint32_t size)
{
	for(uint32_t i = 0; i < size; i++)
	{
		*pDst++ = dsp_int32_to_f32(*pSrc++);
	}
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void calculate_iq_error(float *pSrc, uint32_t size)
{
	static int count = 0;
	float t1 = 0.f;
	float t2 = 0.f;
	float t3 = 0.f;

	size /= 2;

	float *data = pSrc;

	for(uint32_t j = 0; j < size; j++)
	{
		float i = *data++;
		float q = *data++;
		float i_sign = (i < 0.f ? -1.f : ((i > 0.f) ? 1.f : 0.f));
		float q_sign = (q < 0.f ? -1.f : ((q > 0.f) ? 1.f : 0.f));

		t1 += q * i_sign;
		t2 += i * i_sign;
		t3 += q * q_sign;
	}

	// filtering
	t1 = t1/((float)(size));
	t2 = t2/((float)(size));
	t3 = t3/((float)(size));

	// save data
	iq_params.teta1 = -0.003f * t1 + 0.997f * iq_params.teta1;
	iq_params.teta2 = 0.003f * t2 + 0.997f * iq_params.teta2;
	iq_params.teta3 = 0.003f * t3 + 0.997f * iq_params.teta3;

	float c1 = iq_params.teta2 != 0.f ? iq_params.teta1 / iq_params.teta2 : 0.f;
	t2 = iq_params.teta2 * iq_params.teta2;

	if(t2 > 0.f)
		t2 = (iq_params.teta3 * iq_params.teta3 - iq_params.teta1 * iq_params.teta1) / t2;
	float c2 = t2 > 0.f ? sqrtf(t2) : 1.f;

	// phase error in rad
	float psi = asinf(iq_params.teta1/iq_params.teta3);
	if(count == 6)
	{	
		iq_params.psi = psi;
		count = 0;
	}
	else
	{
		iq_params.psi = 0.05 * psi + 0.95 * iq_params.psi;
		count++;
	}

	float * idata = pSrc;
	float * qdata = &pSrc[1];
	for(uint32_t i = 0; i < size; i++)
	{
		*qdata += c1 * *idata;
		*idata *= c2;

		qdata += 2;
		idata += 2;
	}
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void do_ddc(float *pSrc, uint32_t size)
{
	// 12kHz
	for(float * inv = &pSrc[0]; inv < &pSrc[size]; inv += 4)
	{
		*inv = -*inv;
		inv++;
		*inv = -*inv;
		inv++;
		*inv = -*inv;
		inv++;
		*inv = -*inv;
		inv++;
	}
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void am_demodulate(float *pSrc, int32_t * pDst, uint32_t size)
{
	for(int i = 0; i < size/2; i++)
	{
		float im = *pSrc++;
		float re = *pSrc++;
		float res = (im * im) + (re * re);

		res = sqrt(res);
		res = remove_dc_from_sample(res, &dem);
		int32_t demod = dsp_f32_to_int32(res);

		*pDst++ = demod;
		*pDst++ = demod;
	}
}