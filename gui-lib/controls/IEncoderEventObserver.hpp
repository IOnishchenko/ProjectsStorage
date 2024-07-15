#ifndef GUI_ITOUCH_SCREEN_EVENT_OBSERVER_HPP
#define GUI_ITOUCH_SCREEN_EVENT_OBSERVER_HPP

#include "IEncoderEventHandler.hpp"
#include "AsyncCommand.hpp"
#include "AsyncCommandDispatcher.hpp"

namespace gui
{
	class IEncoderEventObserver
	{
	public:
		// constructor
		IEncoderEventObserver(AsyncCommandDispatcher & asyncDispatcher)

		// destructor
		virtual ~IEncoderEventObserver() = default;
		
		// methods
		void RegistrateHandler(IEncoderEventHandler * handler);
		void UnregistrateHandler(IEncoderEventHandler * handler);

		// fields
		// called in another thread or interrupt handler
		AsyncCommand<IEncoderEventObserver, EncoderEvent> HandleEncoderEventCmd;

	private:
		// methods
		void HandleEncoderEvent(EncoderEvent event);
		bool HasRegistratedHandlers();
	};
}

#endif // GUI_ITOUCH_SCREEN_EVENT_OBSERVER_HPP