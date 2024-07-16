#ifndef COMMAND_HPP
#define COMMAND_HPP

#include "Action.hpp"

/*--------------------------------------------------------------------------//
// 
//--------------------------------------------------------------------------*/
template<typename TClss, typename... TParam>
struct Command : public Action<void(TParam...)>
{
	// constructors
	Command() = delete;

	// destructor
	~Command() override = default;
	
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	Command(TClss * clss, void(TClss::*func)(TParam...))
		:_class(clss), _action(func)
	{
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	Command(TClss * clss, void(TClss::*func)(TParam...) const)
		:_class(clss), _action(reinterpret_cast<void(TClss::*)(TParam...)>(func))
	{
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	Command(const Command & item)
	{
		_action = item._action;
		_class = item._class;
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	Command(Command && item)
	{
		_action = item._action;
		item._action = nullptr;
		_class = item._class;
		item._class = nullptr;
	}
	
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	Command & operator=(Command && item)
	{
		_action = item._action;
		_class = item._class;
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	Command & operator=(const Command & item)
	{
		_action = item._action;
		_class = item._class;
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void operator()(TParam... param) const override
	{
		(_class->*_action)(param...);
	}

	/*--------------------------------------------------------------------------//
	// it is for async command to implement unbloking call for calling from ISR
	//--------------------------------------------------------------------------*/
	void TryExecute(TParam... param) const override
	{
		(_class->*_action)(param...);
	}

private:
	TClss * _class;
	void(TClss::*_action)(TParam...);
};

#endif // COMMAND_HPP
