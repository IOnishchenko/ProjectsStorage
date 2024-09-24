#include "ScreenBase.hpp"
#include "OGCommon.hpp"
#include "IFocusManager.hpp"
#include "IEncoderEventManager.hpp"
#include "IKeyboardEventManager.hpp"
#include "IWindowManager.hpp"
#include "MainView.hpp"
#include "RadioView.hpp"
#include "AudioView.hpp"
#include "DSPView.hpp"

namespace gui
{
/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
ScreenBase::ScreenBase(const IUIContext & context)
	:Group(0, 240-24, 320, 24, context,
	{
		&_mainRBGroup
	}, nullptr),

	_onMainButtonClikedCmd(this, &ScreenBase::OnMainButtonClicked),
	_onRadioButtonClikedCmd(this, &ScreenBase::OnRadioButtonClicked),
	_onAudioButtonClikedCmd(this, &ScreenBase::OnAudioButtonClicked),
	_onDSPButtonClikedCmd(this, &ScreenBase::OnDSPButtonClicked),
	_onSettingsButtonClikedCmd(this, &ScreenBase::OnSettingsButtonClicked),

	_mainButton(0, 240-24, "MAIN", context, _onMainButtonClikedCmd),
	_radioButton(64, 240-24, "RADIO", context, _onRadioButtonClikedCmd),
	_audioButton(64*2, 240-24, "AUDIO", context, _onAudioButtonClikedCmd),
	_dspButton(64*3, 240-24, "DSP", context, _onDSPButtonClikedCmd),
	_settingsButton(64*4, 240-24, "SETTING", context, _onSettingsButtonClikedCmd),
	_mainRBGroup(0, 240-24, 320, 24, context,
	{
		&_mainButton, &_radioButton, &_audioButton,
		&_dspButton, &_settingsButton
	}, nullptr)
{
	_mainButton.SetAsSelectedInitially();
	context.FocusManager->RegisterHandler(1004, &_mainButton);
	context.FocusManager->RegisterHandler(1003, &_radioButton);
	context.FocusManager->RegisterHandler(1002, &_audioButton);
	context.FocusManager->RegisterHandler(1001, &_dspButton);
	context.FocusManager->RegisterHandler(1000, &_settingsButton);
	context.WindowManager.CreateAndShowWindow<MainView>();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
ScreenBase::~ScreenBase()
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
void ScreenBase::OnMainButtonClicked(IRadioButton *)
{
	_context.WindowManager.CreateAndShowWindow<MainView>();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void ScreenBase::OnRadioButtonClicked(IRadioButton *)
{
	_context.WindowManager.CreateAndShowWindow<RadioView>();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void ScreenBase::OnAudioButtonClicked(IRadioButton *)
{
	_context.WindowManager.CreateAndShowWindow<AudioView>();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void ScreenBase::OnDSPButtonClicked(IRadioButton *)
{
	_context.WindowManager.CreateAndShowWindow<DSPView>();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void ScreenBase::OnSettingsButtonClicked(IRadioButton *)
{
}

}