#include "complex-biquad-f32.h"
#include "esp_dsp.h"

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void dsp_complex_biquad_cascaded_f32(dsp_complex_biquad_cascade_instance_f32 * iir,
	float * pISrc, float * pQSrc, uint32_t size)
{
	for(int i = 0; i < iir->num_stages; i++)
	{
		dsps_biquad_f32(pISrc, pISrc, size, iir->biquad[i].coeffs, iir->biquad[i].ir);
		dsps_biquad_f32(pQSrc, pQSrc, size, iir->biquad[i].coeffs, iir->biquad[i].qr);
	}
	// float b0, b1, b2, a1, a2;
	// float ir1, ir2, qr1, qr2;

	// float * pOut = pDst;
	// const float * pInput = pSrc;
	// float idata, qdata;

	// for(uint32_t i = 0; i < size/2; i++)
	// {
	// 	idata = *pInput++;
	// 	qdata = *pInput++;
		
	// 	for(int s = 0; s < iir->num_stages; s++)
	// 	{
	// 		a1 = iir->biquad[s].coeffs[0];
	// 		a2 = iir->biquad[s].coeffs[1];
	// 		b0 = iir->biquad[s].coeffs[2];
	// 		b1 = iir->biquad[s].coeffs[3];
	// 		b2 = iir->biquad[s].coeffs[4];

	// 		ir1 = iir->biquad[s].ir1;
	// 		ir2 = iir->biquad[s].ir2;
	// 		qr1 = iir->biquad[s].qr1;
	// 		qr2 = iir->biquad[s].qr2;

	// 		float ir0 = idata - a1 * ir1 - a2 * ir2;
	// 		idata = b0 * ir0 + b1 * ir1 + b2 * ir2;
	// 		ir2 = ir1;
	// 		ir1 = ir0;

	// 		float qr0 = qdata - a1 * qr1 - a2 * qr2;
	// 		qdata = b0 * qr0 + b1 * qr1 + b2 * qr2;
	// 		qr2 = qr1;
	// 		qr1 = qr0;

	// 		iir->biquad[s].ir1 = ir1;
	// 		iir->biquad[s].ir2 = ir2;
	// 		iir->biquad[s].qr1 = qr1;
	// 		iir->biquad[s].qr2 = qr2;
	// 	}

	// 	*pOut++ = idata;
	// 	*pOut++ = qdata;
	// }
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void dsp_init_complex_biquad_cascaded_f32(dsp_complex_biquad_cascade_instance_f32 * iir,
	uint8_t numStage, const float * coeffs, dsp_complex_biquad_f32 * biquad)
{
	for(int i = 0; i < numStage; i++)
	{
		biquad[i].ir[0] = 0.f;
		biquad[i].ir[1] = 0.f;
		biquad[i].qr[0] = 0.f;
		biquad[i].qr[1] = 0.f;
		biquad[i].coeffs = &coeffs[i*5];
	}

	iir->num_stages = numStage;
	iir->biquad = biquad;
}