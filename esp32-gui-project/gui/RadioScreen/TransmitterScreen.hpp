#ifndef GUI_TRANSMITTER_SCREEN_HPP
#define GUI_TRANSMITTER_SCREEN_HPP

#include "Group.hpp"
#include "GERectangle.hpp"

namespace gui
{
	class TransmitterScreen : public Group
	{
	public:
		// constructor
		TransmitterScreen(const IUIContext & context);

		// destructor
		~TransmitterScreen() override = default;

	private:
		GERectangle _background;
	};
}

#endif // GUI_TRANSMITTER_SCREEN_HPP