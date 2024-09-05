#ifndef GUI_ITOUCH_SCREEN_EVENT_OBSERVER_HPP
#define GUI_ITOUCH_SCREEN_EVENT_OBSERVER_HPP

#include "ISubscribersManager.hpp"
#include "ITouchScreenEventHandler.hpp"

namespace gui
{
	class ITouchScreenEventObserver : public ISubscribersManager<ITouchScreenEventHandler>
	{
	public:
		// constructor
		// ITouchScreenEventObserver();

		// destructor
		~ITouchScreenEventObserver() override = default;

		// methods
		void HandleTouchScreenEvent(TouchScreenEven event);

	private:
		// fields
		ITouchScreenEventHandler * _activeHandler = nullptr;

		// methods
		void OnPressed(TouchScreenEven & event);
		void OnReleased(TouchScreenEven & event);
		void OnMoved(TouchScreenEven & event);
	};
}

#endif // GUI_ITOUCH_SCREEN_EVENT_OBSERVER_HPP