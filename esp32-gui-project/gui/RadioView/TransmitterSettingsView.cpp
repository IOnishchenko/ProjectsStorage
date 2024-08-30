#include "TransmitterSettingsView.hpp"
#include "IFocusManager.hpp"
#include "OGCommon.hpp"

namespace gui
{

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
constexpr uint16_t SCREEN_Y = TABCONTROL_HEIGHT + ROW_HEIGHT;
constexpr uint16_t SCREEN_HEIGHT = FULL_SCREEN_HEIGHT-BOTTOM_MENU_HEIGHT-SCREEN_Y;

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
TransmitterSettingsView::TransmitterSettingsView(const IUIContext & context)
	:Group(0, SCREEN_Y, FULL_SCREEN_WIDTH, SCREEN_HEIGHT, context,
	{
		&_powerSlider.Text, &_powerSlider.Slider
	}, &_background),
	_onPowerChangedCmd(this, &TransmitterSettingsView::OnPowerChanged),
	_powerSlider(SCREEN_Y, SCREEN_Y, 50, 10, context, _onPowerChangedCmd,
		"Output Power", "Level (W):", nullptr),
	_background(0, 0, FULL_SCREEN_WIDTH, SCREEN_HEIGHT, BACKGROUND_DARK, _powerSlider.Header)
{
	context.FocusManager->RegisterHandler(100, &_powerSlider.Slider);
	_powerSlider.Text.SetIntValue(10);
	_powerSlider.Text.SetEnable(false);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
TransmitterSettingsView::~TransmitterSettingsView()
{
	_context.FocusManager->UnregisterHandler(&_powerSlider.Slider);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void TransmitterSettingsView::SetEnable(bool ena)
{
	_powerSlider.SetEnable(ena);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void TransmitterSettingsView::OnPowerChanged(int value)
{
	_powerSlider.Text.SetIntValue(value);
	_powerSlider.Text.Draw();
}

}