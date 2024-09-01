#include "ICheckBox.hpp"
#include "ITouchScreenEventObserver.hpp"
#include "IKeyboardEventManager.hpp"

namespace gui
{
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	ICheckBox::ICheckBox(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
		const Action<void(ICheckBox *)> &checkedCmd, const Action<void(ICheckBox *)> &uncheckedCmd,
		IGElement & checkedDisabledGEl, IGElement & uncheckedDisabledGEl,
		IGElement & checkedEnabledGEl, IGElement & uncheckedEnabledGEl,
		IGElement & checkedFocusedGEl, IGElement & uncheckedFocusedGEl,
		IGElement & checkedPressedGEl, IGElement & uncheckedPressedGEl)
		:
		IUIControl(x, y, w, h, context),
		_checkedCmd{checkedCmd}, _uncheckedCmd{uncheckedCmd},
		_checkedDisabledGEl(checkedDisabledGEl), _uncheckedDisabledGEl(uncheckedDisabledGEl),
		_checkedEnabledGEl(checkedEnabledGEl), _uncheckedEnabledGEl(uncheckedEnabledGEl),
		_checkedFocusedGEl(checkedFocusedGEl), _uncheckedFocusedGEl(uncheckedFocusedGEl),
		_checkedPressedGEl{checkedPressedGEl}, _uncheckedPressedGEl{uncheckedPressedGEl}
	{
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	ICheckBox::~ICheckBox()
	{
		_context.KeyboardEventManager->UnregisterHandler(this);
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	IGElement * ICheckBox::GetGraphicElement()
	{
		switch(_visualState)
		{
			case State::CheckedDisabled:
				for(auto itm = &_checkedDisabledGEl; itm; itm = itm->PrepareForDrawing());
				return &_checkedDisabledGEl;
			case State::UncheckedDisabled:
				for(auto itm = &_uncheckedDisabledGEl; itm; itm = itm->PrepareForDrawing());
				return &_uncheckedDisabledGEl;
			case State::CheckedEnabled:
				for(auto itm = &_checkedEnabledGEl; itm; itm = itm->PrepareForDrawing());
				return &_checkedEnabledGEl;
			case State::UncheckedEnabled:
				for(auto itm = &_uncheckedEnabledGEl; itm; itm = itm->PrepareForDrawing());
				return &_uncheckedEnabledGEl;
			case State::CheckedFocused:
				for(auto itm = &_checkedFocusedGEl; itm; itm = itm->PrepareForDrawing());
				return &_checkedFocusedGEl;
			case State::UncheckedFocused:
				for(auto itm = &_uncheckedFocusedGEl; itm; itm = itm->PrepareForDrawing());
				return &_uncheckedFocusedGEl;
			case State::CheckedPressed:
				for(auto itm = &_checkedPressedGEl; itm; itm = itm->PrepareForDrawing());
				return &_checkedPressedGEl;
			case State::UncheckedPressed:
				for(auto itm = &_uncheckedPressedGEl; itm; itm = itm->PrepareForDrawing());
				return &_uncheckedPressedGEl;
			default:
				return nullptr;
		}
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void ICheckBox::SetEnable(bool value)
	{
		if(!value)
		{
			switch(_state)
			{
				case State::CheckedEnabled:
				case State::CheckedFocused:
				case State::CheckedPressed:
					_visualState = State::CheckedDisabled;
					break;
				case State::UncheckedEnabled:
				case State::UncheckedFocused:
				case State::UncheckedPressed:
					_visualState = State::UncheckedDisabled;
					break;
				default:
					break;
			}
		}
		else
			_visualState = _state;
		IUIControl::SetEnable(value);
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void ICheckBox::OnPress(TouchScreenEven & event)
	{
		SetPressedState();
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void ICheckBox::OnRelease(TouchScreenEven & event)
	{ 
		HandleOnReleaseEvent();
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void ICheckBox::OnPenLeave(TouchScreenEven & event)
	{
		if((_visualState != State::CheckedPressed) &&
			(_visualState != State::UncheckedPressed))
			return;

		_visualState = _state;
		Draw();
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	bool ICheckBox::IsUnderTouch(uint16_t x, uint16_t y)
	{
		return IsPositionInsideControl(x, y);
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	bool ICheckBox::OnFocused()
	{
		if(!_enable)
			return false;

		_context.KeyboardEventManager->RegisterHandler(this);
		_state = (_state == State::CheckedEnabled) ?
			State::CheckedFocused : State::UncheckedFocused;
		_visualState = _state;
		Draw();
		return true;
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void ICheckBox::OnFocusLost()
	{
		_context.KeyboardEventManager->UnregisterHandler(this);
		_state = (_state == State::CheckedFocused) ?
			State::CheckedEnabled : State::UncheckedEnabled;
		_visualState = _state;
		Draw();
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void ICheckBox::OnKeyPress(KeyEvent & event)
	{
		SetPressedState();
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void ICheckBox::OnKeyRelease(KeyEvent & event)
	{
		HandleOnReleaseEvent();
	}
	
	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	bool ICheckBox::IsChecked()
	{
		return ((_state == State::CheckedDisabled) || (_state == State::CheckedEnabled)
			|| (_state == State::CheckedFocused) || (_state == State::CheckedPressed));
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void ICheckBox::Check()
	{
		_state = _enable ? State::CheckedEnabled : State::CheckedDisabled;
		_visualState = _state;
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void ICheckBox::Uncheck()
	{
		_state = _enable ? State::UncheckedEnabled : State::UncheckedDisabled;
		_visualState = _state;
	}


	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	inline void ICheckBox::SetPressedState()
	{
		switch(_state)
		{
			case State::CheckedEnabled:
			case State::CheckedFocused:
				_visualState = State::CheckedPressed;
				Draw();
				break;
			case State::UncheckedEnabled:
			case State::UncheckedFocused:
				_visualState = State::UncheckedPressed;
				Draw();
				break;
			default:
				break;
		}
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	inline void ICheckBox::HandleOnReleaseEvent()
	{
		if((_visualState != State::CheckedPressed) &&
			(_visualState != State::UncheckedPressed))
			return;

		switch(_state)
		{
			case State::CheckedEnabled:
				_state = State::UncheckedEnabled;
				_uncheckedCmd(this);
				break;
			case State::CheckedFocused:
				_state = State::UncheckedFocused;
				_uncheckedCmd(this);
				break;
			case State::UncheckedEnabled:
				_state = State::CheckedEnabled;
				_checkedCmd(this);
				break;
			case State::UncheckedFocused:
				_state = State::CheckedFocused;
				_checkedCmd(this);
				break;
			default:
				break;
		}
		_visualState = _state;
		Draw();
	}
}