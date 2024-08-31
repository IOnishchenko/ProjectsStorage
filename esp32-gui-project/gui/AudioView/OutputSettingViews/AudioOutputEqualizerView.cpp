#include "AudioOutputEqualizerView.hpp"
#include "OGCommon.hpp"
#include "IFocusManager.hpp"
#include "font18.h"

namespace gui
{

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
constexpr uint16_t SCREEN_Y = 48;
constexpr uint16_t SCREEN_HEIGHT = FULL_SCREEN_HEIGHT-BOTTOM_MENU_HEIGHT-SCREEN_Y;
constexpr uint16_t TEXT_WIDTH = 40;
constexpr uint16_t SLIDER_HEIGHT = SCREEN_HEIGHT-MARGIN*3-TEXT_HEIGHT;

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
AudioOutputEqualizerView::AudioOutputEqualizerView(const IUIContext & context)
	:Group(0, SCREEN_Y, FULL_SCREEN_WIDTH, SCREEN_HEIGHT, context,
	{
		&_slider0.Text, &_slider0.Slider, &_slider1.Text, &_slider1.Slider,
		&_slider2.Text, &_slider2.Slider, &_slider3.Text, &_slider3.Slider,
		&_slider4.Text, &_slider4.Slider, &_slider5.Text, &_slider5.Slider,
	}, &_background),

	_onSlider0ValueChangedCmd(this, &AudioOutputEqualizerView::OnSlider0ValueChanged),
	_onSlider1ValueChangedCmd(this, &AudioOutputEqualizerView::OnSlider1ValueChanged),
	_onSlider2ValueChangedCmd(this, &AudioOutputEqualizerView::OnSlider2ValueChanged),
	_onSlider3ValueChangedCmd(this, &AudioOutputEqualizerView::OnSlider3ValueChanged),
	_onSlider4ValueChangedCmd(this, &AudioOutputEqualizerView::OnSlider4ValueChanged),
	_onSlider5ValueChangedCmd(this, &AudioOutputEqualizerView::OnSlider5ValueChanged),

	_slider0(16, SCREEN_Y+MARGIN, SLIDER_HEIGHT, 50, 25, context, _onSlider0ValueChangedCmd),
	_slider1(16+50, SCREEN_Y+MARGIN, SLIDER_HEIGHT, 50, 25, context, _onSlider1ValueChangedCmd),
	_slider2(16+100, SCREEN_Y+MARGIN, SLIDER_HEIGHT, 50, 25, context, _onSlider2ValueChangedCmd),
	_slider3(16+150, SCREEN_Y+MARGIN, SLIDER_HEIGHT, 50, 25, context, _onSlider3ValueChangedCmd),
	_slider4(16+200, SCREEN_Y+MARGIN, SLIDER_HEIGHT, 50, 25, context, _onSlider4ValueChangedCmd),
	_slider5(16+250, SCREEN_Y+MARGIN, SLIDER_HEIGHT, 50, 25, context, _onSlider5ValueChangedCmd),

	_slider0Txt(26, MARGIN*2+SLIDER_HEIGHT, TEXT_WIDTH, TEXT_HEIGHT, "0.3", TEXT_COLOR, BACKGROUND_DARK, Font18, nullptr),
	_slider1Txt(26+50, MARGIN*2+SLIDER_HEIGHT, TEXT_WIDTH, TEXT_HEIGHT, "0.5", TEXT_COLOR, BACKGROUND_DARK, Font18, &_slider0Txt),
	_slider2Txt(26+100, MARGIN*2+SLIDER_HEIGHT, TEXT_WIDTH, TEXT_HEIGHT, "0.9", TEXT_COLOR, BACKGROUND_DARK, Font18, &_slider1Txt),
	_slider3Txt(29+150, MARGIN*2+SLIDER_HEIGHT, TEXT_WIDTH, TEXT_HEIGHT, "1.5", TEXT_COLOR, BACKGROUND_DARK, Font18, &_slider2Txt),
	_slider4Txt(26+200, MARGIN*2+SLIDER_HEIGHT, TEXT_WIDTH, TEXT_HEIGHT, "2.2", TEXT_COLOR, BACKGROUND_DARK, Font18, &_slider3Txt),
	_slider5Txt(26+250, MARGIN*2+SLIDER_HEIGHT, TEXT_WIDTH, TEXT_HEIGHT, "3.0", TEXT_COLOR, BACKGROUND_DARK, Font18, &_slider4Txt),
	_background(0, 0, FULL_SCREEN_WIDTH, SCREEN_HEIGHT, BACKGROUND_DARK, &_slider5Txt)
{
	context.FocusManager->RegisterHandler(100, &_slider5.Slider);
	context.FocusManager->RegisterHandler(100, &_slider4.Slider);
	context.FocusManager->RegisterHandler(100, &_slider3.Slider);
	context.FocusManager->RegisterHandler(100, &_slider2.Slider);
	context.FocusManager->RegisterHandler(100, &_slider1.Slider);
	context.FocusManager->RegisterHandler(100, &_slider0.Slider);

	_slider0.Text.SetFloatValue(25, 1, true);
	_slider1.Text.SetFloatValue(25, 1, true);
	_slider2.Text.SetFloatValue(25, 1, true);
	_slider3.Text.SetFloatValue(25, 1, true);
	_slider4.Text.SetFloatValue(25, 1, true);
	_slider5.Text.SetFloatValue(25, 1, true);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
AudioOutputEqualizerView::~AudioOutputEqualizerView()
{
	_context.FocusManager->UnregisterHandler(&_slider0.Slider);
	_context.FocusManager->UnregisterHandler(&_slider1.Slider);
	_context.FocusManager->UnregisterHandler(&_slider2.Slider);
	_context.FocusManager->UnregisterHandler(&_slider3.Slider);
	_context.FocusManager->UnregisterHandler(&_slider4.Slider);
	_context.FocusManager->UnregisterHandler(&_slider5.Slider);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void AudioOutputEqualizerView::OnSlider0ValueChanged(int value)
{
	_slider0.Text.SetFloatValue(value, 1, true);
	_slider0.Text.Draw();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void AudioOutputEqualizerView::OnSlider1ValueChanged(int value)
{
	_slider1.Text.SetFloatValue(value, 1, true);
	_slider1.Text.Draw();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void AudioOutputEqualizerView::OnSlider2ValueChanged(int value)
{
	_slider2.Text.SetFloatValue(value, 1, true);
	_slider2.Text.Draw();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void AudioOutputEqualizerView::OnSlider3ValueChanged(int value)
{
	_slider3.Text.SetFloatValue(value, 1, true);
	_slider3.Text.Draw();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void AudioOutputEqualizerView::OnSlider4ValueChanged(int value)
{
	_slider4.Text.SetFloatValue(value, 1, true);
	_slider4.Text.Draw();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void AudioOutputEqualizerView::OnSlider5ValueChanged(int value)
{
	_slider5.Text.SetFloatValue(value, 1, true);
	_slider5.Text.Draw();
}

}