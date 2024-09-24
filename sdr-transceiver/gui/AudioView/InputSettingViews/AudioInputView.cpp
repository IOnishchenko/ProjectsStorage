#include "AudioInputView.hpp"
#include "OGCommon.hpp"
#include "AudioInputLevelsView.hpp"
#include "AudioInputEqualizerView.hpp"

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
AudioInputView::AudioInputView(const IUIContext & context)
	:OGTabControl2T(SCREEN_Y, SCREEN_HEIGHT, context, "SETTINGS", "EQUALIZER",
	_onLevelsButtonClikedCmd, _onEqulizerButtonClikedCmd),
	_onLevelsButtonClikedCmd(this, &AudioInputView::OnLevelsButtonClicked),
	_onEqulizerButtonClikedCmd(this, &AudioInputView::OnEqulazerButtonClicked),
	_subGroup{new AudioInputLevelsView(context)}
{
	AddChild(_subGroup.get());
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void AudioInputView::OnLevelsButtonClicked(IRadioButton *)
{
	RemoveChild(_subGroup.get());
	_subGroup.reset();
	_subGroup = std::make_unique<AudioInputLevelsView>(_context);
	AddChild(_subGroup.get());
	_subGroup->Draw();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void AudioInputView::OnEqulazerButtonClicked(IRadioButton *)
{
	RemoveChild(_subGroup.get());
	_subGroup.reset();
	_subGroup = std::make_unique<AudioInputEqualizerView>(_context);
	AddChild(_subGroup.get());
	_subGroup->Draw();
}

}