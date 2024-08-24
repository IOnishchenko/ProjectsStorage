#include "AudioInputScreen.hpp"
#include "OGCommon.hpp"
#include "AudioInputLevelsScreen.hpp"
#include "AudioInputEqualizerScreen.hpp"

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
AudioInputScreen::AudioInputScreen(const IUIContext & context)
	:OGTabControl2T(SCREEN_Y, SCREEN_HEIGHT, context, "LEVELS", "EQUALIZER",
	_onLevelsButtonClikedCmd, _onEqulizerButtonClikedCmd),
	_onLevelsButtonClikedCmd(this, &AudioInputScreen::OnLevelsButtonClicked),
	_onEqulizerButtonClikedCmd(this, &AudioInputScreen::OnEqulazerButtonClicked),
	_subGroup{new AudioInputLevelsScreen(context)}
{
	AddChild(_subGroup.get());
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void AudioInputScreen::OnLevelsButtonClicked(IRadioButton *)
{
	RemoveChild(_subGroup.get());
	_subGroup.reset(new AudioInputLevelsScreen(_context));
	AddChild(_subGroup.get());
	_subGroup->Draw();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void AudioInputScreen::OnEqulazerButtonClicked(IRadioButton *)
{
	RemoveChild(_subGroup.get());
	_subGroup.reset(new AudioInputEqualizerScreen(_context));
	AddChild(_subGroup.get());
	_subGroup->Draw();
}

}