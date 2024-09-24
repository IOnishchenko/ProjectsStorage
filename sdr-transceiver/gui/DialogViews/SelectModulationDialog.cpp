#include "SelectModulationDialog.hpp"
#include "OGCommon.hpp"
#include "IFocusManager.hpp"
#include "IWindowManager.hpp"
#include "windows.h"

namespace gui
{
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	constexpr uint16_t WIN_CONTENT_Y0 = WINDOW_Y + WINDOW_HEADER_HEIGHT + 18;
	constexpr uint16_t WIN_CONTENT_OFFSET = 20;

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	SelectModulationDialog::SelectModulationDialog(const IUIContext & context)
		:
		OGDialogCloseBase(context, "Select Modulation"),
		_onAMSelectedCmd(this, &SelectModulationDialog::OnAMSelected),
		_onLSBSelectedCmd(this, &SelectModulationDialog::OnLSBSelected),
		_onUSBSelectedCmd(this, &SelectModulationDialog::OnUSBSelected),
		_onFMSelectedCmd(this, &SelectModulationDialog::OnFMSelected),
		_onCWSelectedCmd(this, &SelectModulationDialog::OnCWSelected),

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
		}, nullptr)
	{
		AddChild(&_radioButtonGroup),
		_modalWindowContext.FocusManager->RegisterHandler(100, &_amRbuttom);
		_modalWindowContext.FocusManager->RegisterHandler(100, &_lsbRbuttom);
		_modalWindowContext.FocusManager->RegisterHandler(100, &_usbRbuttom);
		_modalWindowContext.FocusManager->RegisterHandler(100, &_fmRbuttom);
		_modalWindowContext.FocusManager->RegisterHandler(100, &_cwRbuttom);
		_amRbuttom.SetAsSelectedInitially();
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	SelectModulationDialog::~SelectModulationDialog()
	{
		_modalWindowContext.FocusManager->UnregisterHandler(&_amRbuttom);
		_modalWindowContext.FocusManager->UnregisterHandler(&_lsbRbuttom);
		_modalWindowContext.FocusManager->UnregisterHandler(&_usbRbuttom);
		_modalWindowContext.FocusManager->UnregisterHandler(&_fmRbuttom);
		_modalWindowContext.FocusManager->UnregisterHandler(&_cwRbuttom);
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void SelectModulationDialog::OnAMSelected(IRadioButton *)
	{
		_modalWindowContext.WindowManager.CloseDialogWindow();
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void SelectModulationDialog::OnLSBSelected(IRadioButton *)
	{
		_modalWindowContext.WindowManager.CloseDialogWindow();
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void SelectModulationDialog::OnUSBSelected(IRadioButton *)
	{
		_modalWindowContext.WindowManager.CloseDialogWindow();
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void SelectModulationDialog::OnFMSelected(IRadioButton *)
	{
		_modalWindowContext.WindowManager.CloseDialogWindow();
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void SelectModulationDialog::OnCWSelected(IRadioButton *)
	{
		_modalWindowContext.WindowManager.CloseDialogWindow();
	}
}