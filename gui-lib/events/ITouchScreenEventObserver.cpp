#include "ITouchScreenEventObserver.hpp"

namespace gui
{
	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	void ITouchScreenEventObserver::HandleTouchScreenEvent(TouchScreenEven event)
	{
		switch(event.Type)
		{
			case TouchScreenEventType::Pressed:
				OnPressed(event);
				break;
			case TouchScreenEventType::Released:
				OnReleased(event);
				break;
			case TouchScreenEventType::Moved:
				OnMoved(event);
				break;
		}
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	inline void ITouchScreenEventObserver::OnPressed(TouchScreenEven & event)
	{
		for(auto itm : _subscribers)
		{
			if(itm->IsUnderTouch(event.x, event.y))
			{
				_activeHandler = itm;
				itm->OnPress(event);
				break;
			}
		}
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	inline void ITouchScreenEventObserver::OnReleased(TouchScreenEven & event)
	{
		if(_activeHandler)
		{
			_activeHandler->OnRelease(event);
			_activeHandler = nullptr;
		}
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	inline void ITouchScreenEventObserver::OnMoved(TouchScreenEven & event)
	{
		if(_activeHandler)
		{
			if(_activeHandler->IsUnderTouch(event.x, event.y))
				_activeHandler->OnPenMove(event);
			else
			{
				_activeHandler->OnPenLeave(event);
				_activeHandler = nullptr;
			}
		}
		else
		{
			for(auto itm : _subscribers)
			{
				if(itm->IsUnderTouch(event.x, event.y))
				{
					_activeHandler = itm;
					itm->OnPenEnter(event);
					break;
				}
			}
		}
	}
}
