#ifndef ASYNC_COMMAND_DISPATCHER_HPP
#define ASYNC_COMMAND_DISPATCHER_HPP

#include "AsyncCallMessage.hpp"
#include "AsyncCallQueue.hpp"
#include <new>

/*--------------------------------------------------------------------------//
// 
//--------------------------------------------------------------------------*/
struct AsyncCommandDispatcher
{
	// constructors
	AsyncCommandDispatcher() = delete;
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	AsyncCommandDispatcher(AsyncCallQueue & queue)
		:_queue(queue)
	{
	}

	// destructor
	virtual ~AsyncCommandDispatcher() = default;
	
	// methods
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void HandleAsyncCall()
	{
		Action<void()>  * action = static_cast<Action<void()> *>(_queue.PullFromQueue());
		(*action)();
		action->~Action();
		_queue.MemoryFree(action);
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	template<typename TParam>
	void InvokeAsAsync(const Action<void(TParam)> & func, TParam param)
	{
		void * memory = _queue.MemoryAllocate();
		AsyncCallMessage<TParam> * item = new(memory) AsyncCallMessage<TParam>(func, param);
		_queue.PushToQueue(item);
	}

	/*--------------------------------------------------------------------------//
	// not blocked call to call from ISR
	//--------------------------------------------------------------------------*/
	template<typename TParam>
	void TryInvokeAsAsync(const Action<void(TParam)> & func, TParam param)
	{
		void * memory = _queue.TryMemoryAllocate();
		if(memory)
		{
			AsyncCallMessage<TParam> * item = new(memory) AsyncCallMessage<TParam>(func, param);
			if(!_queue.TryPushToQueue(item))
				_queue.MemoryFree(memory);
		}
	}

protected:
	AsyncCallQueue & _queue;
};

#endif // ASYNC_COMMAND_DISPATCHER_HPP