#ifndef GUI_IUICONTEXT_HPP
#define GUI_IUICONTEXT_HPP

namespace gui
{
	class IUIControl;
	class IRenderer;

	struct IUIContext
	{
		IRenderer & Renderer;
		IUIControl * FocusedControl;
		IUIControl * PressedControl;
	};
}

#endif // GUI_IUICONTEXT_HPP