#include "SpectrumView.hpp"
#include "grid320x100.h"
#include "math.h"

namespace gui
{
/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
template<typename TColor>
SpectrumView<TColor>::SpectrumView(uint16_t y, const IUIContext & context,
	SpectrumViewSettings<TColor> & settings, float (*fft)[SVIEW_FFT_RAW_DATA_SIZE])
	:
	IUIControl(0, y, SVIEW_WIDTH, SVIEW_HEIGHT, context),
	_settings{settings},
	_rawFFTData{fft},
	_spectrumGDataLUT
	{
		settings.Colors.SpectrumTopColor,
		settings.Colors.SpectrumCurveColor,
		settings.Colors.SpectrumBottomColor,
		settings.SelectorColors.SpectrumTopColor,
		settings.SelectorColors.SpectrumCurveColor,
		settings.SelectorColors.SpectrumBottomColor,
	},
#ifdef GUI_USE_PICTUREGDATA
	_spectrunGData
	{
		_spectrumGDataLUT, _gdata,
	},
#else // GUI_USE_PICTUREGDATA
	 _spectrunGData
	 {
		SVIEW_SPECTRUM_LUT_SIZE,
		_spectrumGDataLUT, _gdata
	},
#endif // GUI_USE_PICTUREGDATA
	_spectrumPicObject
	{
		PICTYPE_AL44,
		SVIEW_WIDTH,
		settings.SpectrumHeight.GetValue(),
		&_spectrunGData
	},
	_spectrumPic(0, 0, SVIEW_WIDTH, _spectrumPicObject.height,
		0, 0, &_spectrumPicObject, 0, 0, &grid320x100,
		_spectrumPicObject.height != SVIEW_HEIGHT ? &_waterfallTopPic : nullptr),
#ifdef GUI_USE_PICTUREGDATA
		_waterfallGData
		{
			nullptr,
			&_gdata[_spectrumPicObject.height * FULL_SCREEN_WIDTH]
		},
#else // GUI_USE_PICTUREGDATA
		_waterfallGData
		{
			0, nullptr,
			&_gdata[_spectrumPicObject.height * FULL_SCREEN_WIDTH]
		},
#endif // GUI_USE_PICTUREGDAT
	_waterfallPicObject
	{
		PICTYPE_A8,
		SVIEW_WIDTH,
		(uint16_t)(SVIEW_HEIGHT - _spectrumPicObject.height),
		&_waterfallGData
	},
	_waterfallTopPic(0, _spectrumPicObject.height, SVIEW_WIDTH, _waterfallPicObject.height,
		0, 0, &_waterfallPicObject, settings.WaterfallColor, BACKGROUND_DARK, nullptr),
	_waterfallBottomPic(0, _spectrumPicObject.height, SVIEW_WIDTH, _waterfallPicObject.height,
		0, 0, &_waterfallPicObject, settings.WaterfallColor, BACKGROUND_DARK, nullptr),
	
