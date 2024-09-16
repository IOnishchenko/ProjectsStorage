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

#ifdef GUI_USE_PICTUREGDATA
	_spectrunGData
	{
		_spectrumAlphaLUT, _spectrumColorsLUT, _gdata
	},
#else // GUI_USE_PICTUREGDATA
	 _spectrunGData
	 {
		SVIEW_SPECTRUM_LUT_SIZE, _spectrumAlphaLUT,
		SVIEW_SPECTRUM_LUT_SIZE, _spectrumColorsLUT,
		_gdata
	},
#endif // GUI_USE_PICTUREGDATA
	_spectrumPicObject
	{
		PICTYPE_AL44,
		SVIEW_WIDTH,
		SVIEW_SPECTRUM_HEIGHT,
		&_spectrunGData
	},
	_spectrumPic(&_spectrumPicObject, &_waterfallTopPic),

#ifdef GUI_USE_PICTUREGDATA
		_waterfallGData
		{
			nullptr,
			&_gdata[SVIEW_SPECTRUM_HEIGHT*FULL_SCREEN_WIDTH]
		},
#else // GUI_USE_PICTUREGDATA
		_waterfallGData
		{
			0, nullptr,
			&_gdata[SVIEW_SPECTRUM_HEIGHT*FULL_SCREEN_WIDTH]
		},
#endif // GUI_USE_PICTUREGDAT
	_waterfallPicObject
	{
		PICTYPE_A8,
		SVIEW_WIDTH,
		SVIEW_WATERFALL_HEIGHT,
		&_waterfallGData
	},
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
	UpdateGraphicData();

	// Update the spectrum picture

	// Update the waterfall picture

	// Draw on the screen
	IUIControl::Draw();
}


