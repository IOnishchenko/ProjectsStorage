#ifndef GUI_RADIO_SCREEN_HPP
#define GUI_RADIO_SCREEN_HPP

#include "Group.hpp"
#include "Command.hpp"
#include "OGRadioButton64x24.hpp"
#include "IRadioButtonGroup.hpp"
#include <memory>

#include "GERectangle.hpp"

namespace gui
{
	class RadioScreen : public Group
	{
	public:
		// constructor
		RadioScreen(const IUIContext & context);

		// destructor
		~RadioScreen() override = default;

	private:
		GERectangle _background;
	};
}

#endif // GUI_RADIO_SCREEN_HPP