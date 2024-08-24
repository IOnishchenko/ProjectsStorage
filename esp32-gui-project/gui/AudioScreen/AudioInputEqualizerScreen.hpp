#ifndef GUI_AUDIO_INPUT_QUALIZER_SCREEN_HPP
#define GUI_AUDIO_INPUT_QUALIZER_SCREEN_HPP

#include "Group.hpp"
#include "GERectangle.hpp"

namespace gui
{
	class AudioInputEqualizerScreen : public Group
	{
	public:
		// constructor
		AudioInputEqualizerScreen(const IUIContext & context);

		// destructor
		~AudioInputEqualizerScreen() override = default;

	private:
		GERectangle _background;
	};
}

#endif // GUI_AUDIO_INPUT_QUALIZER_SCREEN_HPP