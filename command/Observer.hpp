#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include "Action.hpp"

/*--------------------------------------------------------------------------//
// 
//--------------------------------------------------------------------------*/
template<typename TParam>
struct Observer
{
	// constructor
	Observer() : item(nullptr)
	{
	}

	// destructor
	virtual ~Observer() = default;

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void Subscribe(const Action<void(TParam)> * callback)
	{
		Object * obj = new Object(callback);
		obj->next = item;
		item = obj;
	}
	
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void Unsubscribe(const Action<void(TParam)> * callback)
	{
		Object * obj = item;
		Object ** prev = &item;
		while (obj)
		{
			if(obj->action == callback)
			{
				*prev = obj->next;
				delete obj;
				break;
			}
			prev = &obj->next;
			obj = obj->next;
		}
	}
	
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void Execute(TParam param)
	{
		Object * obj = item;
		while(obj)
		{
			(*obj->action)(param);
			obj = obj->next;
		}
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	bool CanExecute()
	{
		return (item != nullptr);
	}

private:
	struct Object
	{
		const Action<void(TParam)> * action;
		Object * next;

		Object(const Action<void(TParam)> * act)
			:action(act)
		{}
	};
	
	Object * item;
};

#endif // OBSERVER_HPP