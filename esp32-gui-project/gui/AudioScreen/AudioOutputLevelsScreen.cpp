#include "AudioOutputLevelsScreen.hpp"
#include "IFocusManager.hpp"
#include "OGCommon.hpp"

namespace gui
{

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
constexpr uint16_t SCREEN_Y = 48;
constexpr uint16_t SCREEN_HEIGHT = FULL_SCREEN_HEIGHT-BOTTOM_MENU_HEIGHT-SCREEN_Y;

constexpr uint16_t COLUMN0_X = 3;
constexpr uint16_t COLUMN0_WIDT = 110;

constexpr uint16_t COLUMN1_X = COLUMN0_X + COLUMN0_WIDT + 3;
constexpr uint16_t COLUMN1_WIDT = 190;

constexpr uint16_t ROW_HEIGHT = 18;

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
AudioOutputLevelsScreen::AudioOutputLevelsScreen(const IUIContext & context)
	:Group(0, SCREEN_Y, FULL_SCREEN_WIDTH, SCREEN_HEIGHT, context,
	{
		&_analogGainSlider.Text, &_analogGainSlider.Slider,
		&_digitalGainSlider.Text, &_digitalGainSlider.Slider,
	}, &_background),
	_onAnalogGainCmd(this, &AudioOutputLevelsScreen::OnAgalogGainChanged),
	_onDigitalGainCmd(this, &AudioOutputLevelsScreen::OnDigitalGainChanged),
	_analogGainSlider(COLUMN1_X, SCREEN_Y+18, COLUMN1_WIDT, 100, 10, context, _onAnalogGainCmd),
	_digitalGainSlider(COLUMN1_X, SCREEN_Y+18*3, COLUMN1_WIDT, 30, 5, context, _onDigitalGainCmd),
	_headerTxt0(COLUMN0_X, 3, COLUMN0_WIDT, ROW_HEIGHT, "Analog Gain",
		TEXT_COLOR, BACKGROUND_DARK, Font18, nullptr),
	_headerTxt1(COLUMN0_X, 3+ROW_HEIGHT, COLUMN0_WIDT, ROW_HEIGHT, "Control:",
		TEXT_COLOR, BACKGROUND_DARK, Font18, &_headerTxt0),
	_headerTxt2(COLUMN0_X, 3+ROW_HEIGHT*2, COLUMN0_WIDT, ROW_HEIGHT, "Digital Gain",
		TEXT_COLOR, BACKGROUND_DARK, Font18, &_headerTxt1),
	_headerTxt3(COLUMN0_X, 3+ROW_HEIGHT*3, COLUMN0_WIDT, ROW_HEIGHT, "Control:",
		TEXT_COLOR, BACKGROUND_DARK, Font18, &_headerTxt2),
	_background(0, 0, FULL_SCREEN_WIDTH, SCREEN_HEIGHT, BACKGROUND_DARK, &_headerTxt3)
{
	context.FocusManager->RegisterHandler(100, &_analogGainSlider.Slider);
	context.FocusManager->RegisterHandler(100, &_digitalGainSlider.Slider);

	_analogGainSlider.Text.SetIntValue(10);
	_digitalGainSlider.Text.SetIntValue(10);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
AudioOutputLevelsScreen::~AudioOutputLevelsScreen()
{
	_context.FocusManager->UnregisterHandler(&_analogGainSlider.Slider);
	_context.FocusManager->UnregisterHandler(&_digitalGainSlider.Slider);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void AudioOutputLevelsScreen::OnAgalogGainChanged(int value)
{
	_analogGainSlider.Text.SetFloatValue(value, 1, true);
	_analogGainSlider.Text.Draw();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void AudioOutputLevelsScreen::OnDigitalGainChanged(int value)
{
	_digitalGainSlider.Text.SetIntValue(value);
	_digitalGainSlider.Text.Draw();
}

}