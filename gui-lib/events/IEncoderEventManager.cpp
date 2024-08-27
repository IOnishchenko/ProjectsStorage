#include "IEncoderEventManager.hpp"

namespace gui
{
	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	IEncoderEventManager::IEncoderEventManager(IEncoderEventHandler * defaultHandler, AsyncCommandDispatcher & dispatcher)
		:HandleEncoderEventAsync(this, &IEncoderEventManager::HandleEncoderEvent, dispatcher),
		_defaultHandler{defaultHandler}, _activeHandler{defaultHandler}
	{
	}
	
	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	void IEncoderEventManager::RegisterHandler(IEncoderEventHandler * subscriber)
	{
		_activeHandler = subscriber;
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	void IEncoderEventManager::UnregisterHandler(IEncoderEventHandler * subscriber)
	{
		if(_activeHandler == subscriber)
			_activeHandler = _defaultHandler;
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	void IEncoderEventManager::HandleEncoderEvent(EncoderEvent event)
	{
		if(_activeHandler)
			_activeHandler->OnEncoderMoved(event);
	}
}