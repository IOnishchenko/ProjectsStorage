#ifndef GUI_DIALOG_SET_VOLUME_DIALOG_HPP
#define GUI_DIALOG_SET_VOLUME_DIALOG_HPP

#include "SliderDialog.hpp"
#include "Command.hpp"
namespace gui
{
	class SetVolumeDialog : public SliderDialog
	{
	public:
		// constructor
		SetVolumeDialog(const IUIContext & context);

		// destructor
		~SetVolumeDialog() override = default;

	private:
		// commands
		Command<SetVolumeDialog, int> _onVolumeChangedCmd;

		// methods
		void OnVolumeChanged(int value);
	};
}

#endif // GUI_DIALOG_SET_VOLUME_DIALOG_HPP