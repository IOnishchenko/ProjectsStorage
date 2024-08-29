#include "ReceiverScreen.hpp"
#include "OGCommon.hpp"
#include "IFocusManager.hpp"

namespace gui
{

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
constexpr uint16_t SCREEN_Y = 24;
constexpr uint16_t SCREEN_HEIGHT = FULL_SCREEN_HEIGHT-BOTTOM_MENU_HEIGHT-SCREEN_Y;

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
ReceiverScreen::ReceiverScreen(const IUIContext & context)
	:Group(0, SCREEN_Y, FULL_SCREEN_WIDTH, SCREEN_HEIGHT, context,
	{
		&_attGainSlider.Text, &_attGainSlider.Slider,
		&_analogGainSlider.Text, &_analogGainSlider.Slider,
		&_digitalGainSlider.Text, &_digitalGainSlider.Slider,
	}, &_background),

	_onAttGainCmd(this, &ReceiverScreen::OnAttGainChanged),
	_onAnalogGainCmd(this, &ReceiverScreen::OnAgalogGainChanged),
	_onDigitalGainCmd(this, &ReceiverScreen::OnDigitalGainChanged),

	_attGainSlider(SCREEN_Y, SCREEN_Y+MARGIN*2, 33, 10, context, _onAttGainCmd,
		"Attenuator", "Level (dB):", nullptr),
	_analogGainSlider(SCREEN_Y, SCREEN_Y+ROW_HEIGHT+MARGIN*3, 100, 10, context, _onAnalogGainCmd,
		"Analog Gain", "Control (dB):", _attGainSlider.Header),
	_digitalGainSlider(SCREEN_Y, SCREEN_Y+ROW_HEIGHT*2+MARGIN*4, 30, 5, context, _onDigitalGainCmd,
		"Digital Gain", "Control (dB):", _analogGainSlider.Header),

	_background(0, 0, FULL_SCREEN_WIDTH, SCREEN_HEIGHT, BACKGROUND_DARK, _digitalGainSlider.Header)
{
	context.FocusManager->RegisterHandler(100, &_attGainSlider.Slider);
	context.FocusManager->RegisterHandler(100, &_analogGainSlider.Slider);
	context.FocusManager->RegisterHandler(100, &_digitalGainSlider.Slider);

	_attGainSlider.Text.SetIntValue(8);
	_analogGainSlider.Text.SetIntValue(10);
	_digitalGainSlider.Text.SetIntValue(22);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
ReceiverScreen::~ReceiverScreen()
{
	_context.FocusManager->UnregisterHandler(&_attGainSlider.Slider);
	_context.FocusManager->UnregisterHandler(&_analogGainSlider.Slider);
	_context.FocusManager->UnregisterHandler(&_digitalGainSlider.Slider);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void ReceiverScreen::OnAttGainChanged(int value)
{
	_attGainSlider.Text.SetFloatValue(-value, 1, true);
	_attGainSlider.Text.Draw();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void ReceiverScreen::OnAgalogGainChanged(int value)
{
	_analogGainSlider.Text.SetFloatValue(value, 1, true);
	_analogGainSlider.Text.Draw();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void ReceiverScreen::OnDigitalGainChanged(int value)
{
	_digitalGainSlider.Text.SetFloatValue(value, 1, true);
	_digitalGainSlider.Text.Draw();
}

}