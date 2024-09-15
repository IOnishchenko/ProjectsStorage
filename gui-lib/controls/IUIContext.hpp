#ifndef GUI_IUICONTEXT_HPP
#define GUI_IUICONTEXT_HPP

namespace gui
{
	class IUIControlRenderer;
	class IEncoderEventManager;
	class IKeyboardEventManager;
	class ITouchScreenEventObserver;
	class IFocusManager;
	class IWindowManager;
	class IAnimatedControlManager;

	struct IUIContext
	{
		IUIControlRenderer & Renderer;

		IEncoderEventManager * EncoderEventManager;

		IKeyboardEventManager * KeyboardEventManager;

		ITouchScreenEventObserver * TouchScreenObserver;

		IFocusManager * FocusManager;

		IWindowManager & WindowManager;

		IAnimatedControlManager * AnimatedControlManager;
	};
}

#endif // GUI_IUICONTEXT_HPP