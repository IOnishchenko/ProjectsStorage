#include "AudioScreen.hpp"
#include "OGCommon.hpp"
#include "AudioOutputScreen.hpp"
#include "AudioInputScreen.hpp"

namespace gui
{
/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
constexpr uint16_t SCREEN_HEIGHT = FULL_SCREEN_HEIGHT-BOTTOM_MENU_HEIGHT;

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
AudioScreen::AudioScreen(const IUIContext & context)
	:OGTabControl2T(0, SCREEN_HEIGHT, context, "OUTPUT", "INPUT",
	_onOutputButtonClikedCmd, _onInputButtonClikedCmd),
	_onOutputButtonClikedCmd(this, &AudioScreen::OnOutputButtonClicked),
	_onInputButtonClikedCmd(this, &AudioScreen::OnInputButtonClicked),
	_subGroup{new AudioOutputScreen(context)}
{
	AddChild(_subGroup.get());
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void AudioScreen::OnOutputButtonClicked(IRadioButton *)
{
	RemoveChild(_subGroup.get());
	_subGroup.reset(new AudioOutputScreen(_context));
	AddChild(_subGroup.get());
	_subGroup->Draw();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void AudioScreen::OnInputButtonClicked(IRadioButton *)
{
	RemoveChild(_subGroup.get());
	_subGroup.reset(new AudioInputScreen(_context));
	AddChild(_subGroup.get());
	_subGroup->Draw();
}

}