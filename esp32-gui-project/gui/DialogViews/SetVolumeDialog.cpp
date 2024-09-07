#include "SetVolumeDialog.hpp"

namespace gui
{
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	SetVolumeDialog::SetVolumeDialog(const IUIContext & context)
		:
		SliderDialog(context, "Volume", 56, 14, _onVolumeChangedCmd),
		_onVolumeChangedCmd(this, &SetVolumeDialog::OnVolumeChanged)
	{
		_slider.Text.SetIntValue(14);
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void SetVolumeDialog::OnVolumeChanged(int value)
	{
		_slider.Text.SetIntValue(value);
		_slider.Text.Draw();
	}
}