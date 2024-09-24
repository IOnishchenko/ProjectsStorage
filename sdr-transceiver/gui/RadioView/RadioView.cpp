#include "RadioView.hpp"
#include "OGCommon.hpp"
#include "ReceiverView.hpp"
#include "TransmitterView.hpp"

namespace gui
{

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
constexpr uint16_t SCREEN_HEIGHT = FULL_SCREEN_HEIGHT-BOTTOM_MENU_HEIGHT;

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
RadioView::RadioView(const IUIContext & context)
	:OGTabControl2T(0, SCREEN_HEIGHT, context, "RECEIVER", "TRANSMITTER",
	_onRxButtonClikedCmd, _onTxButtonClikedCmd),
	_onRxButtonClikedCmd(this, &RadioView::OnRxButtonClicked),
	_onTxButtonClikedCmd(this, &RadioView::OnTxButtonClicked),
	_subGroup{new ReceiverView(context)}
{
	AddChild(_subGroup.get());
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void RadioView::OnRxButtonClicked(IRadioButton *)
{
	RemoveChild(_subGroup.get());
	_subGroup.reset();
	_subGroup = std::make_unique<ReceiverView>(_context);
	AddChild(_subGroup.get());
	_subGroup->Draw();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void RadioView::OnTxButtonClicked(IRadioButton *)
{
	RemoveChild(_subGroup.get());
	_subGroup.reset();
	_subGroup = std::make_unique<TransmitterView>(_context);
	AddChild(_subGroup.get());
	_subGroup->Draw();
}

}