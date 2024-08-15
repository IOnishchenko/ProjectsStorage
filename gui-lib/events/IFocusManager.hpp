#ifndef GUI_FOCUS_EVENT_OBSERVER_HPP
#define GUI_FOCUS_EVENT_OBSERVER_HPP

#include "IFocusEventHandler.hpp"
#include "UIControlEvents.hpp"

namespace gui
{
	class IFocusManager
	{
	public:
		// destructor
		virtual ~IFocusManager() = default;
		
		// methods
		void HoldFocus(IFocusEventHandler * handler);
		void ReleaseFocus(IFocusEventHandler * handler);

	private:
		// fields
		IFocusEventHandler * _focusHolder = nullptr;
	};
}

#endif // GUI_ITOUCH_SCREEN_EVENT_OBSERVER_HPP