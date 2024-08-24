#ifndef GUI_RADIO_SCREEN_HPP
#define GUI_RADIO_SCREEN_HPP

#include "OGTabControl2T.hpp"
#include "IUIContext.hpp"
#include "Command.hpp"
#include <memory>

namespace gui
{
	class RadioScreen : public OGTabControl2T
	{
	public:
		// constructor
		RadioScreen(const IUIContext & context);

		// destructor
		~RadioScreen() override = default;

	private:
		// commands
		Command<RadioScreen, IRadioButton *> _onRxButtonClikedCmd;
		Command<RadioScreen, IRadioButton *> _onTxButtonClikedCmd;

		// fields
		std::unique_ptr<IUIControl> _subGroup;

		// methods
		void OnRxButtonClicked(IRadioButton *);
		void OnTxButtonClicked(IRadioButton *);
	};
}

#endif // GUI_RADIO_SCREEN_HPP