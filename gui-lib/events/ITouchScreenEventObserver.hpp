#ifndef GUI_ITOUCH_SCREEN_EVENT_OBSERVER_HPP
#define GUI_ITOUCH_SCREEN_EVENT_OBSERVER_HPP

#include "ISubscriberManager.hpp"
#include "ITouchScreenEventHandler.hpp"
#include "UIControlEvents.hpp"
#include "AsyncCommand.hpp"
#include "AsyncCommandDispatcher.hpp"

namespace gui
{
	class ITouchScreenEventObserver : public ISubscriberManager<ITouchScreenEventHandler>
	{
	public:
		// constructor
		ITouchScreenEventObserver(AsyncCommandDispatcher & asyncDispatcher);

		// destructor
		virtual ~ITouchScreenEventObserver() = default;

		// fields
		// called in another thread or interrupt handler
		AsyncCommand<ITouchScreenEventObserver, TouchScreenEven> HandleTouchPanelEventCmd;

	private:
		// methods
		void HandleTouchPanelEvent(TouchScreenEven event);
	};
}

#endif // GUI_ITOUCH_SCREEN_EVENT_OBSERVER_HPP