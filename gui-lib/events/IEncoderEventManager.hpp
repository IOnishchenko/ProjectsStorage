#ifndef GUI_ITOUCH_SCREEN_EVENT_MANAGER_HPP
#define GUI_ITOUCH_SCREEN_EVENT_MANAGER_HPP

#include "AsyncCommand.hpp"
#include "AsyncCommandDispatcher.hpp"
#include "UIEvents.hpp"
#include "IEncoderEventHandler.hpp"

namespace gui
{
	class IEncoderEventManager
	{
	public:
		// constructor
		IEncoderEventManager(IEncoderEventHandler * defaultHandler,
			AsyncCommandDispatcher & dispatcher);

		// destructor
		virtual ~IEncoderEventManager() = default;

		// methods
		void RegisterHandler(IEncoderEventHandler * subscriber);
		void UnregisterHandler(IEncoderEventHandler * subscriber);

		// async method
		AsyncCommand<IEncoderEventManager, EncoderEvent> HandleEncoderEventAsync;

	private:
		// field
		IEncoderEventHandler * _defaultHandler;
		IEncoderEventHandler * _activeHandler = nullptr;

		// method
		void HandleEncoderEvent(EncoderEvent event);
	};
}

#endif // GUI_ITOUCH_SCREEN_EVENT_OBSERVER_HPP