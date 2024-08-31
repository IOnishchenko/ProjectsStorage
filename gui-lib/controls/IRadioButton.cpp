#include "IRadioButton.hpp"
#include "IFocusManager.hpp"
#include "ITouchScreenEventObserver.hpp"
#include "IKeyboardEventManager.hpp"
#include "IRadioButtonGroup.hpp"

namespace gui
{
	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	IRadioButton::IRadioButton(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
		IGElement & disabledGEl, IGElement & enabledGEl, IGElement & focusedGEl,
		IGElement & pressedGEl, IGElement & selectedGEl, const Action<void(IRadioButton *)> & selCmd)
		:IUIControl(x, y, w, h, context),
		_onItemSelected{selCmd}, _disabledGEl{disabledGEl}, _enabledGEl{enabledGEl}, _focusedGEl{focusedGEl},
		_pressedGEl{pressedGEl}, _selectedGEl{selectedGEl}
	{
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	IRadioButton::~IRadioButton()
	{
		_context.KeyboardEventManager->UnregisterHandler(this);
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	IGElement * IRadioButton::GetGraphicElement()
	{
		switch(_state)
		{
			case State::Disabled:
				for(auto itm = &_disabledGEl; itm; itm = itm->PrepareForDrawing());
				return &_disabledGEl;
			case State::Enabled:
				for(auto itm = &_enabledGEl; itm; itm = itm->PrepareForDrawing());
				return &_enabledGEl;
			case State::Focused:
				for(auto itm = &_focusedGEl; itm; itm = itm->PrepareForDrawing());
				return &_focusedGEl;
			case State::Pressed:
				for(auto itm = &_pressedGEl; itm; itm = itm->PrepareForDrawing());
				return &_pressedGEl;
			case State::Selected:
				for(auto itm = &_selectedGEl; itm; itm = itm->PrepareForDrawing());
				return &_selectedGEl;
			default:
				return nullptr;
		}
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void IRadioButton::SetEnable(bool ena)
	{
		if(ena)
		{
			_state = State::Enabled;
			_logicState = State::Enabled;
		}
		else
		{
			if(_state == State::Focused)
				_context.KeyboardEventManager->UnregisterHandler(this);

			_state = State::Disabled;
			_logicState = State::Disabled;
		}
		IUIControl::SetEnable(ena);
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void IRadioButton::OnPress(TouchScreenEven & event)
	{
		_logicState = _state;
		_state = State::Pressed;
		Draw();
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void IRadioButton::OnRelease(TouchScreenEven & event)
	{
		HandleOnRelease();
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void IRadioButton::OnPenLeave(TouchScreenEven & event)
	{
		if(_state == _logicState)
			return;
		_state = _logicState;
		Draw();
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	bool IRadioButton::IsUnderTouch(uint16_t x, uint16_t y)
	{
		return IsPositionInsideControl(x, y);
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	bool IRadioButton::OnFocused()
	{
		if(!_enable || (_state == State::Selected))
			return false;

		_context.KeyboardEventManager->RegisterHandler(this);
		_state = State::Focused;
		_logicState = _state;
		Draw();
		return true;
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void IRadioButton::OnFocusLost()
	{
		_context.KeyboardEventManager->UnregisterHandler(this);
		_state = _logicState == State::Focused ?
			State::Enabled : State::Selected;
		_logicState = _state;
		Draw();
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void IRadioButton::OnKeyPress(KeyEvent & event)
	{
		_logicState = _state;
		_state = State::Pressed;
		Draw();
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void IRadioButton::OnKeyRelease(KeyEvent & event)
	{
		HandleOnRelease();
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	IRadioButton::State IRadioButton::GetState()
	{
		return _state;
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void IRadioButton::SetAsSelectedInitially()
	{
		_state = State::Selected;
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void IRadioButton::SetState(State state)
	{
		_state = state;
		_logicState = state;
		Draw();
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void IRadioButton::HandleOnRelease()
	{
		if(_state != State::Pressed)
			return;

		switch(_logicState)
		{
			case State::Enabled:
				_state = State::Selected;
				Group->RadioButtonCallBack(this);
				_onItemSelected(this);
				break;
			case State::Focused:
				_state = State::Selected;
				Group->RadioButtonCallBack(this);
				_onItemSelected(this);
				break;
			case State::Selected:
				_state = State::Selected;
				break;
			default:
				return;
		}
		_logicState = _state;
		Draw();
	}
}