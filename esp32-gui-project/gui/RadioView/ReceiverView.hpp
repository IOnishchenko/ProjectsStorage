#ifndef GUI_RECEIVER_VIEW_HPP
#define GUI_RECEIVER_VIEW_HPP

#include "Group.hpp"
#include "GERectangle.hpp"
#include "SliderWithHeader.hpp"
#include "OGCheckBoxH18.hpp"
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
		Command<ReceiverView, ICheckBox*> _onAmpEnabledCmd;
		Command<ReceiverView, ICheckBox*> _onAmpDisabledCmd;

		custom::SliderWithHeader _attGainSlider;
		custom::SliderWithHeader _analogGainSlider;
		custom::SliderWithHeader _digitalGainSlider;
		OGCheckBoxH18 _ampEnableCheckBox;

		GERectangle _background;

		// methods
		void OnAttGainChanged(int value);
		void OnAgalogGainChanged(int value);
		void OnDigitalGainChanged(int value);
		void OnAmpEnabled(ICheckBox *);
		void OnAmpDisabled(ICheckBox *);
	};
}

#endif // GUI_RECEIVER_VIEW_HPP