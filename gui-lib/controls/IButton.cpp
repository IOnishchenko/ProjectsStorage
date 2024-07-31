#include "IButton.hpp"
#include "ITouchScreenEventObserver.hpp"

namespace gui
{
	/*--------------------------------------------------------------------------//
	// constructor
	//--------------------------------------------------------------------------*/
	IButton::IButton(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
		IGElement & normalGEl, IGElement & pressedGEl, const Action<void(IButton*)>& clickCmd)
		:IUIControl(x, y, w, h, context), _state{ButtonState::Normal}, _clickCmd{clickCmd},
		_normalBG{&normalGEl}, _pressedBG{&pressedGEl}
	{
		context.TouchScreenObserver->Subscribe(this);
	}

	/*--------------------------------------------------------------------------//
	// destructor
	//--------------------------------------------------------------------------*/
	IButton::~IButton()
	{
		_context.TouchScreenObserver->Unsubscribe(this);
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	IGElement * IButton::GetGraphicElement()
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
	void IButton::OnPress(ITouchScreenEventHandler *, TouchScreenEven & event)
	{
		_state = ButtonState::Pressed;
		Draw();
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void IButton::OnRelease(ITouchScreenEventHandler *, TouchScreenEven & event)
	{
		_state = ButtonState::Normal;
		Draw();
		_clickCmd(this);
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void IButton::OnPenLeave(ITouchScreenEventHandler *, TouchScreenEven & event)
	{
		if(_state == ButtonState::Normal)
			return;
		_state = ButtonState::Normal;
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
	void IButton::OnFocused(IFocusEventHandler *)
	{
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void IButton::OnFocusLost(IFocusEventHandler *)
	{
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void IButton::OnKeyPress(IKeyboardEventHandler *, KeyEvent & event)
	{

	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void IButton::OnKeyRelease(IKeyboardEventHandler *, KeyEvent & event)
	{

	}
}