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
		&_targetLevelSlider.Text, &_targetLevelSlider,
		&_noiseThreshouldSlider.Text, &_noiseThreshouldSlider,
		&_maxGainSlider.Text, &_maxGainSlider,
	}, &_background),
	_onTargetLevelChangedCmd(this, &AudioInputAGCSettingsView::OnTargetLevelChanged),
	_onNoiseThreshouldChangedCmd(this, &AudioInputAGCSettingsView::OnNoiseThreshouldChanged),
	_onMaxGainChangedCmd(this, &AudioInputAGCSettingsView::OnMaxGainChanged),
	_targetLevelSlider(SCREEN_Y, SCREEN_Y, 64, 30, context, _onTargetLevelChangedCmd,
		"Target", "Level (dB):", nullptr),
	_noiseThreshouldSlider(SCREEN_Y, SCREEN_Y+MARGIN+ROW_HEIGHT, 25, 12, context,
		_onNoiseThreshouldChangedCmd, "Noise", "Level (dB):", _targetLevelSlider.Header),
	_maxGainSlider(SCREEN_Y, SCREEN_Y+MARGIN*2+ROW_HEIGHT*2, 58, 24, context,
		_onMaxGainChangedCmd, "Maximum", "Gain (dB):", _noiseThreshouldSlider.Header),

	_background(0, 0, FULL_SCREEN_WIDTH, SCREEN_HEIGHT, BACKGROUND_DARK, _maxGainSlider.Header)
{
	context.FocusManager->RegisterHandler(100, &_targetLevelSlider);
	context.FocusManager->RegisterHandler(100, &_noiseThreshouldSlider);
	context.FocusManager->RegisterHandler(100, &_maxGainSlider);

	_targetLevelSlider.Text.SetIntValue(64);
	_noiseThreshouldSlider.Text.SetIntValue(12);
	_maxGainSlider.Text.SetIntValue(24);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
AudioInputAGCSettingsView::~AudioInputAGCSettingsView()
{
	_context.FocusManager->UnregisterHandler(&_targetLevelSlider);
	_context.FocusManager->UnregisterHandler(&_noiseThreshouldSlider);
	_context.FocusManager->UnregisterHandler(&_maxGainSlider);
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

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void AudioInputAGCSettingsView::OnMaxGainChanged(int value)
{
	_maxGainSlider.Text.SetIntValue(value);
	_maxGainSlider.Text.Draw();
}

}