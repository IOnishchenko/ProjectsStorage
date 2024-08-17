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
		public ITouchScreenEventHandler, public IFocusEventHandler,
		public IKeyboardEventHandler
	{
		enum class ButtonState
		{
			Normal,
			Pressed,
		};
	
	public:
		// constructor
		IButton(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
			IGElement & normalGEl, IGElement & pressedGEl, const Action<void(IButton *)> & clickCmd);

		// destructor
		~IButton() override;
		
		// methods
		// ITouchScreenEventHandler methods
		IGElement * GetGraphicElement() override;
		void OnPress(TouchScreenEven & event) override;
		void OnRelease(TouchScreenEven & event) override;
		void OnPenLeave(TouchScreenEven & event) override;
		bool IsUnderTouch(uint16_t x, uint16_t y) override;

		// IFocusEventHandler methods
		void OnFocused() override;
		void OnFocusLost() override;

		// IKeyboardEventHandler methods
		void OnKeyPress(KeyEvent & event) override;
		void OnKeyRelease(KeyEvent & event) override;
	
	protected:
		bool _isDrawn = false;
		ButtonState _state;
		const Action<void(IButton *)> &_clickCmd;
		IGElement * _normalBG;
		IGElement * _pressedBG;
	};
}

#endif // GUI_IBUTTON_H