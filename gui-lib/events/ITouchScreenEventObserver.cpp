#include "ITouchScreenEventObserver.hpp"

namespace gui
{
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	ITouchScreenEventObserver::ITouchScreenEventObserver(AsyncCommandDispatcher & asyncDispatcher)
		:HandleTouchPanelEventCmd(this, &ITouchScreenEventObserver::HandleTouchPanelEvent,
		asyncDispatcher, &ITouchScreenEventObserver::HasSubscribers)
	{}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void ITouchScreenEventObserver::HandleTouchPanelEvent(TouchScreenEven event)
	{

	}
}