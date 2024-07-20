#ifndef GUI_IUICONTEXT_HPP
#define GUI_IUICONTEXT_HPP

#include "UIControlEvents.hpp"

namespace gui
{
	class IRenderer;
	class IEncoderEventObserver;
	class IFocusManager;
	class ITouchScreenEventObserver;

	struct IUIContext
	{
		IRenderer & Renderer;

		IEncoderEventObserver * EncoderEventObserver;

		IFocusManager * FocusManager;

		ITouchScreenEventObserver * TouchScreenObserver;
	};
}

#endif // GUI_IUICONTEXT_HPP