#ifndef GUI_AUDIO_INPUT_LEVELS_SCREEN_HPP
#define GUI_AUDIO_INPUT_LEVELS_SCREEN_HPP

#include "Group.hpp"
#include "GERectangle.hpp"
#include "OGCheckBoxH18.hpp"
#include "Command.hpp"

namespace gui
{
	class AudioInputLevelsScreen : public Group
	{
	public:
		// constructor
		AudioInputLevelsScreen(const IUIContext & context);

		// destructor
		~AudioInputLevelsScreen() override;

	private:
		// commands
		Command<AudioInputLevelsScreen, ICheckBox *> _onAGCEnabledCmd;
		Command<AudioInputLevelsScreen, ICheckBox *> _onAGCDisabledCmd;

		// fields
		OGCheckBoxH18 _ageEnaCheckbox;

		GERectangle _background;

		// methods
		void OnAGCEnabled(ICheckBox *);
		void OnAGCDisabled(ICheckBox *);
	};
}

#endif // GUI_AUDIO_INPUT_LEVELS_SCREEN_HPP