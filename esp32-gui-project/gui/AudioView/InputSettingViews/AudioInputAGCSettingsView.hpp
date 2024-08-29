#ifndef GUI_AUDIO_INPUT_AGC_SETTINGS_VIEW_HPP
#define GUI_AUDIO_INPUT_AGC_SETTINGS_VIEW_HPP

#include "Group.hpp"
#include "OGSliderHorizontal.hpp"
#include "SliderWithHeader.hpp"
#include "Command.hpp"
#include "GERectangle.hpp"
#include "GEText.hpp"

namespace gui
{
	class AudioInputAGCSettingsView : public Group
	{
	public:
		// constructor
		AudioInputAGCSettingsView(const IUIContext & context);

		// destructor
		~AudioInputAGCSettingsView() override;

	private:
		// commands
		Command<AudioInputAGCSettingsView, int> _onTargetLevelChangedCmd;
		Command<AudioInputAGCSettingsView, int> _onNoiseThreshouldChangedCmd;

		custom::SliderWithHeader _targetLevelSlider;
		custom::SliderWithHeader _noiseThreshouldSlider;

		GERectangle _background;

		// methods
		void OnTargetLevelChanged(int value);
		void OnNoiseThreshouldChanged(int value);
	};
}

#endif // GUI_AUDIO_INPUT_AGC_SETTINGS_VIEW_HPP