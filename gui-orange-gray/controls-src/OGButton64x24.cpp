#include "OGCommon.hpp"
#include "OGButton64x24.hpp"
#include "buttom64x24.h"

namespace gui
{
	constexpr uint16_t WIDTH = 64;
	constexpr uint16_t HEIGHT = 24;

	/*--------------------------------------------------------------------------//
	// Constructor
	//--------------------------------------------------------------------------*/
	OGButton64x24::OGButton64x24(uint16_t x, uint16_t y, const std::string_view & text,
		const IUIContext & context, const Action<void(IButton*)> & clickCmd)
		:IButton(x, y, WIDTH, HEIGHT, context, _disabledPic, _enabledPic, _focusedPic, _pressedPic, clickCmd),
		_text(GEText::Center_X(WIDTH, text, Font18), GEText::Center_Y(HEIGHT, Font18),
			Font::GetTextLineWidthInPixels(Font18, text), Font::GetCharacterHeightInPixels(Font18),
			text, TEXT_COLOR, BACKGROUND_GRAY, Font18, nullptr),
		_disabledPic(&button64x24disabled, &_text), _enabledPic(&button64x24enabled, &_text),
		_focusedPic(&button64x24focused, &_text), _pressedPic(&button64x24pressed, &_text)
	{
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	IGElement * OGButton64x24::GetGraphicElement()
	{
		switch(_state)
		{
			case ButtonState::Disabled:
				_text.BackgroundColor = BACKGROUND_DISABLED;
				_text.Foreground.Color = TEXT_COLOR_DISABLED;
				break;
			case ButtonState::Enabled:
			case ButtonState::Focused:
				_text.BackgroundColor = BACKGROUND_GRAY;
				_text.Foreground.Color = TEXT_COLOR;
				break;
			case ButtonState::Pressed:
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