#ifndef GUI_IKEYBOARD_EVENT_MANAGER_HPP
#define GUI_IKEYBOARD_EVENT_MANAGER_HPP

#include "IKeyboardEventHandler.hpp"
#include "UIEvents.hpp"

namespace gui
{
	class IKeyboardEventManager
	{
	public:
		// constructor
		IKeyboardEventManager(IKeyboardEventHandler * defaultHandler);

		// destructor
		virtual ~IKeyboardEventManager() = default;

		// methods
		void RegisterHandler(IKeyboardEventHandler * handler);
		void UnregisterHandler(IKeyboardEventHandler * handler);
		void HandleKeyboardEvent(KeyEvent event);

	protected:
		// field
		IKeyboardEventHandler * _defaultHandler;
		IKeyboardEventHandler * _activeHandler = nullptr;
	};
}

#endif // GUI_IKEYBOARD_EVENT_OBSERVER_HPP