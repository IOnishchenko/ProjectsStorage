#include "SetFiltersDialog.hpp"
#include "OGCommon.hpp"
#include "IFocusManager.hpp"
#include "IWindowManager.hpp"
#include "windows.h"
#include "Font.hpp"

namespace gui
{
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	constexpr uint16_t SLIDER_WIDTH = 190;
	constexpr uint16_t SLIDER0_X = WINDOW_X+(WINDOW_WIDTH-SLIDER_WIDTH)/2;
	constexpr uint16_t WIN_CONTENT_Y0 = WINDOW_Y + WINDOW_HEADER_HEIGHT + 40 - TEXT_HEIGHT;
	constexpr uint16_t SLIDER_Y = WIN_CONTENT_Y0-MARGIN;
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	SetFiltersDialog::SetFiltersDialog(const IUIContext & context)
		:
		OGDialogCloseBase(context, "Set Band Pass", &_slider.BackgroundLine),
		_hpfFrequencyChangedCmd(this, &SetFiltersDialog::OnHPFFrequencyChanged),
		_lpfFrequencyChangedCmd(this, &SetFiltersDialog::OnLPFFrequencyChanged),

		_slider(*this, SLIDER0_X, SLIDER_Y, SLIDER_WIDTH, 60, 30, 100, 50,
			_modalWindowContext, _hpfFrequencyChangedCmd, _lpfFrequencyChangedCmd)
	{
		AddChild(&_slider.HPFFrequencyCutoffSlider);
		AddChild(&_slider.LPFFrequencyCutoffSlider);

		AddChild(&_slider.BandPassWidthLabel);
		AddChild(&_slider.HPFFrequencyCutoffLabel);
		AddChild(&_slider.LPFFrequencyCutoffLabel);

		_modalWindowContext.FocusManager->RegisterHandler(100, &_slider.HPFFrequencyCutoffSlider);
		_modalWindowContext.FocusManager->RegisterHandler(100, &_slider.LPFFrequencyCutoffSlider);

		_slider.HPFFrequencyCutoffSlider.SetMaxValue(300);
		_slider.HPFFrequencyCutoffSlider.SetMinValue(200);
		_slider.HPFFrequencyCutoffSlider.SetValue(250);
		_slider.HPFFrequencyCutoffLabel.SetIntValue(250, "Hz");

		_slider.LPFFrequencyCutoffSlider.SetMaxValue(3300);
		_slider.LPFFrequencyCutoffSlider.SetMinValue(3200);
		_slider.LPFFrequencyCutoffSlider.SetValue(3250);
		_slider.LPFFrequencyCutoffLabel.SetIntValue(3250, "Hz");

		_slider.BandPassWidthLabel.SetIntValue(3000, "Hz");
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	SetFiltersDialog::~SetFiltersDialog()
	{
		_modalWindowContext.FocusManager->UnregisterHandler(&_slider.HPFFrequencyCutoffSlider);
		_modalWindowContext.FocusManager->UnregisterHandler(&_slider.LPFFrequencyCutoffSlider);
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void SetFiltersDialog::OnHPFFrequencyChanged(int value)
	{
		_slider.HPFFrequencyCutoffLabel.SetIntValue(value, "Hz");
		_slider.HPFFrequencyCutoffLabel.Draw();

		_slider.BandPassWidthLabel.SetIntValue(_slider.LPFFrequencyCutoffSlider.GetValue() - value, "Hz");
		_slider.BandPassWidthLabel.Draw();
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void SetFiltersDialog::OnLPFFrequencyChanged(int value)
	{
		_slider.LPFFrequencyCutoffLabel.SetIntValue(value, "Hz");
		_slider.LPFFrequencyCutoffLabel.Draw();

		_slider.BandPassWidthLabel.SetIntValue(value - _slider.HPFFrequencyCutoffSlider.GetValue(), "Hz");
		_slider.BandPassWidthLabel.Draw();
	}
}