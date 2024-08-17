#ifndef GUI_IUICONTEXT_HPP
#define GUI_IUICONTEXT_HPP

namespace gui
{
	class IUIControlRenderer;
	class IEncoderEventManager;
	class IKeyboardEventManager;
	class ITouchScreenEventObserver;
	class IFocusManager;

	struct IUIContext
	{
		IUIControlRenderer & Renderer;

		IEncoderEventManager * EncoderEventManager;

		IKeyboardEventManager * KeyboardEventManager;

		ITouchScreenEventObserver * TouchScreenObserver;

		IFocusManager * FocusManager;
	};
}

#endif // GUI_IUICONTEXT_HPP