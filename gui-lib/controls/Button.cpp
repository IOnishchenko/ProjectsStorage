#include "Button.hpp"
#include "ITouchScreenEventObserver.hpp"

namespace gui
{
	/*--------------------------------------------------------------------------//
	// constructor
	//--------------------------------------------------------------------------*/
	Button::Button(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
		IGElement & normalGEl, IGElement & pressedGEl, const Action<void(Button*)>& clickCmd)
		:IUIControl(x, y, w, h, context), _state{ButtonState::Normal}, _clickCmd{clickCmd},
		_normalBG{&normalGEl}, _pressedBG{&pressedGEl}
	{
		context.TouchScreenObserver->Subscribe(this);
	}

	/*--------------------------------------------------------------------------//
	// destructor
	//--------------------------------------------------------------------------*/
	Button::~Button()
	{
		_context.TouchScreenObserver->Unsubscribe(this);
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	IGElement * Button::GetGraphicElement()
	{
		switch(_state)
		{
			case ButtonState::Normal:
				return _normalBG;
			case ButtonState::Pressed:
				return _pressedBG;
			default:
				return nullptr;
		}
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void Button::OnPress(ITouchScreenEventHandler *, TouchScreenEven & event)
	{
		_state = ButtonState::Pressed;
		Draw();
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void Button::OnRelease(ITouchScreenEventHandler *, TouchScreenEven & event)
	{
		_state = ButtonState::Normal;
		Draw();
		_clickCmd(this);
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void Button::OnPenLeave(ITouchScreenEventHandler *, TouchScreenEven & event)
	{
		if(_state == ButtonState::Normal)
			return;
		_state = ButtonState::Normal;
		Draw();
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	bool Button::IsUnderTouch(uint16_t x, uint16_t y)
	{
		return IsPositionInsideControl(x, y);
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void Button::OnFocused(IFocusEventHandler *)
	{
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void Button::OnFocusLost(IFocusEventHandler *)
	{
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void Button::OnKeyPress(IKeyboardEventHandler *, KeyEvent & event)
	{

	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void Button::OnKeyRelease(IKeyboardEventHandler *, KeyEvent & event)
	{

	}
}