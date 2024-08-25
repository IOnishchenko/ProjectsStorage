#include "AudioOutputEqualizerScreen.hpp"
#include "OGCommon.hpp"
#include "IFocusManager.hpp"

namespace gui
{

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
constexpr uint16_t SCREEN_Y = 48;
constexpr uint16_t SCREEN_HEIGHT = FULL_SCREEN_HEIGHT-BOTTOM_MENU_HEIGHT-SCREEN_Y;

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
AudioOutputEqualizerScreen::AudioOutputEqualizerScreen(const IUIContext & context)
	:Group(0, SCREEN_Y, FULL_SCREEN_WIDTH, SCREEN_HEIGHT, context,
	{
		&_slider0, &_slider1, &_slider2, &_slider3, &_slider4, &_slider5
	},&_background),
	_onSlider0ValueChangedCmd(this, &AudioOutputEqualizerScreen::OnSlider0ValueChanged),
	_slider0(32, SCREEN_Y+25, SCREEN_HEIGHT-50, 50, 25, context, _onSlider0ValueChangedCmd),
	_slider1(32+50, SCREEN_Y+25, SCREEN_HEIGHT-50, 50, 25, context, _onSlider0ValueChangedCmd),
	_slider2(32+100, SCREEN_Y+25, SCREEN_HEIGHT-50, 50, 25, context, _onSlider0ValueChangedCmd),
	_slider3(32+150, SCREEN_Y+25, SCREEN_HEIGHT-50, 50, 25, context, _onSlider0ValueChangedCmd),
	_slider4(32+200, SCREEN_Y+25, SCREEN_HEIGHT-50, 50, 25, context, _onSlider0ValueChangedCmd),
	_slider5(32+250, SCREEN_Y+25, SCREEN_HEIGHT-50, 50, 25, context, _onSlider0ValueChangedCmd),
	_background(0, 0, FULL_SCREEN_WIDTH, SCREEN_HEIGHT, BACKGROUND_DARK, nullptr)
{
	context.FocusManager->RegisterHandler(100, &_slider0);
	context.FocusManager->RegisterHandler(100, &_slider1);
	context.FocusManager->RegisterHandler(100, &_slider2);
	context.FocusManager->RegisterHandler(100, &_slider3);
	context.FocusManager->RegisterHandler(100, &_slider4);
	context.FocusManager->RegisterHandler(100, &_slider5);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
AudioOutputEqualizerScreen::~AudioOutputEqualizerScreen()
{
	_context.FocusManager->UnregisterHandler(&_slider0);
	_context.FocusManager->UnregisterHandler(&_slider1);
	_context.FocusManager->UnregisterHandler(&_slider2);
	_context.FocusManager->UnregisterHandler(&_slider3);
	_context.FocusManager->UnregisterHandler(&_slider4);
	_context.FocusManager->UnregisterHandler(&_slider5);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void AudioOutputEqualizerScreen::OnSlider0ValueChanged(int value)
{

}

}