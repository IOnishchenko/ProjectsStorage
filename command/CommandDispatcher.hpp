#ifndef COMMON_COMMAND_DISPATCHER_HPP
#define COMMON_COMMAND_DISPATCHER_HPP

#include "AsyncCallMessage.hpp"
#include "ICommandQueue.hpp"
#include <new>

/*--------------------------------------------------------------------------//
// 
//--------------------------------------------------------------------------*/
// HandleAsyncCall() and PushToQueue() must be called in the same thread
struct CommandDispatcher
{
	// constructors
	CommandDispatcher() = delete;
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	CommandDispatcher(ICommandQueue & queue)
		:_queue(queue)
	{
	}

	// destructor
	virtual ~CommandDispatcher() = default;
	
	// methods
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void HandleAsyncCall()
	{
		for(Action<void()>  * action = static_cast<Action<void()> *>(_queue.PullFront());
			action; action = static_cast<Action<void()> *>(_queue.PullFront()))
		{
			(*action)();
			action->~Action();
		}
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	template<typename TParam>
	bool PushToQueue(const Action<void(TParam)> & func, TParam param)
	{
		void * memory = _queue.AllocateItem();
		if(!memory)
			return false;

		new(memory) AsyncCallMessage<TParam>(func, param);
		return true;
	}

protected:
	ICommandQueue & _queue;
};

#endif // ASYNC_COMMAND_DISPATCHER_HPP