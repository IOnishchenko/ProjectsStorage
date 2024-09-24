#ifndef GUI_DIALOG_SET_RECEIVER_AGC_DIALOG_HPP
#define GUI_DIALOG_SET_RECEIVER_AGC_DIALOG_HPP

#include "SliderDialog.hpp"
#include "Command.hpp"
namespace gui
{
	class SetReceiverAGCDialog : public SliderDialog
	{
	public:
		// constructor
		SetReceiverAGCDialog(const IUIContext & context);

		// destructor
		~SetReceiverAGCDialog() override = default;

	private:
		// commands
		Command<SetReceiverAGCDialog, int> _onAGCChangedCmd;

		// methods
		void OnAGCChanged(int value);
	};
}

#endif // GUI_DIALOG_SET_RECEIVER_AGC_DIALOG_HPP