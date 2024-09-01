
#include "CWModulationView.hpp"

namespace gui
{

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
CWModulationView::CWModulationView(const IUIContext & context)
	:ModulationViewBase(context, _onHPFCutoffChanged, _onLPFCutoffChanged),
	_onHPFCutoffChanged(this, &CWModulationView::OnHPFCutoffFrequencyChanged),
	_onLPFCutoffChanged(this, &CWModulationView::OnLPFCutoffFrequencyChanged)
{
	_hpfCutoffSlider.UpdateRange(50, 80, 100);
	_hpfCutoffSlider.Text.SetIntValue(80);

	_lpfCutoffSlider.UpdateRange(900, 950, 1000);
	_lpfCutoffSlider.Text.SetIntValue(950);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void CWModulationView::OnHPFCutoffFrequencyChanged(int value)
{
	_hpfCutoffSlider.Text.SetIntValue(value);
	_hpfCutoffSlider.Text.Draw();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void CWModulationView::OnLPFCutoffFrequencyChanged(int value)
{
	_lpfCutoffSlider.Text.SetIntValue(value);
	_lpfCutoffSlider.Text.Draw();
}

}