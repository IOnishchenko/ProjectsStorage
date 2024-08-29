#ifndef GUI_AUDIO_OUTPUT_SCREEN_HPP
#define GUI_AUDIO_OUTPUT_SCREEN_HPP

#include "OGTabControl2T.hpp"
#include "Group.hpp"
#include "Command.hpp"
#include <memory>

namespace gui
{
	class AudioOutputView : public OGTabControl2T
	{
	public:
		// constructor
		AudioOutputView(const IUIContext & context);

		// destructor
		~AudioOutputView() override = default;

	private:
		// commands
		Command<AudioOutputView, IRadioButton *> _onLevelsButtonClikedCmd;
		Command<AudioOutputView, IRadioButton *> _onEqulizerButtonClikedCmd;

		// fields
		std::unique_ptr<IUIControl> _subGroup;

		// methods
		void OnLevelsButtonClicked(IRadioButton *);
		void OnEqulazerButtonClicked(IRadioButton *);
	};
}

#endif // GUI_AUDIO_OUTPUT_SCREEN_HPP