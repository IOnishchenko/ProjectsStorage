#include "Screen.hpp"

namespace gui
{
	/*--------------------------------------------------------------------------//
	// Constructor
	//--------------------------------------------------------------------------*/
	Screen::Screen(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
		Group * dynamicContent, const std::initializer_list<IUIControl *> & statisContent,
		IGElement * gelement)
		: Group(x, y, w, h, context, statisContent, gelement)
	{
		Controls.push_front(dynamicContent);
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	Screen::Screen(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
		Group * dynamicContent, IUIControl * statisContent, IGElement * gelement)
		: Group(x, y, w, h, context, {dynamicContent, statisContent}, gelement)
	{
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void Screen::SetSubGroup(Group * cntr)
	{
		ReplaceSubGroup(cntr);
		cntr->Draw();
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void Screen::ReplaceSubGroup(Group * screen)
	{
		Controls.pop_front();
		Controls.push_front(screen);
	}
}