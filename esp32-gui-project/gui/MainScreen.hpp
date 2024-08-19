#ifndef GUI_MAIN_SCREEN_HPP
#define GUI_MAIN_SCREEN_HPP

#include "Group.hpp"
#include "Command.hpp"
#include "GERectangle.hpp"
#include "GEPicture.hpp"
#include "OGButton64x24.hpp"

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
		Command<MainScreen, IButton *> _onMainButtonClikedCmd;
		Command<MainScreen, IButton *> _onRadioButtonClikedCmd;
		Command<MainScreen, IButton *> _onAudioButtonClikedCmd;
		Command<MainScreen, IButton *> _onDSPButtonClikedCmd;
		Command<MainScreen, IButton *> _onSettingsButtonClikedCmd;

		OGButton64x24 _mainButton;
		OGButton64x24 _radioButton;
		OGButton64x24 _audioButton;
		OGButton64x24 _dspButton;
		OGButton64x24 _settingsButton;

		//GERectangle _background;
		GEPicture _picture;

		// methods
		void OnMainButtonClicked(IButton *);
		void OnRadioButtonClicked(IButton *);
		void OnAudioButtonClicked(IButton *);
		void OnDSPButtonClicked(IButton *);
		void OnSettingsButtonClicked(IButton *);
	};
}

#endif // GUI_MAIN_SCREEN_HPP