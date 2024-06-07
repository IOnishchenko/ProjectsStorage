#include "driver/i2s_std.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "complex-biquad-f32.h"
#include "configuration.h"

#include <math.h>

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
i2s_chan_handle_t i2s0_tx_handle = NULL;
i2s_chan_handle_t i2s0_rx_handle = NULL;

typedef union
{
	int32_t data[RX_IQ_BUFFER_SIZE];
	float fdata[RX_IQ_BUFFER_SIZE];
} buffer;

typedef struct
{
	float ibuffer[RX_IQ_BUFFER_SIZE/2];
	float qbuffer[RX_IQ_BUFFER_SIZE/2];
} splited_data;

buffer audio;
splited_data splited;

dsp_complex_biquad_cascade_instance_f32 lpf_6k;
dsp_complex_biquad_f32 complex_biquad[8];
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
const float iir_8_order_hpf_6000Hz_48kHz_coef[] =
{
	0.096839645228667282,
	0.193679290457334563,
	0.096839645228667282,
	-0.819565248381726175,
	0.206923829296395384,

	0.200871689219844607,
	0.401743378439689214,
	0.200871689219844607,
	-0.559007711502103377,
	0.362494468381481860,

	0.338681330070645825,
	0.677362660141291650,
	0.338681330070645825,
	-0.238991388767541835,
	0.593716709050125302,

	0.455348914716548092,
	0.910697829433096184,
	0.455348914716548092,
	-0.031857351621805384,
	0.853253010487997843
};

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void convert_int_to_float(const int32_t * pSrc, splited_data * pDst, uint32_t size);
void calculate_iq_error(splited_data *pSrc, uint32_t size);

