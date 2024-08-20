#ifndef GUI_IBUTTON_HPP
#define GUI_IBUTTON_HPP

#include "IUIControl.hpp"
#include "ITouchScreenEventHandler.hpp"
#include "IFocusEventHandler.hpp"
#include "IKeyboardEventHandler.hpp"
#include "Action.hpp"

namespace gui
{
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	class IButton : public IUIControl,
		public ITouchScreenEventHandler,
		public IFocusEventHandler,
		public IKeyboardEventHandler
	{
	public:

		enum class ButtonState
		{
			Disabled,
			Enabled,
			Focused,
			Pressed,
		};
	
	public:
		// constructor
		IButton(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
			IGElement & disabledGEl, IGElement & enabledGEl, IGElement & focusedGEl,
			IGElement & pressedGEl, const Action<void(IButton*)> & clickCmd);

		// destructor
		~IButton() override = default;
		
		// methods
		void SetState(ButtonState state);
		ButtonState GetState();
		IGElement * GetGraphicElement() override;
		void SetEnable(bool) override;

		// ITouchScreenEventHandler methods
		void OnPress(TouchScreenEven & event) override;
		void OnRelease(TouchScreenEven & event) override;
		void OnPenLeave(TouchScreenEven & event) override;
		bool IsUnderTouch(uint16_t x, uint16_t y) override;

		// IFocusEventHandler methods
		bool OnFocused() override;
		void OnFocusLost() override;

		// IKeyboardEventHandler methods
		void OnKeyPress(KeyEvent & event) override;
		void OnKeyRelease(KeyEvent & event) override;

	protected:
		// fields
		ButtonState _state;
		const Action<void(IButton *)> &_clickCmd;
		IGElement & _disabledGEl;
		IGElement & _enabledGEl;
		IGElement & _focusedGEl;
		IGElement & _pressedGEl;
	};
}

#endif // GUI_IBUTTON_H