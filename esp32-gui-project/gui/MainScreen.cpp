#include "MainScreen.hpp"
#include "OGCommon.hpp"
#include "IFocusManager.hpp"

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
		&_mainButton, &_radioButton, &_audioButton,
		&_dspButton, &_settingsButton
	}, 
	&_picture),

	_onMainButtonClikedCmd(this, &MainScreen::OnMainButtonClicked),
	_onRadioButtonClikedCmd(this, &MainScreen::OnRadioButtonClicked),
	_onAudioButtonClikedCmd(this, &MainScreen::OnAudioButtonClicked),
	_onDSPButtonClikedCmd(this, &MainScreen::OnDSPButtonClicked),
	_onSettingsButtonClikedCmd(this, &MainScreen::OnSettingsButtonClicked),

	_mainButton(0, 240-24, "MAIN", context, _onMainButtonClikedCmd),
	_radioButton(64, 240-24, "RADIO", context, _onRadioButtonClikedCmd),
	_audioButton(64*2, 240-24, "AUDIO", context, _onAudioButtonClikedCmd),
	_dspButton(64*3, 240-24, "DSP", context, _onDSPButtonClikedCmd),
	_settingsButton(64*4, 240-24, "SETTING", context, _onSettingsButtonClikedCmd),
	//_background(0, 240-24, 320, 64, BACKGROUND_DARK, nullptr)
	_picture(&gui320x240, nullptr)
{
	context.FocusManager->RegisterHandler(251, &_mainButton);
	context.FocusManager->RegisterHandler(252, &_radioButton);
	context.FocusManager->RegisterHandler(253, &_audioButton);
	context.FocusManager->RegisterHandler(254, &_dspButton);
	context.FocusManager->RegisterHandler(255, &_settingsButton);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
MainScreen::~MainScreen()
{
	_context.FocusManager->UnregisterHandler(&_mainButton);
	_context.FocusManager->UnregisterHandler(&_radioButton);
	_context.FocusManager->UnregisterHandler(&_audioButton);
	_context.FocusManager->UnregisterHandler(&_dspButton);
	_context.FocusManager->UnregisterHandler(&_settingsButton);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void MainScreen::OnMainButtonClicked(IButton *)
{
	printf("Main button was ckicked\n");
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void MainScreen::OnRadioButtonClicked(IButton *)
{
	printf("Radio button was ckicked\n");
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void MainScreen::OnAudioButtonClicked(IButton *)
{
	printf("Audio button was ckicked\n");
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void MainScreen::OnDSPButtonClicked(IButton *)
{
	printf("DSP button was ckicked\n");
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void MainScreen::OnSettingsButtonClicked(IButton *)
{
	printf("Settings button was ckicked\n");
}

}