#include "AudioInputAGCSettingsView.hpp"
#include "IFocusManager.hpp"
#include "OGCommon.hpp"

namespace gui
{

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
constexpr uint16_t SCREEN_Y = TABCONTROL_HEIGHT * 2 + ROW_HEIGHT;
constexpr uint16_t SCREEN_HEIGHT = FULL_SCREEN_HEIGHT-BOTTOM_MENU_HEIGHT-SCREEN_Y;

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
AudioInputAGCSettingsView::AudioInputAGCSettingsView(const IUIContext & context)
	:Group(0, SCREEN_Y, FULL_SCREEN_WIDTH, SCREEN_HEIGHT, context,
	{
		&_targetLevelSlider.Text, &_targetLevelSlider.Slider,
		&_noiseThreshouldSlider.Text, &_noiseThreshouldSlider.Slider,
	}, &_background),
	_onTargetLevelChangedCmd(this, &AudioInputAGCSettingsView::OnTargetLevelChanged),
	_onNoiseThreshouldChangedCmd(this, &AudioInputAGCSettingsView::OnNoiseThreshouldChanged),
	_targetLevelSlider(SCREEN_Y, SCREEN_Y, 64, 30, context, _onTargetLevelChangedCmd,
		"Target", "Level (dB):", nullptr),
	_noiseThreshouldSlider(SCREEN_Y, SCREEN_Y+MARGIN+ROW_HEIGHT, 25, 12, context,
		_onNoiseThreshouldChangedCmd, "Noise", "Level (dB):", _targetLevelSlider.Header),

	_background(0, 0, FULL_SCREEN_WIDTH, SCREEN_HEIGHT, BACKGROUND_DARK, _noiseThreshouldSlider.Header)
{
	context.FocusManager->RegisterHandler(100, &_targetLevelSlider.Slider);
	context.FocusManager->RegisterHandler(100, &_noiseThreshouldSlider.Slider);

	_targetLevelSlider.Text.SetIntValue(64);
	_noiseThreshouldSlider.Text.SetIntValue(12);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
AudioInputAGCSettingsView::~AudioInputAGCSettingsView()
{
	_context.FocusManager->UnregisterHandler(&_targetLevelSlider.Slider);
	_context.FocusManager->UnregisterHandler(&_noiseThreshouldSlider.Slider);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void AudioInputAGCSettingsView::OnTargetLevelChanged(int value)
{
	_targetLevelSlider.Text.SetFloatValue(value, 1, true);
	_targetLevelSlider.Text.Draw();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void AudioInputAGCSettingsView::OnNoiseThreshouldChanged(int value)
{
	_noiseThreshouldSlider.Text.SetIntValue(value);
	_noiseThreshouldSlider.Text.Draw();
}

}