#ifndef GUI_AUDIO_OUTPUT_QUALIZER_SCREEN_HPP
#define GUI_AUDIO_OUTPUT_QUALIZER_SCREEN_HPP

#include "Group.hpp"
#include "GERectangle.hpp"

namespace gui
{
	class AudioOutputEqualizerScreen : public Group
	{
	public:
		// constructor
		AudioOutputEqualizerScreen(const IUIContext & context);

		// destructor
		~AudioOutputEqualizerScreen() override = default;

	private:
		GERectangle _background;
	};
}

#endif // GUI_AUDIO_OUTPUT_QUALIZER_SCREEN_HPP