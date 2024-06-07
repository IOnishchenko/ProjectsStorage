#ifndef BIQUAD_F32_H
#define BIQUAD_F32_H
#ifdef __cplusplus

#include "stdint.h"

extern "C"
{
#endif
/*-----------------------------------------------------------------//
// num_stages -	number of 2nd order stages in the filter.
// 				Overall order is 2*numStages.
// state - 		points to the array of state coefficients.
//				The array is of length 2*numStages.
// coeffs - 	points to the array of coefficients.
//				The array is of length 5*numStages.
//-----------------------------------------------------------------*/
typedef struct
{
	uint8_t num_stages;
	float * state;
	float * coeffs;
} dsp_biquad_cascade_instance_f32;

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
#ifdef __cplusplus
}
#endif
#endif // BIQUAD_F32_H