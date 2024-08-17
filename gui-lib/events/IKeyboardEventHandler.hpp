#ifndef GUI_IKEYBOARD_EVENT_HANDLER_HPP
#define GUI_IKEYBOARD_EVENT_HANDLER_HPP

#include "UIEvents.hpp"

namespace gui
{
	class IKeyboardEventHandler
	{
	public:

		// destructor
		virtual ~IKeyboardEventHandler() = default;

		// methods
		virtual void OnKeyPress(KeyEvent & event);
		virtual void OnKeyRelease(KeyEvent & event);
		virtual void OnKeyLongPress(KeyEvent & event);
	};
}

#endif // GUI_IKEYBOARD_EVENT_HANDLER_HPP