#ifndef GUI_TRANSMITTER_SETTINGS_VIEW_HPP
#define GUI_TRANSMITTER_SETTINGS_VIEW_HPP

#include "Group.hpp"
#include "GERectangle.hpp"
#include "Command.hpp"
#include "SliderWithHeader.hpp"

namespace gui
{
	class TransmitterSettingsView : public Group
	{
	public:
		// constructor
		TransmitterSettingsView(const IUIContext & context);

		// destructor
		~TransmitterSettingsView() override;

	private:
		// commands
		Command<TransmitterSettingsView, int> _onPowerChangedCmd;

		// fields
		custom::SliderWithHeader _powerSlider;
		GERectangle _background;

		// methods
		void OnPowerChanged(int value);
	};
}

#endif // GUI_TRANSMITTER_SETTINGS_VIEW_HPP