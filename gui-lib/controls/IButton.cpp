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
		:IUIControl(x, y, w, h, context), _state{State::Enabled}, _clickCmd{clickCmd},
		_disabledGEl{disabledGEl}, _enabledGEl{enabledGEl}, _focusedGEl{focusedGEl}, _pressedGEl{pressedGEl}
	{
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	IButton::~IButton()
	{
		_context.KeyboardEventManager->UnregisterHandler(this);
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void IButton::SetState(IButton::State state)
	{
		_state = state;
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	IButton::State IButton::GetState()
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
			case State::Disabled:
				for(auto * itm = &_disabledGEl; itm; itm = itm->PrepareForDrawing());
				return &_disabledGEl;
			case State::Enabled:
				for(auto * itm = &_enabledGEl; itm; itm = itm->PrepareForDrawing());
				return &_enabledGEl;
			case State::Focused:
				for(auto * itm = &_focusedGEl; itm; itm = itm->PrepareForDrawing());
				return &_focusedGEl;
			case State::Pressed:
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
		_state = value ? State::Enabled : State::Disabled;
		IUIControl::SetEnable(value);
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void IButton::OnPress(TouchScreenEven & event)
	{
		_state = State::Pressed;
		Draw();
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void IButton::OnRelease(TouchScreenEven & event)
	{
		_state = State::Enabled;
		Draw();
		_clickCmd(this);
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void IButton::OnPenLeave(TouchScreenEven & event)
	{
		if(_state == State::Enabled)
			return;
		_state = State::Enabled;
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
		_state = State::Focused;
		Draw();
		return true;
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void IButton::OnFocusLost()
	{
		_context.KeyboardEventManager->UnregisterHandler(this);
		_state = State::Enabled;
		Draw();
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void IButton::OnKeyPress(KeyEvent & event)
	{
		_state = State::Pressed;
		Draw();
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void IButton::OnKeyRelease(KeyEvent & event)
	{
		bool onClickEnadled = _state == State::Pressed;
		_state = State::Focused;
		Draw();
		
		if(onClickEnadled)
			_clickCmd(this);
	}
}