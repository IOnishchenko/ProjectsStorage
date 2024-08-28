#ifndef GUI_ITOGGLE_FOCUS_UICONTROL_HPP
#define GUI_ITOGGLE_FOCUS_UICONTROL_HPP

#include "IUIControl.hpp"
#include "IFocusEventHandler.hpp"
#include "IEncoderEventHandler.hpp"
#include "IKeyboardEventHandler.hpp"

namespace gui
{
	class IToggleFocusUIControl : public IUIControl,
		public IFocusEventHandler,
		public IEncoderEventHandler,
		public IKeyboardEventHandler
	{
	protected:
		
		enum class State
		{
			Disabled,
			Enabled,
			Focused,
			Pressed,
			Selected,
		};

	public:
		// constructor
		IToggleFocusUIControl(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context);

		// destructor
		~IToggleFocusUIControl() override;

		// IFocusEventHandler methods
		bool OnFocused() override;
		void OnFocusLost() override;

		// IKeyboardEventHandler methods
		void OnKeyPress(KeyEvent & event) override;
		void OnKeyRelease(KeyEvent & event) override;

		// IUIControl methods
		void SetEnable(bool ena) override;
	
	protected:
		State _state = State::Enabled;
		bool _lockManagers = false;
	};
}


#endif // GUI_TOGGLE_FOCUS_UICONTROL_HPP