#ifndef ACTION_H
#define ACTION_H

/*--------------------------------------------------------------------------//
// 
//--------------------------------------------------------------------------*/
template<typename>
struct Action;
/*--------------------------------------------------------------------------//
// 
//--------------------------------------------------------------------------*/
template<typename... TParam>
struct Action<void(TParam...)>
{
	// destructor
	virtual ~Action() = default;
	
	// operator
	virtual void operator()(TParam...) const = 0;
	// it is not blocking call to call from ISR
	virtual void TryExecute(TParam...) const = 0;
};

#endif // ACTION_H

