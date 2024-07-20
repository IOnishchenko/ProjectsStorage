
#include "CheckBox.hpp"
#include "ITouchScreenEventObserver.hpp"

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
		context.TouchScreenObserver->Subscribe(this);
	}

	/*--------------------------------------------------------------------------//
	// destructor
	//--------------------------------------------------------------------------*/
	CheckBox::~CheckBox()
	{
		_context.TouchScreenObserver->Unsubscribe(this);
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
	void CheckBox::OnPress(ITouchScreenEventHandler *, TouchScreenEven & event)
	{
		_visualState = CheckBoxState::Pressed;
		Draw();
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void CheckBox::OnRelease(ITouchScreenEventHandler *, TouchScreenEven & event)
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
	void CheckBox::OnPenLeave(ITouchScreenEventHandler *, TouchScreenEven & event)
	{
		if(_visualState != CheckBoxState::Pressed)
			return;

		_visualState = _state;
		Draw();
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	bool CheckBox::IsUnderTouch(uint16_t x, uint16_t y)
	{
		return IsPositionInsideControl(x, y);
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void CheckBox::OnFocused(IFocusEventHandler *)
	{
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void CheckBox::OnFocusLost(IFocusEventHandler *)
	{
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void CheckBox::OnKeyPress(IKeyboardEventHandler *, KeyEvent & event)
	{

	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void CheckBox::OnKeyRelease(IKeyboardEventHandler *, KeyEvent & event)
	{

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