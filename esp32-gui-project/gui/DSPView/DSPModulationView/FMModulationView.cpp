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
	_bandPassControls.HPFFrequencyCutoffSlider.UpdateRange(200, 230, 300);
	_bandPassControls.HPFFrequencyCutoffLabel.SetIntValue(230, "Hz");

	_bandPassControls.LPFFrequencyCutoffSlider.UpdateRange(5100, 5150, 5200);
	_bandPassControls.LPFFrequencyCutoffLabel.SetIntValue(5150, "Hz");

	_bandPassControls.BandPassWidthLabel.SetIntValue(5150-230, "Hz");
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void FMModulationView::OnHPFCutoffFrequencyChanged(int value)
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
void FMModulationView::OnLPFCutoffFrequencyChanged(int value)
{
	_bandPassControls.LPFFrequencyCutoffLabel.SetIntValue(value, "Hz");
	_bandPassControls.LPFFrequencyCutoffLabel.Draw();

	_bandPassControls.BandPassWidthLabel.SetIntValue(
		value-_bandPassControls.HPFFrequencyCutoffSlider.GetValue(), "Hz");
	_bandPassControls.BandPassWidthLabel.Draw();
}

}
