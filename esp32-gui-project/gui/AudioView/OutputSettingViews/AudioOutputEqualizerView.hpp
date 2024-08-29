#ifndef GUI_AUDIO_OUTPUT_QUALIZER_SCREEN_HPP
#define GUI_AUDIO_OUTPUT_QUALIZER_SCREEN_HPP

#include "Group.hpp"
#include "GERectangle.hpp"
#include "GEText.hpp"
#include "OGVerticalSliderLabel.hpp"
#include "Command.hpp"

namespace gui
{
	class AudioOutputEqualizerView : public Group
	{
	public:
		// constructor
		AudioOutputEqualizerView(const IUIContext & context);

		// destructor
		~AudioOutputEqualizerView() override;

	private:
		// commands
		Command<AudioOutputEqualizerView, int> _onSlider0ValueChangedCmd;
		Command<AudioOutputEqualizerView, int> _onSlider1ValueChangedCmd;
		Command<AudioOutputEqualizerView, int> _onSlider2ValueChangedCmd;
		Command<AudioOutputEqualizerView, int> _onSlider3ValueChangedCmd;
		Command<AudioOutputEqualizerView, int> _onSlider4ValueChangedCmd;
		Command<AudioOutputEqualizerView, int> _onSlider5ValueChangedCmd;

		OGVerticalSliderLabel _slider0;
		OGVerticalSliderLabel _slider1;
		OGVerticalSliderLabel _slider2;
		OGVerticalSliderLabel _slider3;
		OGVerticalSliderLabel _slider4;
		OGVerticalSliderLabel _slider5;

		GEText _slider0Txt;
		GEText _slider1Txt;
		GEText _slider2Txt;
		GEText _slider3Txt;
		GEText _slider4Txt;
		GEText _slider5Txt;
		GERectangle _background;

		// methods
		void OnSlider0ValueChanged(int value);
		void OnSlider1ValueChanged(int value);
		void OnSlider2ValueChanged(int value);
		void OnSlider3ValueChanged(int value);
		void OnSlider4ValueChanged(int value);
		void OnSlider5ValueChanged(int value);
	};
}

#endif // GUI_AUDIO_OUTPUT_QUALIZER_SCREEN_HPP