#ifndef ASYNC_CALL_MESSAGE_HPP
#define ASYNC_CALL_MESSAGE_HPP

#include "Action.hpp"

/*--------------------------------------------------------------------------//
// 
//--------------------------------------------------------------------------*/
template<typename TParam>
struct AsyncCallMessage : public Action<void()>
{
	// constructors
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	AsyncCallMessage() = delete;

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	AsyncCallMessage(const Action<void(TParam)> & action, TParam param)
		:_action(action), _parameter(param)
	{
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	AsyncCallMessage(const AsyncCallMessage & item)
		:_action{item._action}, _parameter{item._parameter}
	{
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	AsyncCallMessage(AsyncCallMessage && item)
		:_action{item._action}, _parameter{item._parameter}
	{
		item._action = nullptr;
		item._parameter = nullptr;
	}

	// destructor
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	virtual ~AsyncCallMessage() = default;
	
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	AsyncCallMessage & operator=(const AsyncCallMessage & item)
	{
		_action = item._action;
		_parameter = item._parameter;
		return *this;
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	AsyncCallMessage & operator=(AsyncCallMessage && item)
	{
		_action = item._action;
		item._action = nullptr;
		_parameter = item._parameter;
		return *this;
	}
	
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void operator()() const override
	{
		_action(_parameter);
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void TryExecute() const override
	{
		_action.TryExecute(_parameter);
	}

private:
	const Action<void(TParam)> & _action;
	TParam _parameter;
};

#endif // ASYNC_CALL_MESSAGE_HPP