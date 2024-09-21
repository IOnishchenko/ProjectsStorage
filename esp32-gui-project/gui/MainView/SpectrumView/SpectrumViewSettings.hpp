#ifndef GUI_SPECTRUM_VIEW_SETTINGS_HPP
#define GUI_SPECTRUM_VIEW_SETTINGS_HPP

#include "Value.h"
#include "stdint.h"

namespace gui
{
	/*-----------------------------------------------------------------//
	//
	//-----------------------------------------------------------------*/
	template<typename TColor>
	struct SpectrumColorSet
	{
		// top spectrum part color
		TColor SpectrumTopColor;
		// A4 value for alpha chanel
		uint8_t SpectrumTopAlpha;
		// curve spectrum color
		TColor SpectrumCurveColor;
		// A4 value for alpha chanel
		uint8_t SpectrumCurveAlpha;
		// bottom spectrum part color
		TColor SpectrumBottomColor;
		// A4 value for alpha chanel
		uint8_t SpectrumBottomAlpha;
	};

	/*-----------------------------------------------------------------//
	//
	//-----------------------------------------------------------------*/
	template<typename TColor>
	struct SpectrumViewSettings
	{
		// constructor
		SpectrumViewSettings();

		// destructor
		~SpectrumViewSettings() = default;

		// percent value to calculate Spectrum Object Height
		Value<uint16_t> SpectrumHeight;
		float SpectrumRangeToShow = 2.0f;
		float SmoothingCoeff = 0.3;
		int WaterfallDepth = 0;
		// spectrum colors collection
		SpectrumColorSet<TColor> Colors;
		SpectrumColorSet<TColor> SelectorColors;
		// waterfall collor
		TColor WaterfallColor;
	};
}

#endif // GUI_SPECTRUM_VIEW_SETTINGS_HPP