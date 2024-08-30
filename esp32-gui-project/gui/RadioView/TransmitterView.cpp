#include "TransmitterView.hpp"
#include "IFocusManager.hpp"
#include "OGCommon.hpp"

namespace gui
{

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
constexpr uint16_t SCREEN_Y = TABCONTROL_HEIGHT;
constexpr uint16_t SCREEN_HEIGHT = FULL_SCREEN_HEIGHT-BOTTOM_MENU_HEIGHT-SCREEN_Y;

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
TransmitterView::TransmitterView(const IUIContext & context)
	:Group(0, SCREEN_Y, FULL_SCREEN_WIDTH, SCREEN_HEIGHT, context,
	{
		&_eneTXCheckbox, &_settingsGroup
	}, &_background),
	_onAGCEnabledCmd(this, &TransmitterView::OnTXEnabled),
	_onAGCDisabledCmd(this, &TransmitterView::OnTXDisabled),

	_eneTXCheckbox(COLUMN0_X, SCREEN_Y+(ROW_HEIGHT-TEXT_HEIGHT)/2, context,
		_onAGCEnabledCmd, _onAGCDisabledCmd, "Disable Transmitter:", "Enable Transmitter:"),
	_background(0, 0, FULL_SCREEN_WIDTH, ROW_HEIGHT, BACKGROUND_DARK, nullptr),
	_settingsGroup(context)
{
	context.FocusManager->RegisterHandler(7, &_eneTXCheckbox);
	_eneTXCheckbox.Uncheck();
	_settingsGroup.SetEnable(false);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
TransmitterView::~TransmitterView()
{
	_context.FocusManager->UnregisterHandler(&_eneTXCheckbox);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void TransmitterView::OnTXEnabled(ICheckBox *)
{
	_settingsGroup.SetEnable(true);
	_settingsGroup.Draw();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void TransmitterView::OnTXDisabled(ICheckBox *)
{
	_settingsGroup.SetEnable(false);
	_settingsGroup.Draw();
}

}