	_gelement{_spectrumPicObject.height ? (IGElement*)&_spectrumPic : &_waterfallTopPic}
{
	//spectrum initialization
	uint8_t * gdata = _gdata;
	for(int i = 0; i < (_spectrumPicObject.height * SVIEW_WIDTH); ++i)
	{
		*gdata++ = 0;
	}

	// waterfall initializetion
	gdata = &_gdata[_spectrumPicObject.height * FULL_SCREEN_WIDTH];
	for(int i = 0; i < (_waterfallPicObject.height * SVIEW_WIDTH); ++i)
	{
		*gdata++ = SVIEW_WATERFALL_TRANSPARENT_COLOR;
	}
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
template<typename TColor>
IGElement * SpectrumView<TColor>::GetGraphicElement()
{
	return _gelement;
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
template<typename TColor>
void SpectrumView<TColor>::Animate()
{
	float range = _settings.SpectrumRangeToShow;
	// data scaling		
	_scaleAverage = _scaleAverage + SVIEW_AUTOSCALE_COEF * (_scaleCurrentAverage - _scaleAverage);
	_minDisplayedValue = _scaleAverage*1.05;
	_maxDisplayedValue = range + _minDisplayedValue;
	// calculate normalizer line (b - coef in y = k*x + b)
	float y0 = 1.0f / _spectrumPic.GetHeight();
		_normB = y0 - _normK * _minDisplayedValue;

	// Prepare input data
	UpdateGraphicData();

	// Draw on the screen
	IUIControl::Draw();
}


/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
template<typename TColor>
void SpectrumView<TColor>::UpdateGraphicData()
{
	// Update waterfall and calculate data to shift graphic data
	UpdateIfFrequencyChanges();
	// Process new FFT data
	ScaleFFTData();
	// Draw new data in the internal _gdata buffer
	DrawIntoInternalGBuffer();
	// 
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
template<typename TColor>
void SpectrumView<TColor>::ScaleFFTData()
{
	// reset values
	_scaleCurrentAverage = 0;
	float smoothingCoef = _settings.SmoothingCoeff;
	if(_fractionalOffset < 0)
	{
		// shift data from right to left
		for(int i = SVIEW_INTERPOLATED_DATA_SIZE; i >= 0; --i)
		{
			// Scale data to width
			float newFFTValue = InterpolateRawValue(i);
			// Calculate average value
			_scaleCurrentAverage += newFFTValue/SVIEW_INTERPOLATED_DATA_SIZE;
			// Scale data to height
			newFFTValue = ScaleFFTDataToHeight(newFFTValue) * SVIEW_FLOAT_TO_BYTE_CONSTANT;
			
			// Data Smoothing
			int x0 = i + _integerOffset;
			float oldValue0 = (x0 >= 0) && (x0 < SVIEW_INTERPOLATED_DATA_SIZE)
				? static_cast<float>(_fftData[x0]) : newFFTValue;

			int x1 = x0 - 1;
			float oldValue1 = (x1 >= 0) && (x1 < SVIEW_INTERPOLATED_DATA_SIZE)
				? static_cast<float>(_fftData[x1]) : newFFTValue;

			float oldFFTValue = (oldValue0 - oldValue1) * (_fractionalOffset) + oldValue0;
			float fftValue = oldFFTValue + smoothingCoef * (newFFTValue - oldFFTValue);
			_fftData[i] = static_cast<uint8_t>(fftValue);
		}
	}
	else
	{
		// shift data from left to right or not
		for(int i = 0; i < SVIEW_INTERPOLATED_DATA_SIZE; ++i)
		{
			// Scale data to width
			float newFFTValue = InterpolateRawValue(i);
			// Calculate average value
			_scaleCurrentAverage += newFFTValue/SVIEW_INTERPOLATED_DATA_SIZE;
			// Scale data to height
			newFFTValue = ScaleFFTDataToHeight(newFFTValue) * SVIEW_FLOAT_TO_BYTE_CONSTANT;
			
			// Data Smoothing
			int x0 = i + _integerOffset;
			float oldValue0 = (x0 >= 0) && (x0 < SVIEW_INTERPOLATED_DATA_SIZE)
				? static_cast<float>(_fftData[x0]) : newFFTValue;

			int x1 = x0 + 1;
			float oldValue1 = (x1 >= 0) && (x1 < SVIEW_INTERPOLATED_DATA_SIZE)
				? static_cast<float>(_fftData[x1]) : newFFTValue;

			float oldFFTValue = (oldValue0 - oldValue1) * (_fractionalOffset) + oldValue0;
			float fftValue = oldFFTValue + smoothingCoef * (newFFTValue - oldFFTValue);
			_fftData[i] = static_cast<uint8_t>(fftValue);
		}
	}
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
template<typename TColor>
inline float SpectrumView<TColor>::InterpolateRawValue(uint16_t index)
{
	float x = static_cast<float>(index) *
		static_cast<float>(SVIEW_FFT_RAW_DATA_SIZE-1)/
		static_cast<float>(SVIEW_INTERPOLATED_DATA_SIZE-1);
	int srcIndex = floor(x);

	if((index == 0)||(index == SVIEW_INTERPOLATED_DATA_SIZE-1))
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
template<typename TColor>
float SpectrumView<TColor>::ScaleFFTDataToHeight(float value)
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
template<typename TColor>
inline void SpectrumView<TColor>::UpdateIfFrequencyChanges()
{
	if(int frequency = 14123000;/*RadioDeviceDriver.GetCurrentFrequency().GetValue();*/ _frequency != frequency)
	{
		// calculate histories offsets
		uint32_t sampleRate = 48000;//RadioDeviceDriver.GetSecondaryReceiverSampleRate();
		float indexOffset = static_cast<float>(SVIEW_INTERPOLATED_DATA_SIZE)/sampleRate;
		indexOffset *= (frequency - _frequency);

		float integerOffset;
		_fractionalOffset = modf(indexOffset, &integerOffset);
		_integerOffset = static_cast<int>(integerOffset);
		_frequency = frequency;

		// waterfall data processing
		int windex = roundf(indexOffset);
		if(windex > SVIEW_INTERPOLATED_DATA_SIZE || windex < -SVIEW_INTERPOLATED_DATA_SIZE)
		{
#ifdef GUI_USE_PICTUREGDATA
			PictureGData * gdata = static_cast<PictureGData *>(const_cast<void *>(_waterfallPicObject.gdata));
#else // GUI_USE_PICTUREGDATA
			PictureGDataExt * gdata = static_cast<PictureGDataExt *>(const_cast<void *>(_waterfallPicObject.gdata));
#endif // GUI_USE_PICTUREGDATA
			uint8_t * pdst = const_cast<uint8_t *>(gdata->data);
			// clear all data
			for(int r = 0; r < (SVIEW_INTERPOLATED_DATA_SIZE * _waterfallPicObject.height); ++r)
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
			for(int i = 0; i < (_waterfallPicObject.height * (SVIEW_INTERPOLATED_DATA_SIZE - windex)); ++i)
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
			int dataSize = _waterfallPicObject.height * SVIEW_INTERPOLATED_DATA_SIZE;
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
			for(int i = 0; i < (_waterfallPicObject.height * (SVIEW_INTERPOLATED_DATA_SIZE + windex)); ++i)
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
template<typename TColor>
inline void SpectrumView<TColor>::DrawIntoInternalGBuffer()
{
	if(_spectrumPic.Height)
	{
		// draw spectrum
		uint8_t * fftData = _fftData;
		// dots to draw firs line
		float dot0 = static_cast<float>(*fftData++)/SVIEW_FLOAT_TO_BYTE_CONSTANT;
		dot0 *= static_cast<float>(_spectrumPic.Height);
		float dot1 = static_cast<float>(*fftData++)/SVIEW_FLOAT_TO_BYTE_CONSTANT;
		dot1 *= static_cast<float>(_spectrumPic.Height);

		// draw left part
		uint16_t width = SVIEW_WIDTH/2;
		uint8_t * pixels = _gdata;
		uint8_t topColor = (_settings.Colors.SpectrumTopAlpha << 4) | 0x00;			// colot LUT intedx = 0
		uint8_t curveColor = (_settings.Colors.SpectrumCurveAlpha << 4) | 0x01;		// colot LUT intedx = 1
		uint8_t bottomColor = (_settings.Colors.SpectrumBottomAlpha << 4) | 0x02;	// colot LUT intedx = 2
		FillSpectrumLines(dot0, dot1, fftData, width, pixels,
			topColor, curveColor, bottomColor);

		// TODO
		// draw selector part
		// width = SVIEW_WIDTH/2;
		// topColor = (_settings.SelectorColors.SpectrumTopAlpha << 4) | 0x03;			// colot LUT intedx = 3
		// curveColor = (_settings.SelectorColors.SpectrumCurveAlpha << 4) | 0x04;		// colot LUT intedx = 4
		// bottomColor = (_settings.SelectorColors.SpectrumBottomAlpha << 4) | 0x05;	// colot LUT intedx = 5
		// FillSpectrumLines(dot0, dot1,  fftData, width, pixels,
		// 	topColor, curveColor, bottomColor);
		
		// TODO
		// draw right part
		// width = SVIEW_WIDTH/2;
		// topColor = (_settings.Colors.SpectrumTopAlpha << 4) | 0x00;			// colot LUT intedx = 0
		// curveColor = (_settings.Colors.SpectrumCurveAlpha << 4) | 0x01;		// colot LUT intedx = 1
		// bottomColor = (_settings.Colors.SpectrumBottomAlpha << 4) | 0x02;	// colot LUT intedx = 2
		// FillSpectrumLines(dot0, dot1, fftData, width, pixels,
		// 	topColor, curveColor, bottomColor);
	}

	if(_waterfallTopPic.Height || _waterfallBottomPic.Height)
	{
#ifdef GUI_USE_PICTUREGDATA
			const PictureGData * gdata = static_cast<const PictureGData *>(_waterfallPicObject.gdata);
#else // GUI_USE_PICTUREGDATA
			const PictureGDataExt * gdata = static_cast<const PictureGDataExt *>(_waterfallPicObject.gdata);
#endif // GUI_USE_PICTUREGDATA

		uint8_t * pixels = const_cast<uint8_t *>(gdata->data);
		pixels += _waterfallLine;

		uint8_t * fftData = _fftData;
		uint8_t alpha = ConvertFFTDataToAlpha(*fftData++);

		for(int i = 0; i < SVIEW_WIDTH/2; ++i)
		{
			*pixels = alpha;
			pixels += _waterfallPicObject.height;

			alpha = ConvertFFTDataToAlpha(*fftData++);
			*pixels = alpha;
			pixels += _waterfallPicObject.height;
		}
		
		// update waterfall GEPicture Items
		_waterfallTopPic.Foreground.SkippedLines = _waterfallLine;
		_waterfallTopPic.Height = _waterfallPicObject.height - _waterfallLine;
		if(!_waterfallLine)
		{
			_waterfallTopPic.SetChild(&_waterfallBottomPic);
			_waterfallBottomPic.Y = _waterfallTopPic.Y + _waterfallTopPic.Height;
			_waterfallBottomPic.Height = _waterfallLine;
		}
		else
			_waterfallTopPic.SetChild(nullptr);

		_waterfallLine = _waterfallLine ? _waterfallLine - 1 : _waterfallPicObject.height - 1;
	}
	
	// //------------------------------------------------
	// //  0       s0  s1       SPECTRUM_VIEW_WIDTH
	// //  |-------|    |--------|
	// //------------------------------------------------
	// uint32_t s0, s1;
	// uint32_t line = 0;
	// CalculateSelectorPosition(s0, s1);
	// auto colors = _lineDrawer->GetColorCollection();

	// // draw left part
	// while(line < s0)
	// {
	// 	DrawLine(&colors->Colors, line);
	// 	line++;
	// }
	
	// // draw selector part
	// while (line <= s1)
	// {
	// 	DrawLine(&colors->SelectorColors, line);
	// 	line++;
	// } 
	
	// // draw right part
	// while (line < SVIEW_WIDTH)
	// {
	// 	DrawLine(&colors->Colors, line);
	// 	line++;
	// }
}

/*--------------------------------------------------------------------------//
// 
//--------------------------------------------------------------------------*/
template<typename TColor>
inline void SpectrumView<TColor>::FillSpectrumLines(float & dot0, float & dot1,
	uint8_t *& fftData, uint16_t width, uint8_t *& gbuffer, uint8_t topColor,
	uint8_t curveColor, uint8_t bottomColor)
{
	for(int i = 0; i < width; ++i)
	{
		int32_t l = static_cast<int32_t>(dot1) - static_cast<int32_t>(dot0);
		int32_t l1 = l/2;
		int32_t l0 = l1 + l%2;

		int32_t s0, e0;
		int32_t s1, e1;

		if(l < 0)
		{
			s0 = _spectrumPic.Height - dot0;
			e0 = s0 - l0;
			e1 = _spectrumPic.Height - dot1;
			s1 = e1 + l1;
		}
		else
		{
			e0 = _spectrumPic.Height - dot0;
			s0 = e0 - l0;
			s1 = _spectrumPic.Height - dot1;
			e1 = s1 + l1;
		}
		
		for(int j = 0; j < 2; ++j)
		{
			int32_t pixelIndex = 0;
			while(pixelIndex < s0)
			{
				*gbuffer++ = topColor;
				pixelIndex++;
			}

			do
			{
				*gbuffer++ = curveColor;
				pixelIndex++;
			}
			while(pixelIndex < e0);

			while(pixelIndex < _spectrumPic.Height)
			{
				*gbuffer++ = bottomColor;
				pixelIndex++;
			}

			s0 = s1;
			e0 = e1;
		}

		dot0 = dot1;
		dot1 = static_cast<float>(*fftData++)/SVIEW_FLOAT_TO_BYTE_CONSTANT;
		dot1 *= static_cast<float>(_spectrumPic.Height);
	}
}

/*--------------------------------------------------------------------------//
// 
//--------------------------------------------------------------------------*/
template<typename TColor>
inline void SpectrumView<TColor>::CalculateSelectorPosition(uint32_t & leftPos, uint32_t & rightPos)
{
	// // calculate selector width and position
	// uint32_t sampleRate = 48000; //RadioDeviceDriver.GetSecondaryReceiverSampleRate();
	// float fftBandwidth = sampleRate;// sampleRate/2.f;
	// float f0, f1;
	// SettingsFacade.GetMainReceiverBandpass(f0, f1);
	// float pixPerHz = SVIEW_WIDTH/fftBandwidth;
	// constexpr float HALF_WIDTH = static_cast<float>(SVIEW_WIDTH)/2.f;
	
	// // in case of other modulation a complex signal is filterd 
	// // in case of CW a real signal is filtered
	// float mult = SettingsFacade.GetCurrentModulation() == ModulationType::CW ? 2.f : 1.f; //1.f : 0.5f;
	// //------------------------------------------------
	// //  0    leftPos  rightPos       SPECTRUM_VIEW_WIDTH
	// //  |-------|        |--------|
	// //------------------------------------------------
	// leftPos = round(HALF_WIDTH + f0 * pixPerHz * mult);
	// rightPos = round(HALF_WIDTH + f1 * pixPerHz * mult);
}

/*--------------------------------------------------------------------------//
// 
//--------------------------------------------------------------------------*/
// template<typename TColor>
// inline void SpectrumView<TColor>::DrawWaterfallDot(float value, uint16_t index)
// {
// 	uint8_t * pixels = reinterpret_cast<uint8_t *>(const_cast<uint32_t *>(_waterfallPicObject.gdata));
// 	uint8_t alpha = static_cast<uint8_t>(value);
// 	pixels += index * _waterfallPicObject.height + _waterfallLine;
// 	*pixels = alpha;
// }

/*--------------------------------------------------------------------------//
// 
//--------------------------------------------------------------------------*/
template<typename TColor>
inline uint8_t SpectrumView<TColor>::ConvertFFTDataToAlpha(uint8_t inValue)
{
	float fftValue = static_cast<float>(inValue)/SVIEW_FLOAT_TO_BYTE_CONSTANT;
	float value = fftValue * SVIEW_WATERFALL_MAX_ALPHA;
	// prepare faterfall graphic data
	value = (value > _settings.WaterfallDepth) ?
		(value - (float)_settings.WaterfallDepth) : 0.0f;
	return static_cast<uint8_t>(value);
}

/*--------------------------------------------------------------------------//
// 
//--------------------------------------------------------------------------*/
template class SpectrumView<color_t>;

}