#ifndef GUI_IUICONTEXT_HPP
#define GUI_IUICONTEXT_HPP

#include "UIControlEvents.hpp"

namespace gui
{
	class IUIControl;
	class IRenderer;

	struct IUIContext
	{
		IRenderer & Renderer;
		IUIControl * FocusedControl;
		IUIControl * PressedControl;
		TouchScreenEven LastTouchScreenEvent;
	};
}

#endif // GUI_IUICONTEXT_HPP