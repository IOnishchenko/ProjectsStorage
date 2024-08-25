#include "OGHorizontalSliderLabel.hpp"
#include "Font.hpp"
#include "OGCommon.hpp"

namespace gui
{

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
OGHorizontalSliderLabel::OGHorizontalSliderLabel(uint16_t x, uint16_t y,
	uint16_t width, int maxValue, int value, const IUIContext & context,
	const Action<void(int)> & valueChanged)
		:Text(x, y, 32, Font::GetCharacterHeightInPixels(Font18), context,
		TEXT_COLOR_DISABLED, BACKGROUND_DARK, TEXT_COLOR, BACKGROUND_DARK, Font18),
		Slider(x+40, y, 150, maxValue, value, context, valueChanged)
	{
	}
}