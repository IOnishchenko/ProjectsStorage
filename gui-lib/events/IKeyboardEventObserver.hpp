#ifndef GUI_IKEYBOARD_EVENT_OBSERVER_HPP
#define GUI_IKEYBOARD_EVENT_OBSERVER_HPP

#include "ISubscriberManager.hpp"
#include "IKeyboardEventHandler.hpp"
#include "UIControlEvents.hpp"
#include "AsyncCommand.hpp"
#include "AsyncCommandDispatcher.hpp"

namespace gui
{
	class IKeyboardEventObserver : public ISubscriberManager<IKeyboardEventHandler>
	{
	public:
		// constructor
		IKeyboardEventObserver(AsyncCommandDispatcher & asyncDispatcher);

		// destructor
		virtual ~IKeyboardEventObserver() = default;

		// fields
		// called in another thread or interrupt handler
		AsyncCommand<IKeyboardEventObserver, KeyEvent> HandleEventCmd;

	private:
		// methods
		void HandleTouchPanelEvent(KeyEvent event);
	};
}

#endif // GUI_IKEYBOARD_EVENT_OBSERVER_HPP