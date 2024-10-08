#include "ReceiverView.hpp"
#include "OGCommon.hpp"
#include "IFocusManager.hpp"

namespace gui
{

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
constexpr uint16_t SCREEN_Y = 24;
constexpr uint16_t SCREEN_HEIGHT = FULL_SCREEN_HEIGHT-BOTTOM_MENU_HEIGHT-SCREEN_Y;
constexpr uint16_t CHECKBOX_HEIGHT = 18;

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
ReceiverView::ReceiverView(const IUIContext & context)
	:Group(0, SCREEN_Y, FULL_SCREEN_WIDTH, SCREEN_HEIGHT, context,
	{
		&_attGainSlider.Text, &_attGainSlider,
		&_analogGainSlider.Text, &_analogGainSlider,
		&_digitalGainSlider.Text, &_digitalGainSlider,
		&_ampEnableCheckBox
	}, &_background),

	_onAttGainCmd(this, &ReceiverView::OnAttGainChanged),
	_onAnalogGainCmd(this, &ReceiverView::OnAgalogGainChanged),
	_onDigitalGainCmd(this, &ReceiverView::OnDigitalGainChanged),
	_onAmpEnabledCmd(this, &ReceiverView::OnAmpEnabled),
	_onAmpDisabledCmd(this, &ReceiverView::OnAmpDisabled),

	_attGainSlider(SCREEN_Y, SCREEN_Y+MARGIN*2, 33, 10, context, _onAttGainCmd,
		"Attenuator", "Level (dB):", nullptr),
	_analogGainSlider(SCREEN_Y, SCREEN_Y+ROW_HEIGHT+MARGIN*3, 100, 10, context, _onAnalogGainCmd,
		"Analog Gain", "Control (dB):", _attGainSlider.Header),
	_digitalGainSlider(SCREEN_Y, SCREEN_Y+ROW_HEIGHT*2+MARGIN*4, 30, 5, context, _onDigitalGainCmd,
		"Digital Gain", "Control (dB):", _analogGainSlider.Header),
	_ampEnableCheckBox(COLUMN0_X, SCREEN_Y+ROW_HEIGHT*3+MARGIN*5+(ROW_HEIGHT-CHECKBOX_HEIGHT)/2,
		context, _onAmpEnabledCmd, _onAmpDisabledCmd, "Disable LNA:", "Enable LNA:"),

	_background(0, 0, FULL_SCREEN_WIDTH, SCREEN_HEIGHT, BACKGROUND_DARK, _digitalGainSlider.Header)
{
	context.FocusManager->RegisterHandler(100, &_attGainSlider);
	context.FocusManager->RegisterHandler(100, &_analogGainSlider);
	context.FocusManager->RegisterHandler(100, &_digitalGainSlider);
	context.FocusManager->RegisterHandler(100, &_ampEnableCheckBox);

	_attGainSlider.Text.SetIntValue(8);
	_analogGainSlider.Text.SetIntValue(10);
	_digitalGainSlider.Text.SetIntValue(22);

	_ampEnableCheckBox.Check();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
ReceiverView::~ReceiverView()
{
	_context.FocusManager->UnregisterHandler(&_attGainSlider);
	_context.FocusManager->UnregisterHandler(&_analogGainSlider);
	_context.FocusManager->UnregisterHandler(&_digitalGainSlider);
	_context.FocusManager->UnregisterHandler(&_ampEnableCheckBox);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void ReceiverView::OnAttGainChanged(int value)
{
	_attGainSlider.Text.SetFloatValue(-value, 1, true);
	_attGainSlider.Text.Draw();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void ReceiverView::OnAgalogGainChanged(int value)
{
	_analogGainSlider.Text.SetFloatValue(value, 1, true);
	_analogGainSlider.Text.Draw();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void ReceiverView::OnDigitalGainChanged(int value)
{
	_digitalGainSlider.Text.SetFloatValue(value, 1, true);
	_digitalGainSlider.Text.Draw();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void ReceiverView::OnAmpEnabled(ICheckBox *)
{

}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void ReceiverView::OnAmpDisabled(ICheckBox *)
{

}


}