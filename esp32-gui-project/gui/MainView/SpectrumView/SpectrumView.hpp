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

	/*-----------------------------------------------------------------//
	//
	//-----------------------------------------------------------------*/
	class SpectrumView : public IUIControl,
		public IAnimatedControl
	{
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
		// Spectrum GData has L4 coding
		uint8_t _spectrumGData[SVIEW_SPECTRUM_HEIGHT*FULL_SCREEN_WIDTH];
		PictureObject _spectrumPicObject;
		GEPicture _spectrumPic;

		// Waterfall GData has A4 coding
		uint8_t _waterfallGData[SVIEW_WATERFALL_HEIGHT*FULL_SCREEN_WIDTH];
		PictureObject _waterfallPicObject;
		GEPicture _waterfallTopPic;
		GEPicture _waterfallBottomPic;

		// fft values normalizer to height
		float _normK;
		float _normB;

		// auto scaling algorith
		float _scaleCurrentAverage = 0.f;
		float _minDisplayedValue = 0.f;
		float _maxDisplayedValue = 0.f;
		float _scaleAverage = 0.f;

		// methods
		void ScaleFFTData();
		float InterpolateRawValue(uint16_t index);
		float ScaleFFTData(float value);
	};
}

#endif // GUI_MAINVIEW_SPECTRUM_VIEW_HPP