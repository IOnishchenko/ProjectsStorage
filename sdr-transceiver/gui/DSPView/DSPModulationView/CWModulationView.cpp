
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
	_bandPassControls.HPFFrequencyCutoffSlider.UpdateRange(50, 80, 100);
	_bandPassControls.HPFFrequencyCutoffLabel.SetIntValue(80, "Hz");

	_bandPassControls.LPFFrequencyCutoffSlider.UpdateRange(900, 950, 1000);
	_bandPassControls.LPFFrequencyCutoffLabel.SetIntValue(950, "Hz");

	_bandPassControls.BandPassWidthLabel.SetIntValue(950-80, "Hz");
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void CWModulationView::OnHPFCutoffFrequencyChanged(int value)
{
	_bandPassControls.HPFFrequencyCutoffLabel.SetIntValue(value, "Hz");
	_bandPassControls.HPFFrequencyCutoffLabel.Draw();

	_bandPassControls.BandPassWidthLabel.SetIntValue(
		_bandPassControls.LPFFrequencyCutoffSlider.GetValue()-value, "Hz");
	_bandPassControls.BandPassWidthLabel.Draw();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void CWModulationView::OnLPFCutoffFrequencyChanged(int value)
{
	_bandPassControls.LPFFrequencyCutoffLabel.SetIntValue(value, "Hz");
	_bandPassControls.LPFFrequencyCutoffLabel.Draw();

	_bandPassControls.BandPassWidthLabel.SetIntValue(
		value-_bandPassControls.HPFFrequencyCutoffSlider.GetValue(), "Hz");
	_bandPassControls.BandPassWidthLabel.Draw();
}

}