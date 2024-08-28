#include "IFocusManager.hpp"

namespace gui
{
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	// IFocusManager::IFocusManager()
	// {
	// }

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void IFocusManager::RegisterHandler(uint16_t focusIndex, IFocusEventHandler * subscriber)
	{
		if(_first)
		{
			// find position
			uint32_t index = 0;
			auto * itm = _first;

			do
			{
				if(index < focusIndex)
				{
					itm = itm->Next;
					index++;
				}
				else
				{
					if(itm == _first)
						_first = subscriber;

					itm->Previous->Next = subscriber;
					subscriber->Previous = itm->Previous;
					subscriber->Next = itm;
					itm->Previous = subscriber;
					break;
				}
			}
			while(itm != _first);

			if(itm == _first)
			{
				// focus index was not find
				// add to the end
				itm->Previous->Next = subscriber;
				subscriber->Previous = itm->Previous;
				subscriber->Next = itm;
				itm->Previous = subscriber;
			}
		}
		else
		{
			_first = subscriber;
			_first->Next = subscriber;
			_first->Previous = subscriber;
		}
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void IFocusManager::UnregisterHandler(IFocusEventHandler * subscriber)
	{
		// find 
		auto * itm = _first;
		do
		{
			if(itm == subscriber)
			{
				if(_focused == itm)
					_focused = nullptr;

				auto * prev = itm->Previous;
				auto * next = itm->Next;
				if(itm == _first)
				{
					if(itm == next)
					{
						_first = nullptr;
						return;
					}
					else
						_first = next;
				}

				prev->Next = next;
				next->Previous = prev;
				return;
			}

			itm = itm->Next;
		}
		while(itm != _first);
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	bool IFocusManager::HasHandlers()
	{
		return (_first != nullptr);
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	bool IFocusManager::HasFocused()
	{
		return (_focused != nullptr);
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void IFocusManager::OnEncoderMoved(EncoderEvent & event)
	{
		if(_focused)
		{
			_focused->OnFocusLost();
			do
			{
				if(event.Direction == EncoderDirection::ENC_DECREASE)
					_focused = _focused->Next;
				else
					_focused = _focused->Previous;
			}
			while(!_focused->OnFocused());
		}
		else
		{
			if(_first)
			{
				_focused = _first;
				_focused->OnFocused();
			}
		}
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void IFocusManager::OnKeyPress(KeyEvent & event)
	{
		// TODO
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void IFocusManager::OnKeyRelease(KeyEvent & event)
	{
		// TODO
	}
}