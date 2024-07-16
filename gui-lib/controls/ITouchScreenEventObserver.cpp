#include "ITouchScreenEventObserver.hpp"

namespace gui
{
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	ITouchScreenEventObserver::ITouchScreenEventObserver(AsyncCommandDispatcher & asyncDispatcher)
		:HandleTouchPanelEventCmd(this, &ITouchScreenEventObserver::HandleTouchPanelEvent,
		asyncDispatcher, &ITouchScreenEventObserver::HasRegistratedHandlers)
	{}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void ITouchScreenEventObserver::HandleTouchPanelEvent(TouchScreenEven event)
	{

	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	bool ITouchScreenEventObserver::HasRegistratedHandlers()
	{
		return true;
	}
}