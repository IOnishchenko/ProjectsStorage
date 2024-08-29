#ifndef GUI_RECEIVER_SCREEN_HPP
#define GUI_RECEIVER_SCREEN_HPP

#include "Group.hpp"
#include "GERectangle.hpp"
#include "SliderWithHeader.hpp"
#include "Command.hpp"

namespace gui
{
	class ReceiverScreen : public Group
	{
	public:
		// constructor
		ReceiverScreen(const IUIContext & context);

		// destructor
		~ReceiverScreen() override;

	private:
		// commands
		Command<ReceiverScreen, int> _onAttGainCmd;
		Command<ReceiverScreen, int> _onAnalogGainCmd;
		Command<ReceiverScreen, int> _onDigitalGainCmd;

		custom::SliderWithHeader _attGainSlider;
		custom::SliderWithHeader _analogGainSlider;
		custom::SliderWithHeader _digitalGainSlider;

		GERectangle _background;

		// methods
		void OnAttGainChanged(int value);
		void OnAgalogGainChanged(int value);
		void OnDigitalGainChanged(int value);
	};
}

#endif // GUI_RECEIVER_SCREEN_HPP