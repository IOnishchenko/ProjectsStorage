#include "AudioOutputView.hpp"
#include "OGCommon.hpp"
#include "AudioOutputLevelsView.hpp"
#include "AudioOutputEqualizerView.hpp"

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
AudioOutputView::AudioOutputView(const IUIContext & context)
	:OGTabControl2T(SCREEN_Y, SCREEN_HEIGHT, context, "VOLUME", "EQUALIZER",
	_onLevelsButtonClikedCmd, _onEqulizerButtonClikedCmd),
	_onLevelsButtonClikedCmd(this, &AudioOutputView::OnLevelsButtonClicked),
	_onEqulizerButtonClikedCmd(this, &AudioOutputView::OnEqulazerButtonClicked),
	_subGroup{new AudioOutputLevelsView(context)}
{
	AddChild(_subGroup.get());
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void AudioOutputView::OnLevelsButtonClicked(IRadioButton *)
{
	RemoveChild(_subGroup.get());
	_subGroup.reset();
	_subGroup = std::make_unique<AudioOutputLevelsView>(_context);
	AddChild(_subGroup.get());
	_subGroup->Draw();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void AudioOutputView::OnEqulazerButtonClicked(IRadioButton *)
{
	RemoveChild(_subGroup.get());
	_subGroup.reset();
	_subGroup = std::make_unique<AudioOutputEqualizerView>(_context);
	AddChild(_subGroup.get());
	_subGroup->Draw();
}

}