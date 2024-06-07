#ifndef COMPLEX_BIQUAD_F32_H
#define COMPLEX_BIQUAD_F32_H

#include "stdint.h"

#ifdef __cplusplus
extern "C"
{
#endif
/*-----------------------------------------------------------------//
// num_stages -	number of 2nd order stages in the filter.
// 				Overall order is 2*numStages.
// state - 		points to the array of state coefficients.
//				The array is of length 4*numStages.
// coeffs - 	points to the array of coefficients.
//				The array is of length 5*numStages.
//-----------------------------------------------------------------*/
// typedef struct
// {
// 	uint8_t num_stages;
// 	float * state;
// 	const float * coeffs;
// } dsp_complex_biquad_cascade_instance_f32;


typedef struct
{
	// float ir1;
	// float ir2;
	// float qr1;
	// float qr2;
	float ir[2];
	float qr[2];
	const float * coeffs;
} dsp_complex_biquad_f32;

typedef struct
{
	uint8_t num_stages;
	dsp_complex_biquad_f32 * biquad;
} dsp_complex_biquad_cascade_instance_f32;

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
extern void dsp_complex_biquad_cascaded_f32(dsp_complex_biquad_cascade_instance_f32 * iir,
	float * pISrc, float * pQSrc, uint32_t size);

extern void dsp_init_complex_biquad_cascaded_f32(dsp_complex_biquad_cascade_instance_f32 * iir,
	uint8_t numStage, const float * coeffs, dsp_complex_biquad_f32 * biquad);

#ifdef __cplusplus
}
#endif
#endif // COMPLEX_BIQUAD_F32_H