#ifndef GUI_IKEYBOARD_EVENT_OBSERVER_HPP
#define GUI_IKEYBOARD_EVENT_OBSERVER_HPP

#include "ISubscribersManager.hpp"
#include "IKeyboardEventHandler.hpp"

namespace gui
{
	class IKeyboardEventObserver : public ISubscribersManager<IKeyboardEventHandler>
	{
	public:
		// destructor
		~IKeyboardEventObserver() override = default;
	};
}

#endif // GUI_IKEYBOARD_EVENT_OBSERVER_HPP