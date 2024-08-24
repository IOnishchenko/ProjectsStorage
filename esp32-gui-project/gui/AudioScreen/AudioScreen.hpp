#ifndef GUI_AUDIO_SCREEN_HPP
#define GUI_AUDIO_SCREEN_HPP

#include "OGTabControl2T.hpp"
#include "IUIContext.hpp"
#include "Command.hpp"
#include <memory>

namespace gui
{
	class AudioScreen : public OGTabControl2T
	{
	public:
		// constructor
		AudioScreen(const IUIContext & context);

		// destructor
		~AudioScreen() override = default;

	private:
		// commands
		Command<AudioScreen, IRadioButton *> _onOutputButtonClikedCmd;
		Command<AudioScreen, IRadioButton *> _onInputButtonClikedCmd;

		// fields
		std::unique_ptr<IUIControl> _subGroup;

		// methods
		void OnOutputButtonClicked(IRadioButton *);
		void OnInputButtonClicked(IRadioButton *);
	};
}

#endif // GUI_AUDIO_SCREEN_HPP