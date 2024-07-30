#include "MainScreen.hpp"

namespace gui
{

extern IUIContext ColorScreen;

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
MainScreen::MainScreen()
	:Group(0, 0, 320, 240, ColorScreen, {}, &_background),
	_background(0, 0, 320, 240, 0xDEBA, nullptr)
{
}

}