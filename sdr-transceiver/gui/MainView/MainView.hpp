#ifndef GUI_MAIN_VIEW_HPP
#define GUI_MAIN_VIEW_HPP

#include "Group.hpp"
#include "Command.hpp"
#include "GERectangle.hpp"
#include "GEPicture.hpp"
#include "OGRadioButton64x24.hpp"
#include "IRadioButtonGroup.hpp"
#include "OGButton100x22.hpp"
#include "OGNumericUpDown.hpp"
#include "SpectrumView.hpp"
#include "configuration.h"

namespace gui
{
	class MainView : public Group
	{
	public:
		// constructor
		MainView(const IUIContext & context);

		// destructor
		~MainView() override;

	private:
		// fields
		uint32_t _frequency = 14130000u;

		Command<MainView, IButton *> _onButton0ClickedCmd;
		Command<MainView, IButton *> _onButton1ClickedCmd;
		Command<MainView, IButton *> _onButton2ClickedCmd;
		Command<MainView, IButton *> _onButton3ClickedCmd;

		Command<MainView, const NumericUpDown::Parameters &> _onFrequencyChangedCmd;

		OGButton100x22 _button0;
		OGButton100x22 _button1;
		OGButton100x22 _button2;
		OGButton100x22 _button3;

		OGNumericUpDown _frequencyLabel;

		SpectrumView<color_t> _spectrum;

		GEPicture _background;

		// methods
		void OnButton0Clicked(IButton *);
		void OnButton1Clicked(IButton *);
		void OnButton2Clicked(IButton *);
		void OnButton3Clicked(IButton *);

		void OnFrequencyChanged(const NumericUpDown::Parameters & params);
	};
}

#endif // GUI_MAIN_SCREEN_HPP