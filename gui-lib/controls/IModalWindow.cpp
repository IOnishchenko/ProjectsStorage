#include "IModalWindow.hpp"
#include "IWindowManager.hpp"

namespace gui
{
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	IModalWindow::IModalWindow(uint16_t x, uint16_t y, uint16_t w, uint16_t h,
		const IUIContext & context, IGElement * gelement)
		:
		Group(x, y, w, h, _modalWindowContext, gelement), 
		IEncoderEventManager(&_focusManager), IEncoderEventHandler(),
		IKeyboardEventManager(&_focusManager), IKeyboardEventHandler(),
		_modalWindowContext
		{
			context.Renderer,
			this,
			this,
			context.TouchScreenObserver,
			&_focusManager,
			context.WindowManager,
			context.AnimatedControlManager,
		}, _mainContext{context}, _focusManager()
	{
		context.EncoderEventManager->RegisterHandler(this);
		context.KeyboardEventManager->RegisterHandler(this);
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	IModalWindow::IModalWindow(uint16_t x, uint16_t y, uint16_t w, uint16_t h,
		const IUIContext & context, const std::initializer_list<IUIControl *> & controls,
		IGElement * gelement)
		:
		Group(x, y, w, h, _modalWindowContext, controls, gelement), 
		IEncoderEventManager(&_focusManager), IEncoderEventHandler(),
		IKeyboardEventManager(&_focusManager), IKeyboardEventHandler(),
		_modalWindowContext
		{
			context.Renderer,
			this,
			this,
			context.TouchScreenObserver,
			&_focusManager,
			context.WindowManager,
			context.AnimatedControlManager,
		}, _mainContext{context}, _focusManager()
	{
		context.EncoderEventManager->RegisterHandler(this);
		context.KeyboardEventManager->RegisterHandler(this);
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	IModalWindow::~IModalWindow()
	{
		_mainContext.EncoderEventManager->UnregisterHandler(this);
		_mainContext.KeyboardEventManager->UnregisterHandler(this);
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void IModalWindow::OnEncoderMoved(EncoderEvent & event)
	{
		HandleEncoderEvent(event);
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void IModalWindow::OnKeyPress(KeyEvent & event)
	{
		IKeyboardEventManager::_activeHandler->OnKeyPress(event);
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void IModalWindow::OnKeyRelease(KeyEvent & event)
	{
		IKeyboardEventManager::_activeHandler->OnKeyRelease(event);
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void IModalWindow::OnKeyLongPress(KeyEvent & event)
	{
		IKeyboardEventManager::_activeHandler->OnKeyLongPress(event);
	}
}