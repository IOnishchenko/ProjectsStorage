#include "SetReceiverAGCDialog.hpp"

namespace gui
{
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	SetReceiverAGCDialog::SetReceiverAGCDialog(const IUIContext & context)
		:
		SliderDialog(context, "Receiver AGC", 56, 14, _onAGCChangedCmd),
		_onAGCChangedCmd(this, &SetReceiverAGCDialog::OnAGCChanged)
	{
		_slider.Text.SetIntValue(14);
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void SetReceiverAGCDialog::OnAGCChanged(int value)
	{
		_slider.Text.SetIntValue(value);
		_slider.Text.Draw();
	}
}