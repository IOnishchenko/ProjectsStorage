#ifndef GUI_MAIN_SCREEN_HPP
#define GUI_MAIN_SCREEN_HPP

#include "Group.hpp"
#include "GERectangle.hpp"

namespace gui
{
	class MainScreen : public Group
	{
	public:
		// constructor
		MainScreen();

		// destructor
		~MainScreen() override = default;

	private:
		GERectangle _background;
	};
}

#endif // GUI_MAIN_SCREEN_HPP