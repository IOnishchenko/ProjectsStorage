#ifndef GUI_AUDIO_OUTPUT_LEVELS_SCREEN_HPP
#define GUI_AUDIO_OUTPUT_LEVELS_SCREEN_HPP

#include "Group.hpp"
#include "GERectangle.hpp"

namespace gui
{
	class AudioOutputLevelsScreen : public Group
	{
	public:
		// constructor
		AudioOutputLevelsScreen(const IUIContext & context);

		// destructor
		~AudioOutputLevelsScreen() override = default;

	private:
		GERectangle _background;
	};
}

#endif // GUI_AUDIO_OUTPUT_LEVELS_SCREEN_HPP