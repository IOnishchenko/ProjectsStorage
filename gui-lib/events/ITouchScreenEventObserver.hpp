#ifndef GUI_ITOUCH_SCREEN_EVENT_OBSERVER_HPP
#define GUI_ITOUCH_SCREEN_EVENT_OBSERVER_HPP

#include "ISubscribersManager.hpp"
#include "ITouchScreenEventHandler.hpp"
#include "AsyncCommandDispatcher.hpp"
#include "AsyncCommand.hpp"

namespace gui
{
	class ITouchScreenEventObserver : public ISubscribersManager<ITouchScreenEventHandler>
	{
	public:
		// constructor
		ITouchScreenEventObserver(AsyncCommandDispatcher & dispatcher);

		// destructor
		~ITouchScreenEventObserver() override = default;

		// async method
		AsyncCommand<ITouchScreenEventObserver, TouchScreenEven> HandleTouchScreenEventAsync;

	private:
		// fields
		ITouchScreenEventHandler * _activeHandler = nullptr;

		// methods
		void HandleTouchScreenEvent(TouchScreenEven event);
		void OnPressed(TouchScreenEven & event);
		void OnReleased(TouchScreenEven & event);
		void OnMoved(TouchScreenEven & event);
	};
}

#endif // GUI_ITOUCH_SCREEN_EVENT_OBSERVER_HPP