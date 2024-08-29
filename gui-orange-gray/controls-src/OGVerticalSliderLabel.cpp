#include "OGVerticalSliderLabel.hpp"
#include "Font.hpp"
#include "OGCommon.hpp"

namespace gui
{

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
constexpr uint16_t TEXT_WIDTH = 40;
constexpr uint16_t TEXT_HEIHGT = 18;
constexpr uint16_t SLIDER_WIDTH = 12;

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
OGVerticalSliderLabel::OGVerticalSliderLabel(uint16_t x, uint16_t y,
	uint16_t height, int maxValue, int value, const IUIContext & context,
	const Action<void(int)> & valueChanged)
		:Text(x, y, TEXT_WIDTH, Font::GetCharacterHeightInPixels(Font18), context,
		TEXT_COLOR_DISABLED, BACKGROUND_DARK, TEXT_COLOR, BACKGROUND_DARK, Font18),
		Slider(x+(TEXT_WIDTH-SLIDER_WIDTH)/2, y+MARGIN+TEXT_HEIHGT, height-MARGIN-TEXT_HEIHGT,
		maxValue, value, context, valueChanged)
	{
	}
}