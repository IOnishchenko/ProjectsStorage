#include "IKeyboardEventObserver.hpp"

namespace gui
{
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	IKeyboardEventObserver::IKeyboardEventObserver(AsyncCommandDispatcher & asyncDispatcher)
		:HandleEventCmd(this, &IKeyboardEventObserver::HandleTouchPanelEvent,
		asyncDispatcher, &IKeyboardEventObserver::HasSubscribers)
	{}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void IKeyboardEventObserver::HandleTouchPanelEvent(KeyEvent event)
	{

	}
}