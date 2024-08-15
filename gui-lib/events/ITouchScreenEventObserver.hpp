#ifndef GUI_ITOUCH_SCREEN_EVENT_OBSERVER_HPP
#define GUI_ITOUCH_SCREEN_EVENT_OBSERVER_HPP

#include "ISubscribersManager.hpp"
#include "ITouchScreenEventHandler.hpp"

namespace gui
{
	class ITouchScreenEventObserver : public ISubscribersManager<ITouchScreenEventHandler>
	{
	public:
		// destructor
		~ITouchScreenEventObserver() override = default;
	};
}

#endif // GUI_ITOUCH_SCREEN_EVENT_OBSERVER_HPP