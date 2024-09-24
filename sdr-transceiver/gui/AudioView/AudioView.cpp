#include "AudioView.hpp"
#include "OGCommon.hpp"
#include "AudioOutputView.hpp"
#include "AudioInputView.hpp"

namespace gui
{
/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
constexpr uint16_t SCREEN_HEIGHT = FULL_SCREEN_HEIGHT-BOTTOM_MENU_HEIGHT;

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
AudioView::AudioView(const IUIContext & context)
	:OGTabControl2T(0, SCREEN_HEIGHT, context, "OUTPUT", "MICROPHONE",
	_onOutputButtonClikedCmd, _onInputButtonClikedCmd),
	_onOutputButtonClikedCmd(this, &AudioView::OnOutputButtonClicked),
	_onInputButtonClikedCmd(this, &AudioView::OnInputButtonClicked),
	_subGroup{new AudioOutputView(context)}
{
	AddChild(_subGroup.get());
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void AudioView::OnOutputButtonClicked(IRadioButton *)
{
	RemoveChild(_subGroup.get());
	_subGroup.reset();
	_subGroup = std::make_unique<AudioOutputView>(_context);
	AddChild(_subGroup.get());
	_subGroup->Draw();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void AudioView::OnInputButtonClicked(IRadioButton *)
{
	RemoveChild(_subGroup.get());
	_subGroup.reset();
	_subGroup = std::make_unique<AudioInputView>(_context);
	AddChild(_subGroup.get());
	_subGroup->Draw();
}

}