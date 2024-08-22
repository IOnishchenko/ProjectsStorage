#include "RadioScreen.hpp"
#include "OGCommon.hpp"

namespace gui
{
/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
RadioScreen::RadioScreen(const IUIContext & context)
	:Group(0, 0, 320, 240-24, context, &_background),
	_background(0, 0, 320, 240-24, BACKGROUND_DARK, nullptr)
{
}

}