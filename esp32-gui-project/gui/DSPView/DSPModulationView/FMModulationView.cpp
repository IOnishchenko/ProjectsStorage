#include "FMModulationView.hpp"

namespace gui
{

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
FMModulationView::FMModulationView(const IUIContext & context)
	:ModulationViewBase(context, _onHPFCutoffChanged, _onLPFCutoffChanged),
	_onHPFCutoffChanged(this, &FMModulationView::OnHPFCutoffFrequencyChanged),
	_onLPFCutoffChanged(this, &FMModulationView::OnLPFCutoffFrequencyChanged)
{
	_hpfCutoffSlider.Slider.UpdateRange(200, 230, 300);
	_hpfCutoffSlider.Text.SetIntValue(230);

	_lpfCutoffSlider.Slider.UpdateRange(5100, 5150, 5200);
	_lpfCutoffSlider.Text.SetIntValue(5150);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void FMModulationView::OnHPFCutoffFrequencyChanged(int value)
{
	_hpfCutoffSlider.Text.SetIntValue(value);
	_hpfCutoffSlider.Text.Draw();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void FMModulationView::OnLPFCutoffFrequencyChanged(int value)
{
	_lpfCutoffSlider.Text.SetIntValue(value);
	_lpfCutoffSlider.Text.Draw();
}

}
