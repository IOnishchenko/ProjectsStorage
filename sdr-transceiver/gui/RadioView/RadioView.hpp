#ifndef GUI_RADIO_VIEW_HPP
#define GUI_RADIO_VIEW_HPP

#include "OGTabControl2T.hpp"
#include "IUIContext.hpp"
#include "Command.hpp"
#include <memory>

namespace gui
{
	class RadioView : public OGTabControl2T
	{
	public:
		// constructor
		RadioView(const IUIContext & context);

		// destructor
		~RadioView() override = default;

	private:
		// commands
		Command<RadioView, IRadioButton *> _onRxButtonClikedCmd;
		Command<RadioView, IRadioButton *> _onTxButtonClikedCmd;

		// fields
		std::unique_ptr<IUIControl> _subGroup;

		// methods
		void OnRxButtonClicked(IRadioButton *);
		void OnTxButtonClicked(IRadioButton *);
	};
}

#endif // GUI_RADIO_VIEW_HPP