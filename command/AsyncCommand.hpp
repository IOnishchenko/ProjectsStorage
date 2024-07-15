#ifndef ASYNC_COMMAND_HPP
#define ASYNC_COMMAND_HPP

#include "Command.hpp"
#include "AsyncCommandDispatcher.hpp"

/*--------------------------------------------------------------------------//
// 
//--------------------------------------------------------------------------*/
template<typename TClss, typename TParam>
struct AsyncCommand : public Action<void(TParam)>
{
	// constructors
	AsyncCommand() = delete;

	

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	AsyncCommand(TClss * clss, void(TClss::*func)(TParam), AsyncCommandDispatcher & handler)
		:_command(clss, func), _hendler(handler), _predicate{nullptr}, _class{nullptr}
	{
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	AsyncCommand(TClss * clss, void(TClss::*func)(TParam),
		AsyncCommandDispatcher & handler, bool (TClss::*pred)(void))
		:_command(clss, func), _hendler(handler), _predicate{pred}, _class{clss}
	{
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	AsyncCommand(TClss * clss, void(TClss::*func)(TParam) const, AsyncCommandDispatcher & handler)
		:_command(clss, func), _hendler(handler), _predicate{nullptr}, _class{nullptr}
	{
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	AsyncCommand(TClss * clss, void(TClss::*func)(TParam) const,
		AsyncCommandDispatcher & handler, bool (TClss::*pred)(void))
		:_command(clss, func), _hendler(handler), _predicate{pred}, _class{clss}
	{
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	AsyncCommand(const AsyncCommand & item)
		:_command(item)
	{
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	AsyncCommand(AsyncCommand && item)
		:_command(item)
	{
	}

	// destructor
	~AsyncCommand() override = default;
	
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void operator()(TParam param) const override
	{
		if((_class == nullptr) || (_class->*_predicate)())
			_hendler.InvokeAsAsync(_command, param);
	}

	/*--------------------------------------------------------------------------//
	// not blocked method to call from ISR
	//--------------------------------------------------------------------------*/
	void TryExecute(TParam param) const override
	{
		if((_class == nullptr) || (_class->*_predicate)())
			_hendler.TryInvokeAsAsync(_command, param);
	}

protected:
	Command<TClss, TParam> _command;
	AsyncCommandDispatcher & _hendler;
	bool (TClss::*_predicate)(void);
	TClss * _class;
};

#endif // ASYNC_COMMAND_HPP