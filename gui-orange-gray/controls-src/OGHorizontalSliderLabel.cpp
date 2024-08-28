#include "OGHorizontalSliderLabel.hpp"
#include "Font.hpp"
#include "OGCommon.hpp"

namespace gui
{

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
constexpr uint16_t MARGIN = 3;
constexpr uint16_t TEXT_WIDTH = 40;
constexpr uint16_t TEXT_HEIHGT = 18;
constexpr uint16_t SLIDER_HEIGHT = 12;

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
OGHorizontalSliderLabel::OGHorizontalSliderLabel(uint16_t x, uint16_t y,
	uint16_t width, int maxValue, int value, const IUIContext & context,
	const Action<void(int)> & valueChanged)
		:Text(x, y, TEXT_WIDTH, Font::GetCharacterHeightInPixels(Font18), context,
		TEXT_COLOR_DISABLED, BACKGROUND_DARK, TEXT_COLOR, BACKGROUND_DARK, Font18),
		Slider(x+MARGIN+TEXT_WIDTH, y+(TEXT_HEIHGT-SLIDER_HEIGHT)/2,
		width-MARGIN-TEXT_WIDTH, maxValue, value, context, valueChanged)
	{
	}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void OGHorizontalSliderLabel::SetEnable(bool ena)
{
	Text.SetEnable(ena);
	Text.Draw();

	Slider.SetEnable(ena);
	Slider.Draw();
}

}