/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void SpectrumView::UpdateGraphicData()
{
	// Update waterfall and calculate data to shift graphic data
	UpdateIfFrequencyChanges();
	// Process new FFT data
	ScaleFFTData();
	// Draw new data in the internal _gdata buffer
	
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void SpectrumView::ScaleFFTData()
{
	// reset values
	_scaleCurrentAverage = 0;
	float smoothingCoef = 0.8f; //Storage->Settings.UI.SpectrumViewSettings.Smoothing;
	
	if(_fractionalOffset < 0)
	{
		for(int i = SVIEW_WIDTH; i >= 0; --i)
		{
			// Scale data to width
			float newFFTValue = InterpolateRawValue(i);
			// Calculate average value
			_scaleCurrentAverage += newFFTValue/SVIEW_WIDTH;
			// Scale data to height
			newFFTValue = ScaleFFTDataToHeight(newFFTValue) * SVIEW_FLOAT_TO_BYTE_CONSTANT;
			
			// Data Smoothing
			int x0 = i + _integerOffset;
			float oldValue0 = (x0 >= 0) && (x0 < SVIEW_WIDTH)
				? static_cast<float>(_fftData[x0]) : newFFTValue;

			int x1 = x0 - 1;
			float oldValue1 = (x1 >= 0) && (x1 < SVIEW_WIDTH)
				? static_cast<float>(_fftData[x1]) : newFFTValue;

			float oldFFTValue = (oldValue0 - oldValue1) * (_fractionalOffset) + oldValue0;
			float fftValue = oldFFTValue + smoothingCoef * (fftValue - oldFFTValue);
			_fftData[i] = static_cast<uint8_t>(fftValue);
		}
	}
	else
	{
		for(int i = 0; i < SVIEW_WIDTH; ++i)
		{
			// Scale data to width
			float newFFTValue = InterpolateRawValue(i);
			// Calculate average value
			_scaleCurrentAverage += newFFTValue/SVIEW_WIDTH;
			// Scale data to height
			newFFTValue = ScaleFFTDataToHeight(newFFTValue) * SVIEW_FLOAT_TO_BYTE_CONSTANT;
			
			// Data Smoothing
			int x0 = i + _integerOffset;
			float oldValue0 = (x0 >= 0) && (x0 < SVIEW_WIDTH)
				? static_cast<float>(_fftData[x0]) : newFFTValue;

			int x1 = x0 + 1;
			float oldValue1 = (x1 >= 0) && (x1 < SVIEW_WIDTH)
				? static_cast<float>(_fftData[x1]) : newFFTValue;

			float oldFFTValue = (oldValue0 - oldValue1) * (_fractionalOffset) + oldValue0;
			float fftValue = oldFFTValue + smoothingCoef * (fftValue - oldFFTValue);
			_fftData[i] = static_cast<uint8_t>(fftValue);
		}
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
float SpectrumView::ScaleFFTDataToHeight(float value)
{
	if(_maxDisplayedValue < value)
		return 1.0f;

	if(_minDisplayedValue > value)
		return 1.0f/static_cast<float>(_spectrumPic.Height);

	return (_normK * value + _normB);
}

/*--------------------------------------------------------------------------//
// 
//--------------------------------------------------------------------------*/
inline void SpectrumView::UpdateIfFrequencyChanges()
{
	if(int frequency = 14123000;/*RadioDeviceDriver.GetCurrentFrequency().GetValue();*/ _frequency != frequency)
	{
		// calculate histories offsets
		uint32_t sampleRate = 48000;//RadioDeviceDriver.GetSecondaryReceiverSampleRate();
		float indexOffset = static_cast<float>(SVIEW_WIDTH)/sampleRate;
		indexOffset *= (frequency - _frequency);

		float integerOffset;
		_fractionalOffset = modf(indexOffset, &integerOffset);
		_integerOffset = static_cast<int>(integerOffset);
		_frequency = frequency;

		// waterfall data processing
		int windex = roundf(indexOffset);
		if(windex > SVIEW_WIDTH || windex < -SVIEW_WIDTH)
		{
#ifdef GUI_USE_PICTUREGDATA
			PictureGData * gdata = static_cast<PictureGData *>(const_cast<void *>(_waterfallPicObject.gdata));
#else // GUI_USE_PICTUREGDATA
			PictureGDataExt * gdata = static_cast<PictureGDataExt *>(const_cast<void *>(_waterfallPicObject.gdata));
#endif // GUI_USE_PICTUREGDATA
			uint8_t * pdst = const_cast<uint8_t *>(gdata->data);
			// clear all data
			for(int r = 0; r < (SVIEW_WIDTH * _waterfallPicObject.height); ++r)
			{
				*pdst++ = SVIEW_WATERFALL_TRANSPARENT_COLOR;
			}
		}
		else if(windex > 0)
		{
#ifdef GUI_USE_PICTUREGDATA
			PictureGData * gdata = static_cast<PictureGData *>(const_cast<void *>(_waterfallPicObject.gdata));
#else // GUI_USE_PICTUREGDATA
			PictureGDataExt * gdata = static_cast<PictureGDataExt *>(const_cast<void *>(_waterfallPicObject.gdata));
#endif // GUI_USE_PICTUREGDATA
			uint8_t * pdst = const_cast<uint8_t *>(gdata->data);
			uint8_t * psrc = pdst;
			psrc += windex * _waterfallPicObject.height;
			// shift waterfall
			// move data
			for(int i = 0; i < (_waterfallPicObject.height * (SVIEW_WIDTH - windex)); ++i)
			{
				*pdst++ = *psrc++;
			}
			// fill background
			for(int i = 0; i < (_waterfallPicObject.height * windex); ++i)
			{
				*pdst++ = SVIEW_WATERFALL_TRANSPARENT_COLOR;
			}
		}
		else
		{
			int dataSize = _waterfallPicObject.height * SVIEW_WIDTH;
#ifdef GUI_USE_PICTUREGDATA
			PictureGData * gdata = static_cast<PictureGData *>(const_cast<void *>(_waterfallPicObject.gdata));
#else // GUI_USE_PICTUREGDATA
			PictureGDataExt * gdata = static_cast<PictureGDataExt *>(const_cast<void *>(_waterfallPicObject.gdata));
#endif // GUI_USE_PICTUREGDATA
			uint8_t * pdst = const_cast<uint8_t *>(gdata->data);
			pdst += dataSize - 1;
			uint8_t * psrc = pdst;
			psrc += windex * _waterfallPicObject.height;
			// shift waterfall
			// move data
			for(int i = 0; i < (_waterfallPicObject.height * (SVIEW_WIDTH + windex)); ++i)
			{
				*pdst-- = *psrc--;
			}
			// fill background
			for(int i = 0; i < (_waterfallPicObject.height * (-windex)); ++i)
			{
				*pdst-- = SVIEW_WATERFALL_TRANSPARENT_COLOR;
			}
		}
	}
	else
	{
		_integerOffset = 0;
		_fractionalOffset = 0.f;
	}
}

/*--------------------------------------------------------------------------//
// 
//--------------------------------------------------------------------------*/
void SpectrumView::DrawIntoInternalGBuffer()
{
	//------------------------------------------------
	//  0       s0  s1       SPECTRUM_VIEW_WIDTH
	//  |-------|    |--------|
	//------------------------------------------------
	uint32_t s0, s1;
	uint32_t line = 0;
	CalculateSelectorPosition(s0, s1);
	auto colors = _lineDrawer->GetColorCollection();

	// draw left part
	while(line < s0)
	{
		DrawLine(&colors->Colors, line);
		line++;
	}
	
	// draw selector part
	while (line <= s1)
	{
		DrawLine(&colors->SelectorColors, line);
		line++;
	} 
	
	// draw right part
	while (line < SVIEW_WIDTH)
	{
		DrawLine(&colors->Colors, line);
		line++;
	}
}

/*--------------------------------------------------------------------------//
// 
//--------------------------------------------------------------------------*/
inline void SpectrumView::CalculateSelectorPosition(uint32_t & leftPos, uint32_t & rightPos)
{
	// calculate selector width and position
	uint32_t sampleRate = 48000; //RadioDeviceDriver.GetSecondaryReceiverSampleRate();
	float fftBandwidth = sampleRate;// sampleRate/2.f;
	float f0, f1;
	SettingsFacade.GetMainReceiverBandpass(f0, f1);
	float pixPerHz = SVIEW_WIDTH/fftBandwidth;
	constexpr float HALF_WIDTH = static_cast<float>(SVIEW_WIDTH)/2.f;
	
	// in case of other modulation a complex signal is filterd 
	// in case of CW a real signal is filtered
	float mult = SettingsFacade.GetCurrentModulation() == ModulationType::CW ? 2.f : 1.f; //1.f : 0.5f;
	//------------------------------------------------
	//  0    leftPos  rightPos       SPECTRUM_VIEW_WIDTH
	//  |-------|        |--------|
	//------------------------------------------------
	leftPos = round(HALF_WIDTH + f0 * pixPerHz * mult);
	rightPos = round(HALF_WIDTH + f1 * pixPerHz * mult);
}

/*--------------------------------------------------------------------------//
// 
//--------------------------------------------------------------------------*/
void SpectrumView::DrawLine(const SpectrumDrawerColorSet * colors, int line)
{
	float fftValue = static_cast<float>(_fftData[line])/SVIEW_FLOAT_TO_BYTE_CONSTANT;
	// spectrum scope
	if(_spectrumPic.Height)
	{
		// prepare spectrum scope graphic data
		float value = fftValue * (float)_spectrumPic.Height;
		_lineDrawer->Draw(value, line, colors);
	}

	// waterfall
	if(_waterfallTopPic.Height || _waterfallBottomPic.Height)
	{
		float value = fftValue * SVIEW_WATERFALL_MAX_ALPHA;
		// prepare faterfall graphic data
		value = (value > Storage->Settings.UI.SpectrumViewSettings.WaterfallDepth) ?
			(value - (float)Storage->Settings.UI.SpectrumViewSettings.WaterfallDepth) : 0.0f;
		DrawWaterfallDot(value, line);
	}
}

/*--------------------------------------------------------------------------//
// 
//--------------------------------------------------------------------------*/
inline void SpectrumView::DrawWaterfallDot(float value, uint16_t index)
{
	uint8_t * pixels = reinterpret_cast<uint8_t *>(const_cast<uint32_t *>(_waterfallPicObject.gdata));
	uint8_t alpha = static_cast<uint8_t>(value);
	pixels += index * _waterfallPicObject.height + _waterfallLine;
	*pixels = alpha;
}

}