#ifndef GUI_AUDIO_INPUT_LEVELS_SCREEN_HPP
#define GUI_AUDIO_INPUT_LEVELS_SCREEN_HPP

#include "Group.hpp"
#include "GERectangle.hpp"

namespace gui
{
	class AudioInputLevelsScreen : public Group
	{
	public:
		// constructor
		AudioInputLevelsScreen(const IUIContext & context);

		// destructor
		~AudioInputLevelsScreen() override = default;

	private:
		GERectangle _background;
	};
}

#endif // GUI_AUDIO_INPUT_LEVELS_SCREEN_HPP