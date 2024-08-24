#include "RadioScreen.hpp"
#include "OGCommon.hpp"
#include "ReceiverScreen.hpp"
#include "TransmitterScreen.hpp"

namespace gui
{

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
constexpr uint16_t SCREEN_HEIGHT = FULL_SCREEN_HEIGHT-BOTTOM_MENU_HEIGHT;

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
RadioScreen::RadioScreen(const IUIContext & context)
	:OGTabControl2T(0, SCREEN_HEIGHT, context, "RECEIVER", "TRANSMITTER",
	_onRxButtonClikedCmd, _onTxButtonClikedCmd),
	_onRxButtonClikedCmd(this, &RadioScreen::OnRxButtonClicked),
	_onTxButtonClikedCmd(this, &RadioScreen::OnTxButtonClicked),
	_subGroup{new ReceiverScreen(context)}
{
	AddChild(_subGroup.get());
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void RadioScreen::OnRxButtonClicked(IRadioButton *)
{
	RemoveChild(_subGroup.get());
	_subGroup.reset(new ReceiverScreen(_context));
	AddChild(_subGroup.get());
	_subGroup->Draw();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void RadioScreen::OnTxButtonClicked(IRadioButton *)
{
	RemoveChild(_subGroup.get());
	_subGroup.reset(new TransmitterScreen(_context));
	AddChild(_subGroup.get());
	_subGroup->Draw();
}

}