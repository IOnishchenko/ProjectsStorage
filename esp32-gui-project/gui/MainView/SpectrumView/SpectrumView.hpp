#ifndef GUI_MAINVIEW_SPECTRUM_VIEW_HPP
#define GUI_MAINVIEW_SPECTRUM_VIEW_HPP

#include "IUIControl.hpp"
#include "IAnimatedControl.hpp"
#include "OGCommon.hpp"
#include "GEPictureMixedWithPicture.hpp"
#include "GEPictureMixedWithColor.hpp"
#include "gui_resource_types.h"
#include "configuration.h"

#include "SpectrumViewSettings.hpp"

namespace gui
{
	/*-----------------------------------------------------------------//
	//
	//-----------------------------------------------------------------*/
	constexpr uint16_t SVIEW_FFT_RAW_DATA_SIZE = 128;
	constexpr uint16_t SVIEW_HEIGHT = 100;
	constexpr uint16_t SVIEW_WIDTH = FULL_SCREEN_WIDTH;
	constexpr uint16_t SVIEW_INTERPOLATED_DATA_SIZE = FULL_SCREEN_WIDTH/2 + 1;

	constexpr float SVIEW_AUTOSCALE_COEF = 0.5f;
	constexpr uint8_t SVIEW_FLOAT_TO_BYTE_CONSTANT = 255.f;

	constexpr uint16_t SVIEW_SPECTRUM_LUT_SIZE = 6;
	constexpr uint8_t SVIEW_WATERFALL_TRANSPARENT_COLOR = 0x0u;
	constexpr uint8_t SVIEW_WATERFALL_MAX_ALPHA = 255U;

	/*-----------------------------------------------------------------//
	//
	//-----------------------------------------------------------------*/
	template<typename TColor>
	class SpectrumView : public IUIControl,
		public IAnimatedControl
	{
	public:
		// constructor
		SpectrumView(uint16_t y, const IUIContext & context,
			SpectrumViewSettings<TColor> & settings, float (*fft)[SVIEW_FFT_RAW_DATA_SIZE]);

		// destructor
		~SpectrumView() override;

		// IUIControl methods
		IGElement * GetGraphicElement() override;

		// IAnimatedControl method
		void Animate() override;

	private:
		// fields
		SpectrumViewSettings<color_t> & _settings;
		float (*_rawFFTData)[SVIEW_FFT_RAW_DATA_SIZE];
		// bit map array
		uint8_t _gdata[SVIEW_HEIGHT * FULL_SCREEN_WIDTH];

		// Spectrum AL44 coding
		TColor _spectrumGDataLUT[SVIEW_SPECTRUM_LUT_SIZE];
#ifdef GUI_USE_PICTUREGDATA
		PictureGData _spectrunGData;
#else // GUI_USE_PICTUREGDATA
		PictureGDataExt _spectrunGData;
#endif // GUI_USE_PICTUREGDATA
		PictureObject _spectrumPicObject;
		GEPictureMixedWithPicture _spectrumPic;

		// Waterfall A8 coding
#ifdef GUI_USE_PICTUREGDATA
		PictureGData _waterfallGData;
#else // GUI_USE_PICTUREGDATA
		PictureGDataExt _waterfallGData;
#endif // GUI_USE_PICTUREGDAT
		PictureObject _waterfallPicObject;
		GEPictureMixedWithColor _waterfallTopPic;
		GEPictureMixedWithColor _waterfallBottomPic;
		uint16_t _waterfallLine = 0;

		// Graphic element to draw
		IGElement * _gelement;

		// history elements
		float _fractionalOffset = 0.f;
		int _integerOffset = 0;
		int _frequency;
		uint8_t _fftData[SVIEW_INTERPOLATED_DATA_SIZE];

		// fft values normalizer to height
		float _normK = 0;
		float _normB = 0;

		// auto scaling algorith
		float _scaleCurrentAverage = 0.f;
		float _minDisplayedValue = 0.f;
		float _maxDisplayedValue = 0.f;
		float _scaleAverage = 0.f;

		// methods
		void UpdateGraphicData();
		void ScaleFFTData();
		float InterpolateRawValue(uint16_t index);
		float ScaleFFTDataToHeight(float value);
		void UpdateIfFrequencyChanges();
		void DrawIntoInternalGBuffer();
		void FillSpectrumLines(float & dot0, float & dot1, uint8_t *& fftData, uint16_t width,
			uint8_t *& gbuffer, uint8_t topColor, uint8_t curveColor, uint8_t bottomColor);
		void CalculateSelectorPosition(uint32_t & leftPos, uint32_t & rightPos);
		uint8_t ConvertFFTDataToAlpha(uint8_t fftValue);
	};
}

#endif // GUI_MAINVIEW_SPECTRUM_VIEW_HPP