#include "SpectrumView.hpp"
#include "math.h"

namespace gui
{
/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
SpectrumView::SpectrumView(uint16_t y, const IUIContext & context,
	float (*fft)[SVIEW_FFT_RAW_DATA_SIZE])
	:
	IUIControl(0, y, SVIEW_WIDTH, SVIEW_HEIGHT, context),
	_rawFFTData{fft},

	_spectrumPicObject{PICTYPE_L4, SVIEW_WIDTH, SVIEW_SPECTRUM_HEIGHT, _spectrumGData},
	_spectrumPic(&_spectrumPicObject, &_waterfallTopPic),
	
	_waterfallPicObject{PICTYPE_A4, SVIEW_WIDTH, SVIEW_WATERFALL_HEIGHT, _waterfallGData},
	_waterfallTopPic(&_waterfallPicObject, &_waterfallBottomPic),
	_waterfallBottomPic(&_waterfallPicObject, nullptr)
{
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void SpectrumView::Animate()
{
	float range = 40.f; //Storage->Settings.UI.SpectrumViewSettings.SpectrumViewRangeToShow;
	// data scaling		
	_scaleAverage = _scaleAverage + SVIEW_AUTOSCALE_COEF * (_scaleCurrentAverage - _scaleAverage);
	_minDisplayedValue = _scaleAverage*1.05;
	_maxDisplayedValue = range + _minDisplayedValue;
	// calculate normalizer line (b - coef in y = k*x + b)
	float y0 = 1.0f / _spectrumPic.GetHeight();
		_normB = y0 - _normK * _minDisplayedValue;

	// Prepare input data

	// Update the spectrum picture

	// Update the waterfall picture

	// Draw on the screen
	IUIControl::Draw();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void SpectrumView::ScaleFFTData()
{
	for(int i = 0; i < SVIEW_WIDTH; ++i)
	{
		// Scale data to width
		float fftValue = InterpolateRawValue(i);
		// Scale data to height
		fftValue = ScaleFFTData(fftValue);
		// auto offset calculatio

		// data smothing
	}
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
inline float SpectrumView::InterpolateRawValue(uint16_t index)
{
	float x = static_cast<float>(index) *
		static_cast<float>(SVIEW_FFT_RAW_DATA_SIZE-1)/
		static_cast<float>(SVIEW_WIDTH-1);
	int srcIndex = floor(x);

	if((index == 0)||(index == SVIEW_WIDTH-1))
		return (*_rawFFTData)[srcIndex];

	float y0 = (*_rawFFTData)[srcIndex];
	float y1 = (*_rawFFTData)[srcIndex+1];
	float k = y1 - y0;
	float b = y0 - k * srcIndex;

	return (k * x + b);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
float SpectrumView::ScaleFFTData(float value)
{
	if(_maxDisplayedValue < value)
		return 1.0f;

	if(_minDisplayedValue > value)
		return 1.0f/static_cast<float>(_spectrumPic.Height);

	return (_normK * value + _normB);
}

}