#ifndef GUI_BUTTON_HPP
#define GUI_BUTTON_HPP

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
	class Button : public IUIControl,
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
		Button(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
			IGElement & normalGEl, IGElement & pressedGEl, const Action<void(Button *)> & clickCmd);

		// destructor
		~Button() override;
		
		// methods
		// ITouchScreenEventHandler methods
		IGElement * GetGraphicElement() override;
		void OnPress(ITouchScreenEventHandler *, TouchScreenEven & event) override;
		void OnRelease(ITouchScreenEventHandler *, TouchScreenEven & event) override;
		void OnPenLeave(ITouchScreenEventHandler *, TouchScreenEven & event) override;
		bool IsUnderTouch(uint16_t x, uint16_t y) override;

		// IFocusEventHandler methods
		void OnFocused(IFocusEventHandler *) override;
		void OnFocusLost(IFocusEventHandler *) override;

		// IKeyboardEventHandler methods
		void OnKeyPress(IKeyboardEventHandler *, KeyEvent & event) override;
		void OnKeyRelease(IKeyboardEventHandler *, KeyEvent & event) override;
	
	protected:
		bool _isDrawn = false;
		ButtonState _state;
		const Action<void(Button *)> &_clickCmd;
		IGElement * _normalBG;
		IGElement * _pressedBG;
	};
}

#endif // BUTTON_H