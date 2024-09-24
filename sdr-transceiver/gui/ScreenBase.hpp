#ifndef GUI_SCREEN_BASE_HPP
#define GUI_SCREEN_BASE_HPP

#include "Group.hpp"
#include "Command.hpp"
#include "OGRadioButton64x24.hpp"
#include "IRadioButtonGroup.hpp"
#include <memory>

namespace gui
{
	class ScreenBase : public Group
	{
	public:
		// constructor
		ScreenBase(const IUIContext & context);

		// destrictor
		~ScreenBase() override;

	private:
		// commands
		Command<ScreenBase, IRadioButton *> _onMainButtonClikedCmd;
		Command<ScreenBase, IRadioButton *> _onRadioButtonClikedCmd;
		Command<ScreenBase, IRadioButton *> _onAudioButtonClikedCmd;
		Command<ScreenBase, IRadioButton *> _onDSPButtonClikedCmd;
		Command<ScreenBase, IRadioButton *> _onSettingsButtonClikedCmd;

		OGRadioButton64x24 _mainButton;
		OGRadioButton64x24 _radioButton;
		OGRadioButton64x24 _audioButton;
		OGRadioButton64x24 _dspButton;
		OGRadioButton64x24 _settingsButton;
		IRadioButtonGroup _mainRBGroup;

		// methods
		void OnMainButtonClicked(IRadioButton *);
		void OnRadioButtonClicked(IRadioButton *);
		void OnAudioButtonClicked(IRadioButton *);
		void OnDSPButtonClicked(IRadioButton *);
		void OnSettingsButtonClicked(IRadioButton *);
	};
}

#endif // GUI_SCREEN_BASE_HPP