#include "OGCommon.hpp"
#include "OGRadioButtonH18.hpp"
#include "checkbox18x18.h"

namespace gui
{
	//constexpr uint16_t WIDTH = 64;
	constexpr uint16_t HEIGHT = 18;
	constexpr uint16_t CHECKBOX_PIC_WIDTH = 18;

	/*--------------------------------------------------------------------------//
	// Constructor
	//--------------------------------------------------------------------------*/
	OGRadioButtonH18::OGRadioButtonH18(uint16_t x, uint16_t y, const std::string_view & text,
		const IUIContext & context, const Action<void(IRadioButton *)> & selCmd)
		:IRadioButton(x, y,
			Font::GetTextLineWidthInPixels(Font18, text)+MARGIN+CHECKBOX_PIC_WIDTH,
			HEIGHT, context, _disabledPic, _enabledPic, _focusedPic,
			_pressedPic, _selectedPic, selCmd),
		_text(0, 0, Font::GetTextLineWidthInPixels(Font18, text),
			HEIGHT, text, TEXT_COLOR, BACKGROUND_GRAY, Font18, nullptr),
		_disabledPic(_text.Width+MARGIN, 0, CHECKBOX_PIC_WIDTH, HEIGHT, 0, 0,
			&checkbox18x18unchecked_dis, &_text),
		_enabledPic(_text.Width+MARGIN, 0, CHECKBOX_PIC_WIDTH, HEIGHT, 0, 0,
			&checkbox18x18unchecked_ena, &_text),
		_focusedPic(_text.Width+MARGIN, 0, CHECKBOX_PIC_WIDTH, HEIGHT, 0, 0,
			&checkbox18x18unchecked_foc, &_text),
		_pressedPic(_text.Width+MARGIN, 0, CHECKBOX_PIC_WIDTH, HEIGHT, 0, 0,
			&checkbox18x18unchecked_press, &_text),
		_selectedPic(_text.Width+MARGIN, 0, CHECKBOX_PIC_WIDTH, HEIGHT, 0, 0,
			&checkbox18x18checked_ena, &_text)
	{
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	IGElement * OGRadioButtonH18::GetGraphicElement()
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
				_text.BackgroundColor = BACKGROUND_LIGHT;
				_text.Foreground.Color = TEXT_COLOR;
				break;
			case State::Selected:
				_text.BackgroundColor = BACKGROUND_DARK;
				_text.Foreground.Color = TEXT_COLOR_LIGHT;
				break;
			default:
				_text.BackgroundColor = BACKGROUND_GRAY;
				_text.Foreground.Color = TEXT_COLOR;
				break;
		}

		return IRadioButton::GetGraphicElement();
	}
}