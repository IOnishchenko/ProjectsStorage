#ifndef GUI_MAINVIEW_SPECTRUM_VIEW_HPP
#define GUI_MAINVIEW_SPECTRUM_VIEW_HPP

#include "IUIControl.hpp"
#include "IAnimatedControl.hpp"
#include "OGCommon.hpp"
#include "GEPicture.hpp"
#include "gui_resource_types.h"

namespace gui
{
	/*-----------------------------------------------------------------//
	//
	//-----------------------------------------------------------------*/
	constexpr uint16_t SVIEW_FFT_RAW_DATA_SIZE = 128;
	constexpr uint16_t SVIEW_INTERPOLATED_DATA_SIZE = 160;

	constexpr uint16_t SVIEW_SPECTRUM_HEIGHT = 50;
	constexpr uint16_t SVIEW_WATERFALL_HEIGHT = 50;
	constexpr uint16_t SVIEW_HEIGHT = SVIEW_SPECTRUM_HEIGHT + SVIEW_WATERFALL_HEIGHT;
	constexpr uint16_t SVIEW_WIDTH = FULL_SCREEN_WIDTH;

	constexpr float SVIEW_AUTOSCALE_COEF = 0.5f;

	constexpr uint16_t SVIEW_SPECTRUM_LUT_SIZE = 3;
	constexpr uint8_t SVIEW_WATERFALL_TRANSPARENT_COLOR = 0x0u;

	constexpr uint8_t SVIEW_FLOAT_TO_BYTE_CONSTANT = 255.f;
	constexpr uint8_t SVIEW_WATERFALL_MAX_ALPHA = 255U;

	/*-----------------------------------------------------------------//
	//
	//-----------------------------------------------------------------*/
	class SpectrumView : public IUIControl,
		public IAnimatedControl
	{
		struct SpectrumDrawerColorSet
		{
			uint8_t TopBackgroundColor;	// AL44 color value
			uint8_t CurveColor;			// AL44 color value
			uint8_t BottomBackground;	// AL44 color value
		};
	public:
		// constructor
		SpectrumView(uint16_t y, const IUIContext & context,
			float (*fft)[SVIEW_FFT_RAW_DATA_SIZE]);

		// destructor
		~SpectrumView() override = default;

		// IAnimatedControl method
		void Animate() override;

	private:
		// fields
		float (*_rawFFTData)[SVIEW_FFT_RAW_DATA_SIZE];
		// bit map array
		uint8_t _gdata[(SVIEW_SPECTRUM_HEIGHT+SVIEW_WATERFALL_HEIGHT) *
			FULL_SCREEN_WIDTH];

		// Spectrum AL44 coding
		uint16_t _spectrumAlphaLUT[SVIEW_SPECTRUM_LUT_SIZE];
		uint16_t _spectrumColorsLUT[SVIEW_SPECTRUM_LUT_SIZE];
#ifdef GUI_USE_PICTUREGDATA
		AL44PictureGData _spectrunGData;
#else // GUI_USE_PICTUREGDATA
		AL44PictureGDataExt _spectrunGData;
#endif // GUI_USE_PICTUREGDATA
		PictureObject _spectrumPicObject;
		GEPicture _spectrumPic;

		// Waterfall A8 coding
#ifdef GUI_USE_PICTUREGDATA
		PictureGData _waterfallGData;
#else // GUI_USE_PICTUREGDATA
		PictureGDataExt _waterfallGData;
#endif // GUI_USE_PICTUREGDAT
		PictureObject _waterfallPicObject;
		GEPicture _waterfallTopPic;
		GEPicture _waterfallBottomPic;
		uint16_t _waterfallLine = 0;

		// history elements
		float _fractionalOffset;
		int _integerOffset;
		int _frequency;
		uint8_t _fftData[SVIEW_WIDTH];

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
		void CalculateSelectorPosition(uint32_t & leftPos, uint32_t & rightPos);
		void DrawLine(const SpectrumDrawerColorSet * colors, int line);
		void DrawWaterfallDot(float value, uint16_t index);
	};
}

#endif // GUI_MAINVIEW_SPECTRUM_VIEW_HPP