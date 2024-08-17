#ifndef GUI_ITOUCH_SCREEN_EVENT_HANDLER_HPP
#define GUI_ITOUCH_SCREEN_EVENT_HANDLER_HPP

#include "UIEvents.hpp"

namespace gui
{
	class ITouchScreenEventHandler
	{
	public:

		// destructor
		virtual ~ITouchScreenEventHandler() = default;

		// methods
		virtual void OnPress(TouchScreenEven & event);
		virtual void OnRelease(TouchScreenEven & event);
		virtual void OnLongPress(TouchScreenEven & event);
		virtual void OnPenEnter(TouchScreenEven & event);
		virtual void OnPenLeave(TouchScreenEven & event);
		virtual void OnPenMove(TouchScreenEven & event);
		virtual bool IsUnderTouch(uint16_t x, uint16_t y) = 0;
	};
}

#endif // GUI_ITOUCH_SCREEN_EVENT_HANDLER_HPP