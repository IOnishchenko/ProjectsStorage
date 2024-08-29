#include "TransmitterScreen.hpp"
#include "IFocusManager.hpp"
#include "OGCommon.hpp"

namespace gui
{

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
constexpr uint16_t SCREEN_Y = 24;
constexpr uint16_t SCREEN_HEIGHT = FULL_SCREEN_HEIGHT-BOTTOM_MENU_HEIGHT-SCREEN_Y;

constexpr uint16_t CHECKBOX_ROW_HEIGHT = 18 + MARGIN;
constexpr uint16_t ROW0_Y = SCREEN_Y + CHECKBOX_ROW_HEIGHT + MARGIN;

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
TransmitterScreen::TransmitterScreen(const IUIContext & context)
	:Group(0, SCREEN_Y, FULL_SCREEN_WIDTH, SCREEN_HEIGHT, context,
	{
		&_eneTXCheckbox, &_powerSlider.Text, &_powerSlider.Slider
	}, &_background),
	_onAGCEnabledCmd(this, &TransmitterScreen::OnTXEnabled),
	_onAGCDisabledCmd(this, &TransmitterScreen::OnTXDisabled),
	_onPowerChangedCmd(this, &TransmitterScreen::OnPowerChanged),

	_eneTXCheckbox(MARGIN, SCREEN_Y+MARGIN, context, _onAGCEnabledCmd, _onAGCDisabledCmd,
		"Disable Transmitter:", "Enable Transmitter:"),
	_powerSlider(COLUMN1_X, ROW0_Y+18, COLUMN1_WIDT, 50, 10, context, _onPowerChangedCmd),

	_headerTxt0(COLUMN0_X, ROW0_Y-SCREEN_Y, COLUMN0_WIDT, 18, "Output Power",
		TEXT_COLOR, BACKGROUND_DARK, Font18, nullptr),
	_headerTxt1(COLUMN0_X, ROW0_Y-SCREEN_Y+18, COLUMN0_WIDT, 18, "Level (W):",
		TEXT_COLOR, BACKGROUND_DARK, Font18, &_headerTxt0),
	_background(0, 0, FULL_SCREEN_WIDTH, SCREEN_HEIGHT, BACKGROUND_DARK, &_headerTxt1)
{
	context.FocusManager->RegisterHandler(100, &_eneTXCheckbox);
	_eneTXCheckbox.Uncheck();

	context.FocusManager->RegisterHandler(100, &_powerSlider.Slider);
	_powerSlider.Slider.SetEnable(false);
	_powerSlider.Text.SetIntValue(10);
	_powerSlider.Text.SetEnable(false);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
TransmitterScreen::~TransmitterScreen()
{
	_context.FocusManager->UnregisterHandler(&_eneTXCheckbox);
	_context.FocusManager->UnregisterHandler(&_powerSlider.Slider);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void TransmitterScreen::OnTXEnabled(ICheckBox *)
{
	_powerSlider.SetEnable(true);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void TransmitterScreen::OnTXDisabled(ICheckBox *)
{
	_powerSlider.SetEnable(false);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void TransmitterScreen::OnPowerChanged(int value)
{
	_powerSlider.Text.SetIntValue(value);
	_powerSlider.Text.Draw();
}

}