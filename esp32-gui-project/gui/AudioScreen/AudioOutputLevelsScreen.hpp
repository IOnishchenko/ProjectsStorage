#ifndef GUI_AUDIO_OUTPUT_LEVELS_SCREEN_HPP
#define GUI_AUDIO_OUTPUT_LEVELS_SCREEN_HPP

#include "Group.hpp"
#include "OGSliderHorizontal.hpp"
#include "OGHorizontalSliderLabel.hpp"
#include "Command.hpp"
#include "GERectangle.hpp"
#include "GEText.hpp"

namespace gui
{
	class AudioOutputLevelsScreen : public Group
	{
	public:
		// constructor
		AudioOutputLevelsScreen(const IUIContext & context);

		// destructor
		~AudioOutputLevelsScreen() override;

	private:
		// commands
		Command<AudioOutputLevelsScreen, int> _onAnalogGainCmd;
		Command<AudioOutputLevelsScreen, int> _onDigitalGainCmd;

		OGHorizontalSliderLabel _analogGainSlider;
		OGHorizontalSliderLabel _digitalGainSlider;

		GEText _headerTxt0;
		GEText _headerTxt1;
		GEText _headerTxt2;
		GEText _headerTxt3;
		GERectangle _background;

		// methods
		void OnAgalogGainChanged(int value);
		void OnDigitalGainChanged(int value);
	};
}

#endif // GUI_AUDIO_OUTPUT_LEVELS_SCREEN_HPP