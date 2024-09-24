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
		// type to save this settings to non-volatile memory
		struct Storage
		{
			uint32_t SpectrumHeightIndex = 30u;
			float SpectrumRangeToShow = 2.0f;
			float SmoothingCoeff = 0.2;
			int WaterfallDepth = 0;
			gui::SpectrumColorSet<TColor> SpectrumColor;
			gui::SpectrumColorSet<TColor> SpectrumSelectorColor;
			TColor WaterfallColor;
		};

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

		// methods
		void Save(Storage & storage)
		{
			storage.SpectrumHeightIndex = SpectrumHeight.GetIndex();
			storage.SpectrumRangeToShow = SpectrumRangeToShow;
			storage.SmoothingCoeff = SmoothingCoeff;
			storage.WaterfallDepth = WaterfallDepth;
			storage.SpectrumColor = Colors;
			storage.SpectrumSelectorColor = SelectorColors;
			storage.WaterfallColor = WaterfallColor;
		}

		void Restore(const Storage & storage)
		{
			SpectrumHeight.SetValueByIndex(storage.SpectrumHeightIndex);
			SpectrumRangeToShow = storage.SpectrumRangeToShow;
			SmoothingCoeff = storage.SmoothingCoeff;
			WaterfallDepth = storage.WaterfallDepth;
			Colors = storage.SpectrumColor;
			SelectorColors = storage.SpectrumSelectorColor;
			WaterfallColor = storage.WaterfallColor;
		}

		
	};
}

#endif // GUI_SPECTRUM_VIEW_SETTINGS_HPP