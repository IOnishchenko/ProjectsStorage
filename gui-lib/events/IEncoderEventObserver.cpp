#include "IEncoderEventObserver.hpp"

namespace gui
{
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	IEncoderEventObserver::IEncoderEventObserver(AsyncCommandDispatcher & asyncDispatcher)
		:HandleEncoderEventCmd(this, &IEncoderEventObserver::HandleEncoderEvent,
		asyncDispatcher, &IEncoderEventObserver::HasSubscribers)
	{}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void IEncoderEventObserver::HandleEncoderEvent(EncoderEvent event)
	{

	}
}