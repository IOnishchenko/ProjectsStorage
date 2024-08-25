#ifndef GUI_AUDIO_OUTPUT_QUALIZER_SCREEN_HPP
#define GUI_AUDIO_OUTPUT_QUALIZER_SCREEN_HPP

#include "Group.hpp"
#include "GERectangle.hpp"
#include "OGSliderVertical.hpp"
#include "Command.hpp"

namespace gui
{
	class AudioOutputEqualizerScreen : public Group
	{
	public:
		// constructor
		AudioOutputEqualizerScreen(const IUIContext & context);

		// destructor
		~AudioOutputEqualizerScreen() override;

	private:
		// commands
		Command<AudioOutputEqualizerScreen, int> _onSlider0ValueChangedCmd;

		OGSliderVertical _slider0;
		OGSliderVertical _slider1;
		OGSliderVertical _slider2;
		OGSliderVertical _slider3;
		OGSliderVertical _slider4;
		OGSliderVertical _slider5;

		GERectangle _background;

		// methods
		void OnSlider0ValueChanged(int value);
	};
}

#endif // GUI_AUDIO_OUTPUT_QUALIZER_SCREEN_HPP