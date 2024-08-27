#include "IKeyboardEventManager.hpp"

namespace gui
{
	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	IKeyboardEventManager::IKeyboardEventManager(IKeyboardEventHandler * defaultHandler,
		AsyncCommandDispatcher & dispatcher)
		:HandleKeyboardEventAsync(this, &IKeyboardEventManager::HandleKeyboardEvent, dispatcher),
		_defaultHandler{defaultHandler}, _activeHandler{defaultHandler}
	{
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	void IKeyboardEventManager::RegisterHandler(IKeyboardEventHandler * handler)
	{
		_activeHandler = handler;
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	void IKeyboardEventManager::UnregisterHandler(IKeyboardEventHandler * handler)
	{
		if(_activeHandler == handler)
			_activeHandler = _defaultHandler;
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	void IKeyboardEventManager::HandleKeyboardEvent(KeyEvent event)
	{
		if(_activeHandler)
		{
			switch(event.Type)
			{
				case KeyEventType::Pressed:
					_activeHandler->OnKeyPress(event);
					break;
				case KeyEventType::LongPressed:
					_activeHandler->OnKeyLongPress(event);
					break;
				case KeyEventType::Released:
					_activeHandler->OnKeyRelease(event);
					break;
				default:
					return;
			}
		}
	}
}