
#include "ICheckBox.hpp"
#include "ITouchScreenEventObserver.hpp"

namespace gui
{
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	ICheckBox::ICheckBox(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
		const Action<void(ICheckBox *)> &checkedCmd, const Action<void(ICheckBox *)> &uncheckedCmd,
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
	ICheckBox::~ICheckBox()
	{
		_context.TouchScreenObserver->Unsubscribe(this);
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	IGElement * ICheckBox::GetGraphicElement()
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
	void ICheckBox::OnPress(ITouchScreenEventHandler *, TouchScreenEven & event)
	{
		_visualState = CheckBoxState::Pressed;
		Draw();
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void ICheckBox::OnRelease(ITouchScreenEventHandler *, TouchScreenEven & event)
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
	void ICheckBox::OnPenLeave(ITouchScreenEventHandler *, TouchScreenEven & event)
	{
		if(_visualState != CheckBoxState::Pressed)
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
	void ICheckBox::OnFocused(IFocusEventHandler *)
	{
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void ICheckBox::OnFocusLost(IFocusEventHandler *)
	{
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void ICheckBox::OnKeyPress(IKeyboardEventHandler *, KeyEvent & event)
	{

	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void ICheckBox::OnKeyRelease(IKeyboardEventHandler *, KeyEvent & event)
	{

	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	CheckBoxState ICheckBox::GetState()
	{
		return _state;
	}
	
	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void ICheckBox::SetState(CheckBoxState state)
	{
		_state = state;
		_visualState = state;
	}
}