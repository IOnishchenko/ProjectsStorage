#ifndef GUI_AUDIO_INPUT_SCREEN_HPP
#define GUI_AUDIO_INPUT_SCREEN_HPP

#include "OGTabControl2T.hpp"
#include "Group.hpp"
#include "Command.hpp"
#include <memory>

namespace gui
{
	class AudioInputScreen : public OGTabControl2T
	{
	public:
		// constructor
		AudioInputScreen(const IUIContext & context);

		// destructor
		~AudioInputScreen() override = default;

	private:
		// commands
		Command<AudioInputScreen, IRadioButton *> _onLevelsButtonClikedCmd;
		Command<AudioInputScreen, IRadioButton *> _onEqulizerButtonClikedCmd;

		// fields
		std::unique_ptr<IUIControl> _subGroup;

		// methods
		void OnLevelsButtonClicked(IRadioButton *);
		void OnEqulazerButtonClicked(IRadioButton *);
	};
}

#endif // GUI_AUDIO_INPUT_SCREEN_HPP