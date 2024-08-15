#ifndef GUI_ITOUCH_SCREEN_EVENT_OBSERVER_HPP
#define GUI_ITOUCH_SCREEN_EVENT_OBSERVER_HPP

#include "ISubscribersManager.hpp"
#include "IEncoderEventHandler.hpp"

namespace gui
{
	class IEncoderEventObserver : public ISubscribersManager<IEncoderEventHandler>
	{
	public:
		// destructor
		~IEncoderEventObserver() override = default;
	};
}

#endif // GUI_ITOUCH_SCREEN_EVENT_OBSERVER_HPP