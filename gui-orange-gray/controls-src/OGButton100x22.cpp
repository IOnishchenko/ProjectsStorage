#include "OGCommon.hpp"
#include "OGButton100x22.hpp"
#include "button100x22.h"

namespace gui
{
	constexpr uint16_t WIDTH = 100;
	constexpr uint16_t HEIGHT = 22;

	/*--------------------------------------------------------------------------//
	// Constructor
	//--------------------------------------------------------------------------*/
	OGButton100x22::OGButton100x22(uint16_t x, uint16_t y, const std::string_view & text,
		const IUIContext & context, const Action<void(IButton*)> & clickCmd)
		:IButton(x, y, WIDTH, HEIGHT, context, _disabledPic, _enabledPic, _focusedPic, _pressedPic, clickCmd),
		_text(GEText::Center_X(WIDTH, text, Font18), GEText::Center_Y(HEIGHT, Font18) + 1,
			Font::GetTextLineWidthInPixels(Font18, text), Font::GetCharacterHeightInPixels(Font18),
			text, TEXT_COLOR, BACKGROUND_GRAY, Font18, nullptr),
		_disabledPic(&button100x22disabled, &_text), _enabledPic(&button100x22enabled, &_text),
		_focusedPic(&button100x22focused, &_text), _pressedPic(&button100x22pressed, &_text)
	{
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	IGElement * OGButton100x22::GetGraphicElement()
	{
		switch(_state)
		{
			case State::Disabled:
				_text.BackgroundColor = BACKGROUND_DISABLED;
				_text.Foreground.Color = TEXT_COLOR_DISABLED;
				break;
			case State::Enabled:
			case State::Focused:
				_text.BackgroundColor = BACKGROUND_GRAY;
				_text.Foreground.Color = TEXT_COLOR;
				break;
			case State::Pressed:
				_text.BackgroundColor = BACKGROUND_DARK;
				_text.Foreground.Color = TEXT_COLOR_LIGHT;
				break;
			default:
				_text.BackgroundColor = BACKGROUND_GRAY;
				_text.Foreground.Color = TEXT_COLOR;
				break;
		}

		return IButton::GetGraphicElement();
	}
}