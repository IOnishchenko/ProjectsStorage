#ifndef GUI_AUDIO_INPUT_MANUAL_SETTINGS_VIEW_HPP
#define GUI_AUDIO_INPUT_MANUAL_SETTINGS_VIEW_HPP

#include "Group.hpp"
#include "OGSliderHorizontal.hpp"
#include "SliderWithHeader.hpp"
#include "Command.hpp"
#include "GERectangle.hpp"
#include "GEText.hpp"

namespace gui
{
	class AudioInputManualSettingsView : public Group
	{
	public:
		// constructor
		AudioInputManualSettingsView(const IUIContext & context);

		// destructor
		~AudioInputManualSettingsView() override;

	private:
		// commands
		Command<AudioInputManualSettingsView, int> _onAnalogGainCmd;
		Command<AudioInputManualSettingsView, int> _onDigitalGainCmd;

		custom::SliderWithHeader _analogGainSlider;
		custom::SliderWithHeader _digitalGainSlider;

		GERectangle _background;

		// methods
		void OnAgalogGainChanged(int value);
		void OnDigitalGainChanged(int value);
	};
}

#endif // GUI_AUDIO_INPUT_MANUAL_SETTINGS_VIEW_HPP