#ifndef GUI_AUDIO_INPUT_QUALIZER_SCREEN_HPP
#define GUI_AUDIO_INPUT_QUALIZER_SCREEN_HPP

#include "Group.hpp"
#include "GERectangle.hpp"
#include "GEText.hpp"
#include "OGVerticalSliderLabel.hpp"
#include "Command.hpp"

namespace gui
{
	class AudioInputEqualizerView : public Group
	{
	public:
		// constructor
		AudioInputEqualizerView(const IUIContext & context);

		// destructor
		~AudioInputEqualizerView() override;

	private:
		// commands
		Command<AudioInputEqualizerView, int> _onSlider0ValueChangedCmd;
		Command<AudioInputEqualizerView, int> _onSlider1ValueChangedCmd;
		Command<AudioInputEqualizerView, int> _onSlider2ValueChangedCmd;
		Command<AudioInputEqualizerView, int> _onSlider3ValueChangedCmd;
		Command<AudioInputEqualizerView, int> _onSlider4ValueChangedCmd;

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