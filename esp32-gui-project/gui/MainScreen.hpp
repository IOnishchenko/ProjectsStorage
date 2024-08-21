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

		Command<MainScreen, IRadioButton *> _onMainButtonClikedCmd;
		Command<MainScreen, IRadioButton *> _onRadioButtonClikedCmd;
		Command<MainScreen, IRadioButton *> _onAudioButtonClikedCmd;
		Command<MainScreen, IRadioButton *> _onDSPButtonClikedCmd;
		Command<MainScreen, IRadioButton *> _onSettingsButtonClikedCmd;

		Command<MainScreen, const NumericUpDown::Parameters &> _onFrequencyChangedCmd;

		OGButton100x22 _button0;
		OGButton100x22 _button1;
		OGButton100x22 _button2;
		OGButton100x22 _button3;

		OGRadioButton64x24 _mainButton;
		OGRadioButton64x24 _radioButton;
		OGRadioButton64x24 _audioButton;
		OGRadioButton64x24 _dspButton;
		OGRadioButton64x24 _settingsButton;
		IRadioButtonGroup _mainRBGroup;

		OGNumericUpDown _frequencyLabel;

		//GERectangle _background;
		GEPicture _picture;

		// methods
		void OnButton0Clicked(IButton *);
		void OnButton1Clicked(IButton *);
		void OnButton2Clicked(IButton *);
		void OnButton3Clicked(IButton *);

		void OnMainButtonClicked(IRadioButton *);
		void OnRadioButtonClicked(IRadioButton *);
		void OnAudioButtonClicked(IRadioButton *);
		void OnDSPButtonClicked(IRadioButton *);
		void OnSettingsButtonClicked(IRadioButton *);

		void OnFrequencyChanged(const NumericUpDown::Parameters & params);
	};
}

#endif // GUI_MAIN_SCREEN_HPP