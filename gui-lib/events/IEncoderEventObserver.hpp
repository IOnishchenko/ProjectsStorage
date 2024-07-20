#ifndef GUI_ITOUCH_SCREEN_EVENT_OBSERVER_HPP
#define GUI_ITOUCH_SCREEN_EVENT_OBSERVER_HPP

#include "ISubscriberManager.hpp"
#include "IEncoderEventHandler.hpp"
#include "AsyncCommand.hpp"
#include "AsyncCommandDispatcher.hpp"

namespace gui
{
	class IEncoderEventObserver : public ISubscriberManager<IEncoderEventHandler>
	{
	public:
		// constructor
		IEncoderEventObserver(AsyncCommandDispatcher & asyncDispatcher);

		// destructor
		virtual ~IEncoderEventObserver() = default;

		// fields
		// called in another thread or interrupt handler
		AsyncCommand<IEncoderEventObserver, EncoderEvent> HandleEncoderEventCmd;

	private:
		// methods
		void HandleEncoderEvent(EncoderEvent event);
	};
}

#endif // GUI_ITOUCH_SCREEN_EVENT_OBSERVER_HPP