#ifndef GUI_IUICONTEXT_HPP
#define GUI_IUICONTEXT_HPP

namespace gui
{
	class IUIControlRenderer;
	class IEncoderEventObserver;
	class IKeyboardEventObserver;
	class ITouchScreenEventObserver;
	class IFocusManager;

	struct IUIContext
	{
		IUIControlRenderer & Renderer;

		IEncoderEventObserver * EncoderEventObserver;

		IKeyboardEventObserver * KeyboardEventObserver;

		ITouchScreenEventObserver * TouchScreenObserver;

		IFocusManager * FocusManager;

		
	};
}

#endif // GUI_IUICONTEXT_HPP