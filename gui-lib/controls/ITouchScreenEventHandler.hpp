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
		virtual void OnPress(TouchScreenEven &);
		virtual void OnRelease(TouchScreenEven &);
		virtual void OnLongPress(TouchScreenEven &);
		virtual void OnPenEnter(TouchScreenEven &);
		virtual void OnPenLeave(TouchScreenEven &);
		virtual void OnPenMove(TouchScreenEven &);
	};
}

#endif // GUI_ITOUCH_SCREEN_EVENT_HANDLER_HPP