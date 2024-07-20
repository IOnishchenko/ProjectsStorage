#ifndef GUI_ITOUCH_SCREEN_EVENT_HANDLER_HPP
#define GUI_ITOUCH_SCREEN_EVENT_HANDLER_HPP

#include "UIControlEvents.hpp"

namespace gui
{
	class ITouchScreenEventHandler
	{
	public:

		// destructor
		virtual ~ITouchScreenEventHandler() = default;

		// methods
		virtual void OnPress(ITouchScreenEventHandler *, TouchScreenEven & event);
		virtual void OnRelease(ITouchScreenEventHandler *, TouchScreenEven & event);
		virtual void OnLongPress(ITouchScreenEventHandler *, TouchScreenEven & event);
		virtual void OnPenEnter(ITouchScreenEventHandler *, TouchScreenEven & event);
		virtual void OnPenLeave(ITouchScreenEventHandler *, TouchScreenEven & event);
		virtual void OnPenMove(ITouchScreenEventHandler *, TouchScreenEven & event);
		virtual bool IsUnderTouch(uint16_t x, uint16_t y) = 0;
	};
}

#endif // GUI_ITOUCH_SCREEN_EVENT_HANDLER_HPP