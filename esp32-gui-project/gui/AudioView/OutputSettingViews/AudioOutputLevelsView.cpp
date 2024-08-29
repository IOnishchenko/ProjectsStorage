#include "AudioOutputLevelsView.hpp"
#include "IFocusManager.hpp"
#include "OGCommon.hpp"

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
AudioOutputLevelsView::AudioOutputLevelsView(const IUIContext & context)
	:Group(0, SCREEN_Y, FULL_SCREEN_WIDTH, SCREEN_HEIGHT, context,
	{
		&_analogGainSlider.Text, &_analogGainSlider.Slider,
		&_digitalGainSlider.Text, &_digitalGainSlider.Slider,
	}, &_background),
	_onAnalogGainCmd(this, &AudioOutputLevelsView::OnAgalogGainChanged),
	_onDigitalGainCmd(this, &AudioOutputLevelsView::OnDigitalGainChanged),
	_analogGainSlider(SCREEN_Y, SCREEN_Y+MARGIN*2, 100, 10, context, _onAnalogGainCmd,
		"Analog Gain", "Control (dB):", nullptr),
	_digitalGainSlider(SCREEN_Y, SCREEN_Y+MARGIN*3+ROW_HEIGHT, 30, 5, context,
		_onDigitalGainCmd, "Digital Gain", "Control (dB):", _analogGainSlider.Header),

	_background(0, 0, FULL_SCREEN_WIDTH, SCREEN_HEIGHT, BACKGROUND_DARK, _digitalGainSlider.Header)
{
	context.FocusManager->RegisterHandler(100, &_analogGainSlider.Slider);
	context.FocusManager->RegisterHandler(100, &_digitalGainSlider.Slider);

	_analogGainSlider.Text.SetIntValue(10);
	_digitalGainSlider.Text.SetIntValue(10);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
AudioOutputLevelsView::~AudioOutputLevelsView()
{
	_context.FocusManager->UnregisterHandler(&_analogGainSlider.Slider);
	_context.FocusManager->UnregisterHandler(&_digitalGainSlider.Slider);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void AudioOutputLevelsView::OnAgalogGainChanged(int value)
{
	_analogGainSlider.Text.SetFloatValue(value, 1, true);
	_analogGainSlider.Text.Draw();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void AudioOutputLevelsView::OnDigitalGainChanged(int value)
{
	_digitalGainSlider.Text.SetIntValue(value);
	_digitalGainSlider.Text.Draw();
}

}