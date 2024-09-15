#ifndef GUI_SPECTRUM_VIEW_SETTINGS_HPP
#define GUI_SPECTRUM_VIEW_SETTINGS_HPP

#include "stdint.h"

namespace gui
{
	struct SpectrumViewSettings
	{
		// percent value to calculate Spectrum Object Height
		uint8_t SpectrumRelativeHeight = 50;
		float SpectrumViewRangeToShow = 2.0f;
		float Smoothing = 0.3; 
	};
}

#endif // GUI_SPECTRUM_VIEW_SETTINGS_HPP