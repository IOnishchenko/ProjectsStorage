#include "Button.hpp"

namespace gui
{
	/*--------------------------------------------------------------------------//
	// constructor
	//--------------------------------------------------------------------------*/
	Button::Button(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
		IGElement & normalGEl, IGElement & pressedGEl, const Action<void(Button*)>& clickCmd)
		:_state{ButtonState::Normal}, _clickCmd{clickCmd}, _normalBG{&normalGEl}, _pressedBG{&pressedGEl},
		IUIControl(x, y, w, h, context)
	{
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
	void Button::OnPress(TouchScreenEven & penInfo)
	{
		_state = ButtonState::Pressed;
		Draw();
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void Button::OnRelease(TouchScreenEven & penInfo)
	{
		_state = ButtonState::Normal;
		Draw();
		_clickCmd(this);
	}
	
	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void Button::OnPenLeave(TouchScreenEven & penInfo)
	{
		if(_state == ButtonState::Normal)
			return;
		_state = ButtonState::Normal;
		Draw();
	}
}