#include "Screen.hpp"

namespace gui
{
	/*--------------------------------------------------------------------------//
	// Constructor
	//--------------------------------------------------------------------------*/
	Screen::Screen(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
		IUIControl * dynamicContent, const std::forward_list<IUIControl *> & statisContent,
		IGElement * gelement)
		: Group(x, y, w, h, context, statisContent, gelement)
	{
		_content.push_front(dynamicContent);
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	Screen::Screen(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
		IUIControl * dynamicContent, const std::initializer_list<IUIControl *> & statisContent,
		IGElement * gelement)
		: Group(x, y, w, h, context, statisContent, gelement)
	{
		_content.push_front(dynamicContent);
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	Screen::Screen(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
		IUIControl * dynamicContent, IUIControl * statisContent, IGElement * gelement)
		: Group(x, y, w, h, context, {dynamicContent, statisContent}, gelement)
	{
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void Screen::SetScreen(IUIControl * cntr)
	{
		ReplaceDynamicUIControl(cntr);
		cntr->Draw();
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void Screen::ReplaceDynamicUIControl(IUIControl * screen)
	{
		_content.pop_front();
		_content.push_front(screen);
	}
}