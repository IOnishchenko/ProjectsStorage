#ifndef GUI_IKEYBOARD_EVENT_MANAGER_HPP
#define GUI_IKEYBOARD_EVENT_MANAGER_HPP

#include "IKeyboardEventHandler.hpp"
#include "AsyncCommand.hpp"
#include "UIEvents.hpp"

namespace gui
{
	class IKeyboardEventManager
	{
	public:
		// constructor
		IKeyboardEventManager(IKeyboardEventHandler * defaultHandler,
			AsyncCommandDispatcher & dispatcher);

		// destructor
		virtual ~IKeyboardEventManager() = default;

		// methods
		void RegisterHandler(IKeyboardEventHandler * handler);
		void UnregisterHandler(IKeyboardEventHandler * handler);

		// async method
		AsyncCommand<IKeyboardEventManager, KeyEvent> HandleKeyboardEventAsync;

	private:
		// field
		IKeyboardEventHandler * _defaultHandler;
		IKeyboardEventHandler * _activeHandler = nullptr;

		// metods
		void HandleKeyboardEvent(KeyEvent event);
	};
}

#endif // GUI_IKEYBOARD_EVENT_OBSERVER_HPP