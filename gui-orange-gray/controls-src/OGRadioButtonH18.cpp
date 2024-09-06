#include "OGCommon.hpp"
#include "OGRadioButtonH18.hpp"
#include "checkbox18x18.h"

namespace gui
{
	constexpr uint16_t HEIGHT = 18;
	constexpr uint16_t CHECKBOX_PIC_WIDTH = 18;
	constexpr uint16_t CHECKBOX_MARGIN = 10;

	/*--------------------------------------------------------------------------//
	// Constructor
	//--------------------------------------------------------------------------*/
	OGRadioButtonH18::OGRadioButtonH18(uint16_t x, uint16_t y, const std::string_view & text,
		const IUIContext & context, const Action<void(IRadioButton *)> & selCmd)
		:IRadioButton(x, y,
			Font::GetTextLineWidthInPixels(Font18, text)+CHECKBOX_MARGIN+CHECKBOX_PIC_WIDTH,
			HEIGHT, context, _disabledPic, _enabledPic, _focusedPic,
			_pressedPic, _selectedPic, selCmd),

		_text(0, 0, Font::GetTextLineWidthInPixels(Font18, text), HEIGHT, text, TEXT_COLOR,
			BACKGROUND_DARK, Font18, &_background),
		_background(_text.Width, 0, CHECKBOX_MARGIN, HEIGHT, BACKGROUND_DARK, nullptr),

		_disabledPic(_text.Width+CHECKBOX_MARGIN, 0, CHECKBOX_PIC_WIDTH, HEIGHT, 0, 0,
			&checkbox18x18unchecked_dis, &_text),
		_enabledPic(_text.Width+CHECKBOX_MARGIN, 0, CHECKBOX_PIC_WIDTH, HEIGHT, 0, 0,
			&checkbox18x18unchecked_ena, &_text),
		_focusedPic(_text.Width+CHECKBOX_MARGIN, 0, CHECKBOX_PIC_WIDTH, HEIGHT, 0, 0,
			&checkbox18x18unchecked_foc, &_text),
		_pressedPic(_text.Width+CHECKBOX_MARGIN, 0, CHECKBOX_PIC_WIDTH, HEIGHT, 0, 0,
			&checkbox18x18unchecked_press, &_text),
		_selectedPic(_text.Width+CHECKBOX_MARGIN, 0, CHECKBOX_PIC_WIDTH, HEIGHT, 0, 0,
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
				_text.Foreground.Color = TEXT_COLOR_DISABLED;
				break;
			case State::Enabled:
			case State::Focused:
			case State::Pressed:
			case State::Selected:
			default:
				_text.Foreground.Color = TEXT_COLOR;
				break;
		}

		return IRadioButton::GetGraphicElement();
	}
}