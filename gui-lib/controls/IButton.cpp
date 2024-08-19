#include "IButton.hpp"
#include "IFocusManager.hpp"
#include "ITouchScreenEventObserver.hpp"
#include "IKeyboardEventManager.hpp"

namespace gui
{
	/*--------------------------------------------------------------------------//
	// constructor
	//--------------------------------------------------------------------------*/
	IButton::IButton(uint16_t x, uint16_t y, uint16_t w, uint16_t h,
		const IUIContext & context, IGElement & disabledGEl, IGElement & enabledGEl,
		IGElement & focusedGEl, IGElement & pressedGEl,
		const Action<void(IButton*)> & clickCmd)
		:IUIControl(x, y, w, h, context), _state{ButtonState::Enabled}, _clickCmd{clickCmd},
		_disabledGEl{disabledGEl}, _enabledGEl{enabledGEl}, _focusedGEl{focusedGEl}, _pressedGEl{pressedGEl}
	{
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void IButton::SetState(IButton::ButtonState state)
	{
		_state = state;
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	IButton::ButtonState IButton::GetState()
	{
		return _state;
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	IGElement * IButton::GetGraphicElement()
	{
		switch(_state)
		{
			case ButtonState::Disabled:
				for(auto * itm = &_disabledGEl; itm; itm = itm->PrepareForDrawing());
				return &_disabledGEl;
			case ButtonState::Enabled:
				for(auto * itm = &_enabledGEl; itm; itm = itm->PrepareForDrawing());
				return &_enabledGEl;
			case ButtonState::Focused:
				for(auto * itm = &_focusedGEl; itm; itm = itm->PrepareForDrawing());
				return &_focusedGEl;
			case ButtonState::Pressed:
				for(auto * itm = &_pressedGEl; itm; itm = itm->PrepareForDrawing());
				return &_pressedGEl;
			default:
				return nullptr;
		}
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void IButton::SetEnable(bool value)
	{
		_state = value ? ButtonState::Enabled : ButtonState::Disabled;
		IUIControl::SetEnable(value);
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void IButton::OnPress(TouchScreenEven & event)
	{
		_state = ButtonState::Pressed;
		Draw();
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void IButton::OnRelease(TouchScreenEven & event)
	{
		_state = ButtonState::Enabled;
		Draw();
		_clickCmd(this);
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void IButton::OnPenLeave(TouchScreenEven & event)
	{
		if(_state == ButtonState::Enabled)
			return;
		_state = ButtonState::Enabled;
		Draw();
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	bool IButton::IsUnderTouch(uint16_t x, uint16_t y)
	{
		return IsPositionInsideControl(x, y);
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	bool IButton::OnFocused()
	{
		if(!_enable)
			return false;
		
		_context.KeyboardEventManager->RegisterHandler(this);
		_state = ButtonState::Focused;
		Draw();
		return true;
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void IButton::OnFocusLost()
	{
		_context.KeyboardEventManager->UnregisterHandler();
		_state = ButtonState::Enabled;
		Draw();
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void IButton::OnKeyPress(KeyEvent & event)
	{
		_state = ButtonState::Pressed;
		Draw();
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void IButton::OnKeyRelease(KeyEvent & event)
	{
		bool onClickEnadled = _state == ButtonState::Pressed;
		_state = ButtonState::Focused;
		Draw();
		
		if(onClickEnadled)
			_clickCmd(this);
	}
}