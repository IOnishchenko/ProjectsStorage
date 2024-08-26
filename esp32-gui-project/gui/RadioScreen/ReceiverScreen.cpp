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
constexpr uint16_t COLUMN0_X = 3;
constexpr uint16_t COLUMN0_WIDT = 110;
constexpr uint16_t COLUMN1_X = COLUMN0_X + COLUMN0_WIDT + 3;
constexpr uint16_t COLUMN1_WIDT = 190;
constexpr uint16_t ROW_HEIGHT = 18;

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

	_attGainSlider(COLUMN1_X, SCREEN_Y+18, COLUMN1_WIDT, 33, 10, context, _onAttGainCmd),
	_analogGainSlider(COLUMN1_X, SCREEN_Y+18*3, COLUMN1_WIDT, 100, 10, context, _onAnalogGainCmd),
	_digitalGainSlider(COLUMN1_X, SCREEN_Y+18*5, COLUMN1_WIDT, 30, 5, context, _onDigitalGainCmd),

	_headerTxt0(COLUMN0_X, 3, COLUMN0_WIDT, ROW_HEIGHT, "Attenuator",
		TEXT_COLOR, BACKGROUND_DARK, Font18, nullptr),
	_headerTxt1(COLUMN0_X, 3+ROW_HEIGHT, COLUMN0_WIDT, ROW_HEIGHT, "Level (dB):",
		TEXT_COLOR, BACKGROUND_DARK, Font18, &_headerTxt0),
	_headerTxt2(COLUMN0_X, 3+ROW_HEIGHT*2, COLUMN0_WIDT, ROW_HEIGHT, "Analog Gain",
		TEXT_COLOR, BACKGROUND_DARK, Font18, &_headerTxt1),
	_headerTxt3(COLUMN0_X, 3+ROW_HEIGHT*3, COLUMN0_WIDT, ROW_HEIGHT, "Control (dB):",
		TEXT_COLOR, BACKGROUND_DARK, Font18, &_headerTxt2),
	_headerTxt4(COLUMN0_X, 3+ROW_HEIGHT*4, COLUMN0_WIDT, ROW_HEIGHT, "Digital Gain",
		TEXT_COLOR, BACKGROUND_DARK, Font18, &_headerTxt3),
	_headerTxt5(COLUMN0_X, 3+ROW_HEIGHT*5, COLUMN0_WIDT, ROW_HEIGHT, "Control (dB):",
		TEXT_COLOR, BACKGROUND_DARK, Font18, &_headerTxt4),

	_background(0, 0, FULL_SCREEN_WIDTH, SCREEN_HEIGHT, BACKGROUND_DARK, &_headerTxt5)
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