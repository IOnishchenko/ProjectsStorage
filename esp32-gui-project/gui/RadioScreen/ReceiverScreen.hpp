#ifndef GUI_RECEIVER_SCREEN_HPP
#define GUI_RECEIVER_SCREEN_HPP

#include "Group.hpp"
#include "GERectangle.hpp"

namespace gui
{
	class ReceiverScreen : public Group
	{
	public:
		// constructor
		ReceiverScreen(const IUIContext & context);

		// destructor
		~ReceiverScreen() override = default;

	private:
		GERectangle _background;
	};
}

#endif // GUI_RECEIVER_SCREEN_HPP