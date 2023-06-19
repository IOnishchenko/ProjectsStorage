#pragma once

#include "Command.h"
#include "AsyncCommandDispatcher.h"

/*--------------------------------------------------------------------------//
// 
//--------------------------------------------------------------------------*/
template<typename TClss, typename TParam>
struct AsyncCommand : public Action<void(TParam)>
{
	// constructors
	AsyncCommand() = delete;

	// destructor
	~AsyncCommand() override = default;

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