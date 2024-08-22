#ifndef GUI_MAIN_SCREEN_HPP
#define GUI_MAIN_SCREEN_HPP

#include "Group.hpp"
#include "Command.hpp"
#include "GERectangle.hpp"
#include "GEPicture.hpp"
#include "OGRadioButton64x24.hpp"
#include "IRadioButtonGroup.hpp"
#include "OGButton100x22.hpp"
#include "OGNumericUpDown.hpp"

namespace gui
{
	class MainScreen : public Group
	{
	public:
		// constructor
		MainScreen(const IUIContext & context);

		// destructor
		~MainScreen() override;

	private:
		// fields
		uint32_t _frequency = 14130000u;

		Command<MainScreen, IButton *> _onButton0ClickedCmd;
		Command<MainScreen, IButton *> _onButton1ClickedCmd;
		Command<MainScreen, IButton *> _onButton2ClickedCmd;
		Command<MainScreen, IButton *> _onButton3ClickedCmd;

		Command<MainScreen, const NumericUpDown::Parameters &> _onFrequencyChangedCmd;

		OGButton100x22 _button0;
		OGButton100x22 _button1;
		OGButton100x22 _button2;
		OGButton100x22 _button3;

		OGNumericUpDown _frequencyLabel;

		// methods
		void OnButton0Clicked(IButton *);
		void OnButton1Clicked(IButton *);
		void OnButton2Clicked(IButton *);
		void OnButton3Clicked(IButton *);

		void OnFrequencyChanged(const NumericUpDown::Parameters & params);
	};
}

#endif // GUI_MAIN_SCREEN_HPP