#include "OGCommon.hpp"
#include "OGRadioButton160x24.hpp"
#include "tab2.h"

namespace gui
{
	constexpr uint16_t WIDTH = 160;
	constexpr uint16_t HEIGHT = 24;

	/*--------------------------------------------------------------------------//
	// Constructor
	//--------------------------------------------------------------------------*/
	OGRadioButton160x24::OGRadioButton160x24(uint16_t x, uint16_t y, const std::string_view & text,
		const IUIContext & context, const Action<void(IRadioButton *)> & selCmd)
		:IRadioButton(x, y, WIDTH, HEIGHT, context, _disabledPic, _enabledPic, _focusedPic,
			_pressedPic, _selectedPic, _selectedFocusedPic, selCmd),
		_text(GEText::Center_X(WIDTH, text, Font18), GEText::Center_Y(HEIGHT, Font18) + 2,
			Font::GetTextLineWidthInPixels(Font18, text), Font::GetCharacterHeightInPixels(Font18),
			text, TEXT_COLOR, BACKGROUND_GRAY, Font18, nullptr),
		_disabledPic(&tab160x24disabled, &_text), _enabledPic(&tab160x24enabled, &_text),
		_focusedPic(&tab160x24focused, &_text), _pressedPic(&tab160x24pressed, &_text),
		_selectedPic(&tab160x24selected, &_text), _selectedFocusedPic(&tab160x24selected_focused, &_text)
	{
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	IGElement * OGRadioButton160x24::GetGraphicElement()
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
			case State::Selected:
			case State::SelectedFocused:
				_text.BackgroundColor = BACKGROUND_LIGHT;
				_text.Foreground.Color = TEXT_COLOR;
				break;
			default:
				_text.BackgroundColor = BACKGROUND_GRAY;
				_text.Foreground.Color = TEXT_COLOR;
				break;
		}

		return IRadioButton::GetGraphicElement();
	}
}