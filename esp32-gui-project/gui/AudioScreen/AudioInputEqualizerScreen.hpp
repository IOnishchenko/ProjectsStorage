#ifndef GUI_AUDIO_INPUT_QUALIZER_SCREEN_HPP
#define GUI_AUDIO_INPUT_QUALIZER_SCREEN_HPP

#include "Group.hpp"
#include "GERectangle.hpp"
#include "GEText.hpp"
#include "OGVerticalSliderLabel.hpp"
#include "Command.hpp"

namespace gui
{
	class AudioInputEqualizerScreen : public Group
	{
	public:
		// constructor
		AudioInputEqualizerScreen(const IUIContext & context);

		// destructor
		~AudioInputEqualizerScreen() override;

	private:
				// commands
		Command<AudioInputEqualizerScreen, int> _onSlider0ValueChangedCmd;
		Command<AudioInputEqualizerScreen, int> _onSlider1ValueChangedCmd;
		Command<AudioInputEqualizerScreen, int> _onSlider2ValueChangedCmd;
		Command<AudioInputEqualizerScreen, int> _onSlider3ValueChangedCmd;
		Command<AudioInputEqualizerScreen, int> _onSlider4ValueChangedCmd;

		OGVerticalSliderLabel _slider0;
		OGVerticalSliderLabel _slider1;
		OGVerticalSliderLabel _slider2;
		OGVerticalSliderLabel _slider3;
		OGVerticalSliderLabel _slider4;

		GEText _slider0Txt;
		GEText _slider1Txt;
		GEText _slider2Txt;
		GEText _slider3Txt;
		GEText _slider4Txt;
		GERectangle _background;

		// methods
		void OnSlider0ValueChanged(int value);
		void OnSlider1ValueChanged(int value);
		void OnSlider2ValueChanged(int value);
		void OnSlider3ValueChanged(int value);
		void OnSlider4ValueChanged(int value);
	};
}

#endif // GUI_AUDIO_INPUT_QUALIZER_SCREEN_HPP