#ifndef GUI_RECEIVER_VIEW_HPP
#define GUI_RECEIVER_VIEW_HPP

#include "Group.hpp"
#include "GERectangle.hpp"
#include "SliderWithHeader.hpp"
#include "Command.hpp"

namespace gui
{
	class ReceiverView : public Group
	{
	public:
		// constructor
		ReceiverView(const IUIContext & context);

		// destructor
		~ReceiverView() override;

	private:
		// commands
		Command<ReceiverView, int> _onAttGainCmd;
		Command<ReceiverView, int> _onAnalogGainCmd;
		Command<ReceiverView, int> _onDigitalGainCmd;

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

#endif // GUI_RECEIVER_VIEW_HPP