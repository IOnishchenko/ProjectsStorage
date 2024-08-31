
#include "AMModulationView.hpp"

namespace gui
{

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
AMModulationView::AMModulationView(const IUIContext & context)
	:ModulationViewBase(context, _onHPFCutoffChanged, _onLPFCutoffChanged),
	_onHPFCutoffChanged(this, &AMModulationView::OnHPFCutoffFrequencyChanged),
	_onLPFCutoffChanged(this, &AMModulationView::OnLPFCutoffFrequencyChanged)
{
	_hpfCutoffSlider.Slider.UpdateRange(100, 150, 200);
	_hpfCutoffSlider.Text.SetIntValue(150);

	_lpfCutoffSlider.Slider.UpdateRange(6100, 6150, 6200);
	_lpfCutoffSlider.Text.SetIntValue(6150);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void AMModulationView::OnHPFCutoffFrequencyChanged(int value)
{
	_hpfCutoffSlider.Text.SetIntValue(value);
	_hpfCutoffSlider.Text.Draw();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void AMModulationView::OnLPFCutoffFrequencyChanged(int value)
{
	_lpfCutoffSlider.Text.SetIntValue(value);
	_lpfCutoffSlider.Text.Draw();
}

}