#include "DialogOkBaseView.hpp"
#include "OGCommon.hpp"
#include "IFocusManager.hpp"
#include "IWindowManager.hpp"
#include "windows.h"

namespace gui
{
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	constexpr uint16_t WINDOW_X = 42;
	constexpr uint16_t WINDOW_Y = 30;

	constexpr uint16_t WINDOW_WIDTH = 240;
	constexpr uint16_t WINDOW_HEIGHT = 176;
	constexpr uint16_t WINDOW_HEADER_HEIGHT = 36;

	constexpr uint16_t WIN_CONTENT_Y0 = WINDOW_Y + WINDOW_HEADER_HEIGHT + 18;
	constexpr uint16_t WIN_CONTENT_OFFSET = 20;

	constexpr uint16_t WIN_CANCEL_X = WINDOW_X+(WINDOW_WIDTH-100)/2;
	constexpr uint16_t WIN_CANCEL_Y = WINDOW_Y+WINDOW_HEIGHT-22-8;

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	DialogOkBaseView::DialogOkBaseView(const IUIContext & context)
		:
		IModalWindow(WINDOW_X, WINDOW_Y, WINDOW_WIDTH, WINDOW_HEIGHT, context,
		{
			&_radioButtonGroup, &_closeButton
		}, &_background),

		_onAMSelectedCmd(this, &DialogOkBaseView::OnAMSelected),
		_onLSBSelectedCmd(this, &DialogOkBaseView::OnLSBSelected),
		_onUSBSelectedCmd(this, &DialogOkBaseView::OnUSBSelected),
		_onFMSelectedCmd(this, &DialogOkBaseView::OnFMSelected),
		_onCWSelectedCmd(this, &DialogOkBaseView::OnCWSelected),
		_onCloseButtonClickedCmd(this, &DialogOkBaseView::OnCloseButtonClicked),

		_amRbuttom(WINDOW_X+WIN_CONTENT_OFFSET, WIN_CONTENT_Y0, "AM:",
			_modalWindowContext, _onAMSelectedCmd),
		_lsbRbuttom(WINDOW_X+WIN_CONTENT_OFFSET+70, WIN_CONTENT_Y0, "LSB:",
			_modalWindowContext, _onAMSelectedCmd),
		_usbRbuttom(WINDOW_X+WIN_CONTENT_OFFSET+140, WIN_CONTENT_Y0, "USB:",
			_modalWindowContext, _onAMSelectedCmd),
		_fmRbuttom(WINDOW_X+WIN_CONTENT_OFFSET, WIN_CONTENT_Y0+40, "FM:",
			_modalWindowContext, _onAMSelectedCmd),
		_cwRbuttom(WINDOW_X+WIN_CONTENT_OFFSET+70, WIN_CONTENT_Y0+40, "CW:",
			_modalWindowContext, _onAMSelectedCmd),

		_radioButtonGroup(WINDOW_X, WIN_CONTENT_Y0, WINDOW_WIDTH, 80, _modalWindowContext,
		{
			&_amRbuttom, &_lsbRbuttom, &_usbRbuttom, &_fmRbuttom, &_cwRbuttom,
		}, nullptr),

		_closeButton(WIN_CANCEL_X, WIN_CANCEL_Y, "CLOSE", _modalWindowContext,
			_onCloseButtonClickedCmd),

		_headerText(20, 11, 100, 18, "SELECT MODULATION", TEXT_COLOR, BACKGROUND_GRAY,
			Font18, nullptr),
		_background(&window240x176, &_headerText)
	{
		_modalWindowContext.FocusManager->RegisterHandler(100, &_amRbuttom);
		_modalWindowContext.FocusManager->RegisterHandler(100, &_lsbRbuttom);
		_modalWindowContext.FocusManager->RegisterHandler(100, &_usbRbuttom);
		_modalWindowContext.FocusManager->RegisterHandler(100, &_fmRbuttom);
		_modalWindowContext.FocusManager->RegisterHandler(100, &_cwRbuttom);
		_modalWindowContext.FocusManager->RegisterHandler(100, &_closeButton);
		_amRbuttom.SetAsSelectedInitially();
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	DialogOkBaseView::~DialogOkBaseView()
	{
		_modalWindowContext.FocusManager->UnregisterHandler(&_amRbuttom);
		_modalWindowContext.FocusManager->UnregisterHandler(&_lsbRbuttom);
		_modalWindowContext.FocusManager->UnregisterHandler(&_usbRbuttom);
		_modalWindowContext.FocusManager->UnregisterHandler(&_fmRbuttom);
		_modalWindowContext.FocusManager->UnregisterHandler(&_cwRbuttom);
		_modalWindowContext.FocusManager->UnregisterHandler(&_closeButton);
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void DialogOkBaseView::OnAMSelected(IRadioButton *)
	{
		_modalWindowContext.WindowManager.CloseDialogWindow();
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void DialogOkBaseView::OnLSBSelected(IRadioButton *)
	{
		_modalWindowContext.WindowManager.CloseDialogWindow();
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void DialogOkBaseView::OnUSBSelected(IRadioButton *)
	{
		_modalWindowContext.WindowManager.CloseDialogWindow();
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void DialogOkBaseView::OnFMSelected(IRadioButton *)
	{
		_modalWindowContext.WindowManager.CloseDialogWindow();
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void DialogOkBaseView::OnCWSelected(IRadioButton *)
	{
		_modalWindowContext.WindowManager.CloseDialogWindow();
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void DialogOkBaseView::OnCloseButtonClicked(IButton *)
	{
		_modalWindowContext.WindowManager.CloseDialogWindow();
	}
}