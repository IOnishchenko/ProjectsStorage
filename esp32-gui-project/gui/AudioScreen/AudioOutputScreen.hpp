#ifndef GUI_AUDIO_OUTPUT_SCREEN_HPP
#define GUI_AUDIO_OUTPUT_SCREEN_HPP

#include "OGTabControl2T.hpp"
#include "Group.hpp"
#include "Command.hpp"
#include <memory>

namespace gui
{
	class AudioOutputScreen : public OGTabControl2T
	{
	public:
		// constructor
		AudioOutputScreen(const IUIContext & context);

		// destructor
		~AudioOutputScreen() override = default;

	private:
		// commands
		Command<AudioOutputScreen, IRadioButton *> _onLevelsButtonClikedCmd;
		Command<AudioOutputScreen, IRadioButton *> _onEqulizerButtonClikedCmd;

		// fields
		std::unique_ptr<IUIControl> _subGroup;

		// methods
		void OnLevelsButtonClicked(IRadioButton *);
		void OnEqulazerButtonClicked(IRadioButton *);
	};
}

#endif // GUI_AUDIO_OUTPUT_SCREEN_HPP