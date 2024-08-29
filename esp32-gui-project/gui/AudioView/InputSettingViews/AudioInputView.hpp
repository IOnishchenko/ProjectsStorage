#ifndef GUI_AUDIO_INPUT_SCREEN_HPP
#define GUI_AUDIO_INPUT_SCREEN_HPP

#include "OGTabControl2T.hpp"
#include "Group.hpp"
#include "Command.hpp"
#include <memory>

namespace gui
{
	class AudioInputView : public OGTabControl2T
	{
	public:
		// constructor
		AudioInputView(const IUIContext & context);

		// destructor
		~AudioInputView() override = default;

	private:
		// commands
		Command<AudioInputView, IRadioButton *> _onLevelsButtonClikedCmd;
		Command<AudioInputView, IRadioButton *> _onEqulizerButtonClikedCmd;

		// fields
		std::unique_ptr<IUIControl> _subGroup;

		// methods
		void OnLevelsButtonClicked(IRadioButton *);
		void OnEqulazerButtonClicked(IRadioButton *);
	};
}

#endif // GUI_AUDIO_INPUT_SCREEN_HPP