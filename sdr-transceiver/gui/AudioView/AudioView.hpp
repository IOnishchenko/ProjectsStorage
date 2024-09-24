#ifndef GUI_AUDIO_SCREEN_HPP
#define GUI_AUDIO_SCREEN_HPP

#include "OGTabControl2T.hpp"
#include "IUIContext.hpp"
#include "Command.hpp"
#include <memory>

namespace gui
{
	class AudioView : public OGTabControl2T
	{
	public:
		// constructor
		AudioView(const IUIContext & context);

		// destructor
		~AudioView() override = default;

	private:
		// commands
		Command<AudioView, IRadioButton *> _onOutputButtonClikedCmd;
		Command<AudioView, IRadioButton *> _onInputButtonClikedCmd;

		// fields
		std::unique_ptr<IUIControl> _subGroup;

		// methods
		void OnOutputButtonClicked(IRadioButton *);
		void OnInputButtonClicked(IRadioButton *);
	};
}

#endif // GUI_AUDIO_SCREEN_HPP