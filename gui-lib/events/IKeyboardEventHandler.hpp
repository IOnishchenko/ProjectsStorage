#ifndef GUI_IKEYBOARD_EVENT_HANDLER_HPP
#define GUI_IKEYBOARD_EVENT_HANDLER_HPP

#include "UIControlEvents.hpp"

namespace gui
{
	class IKeyboardEventHandler
	{
	public:

		// destructor
		virtual ~IKeyboardEventHandler() = default;

		// methods
		virtual void OnKeyPress(IKeyboardEventHandler *, KeyEvent & event);
		virtual void OnKeyRelease(IKeyboardEventHandler *, KeyEvent & event);
		virtual void OnKeyLongPress(IKeyboardEventHandler *, KeyEvent & event);
	};
}

#endif // GUI_IKEYBOARD_EVENT_HANDLER_HPP