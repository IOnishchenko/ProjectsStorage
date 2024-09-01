#include "DSPAlgorithmViewBase.hpp"
#include "OGCommon.hpp"
#include "IFocusManager.hpp"

namespace gui
{
/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
constexpr uint16_t SCREEN_Y = TABCONTROL_HEIGHT * 2;
constexpr uint16_t SCREEN_HEIGHT = FULL_SCREEN_HEIGHT-BOTTOM_MENU_HEIGHT-SCREEN_Y;

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
DSPAlgorithmViewBase::DSPAlgorithmViewBase(const IUIContext & context,
	const Action<void(ICheckBox *)> & checkedCmd, const Action<void(ICheckBox *)> & uncheckedCmd,
	const std::string_view & checkedText, const std::string_view & uncheckedText)
	:
	Group(0, SCREEN_Y, FULL_SCREEN_WIDTH, SCREEN_HEIGHT, context,
	{
		&_enaCheckbox
	}, &_background),
	_enaCheckbox(COLUMN0_X, SCREEN_Y+(ROW_HEIGHT - TEXT_HEIGHT)/2, context,
		checkedCmd, uncheckedCmd, checkedText, uncheckedText),
	_background(0, 0, FULL_SCREEN_WIDTH, ROW_HEIGHT, BACKGROUND_DARK, nullptr)
{
	context.FocusManager->RegisterHandler(100, &_enaCheckbox);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
DSPAlgorithmViewBase::~DSPAlgorithmViewBase()
{
	_context.FocusManager->UnregisterHandler(&_enaCheckbox);
}

}