#include "IToggleFocusUIControl.hpp"
#include "IKeyboardEventManager.hpp"
#include "IEncoderEventManager.hpp"
#include "IFocusManager.hpp"

namespace gui
{
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	IToggleFocusUIControl::IToggleFocusUIControl(uint16_t x, uint16_t y,
		uint16_t w, uint16_t h, const IUIContext & context)
		:IUIControl(x, y, w, h, context)
	{
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	IToggleFocusUIControl::~IToggleFocusUIControl()
	{
		if(_state == State::Selected)
		{
			_context.EncoderEventManager->UnregisterHandler(this);
			_context.KeyboardEventManager->UnregisterHandler(this);
		}

		if(_state == State::Focused)
			_context.KeyboardEventManager->UnregisterHandler(this);
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	bool IToggleFocusUIControl::OnFocused()
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
	void IToggleFocusUIControl::OnFocusLost()
	{
		_lockManagers = false;
		_context.KeyboardEventManager->UnregisterHandler(this);
		_state = State::Enabled;
		Draw();
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void IToggleFocusUIControl::OnKeyPress(KeyEvent & event)
	{
		_lockManagers = _state == State::Focused;
		_state = State::Pressed;
		Draw();
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void IToggleFocusUIControl::OnKeyRelease(KeyEvent & event)
	{
		if(_lockManagers)
		{
			_context.EncoderEventManager->RegisterHandler(this);
			_state = State::Selected;
		}
		else
		{
			_context.EncoderEventManager->UnregisterHandler(this);
			_state = State::Focused;
		}
		Draw();
	}
}
