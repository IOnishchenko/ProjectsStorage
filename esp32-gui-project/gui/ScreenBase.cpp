#include "ScreenBase.hpp"
#include "OGCommon.hpp"
#include "IFocusManager.hpp"
#include "IEncoderEventManager.hpp"
#include "IKeyboardEventManager.hpp"
#include "MainView.hpp"
#include "RadioView.hpp"
#include "AudioView.hpp"

#include "dumy_picture.h"

namespace gui
{
/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
ScreenBase::ScreenBase(const IUIContext & context)
	:Group(0, 0, 320, 240, context,
	{
		&_mainRBGroup
	}, 
	&_picture),

	_onMainButtonClikedCmd(this, &ScreenBase::OnMainButtonClicked),
	_onRadioButtonClikedCmd(this, &ScreenBase::OnRadioButtonClicked),
	_onAudioButtonClikedCmd(this, &ScreenBase::OnAudioButtonClicked),
	_onDSPButtonClikedCmd(this, &ScreenBase::OnDSPButtonClicked),
	_onSettingsButtonClikedCmd(this, &ScreenBase::OnSettingsButtonClicked),

	_subGroup{new MainView(context)},

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
	_picture(&gui320x240, nullptr)
{
	_mainButton.SetAsSelectedInitially();
	context.FocusManager->RegisterHandler(1004, &_mainButton);
	context.FocusManager->RegisterHandler(1003, &_radioButton);
	context.FocusManager->RegisterHandler(1002, &_audioButton);
	context.FocusManager->RegisterHandler(1001, &_dspButton);
	context.FocusManager->RegisterHandler(1000, &_settingsButton);
	AddChild(_subGroup.get());
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void ScreenBase::OnMainButtonClicked(IRadioButton *)
{
	RemoveChild(_subGroup.get());
	_subGroup.reset();
	_subGroup = std::make_unique<MainView>(_context);
	AddChild(_subGroup.get());
	Draw();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void ScreenBase::OnRadioButtonClicked(IRadioButton *)
{
	RemoveChild(_subGroup.get());
	_subGroup.reset();
	_subGroup = std::make_unique<RadioView>(_context);
	AddChild(_subGroup.get());
	_subGroup->Draw();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void ScreenBase::OnAudioButtonClicked(IRadioButton *)
{
	RemoveChild(_subGroup.get());
	_subGroup.reset();
	_subGroup = std::make_unique<AudioView>(_context);
	AddChild(_subGroup.get());
	_subGroup->Draw();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void ScreenBase::OnDSPButtonClicked(IRadioButton *)
{
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void ScreenBase::OnSettingsButtonClicked(IRadioButton *)
{
}

}