void shift_friquence_12k(splited_data *pSrc, uint32_t size);
void shift_friquence_6k(splited_data *pSrc, uint32_t size, uint8_t up);
void am_demodulate(splited_data *pSrc, int32_t * pDst, uint32_t size);
void usb_demodulate(splited_data *pSrc, int32_t * pDst, uint32_t size);
void lsb_demodulate(splited_data *pSrc, int32_t * pDst, uint32_t size);

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void audio_data_flow_thread(void * args)
{
	size_t bytes_read = 0;
	size_t bytes_write = 0;
	uint32_t preload_counter = 0;
	esp_err_t res = ESP_OK;

	dsp_init_complex_biquad_cascaded_f32(&lpf_6k, 4,
		iir_8_order_hpf_6000Hz_48kHz_coef, complex_biquad);

	// preload
	while(preload_counter != 2)
	{
		res = i2s_channel_preload_data(i2s0_tx_handle, audio.data, RX_IQ_BUFFER_SIZE, &bytes_write);
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
		res = i2s_channel_read(i2s0_rx_handle, audio.data, RX_IQ_BUFFER_SIZE, &bytes_read, 1000);
		if(res != ESP_OK || (bytes_read != RX_IQ_BUFFER_SIZE))
		{
			printf("audio_data_flow_thread: reading: err = 0x%04x, size = %d\n", res, bytes_read);
		}
		
		convert_int_to_float(audio.data, &splited, RX_IQ_BUFFER_SIZE);
		calculate_iq_error(&splited, RX_IQ_BUFFER_SIZE);
		shift_friquence_6k(&splited, RX_IQ_BUFFER_SIZE, 0);

		//dsp_complex_biquad_cascaded_f32(&lpf_6k,
		//	splited.ibuffer, splited.qbuffer, RX_IQ_BUFFER_SIZE/2);

		am_demodulate(&splited, audio.data, RX_IQ_BUFFER_SIZE);

		res = i2s_channel_write(i2s0_tx_handle, audio.data, RX_IQ_BUFFER_SIZE, &bytes_write, 1000);
		if(res != ESP_OK || (bytes_write != RX_IQ_BUFFER_SIZE))
		{
			printf("audio_data_flow_thread: writting: err = 0x%04x, size = %d\n", res, bytes_write);
		}
	}
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void convert_int_to_float(const int32_t * pSrc, splited_data * pDst, uint32_t size)
{
	for(uint32_t i = 0; i < size/2; i++)
	{
		pDst->ibuffer[i] = dsp_int32_to_f32(*pSrc++);
		pDst->qbuffer[i] = dsp_int32_to_f32(*pSrc++);
	}
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void calculate_iq_error(splited_data *pSrc, uint32_t size)
{
	static int count = 0;
	float t1 = 0.f;
	float t2 = 0.f;
	float t3 = 0.f;
	uint32_t tsize = size/16;

	float * idata = pSrc->ibuffer;
	float * qdata = pSrc->qbuffer;
	float * ioutdata = idata;
	float * qoutdata = qdata;

	while(size)
	{
		for(uint32_t j = 0; j < tsize; j++)
		{
			float i = *idata++;
			float q = *qdata++;
			float i_sign = (i < 0.f ? -1.f : ((i > 0.f) ? 1.f : 0.f));
			float q_sign = (q < 0.f ? -1.f : ((q > 0.f) ? 1.f : 0.f));

			t1 += q * i_sign;
			t2 += i * i_sign;
			t3 += q * q_sign;
		}

		// filtering
		t1 = t1/((float)(tsize));
		t2 = t2/((float)(tsize));
		t3 = t3/((float)(tsize));

		// save data
		iq_params.teta1 = -0.007f * t1 + 0.993f * iq_params.teta1;
		iq_params.teta2 = 0.007f * t2 + 0.993f * iq_params.teta2;
		iq_params.teta3 = 0.007f * t3 + 0.993f * iq_params.teta3;

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

		// correct
		for(uint32_t i = 0; i < tsize; i++)
		{
			*qoutdata += c1 * *ioutdata;
			*ioutdata *= c2;
			qoutdata++;
			ioutdata++;
		}
		size -= 2 * tsize;
	}
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void shift_friquence_12k(splited_data *pSrc, uint32_t size)
{
	float * isample = pSrc->ibuffer;
	float * qsample = pSrc->qbuffer;

	for(float * inv = isample; inv < &isample[size/2]; isample += 2, qsample += 2)
	{
		*isample = -*isample;
		isample++;
		*isample = -*isample;
		isample++;

		*qsample = -*qsample;
		qsample++;
		*qsample = -*qsample;
		qsample++;
	}
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void shift_friquence_6k(splited_data *pSrc, uint32_t size, uint8_t up)
{
	static uint32_t index = 0;
	static float sin_lut[] =
	{
		0.f, 0.70710678118654752440084436210485f, 1.f, 0.70710678118654752440084436210485f,
		0.f,-0.70710678118654752440084436210485f,-1.f,-0.70710678118654752440084436210485f
	};

	static float cos_lut[] =
	{
		 1.f, 0.70710678118654752440084436210485f, 0.f,-0.70710678118654752440084436210485f,
		-1.f,-0.70710678118654752440084436210485f, 0.f, 0.70710678118654752440084436210485f
	};

	float * isample = pSrc->ibuffer;
	float * qsample = pSrc->qbuffer;
	float re, im;

	size /= 2;
	if(up)
	{
		for(uint32_t i = 0; i < size; i++)
		{
			re = *isample * sin_lut[index];
			im = *isample * cos_lut[index];
			*isample++ = im + re;
			im = *qsample * sin_lut[index];
			re = *qsample * cos_lut[index];
			*qsample++ = im + re;
			index = (index == (sizeof(sin_lut)/sizeof(float) - 1)) ? 0 : index + 1;
		}
	}
	else
	{
		for(uint32_t i = 0; i < size; i++)
		{
			re = *isample * sin_lut[index];
			im = *isample * cos_lut[index];
			*isample++ = im - re;
			im = *qsample * sin_lut[index];
			re = *qsample * cos_lut[index];
			*qsample++ = im - re;
			index = (index == (sizeof(sin_lut)/sizeof(float) - 1)) ? 0 : index + 1;
		}
	}
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void am_demodulate(splited_data *pSrc, int32_t * pDst, uint32_t size)
{
	for(int i = 0; i < size/2; i++)
	{
		float im = pSrc->ibuffer[i];
		float re = pSrc->qbuffer[i];
		float res = (im * im) + (re * re);

		res = sqrt(res);
		res = remove_dc_from_sample(res, &dem);
		int32_t demod = dsp_f32_to_int32(res);

		*pDst++ = demod;
		*pDst++ = demod;
	}
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void usb_demodulate(splited_data *pSrc, int32_t * pDst, uint32_t size)
{
	for(int i = 0; i < size/2; i++)
	{
		float im = pSrc->ibuffer[i];
		float re = pSrc->qbuffer[i];
		float res = im + re;
		int32_t demod = dsp_f32_to_int32(res);

		*pDst++ = demod;
		*pDst++ = demod;
	}
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void lsb_demodulate(splited_data *pSrc, int32_t * pDst, uint32_t size)
{
	for(int i = 0; i < size/2; i++)
	{
		float im = pSrc->ibuffer[i];
		float re = pSrc->qbuffer[i];
		float res = im - re;
		int32_t demod = dsp_f32_to_int32(res);

		*pDst++ = demod;
		*pDst++ = demod;
	}
}