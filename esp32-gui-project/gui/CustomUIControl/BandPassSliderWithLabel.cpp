#include "BandPassSliderWithLabel.hpp"
#include "OGCommon.hpp"
#include "IFocusManager.hpp"
#include "IWindowManager.hpp"
#include "windows.h"
#include "Font.hpp"

namespace gui
{
namespace custom
{
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	constexpr uint16_t LABEL_WIDTH = 70;
	constexpr uint16_t SLIDER_Y_OFFSET = TEXT_HEIGHT;
	constexpr uint16_t SLIDER_HEIGHT = 18;
	constexpr uint16_t LINE_HEIGHT = 2;
	constexpr uint16_t LILE_PF_Y_OFFSET = SLIDER_Y_OFFSET + SLIDER_HEIGHT;
	constexpr uint16_t LABEL_PF_Y_OFFSET = LILE_PF_Y_OFFSET + LINE_HEIGHT + MARGIN;

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	BandPassSliderWithLabel::BandPassSliderWithLabel(Group & baseGroup, uint16_t x, uint16_t y,
		uint16_t width, uint16_t hpfMaxValue, uint16_t hpfValue, uint16_t lpfMaxValue,
		uint16_t lpfValue, const IUIContext & context, const Action<void(int)> & hpfFrequecyChanged,
		const Action<void(int)> & lpfFrequecyChanged)
		:
		BandPassWidthLabel(x+(width-LABEL_WIDTH)/2, y, LABEL_WIDTH, TEXT_HEIGHT,
			context, TEXT_COLOR_DISABLED, BACKGROUND_DARK, TEXT_COLOR, BACKGROUND_DARK, Font18),

		HPFFrequencyCutoffSlider(x, y+SLIDER_Y_OFFSET, (hpfMaxValue*width)/(hpfMaxValue+lpfMaxValue),
			hpfMaxValue, hpfValue, context, hpfFrequecyChanged),
		LPFFrequencyCutoffSlider(x+HPFFrequencyCutoffSlider.Width, y+SLIDER_Y_OFFSET,
			width-HPFFrequencyCutoffSlider.Width, lpfMaxValue, lpfValue, context, lpfFrequecyChanged),

		HPFFrequencyCutoffLabel(x, y+LABEL_PF_Y_OFFSET, LABEL_WIDTH, TEXT_HEIGHT,
			context, TEXT_COLOR_DISABLED, BACKGROUND_DARK, TEXT_COLOR, BACKGROUND_DARK, Font18),

		LPFFrequencyCutoffLabel(x+width-LABEL_WIDTH, y+LABEL_PF_Y_OFFSET, LABEL_WIDTH,
			TEXT_HEIGHT, context, TEXT_COLOR_DISABLED, BACKGROUND_DARK, TEXT_COLOR, BACKGROUND_DARK, Font18),

		BackgroundLine(x-baseGroup.X, y-baseGroup.Y+LILE_PF_Y_OFFSET, width,
			LINE_HEIGHT, BACKGROUND_LIGHT, nullptr)
	{
	}
}
}