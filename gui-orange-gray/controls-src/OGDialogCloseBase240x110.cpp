#include "OGDialogCloseBase240x110.hpp"
#include "OGCommon.hpp"
#include "IFocusManager.hpp"
#include "IWindowManager.hpp"
#include "windows.h"

namespace gui
{
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	constexpr uint16_t WIN_CANCEL_X = WINDOW240x110_X+(WINDOW240x110_WIDTH-100)/2;
	constexpr uint16_t WIN_CANCEL_Y = WINDOW240x110_Y+WINDOW240x110_HEIGHT-22-8;

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	OGDialogCloseBase240x110::OGDialogCloseBase240x110(const IUIContext & context,
		const std::string_view & headerText)
		:
		IModalWindow(WINDOW240x110_X, WINDOW240x110_Y, WINDOW240x110_WIDTH,
			WINDOW240x110_HEIGHT, context,
		{
			&_closeButton,
		}, &_background),

		_onCloseButtonClickedCmd(this, &OGDialogCloseBase240x110::OnCloseButtonClicked),

		_closeButton(WIN_CANCEL_X, WIN_CANCEL_Y, "CLOSE", _modalWindowContext,
			_onCloseButtonClickedCmd),

		_headerText(20, 10, 100, 18, headerText, TEXT_COLOR, BACKGROUND_GRAY,
			Font18, nullptr),
		_background(&window240x110, &_headerText)
	{
		_modalWindowContext.FocusManager->RegisterHandler(100, &_closeButton);
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	OGDialogCloseBase240x110::~OGDialogCloseBase240x110()
	{
		_modalWindowContext.FocusManager->UnregisterHandler(&_closeButton);
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void OGDialogCloseBase240x110::OnCloseButtonClicked(IButton *)
	{
		_modalWindowContext.WindowManager.CloseDialogWindow();
	}
}