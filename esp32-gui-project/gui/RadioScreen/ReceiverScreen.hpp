#ifndef GUI_RECEIVER_SCREEN_HPP
#define GUI_RECEIVER_SCREEN_HPP

#include "Group.hpp"
#include "GERectangle.hpp"
#include "OGHorizontalSliderLabel.hpp"
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

		OGHorizontalSliderLabel _attGainSlider;
		OGHorizontalSliderLabel _analogGainSlider;
		OGHorizontalSliderLabel _digitalGainSlider;

		GEText _headerTxt0;
		GEText _headerTxt1;
		GEText _headerTxt2;
		GEText _headerTxt3;
		GEText _headerTxt4;
		GEText _headerTxt5;
		GERectangle _background;

		// methods
		void OnAttGainChanged(int value);
		void OnAgalogGainChanged(int value);
		void OnDigitalGainChanged(int value);
	};
}

#endif // GUI_RECEIVER_SCREEN_HPP