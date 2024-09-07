#include "OGDialogCloseBase.hpp"
#include "OGCommon.hpp"
#include "IFocusManager.hpp"
#include "IWindowManager.hpp"
#include "windows.h"

namespace gui
{
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	constexpr uint16_t WIN_CANCEL_X = WINDOW_X+(WINDOW_WIDTH-100)/2;
	constexpr uint16_t WIN_CANCEL_Y = WINDOW_Y+WINDOW_HEIGHT-22-8;

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	OGDialogCloseBase::OGDialogCloseBase(const IUIContext & context,
		const std::string_view & headerText)
		:
		IModalWindow(WINDOW_X, WINDOW_Y, WINDOW_WIDTH, WINDOW_HEIGHT, context,
		{
			&_closeButton,
		}, &_background),

		_onCloseButtonClickedCmd(this, &OGDialogCloseBase::OnCloseButtonClicked),

		_closeButton(WIN_CANCEL_X, WIN_CANCEL_Y, "CLOSE", _modalWindowContext,
			_onCloseButtonClickedCmd),

		_headerText(20, 10, 100, 18, headerText, TEXT_COLOR, BACKGROUND_GRAY,
			Font18, nullptr),
		_background(&window240x176, &_headerText)
	{
		_modalWindowContext.FocusManager->RegisterHandler(100, &_closeButton);
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	OGDialogCloseBase::~OGDialogCloseBase()
	{
		_modalWindowContext.FocusManager->UnregisterHandler(&_closeButton);
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void OGDialogCloseBase::OnCloseButtonClicked(IButton *)
	{
		_modalWindowContext.WindowManager.CloseDialogWindow();
	}
}