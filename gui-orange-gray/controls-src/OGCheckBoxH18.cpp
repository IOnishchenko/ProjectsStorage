#include "OGCheckBoxH18.hpp"
#include "checkbox36x18.h"
#include "OGCommon.hpp"
#include "Font.hpp"

namespace gui
{
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	constexpr uint16_t CHECKBOX_HEIGHT = 18;
	constexpr uint16_t CHECKBOX_ICON_WIDTH = 36;
	constexpr uint16_t MARGIN = 5;
	
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	OGCheckBoxH18::OGCheckBoxH18(uint16_t x, uint16_t y, const IUIContext & context,
		const Action<void(ICheckBox *)> & checkedCmd, const Action<void(ICheckBox *)> & uncheckedCmd,
		const std::string_view & checkedText, const std::string_view & uncheckedText)
		:
		ICheckBox(x, y, 0, CHECKBOX_HEIGHT, context, checkedCmd, uncheckedCmd,
			_checkedDisabledPic, _uncheckedDisabledPic,
			_checkedEnabledPic, _uncheckedEnabledPic,
			_checkedFocusedPic, _uncheckedFocusedPic,
			_checkedPressedPic, _uncheckedPressedPic),
		_checkedDisabledPic(&checkbox36x18checked_dis, &_checkedText),
		_uncheckedDisabledPic(&checkbox36x18unchecked_dis, &_uncheckedText),
		_checkedEnabledPic(&checkbox36x18checked_ena, &_checkedText),
		_uncheckedEnabledPic(&checkbox36x18unchecked_ena, &_uncheckedText),
		_checkedFocusedPic(&checkbox36x18checked_foc, &_checkedText),
		_uncheckedFocusedPic(&checkbox36x18unchecked_foc, &_uncheckedText),
		_checkedPressedPic(&checkbox36x18checked_press, &_checkedText),
		_uncheckedPressedPic(&checkbox36x18unchecked_press, &_uncheckedText),
		
		_backgroundChecked(0, 0, 0, CHECKBOX_HEIGHT, BACKGROUND_DARK, nullptr),
		_checkedText(0, 0, 0, Font::GetCharacterHeightInPixels(Font18), checkedText,
			TEXT_COLOR, BACKGROUND_DARK, Font18, &_backgroundChecked),
		
		_backgroundUncheked(0, 0, 0, CHECKBOX_HEIGHT, BACKGROUND_DARK, nullptr),
		_uncheckedText(0, 0, 0, Font::GetCharacterHeightInPixels(Font18), uncheckedText,
			TEXT_COLOR, BACKGROUND_DARK, Font18, &_backgroundUncheked)
	{
		uint16_t checkedWidth = Font::GetTextLineWidthInPixels(Font18, checkedText);
		_checkedText.Width = checkedWidth;
		uint16_t uncheckedWidth = Font::GetTextLineWidthInPixels(Font18, uncheckedText);
		_uncheckedText.Width = uncheckedWidth;

		uint16_t fullWidth = (checkedWidth > uncheckedWidth) ?
			checkedWidth + MARGIN : uncheckedWidth + MARGIN;

		_backgroundChecked.X = checkedWidth;
		_backgroundChecked.SetWidth(fullWidth - checkedWidth);

		_backgroundUncheked.X = uncheckedWidth;
		_backgroundUncheked.SetWidth(fullWidth - uncheckedWidth);

		_checkedDisabledPic.X = fullWidth;
		_uncheckedDisabledPic.X = fullWidth;
		_checkedEnabledPic.X = fullWidth;
		_uncheckedEnabledPic.X = fullWidth;
		_checkedFocusedPic.X = fullWidth;
		_uncheckedFocusedPic.X = fullWidth;
		_checkedPressedPic.X = fullWidth;
		_uncheckedPressedPic.X = fullWidth;

		Width = fullWidth + CHECKBOX_ICON_WIDTH;
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	IGElement * OGCheckBoxH18::GetGraphicElement()
	{
		switch(_visualState)
		{
			case State::CheckedDisabled:
				_checkedText.Foreground.Color = TEXT_COLOR_DISABLED;
				break;
			case State::UncheckedDisabled:
				_uncheckedText.Foreground.Color = TEXT_COLOR_DISABLED;
				break;
			case State::CheckedFocused:
			case State::CheckedEnabled:
				_checkedText.Foreground.Color = TEXT_COLOR;
				break;
			case State::UncheckedFocused:
			case State::UncheckedEnabled:
				_uncheckedText.Foreground.Color = TEXT_COLOR;
				break;
			case State::CheckedPressed:
				_checkedText.Foreground.Color = BACKGROUND_GRAY;
				break;
			case State::UncheckedPressed:
				_uncheckedText.Foreground.Color = BACKGROUND_GRAY;
				break;
			default:
				return nullptr;
		}
		return ICheckBox::GetGraphicElement();
	}
}