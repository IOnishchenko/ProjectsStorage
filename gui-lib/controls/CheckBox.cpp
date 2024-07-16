
#include "CheckBox.hpp"

namespace gui
{
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	CheckBox::CheckBox(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
		const Action<void(CheckBox *)> &checkedCmd, const Action<void(CheckBox *)> &uncheckedCmd,
		IGElement * unchecked, IGElement * pressed, IGElement * checked)
		:IUIControl(x, y, w, h, context), _state(CheckBoxState::Unchecked), _visualState(CheckBoxState::Unchecked),
		_checkedCmd{checkedCmd}, _uncheckedCmd{uncheckedCmd},
		_uncheckedGEl{unchecked}, _pressedGEl{pressed}, _checkedGEl{checked}
	{
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	IGElement * CheckBox::GetGraphicElement()
	{
		switch(_visualState)
		{
			case CheckBoxState::Unchecked:
				return _uncheckedGEl;
			case CheckBoxState::Pressed:
				return _pressedGEl;
			case CheckBoxState::Checked:
				return _checkedGEl;
		}
		return nullptr;
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void CheckBox::OnPress(ITouchScreenEventHandler &)
	{
		_visualState = CheckBoxState::Pressed;
		Draw();
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void CheckBox::OnRelease(ITouchScreenEventHandler &)
	{ 
		if(_visualState != CheckBoxState::Pressed)
			return;

		if(_state == CheckBoxState::Unchecked)
		{
			_state = CheckBoxState::Checked;
			_checkedCmd(this);
		}
		else
		{
			_state = CheckBoxState::Unchecked;
			_uncheckedCmd(this);
		}
			
		_visualState = _state;
		Draw();
	}
	
	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void CheckBox::OnPenLeave(ITouchScreenEventHandler &)
	{
		if(_visualState != CheckBoxState::Pressed)
			return;

		_visualState = _state;
		Draw();
	}
	
	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	CheckBoxState CheckBox::GetState()
	{
		return _state;
	}
	
	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void CheckBox::SetState(CheckBoxState state)
	{
		_state = state;
		_visualState = state;
	}
}