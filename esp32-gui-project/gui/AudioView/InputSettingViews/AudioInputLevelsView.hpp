#ifndef GUI_AUDIO_INPUT_LEVELS_SCREEN_HPP
#define GUI_AUDIO_INPUT_LEVELS_SCREEN_HPP

#include "Group.hpp"
#include "GERectangle.hpp"
#include "OGCheckBoxH18.hpp"
#include "Command.hpp"
#include <memory>

namespace gui
{
	class AudioInputLevelsView : public Group
	{
	public:
		// constructor
		AudioInputLevelsView(const IUIContext & context);

		// destructor
		~AudioInputLevelsView() override;

	private:
		// commands
		Command<AudioInputLevelsView, ICheckBox *> _onAGCEnabledCmd;
		Command<AudioInputLevelsView, ICheckBox *> _onAGCDisabledCmd;

		// fields
		OGCheckBoxH18 _agcEnaCheckbox;
		GERectangle _background;
		std::unique_ptr<IUIControl> _subGroup;

		// methods
		void OnAGCEnabled(ICheckBox *);
		void OnAGCDisabled(ICheckBox *);
	};
}

#endif // GUI_AUDIO_INPUT_LEVELS_SCREEN_HPP