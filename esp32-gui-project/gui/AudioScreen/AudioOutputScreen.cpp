#include "AudioOutputScreen.hpp"
#include "OGCommon.hpp"
#include "AudioOutputLevelsScreen.hpp"
#include "AudioOutputEqualizerScreen.hpp"

namespace gui
{

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
constexpr uint16_t SCREEN_Y = 24;
constexpr uint16_t SCREEN_HEIGHT = FULL_SCREEN_HEIGHT-BOTTOM_MENU_HEIGHT-SCREEN_Y;

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
AudioOutputScreen::AudioOutputScreen(const IUIContext & context)
	:OGTabControl2T(SCREEN_Y, SCREEN_HEIGHT, context, "LEVELS", "EQUALIZER",
	_onLevelsButtonClikedCmd, _onEqulizerButtonClikedCmd),
	_onLevelsButtonClikedCmd(this, &AudioOutputScreen::OnLevelsButtonClicked),
	_onEqulizerButtonClikedCmd(this, &AudioOutputScreen::OnEqulazerButtonClicked),
	_subGroup{new AudioOutputLevelsScreen(context)}
{
	AddChild(_subGroup.get());
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void AudioOutputScreen::OnLevelsButtonClicked(IRadioButton *)
{
	RemoveChild(_subGroup.get());
	_subGroup.reset(new AudioOutputLevelsScreen(_context));
	AddChild(_subGroup.get());
	_subGroup->Draw();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void AudioOutputScreen::OnEqulazerButtonClicked(IRadioButton *)
{
	RemoveChild(_subGroup.get());
	_subGroup.reset(new AudioOutputEqualizerScreen(_context));
	AddChild(_subGroup.get());
	_subGroup->Draw();
}

}