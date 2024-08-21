#include "MainScreen.hpp"
#include "OGCommon.hpp"
#include "IFocusManager.hpp"
#include "IEncoderEventManager.hpp"
#include "IKeyboardEventManager.hpp"

#include <cstdio>
#include "dumy_picture.h"

namespace gui
{
/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
MainScreen::MainScreen(const IUIContext & context)
	:Group(0, 0, 320, 240, context,
	{
		&_button0, &_button1, &_button2, &_button3,
		&_mainRBGroup, &_frequencyLabel
	}, 
	&_picture),

	_onButton0ClickedCmd(this, &MainScreen::OnButton0Clicked),
	_onButton1ClickedCmd(this, &MainScreen::OnButton1Clicked),
	_onButton2ClickedCmd(this, &MainScreen::OnButton2Clicked),
	_onButton3ClickedCmd(this, &MainScreen::OnButton3Clicked),

	_onMainButtonClikedCmd(this, &MainScreen::OnMainButtonClicked),
	_onRadioButtonClikedCmd(this, &MainScreen::OnRadioButtonClicked),
	_onAudioButtonClikedCmd(this, &MainScreen::OnAudioButtonClicked),
	_onDSPButtonClikedCmd(this, &MainScreen::OnDSPButtonClicked),
	_onSettingsButtonClikedCmd(this, &MainScreen::OnSettingsButtonClicked),

	_onFrequencyChangedCmd(this, &MainScreen::OnFrequencyChanged),

	_button0(6, 24, "AGC: 40", context, _onButton0ClickedCmd),
	_button1(6, 46, "BW: 2.75", context, _onButton1ClickedCmd),
	_button2(6, 68, "TXP: 25", context, _onButton2ClickedCmd),
	_button3(6, 90, "VOL: 45", context, _onButton3ClickedCmd),

	_mainButton(0, 240-24, "MAIN", context, _onMainButtonClikedCmd),
	_radioButton(64, 240-24, "RADIO", context, _onRadioButtonClikedCmd),
	_audioButton(64*2, 240-24, "AUDIO", context, _onAudioButtonClikedCmd),
	_dspButton(64*3, 240-24, "DSP", context, _onDSPButtonClikedCmd),
	_settingsButton(64*4, 240-24, "SETTING", context, _onSettingsButtonClikedCmd),
	_mainRBGroup(0, 240-24, 320, 24, context,
	{
		&_mainButton, &_radioButton, &_audioButton,
		&_dspButton, &_settingsButton
	}, nullptr),

	_frequencyLabel(117, 68, context, _onFrequencyChangedCmd),

	//_background(0, 240-24, 320, 64, BACKGROUND_DARK, nullptr)
	_picture(&gui320x240, nullptr)
{
	context.FocusManager->RegisterHandler(0, &_frequencyLabel);
	context.FocusManager->RegisterHandler(1, &_button0);
	context.FocusManager->RegisterHandler(2, &_button1);
	context.FocusManager->RegisterHandler(3, &_button2);
	context.FocusManager->RegisterHandler(4, &_button3);

	context.FocusManager->RegisterHandler(251, &_mainButton);
	context.FocusManager->RegisterHandler(252, &_radioButton);
	context.FocusManager->RegisterHandler(253, &_audioButton);
	context.FocusManager->RegisterHandler(254, &_dspButton);
	context.FocusManager->RegisterHandler(255, &_settingsButton);

	context.EncoderEventManager->RegisterHandler(&_frequencyLabel);
	context.KeyboardEventManager->RegisterHandler(&_frequencyLabel);
	_frequencyLabel.SetIntValue(_frequency, "Hz");
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
MainScreen::~MainScreen()
{
	_context.FocusManager->UnregisterHandler(&_frequencyLabel);
	_context.FocusManager->UnregisterHandler(&_button0);
	_context.FocusManager->UnregisterHandler(&_button1);
	_context.FocusManager->UnregisterHandler(&_button2);
	_context.FocusManager->UnregisterHandler(&_button3);

	_context.FocusManager->UnregisterHandler(&_mainButton);
	_context.FocusManager->UnregisterHandler(&_radioButton);
	_context.FocusManager->UnregisterHandler(&_audioButton);
	_context.FocusManager->UnregisterHandler(&_dspButton);
	_context.FocusManager->UnregisterHandler(&_settingsButton);

	_context.EncoderEventManager->UnregisterHandler();
	_context.KeyboardEventManager->UnregisterHandler();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void MainScreen::OnButton0Clicked(IButton *)
{
	printf("Button0 was ckicked\n");
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void MainScreen::OnButton1Clicked(IButton *)
{
	printf("Button1 was ckicked\n");
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void MainScreen::OnButton2Clicked(IButton *)
{
	printf("Button2 was ckicked\n");
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void MainScreen::OnButton3Clicked(IButton *)
{
	printf("Button3 was ckicked\n");
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void MainScreen::OnMainButtonClicked(IRadioButton *)
{
	printf("Main button was ckicked\n");
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void MainScreen::OnRadioButtonClicked(IRadioButton *)
{
	printf("Radio button was ckicked\n");
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void MainScreen::OnAudioButtonClicked(IRadioButton *)
{
	printf("Audio button was ckicked\n");
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void MainScreen::OnDSPButtonClicked(IRadioButton *)
{
	printf("DSP button was ckicked\n");
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void MainScreen::OnSettingsButtonClicked(IRadioButton *)
{
	printf("Settings button was ckicked\n");
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void MainScreen::OnFrequencyChanged(const NumericUpDown::Parameters & params)
{
	printf("Frequency was changed\n");
	(params.EventType == NumericUpDown::Direction::Increase) ?
		_frequency++ : _frequency--;

	_frequencyLabel.SetIntValue(_frequency, "Hz");
	_frequencyLabel.Draw();
}

}