#ifndef GUI_AUDIO_OUTPUT_LEVELS_SCREEN_HPP
#define GUI_AUDIO_OUTPUT_LEVELS_SCREEN_HPP

#include "Group.hpp"
#include "OGSliderHorizontal.hpp"
#include "SliderWithHeader.hpp"
#include "Command.hpp"
#include "GERectangle.hpp"
#include "GEText.hpp"

namespace gui
{
	class AudioOutputLevelsView : public Group
	{
	public:
		// constructor
		AudioOutputLevelsView(const IUIContext & context);

		// destructor
		~AudioOutputLevelsView() override;

	private:
		// commands
		Command<AudioOutputLevelsView, int> _onAnalogGainCmd;
		Command<AudioOutputLevelsView, int> _onDigitalGainCmd;

		custom::SliderWithHeader _analogGainSlider;
		custom::SliderWithHeader _digitalGainSlider;

		GERectangle _background;

		// methods
		void OnAgalogGainChanged(int value);
		void OnDigitalGainChanged(int value);
	};
}

#endif // GUI_AUDIO_OUTPUT_LEVELS_SCREEN_HPP