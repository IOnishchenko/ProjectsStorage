
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
	_hpfCutoffSlider.UpdateRange(100, 150, 200);
	_hpfCutoffSlider.Text.SetIntValue(150, "Hz");

	_lpfCutoffSlider.UpdateRange(6100, 6150, 6200);
	_lpfCutoffSlider.Text.SetIntValue(6150, "Hz");
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void AMModulationView::OnHPFCutoffFrequencyChanged(int value)
{
	_hpfCutoffSlider.Text.SetIntValue(value, "Hz");
	_hpfCutoffSlider.Text.Draw();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void AMModulationView::OnLPFCutoffFrequencyChanged(int value)
{
	_lpfCutoffSlider.Text.SetIntValue(value, "Hz");
	_lpfCutoffSlider.Text.Draw();
}

}