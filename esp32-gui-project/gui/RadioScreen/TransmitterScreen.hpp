#ifndef GUI_TRANSMITTER_SCREEN_HPP
#define GUI_TRANSMITTER_SCREEN_HPP

#include "Group.hpp"
#include "GERectangle.hpp"
#include "Command.hpp"
#include "OGCheckBoxH18.hpp"
#include "OGHorizontalSliderLabel.hpp"

namespace gui
{
	class TransmitterScreen : public Group
	{
	public:
		// constructor
		TransmitterScreen(const IUIContext & context);

		// destructor
		~TransmitterScreen() override;

	private:
		// commands
		Command<TransmitterScreen, ICheckBox *> _onAGCEnabledCmd;
		Command<TransmitterScreen, ICheckBox *> _onAGCDisabledCmd;
		Command<TransmitterScreen, int> _onPowerChangedCmd;

		// fields
		OGCheckBoxH18 _eneTXCheckbox;
		OGHorizontalSliderLabel _powerSlider;

		GEText _headerTxt0;
		GEText _headerTxt1;
		GERectangle _background;

		// methods
		void OnTXEnabled(ICheckBox *);
		void OnTXDisabled(ICheckBox *);
		void OnPowerChanged(int value);
	};
}

#endif // GUI_TRANSMITTER_SCREEN_HPP