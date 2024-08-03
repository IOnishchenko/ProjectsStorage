#ifndef GUI_IUICONTEXT_HPP
#define GUI_IUICONTEXT_HPP

namespace gui
{
	class IUIControlRenderer;
	class IRenderer;
	class IEncoderEventObserver;
	class IFocusManager;
	class ITouchScreenEventObserver;

	struct IUIContext
	{
		IUIControlRenderer & Renderer;

		IEncoderEventObserver * EncoderEventObserver;

		IFocusManager * FocusManager;

		ITouchScreenEventObserver * TouchScreenObserver;
	};
}

#endif // GUI_IUICONTEXT_HPP