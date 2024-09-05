#ifndef GUI_ITOUCH_SCREEN_EVENT_MANAGER_HPP
#define GUI_ITOUCH_SCREEN_EVENT_MANAGER_HPP

#include "UIEvents.hpp"
#include "IEncoderEventHandler.hpp"

namespace gui
{
	class IEncoderEventManager
	{
	public:
		// constructor
		IEncoderEventManager(IEncoderEventHandler * defaultHandler);

		// destructor
		virtual ~IEncoderEventManager() = default;

		// methods
		void RegisterHandler(IEncoderEventHandler * subscriber);
		void UnregisterHandler(IEncoderEventHandler * subscriber);
		void HandleEncoderEvent(EncoderEvent event);

	protected:
		// field
		IEncoderEventHandler * _defaultHandler;
		IEncoderEventHandler * _activeHandler = nullptr;
	};
}

#endif // GUI_ITOUCH_SCREEN_EVENT_OBSERVER_HPP