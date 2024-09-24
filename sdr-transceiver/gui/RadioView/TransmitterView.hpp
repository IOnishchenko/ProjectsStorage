#ifndef GUI_TRANSMITTER_VIEW_HPP
#define GUI_TRANSMITTER_VIEW_HPP

#include "Group.hpp"
#include "GERectangle.hpp"
#include "Command.hpp"
#include "OGCheckBoxH18.hpp"
#include "OGHorizontalSliderLabel.hpp"
#include "TransmitterSettingsView.hpp"

namespace gui
{
	class TransmitterView : public Group
	{
	public:
		// constructor
		TransmitterView(const IUIContext & context);

		// destructor
		~TransmitterView() override;

	private:
		// commands
		Command<TransmitterView, ICheckBox *> _onAGCEnabledCmd;
		Command<TransmitterView, ICheckBox *> _onAGCDisabledCmd;

		// fields
		OGCheckBoxH18 _eneTXCheckbox;
		GERectangle _background;
		TransmitterSettingsView _settingsGroup;

		// methods
		void OnTXEnabled(ICheckBox *);
		void OnTXDisabled(ICheckBox *);
	};
}

#endif // GUI_TRANSMITTER_VIEW_HPP