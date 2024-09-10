
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
	_bandPassControls.HPFFrequencyCutoffSlider.UpdateRange(100, 150, 200);
	_bandPassControls.HPFFrequencyCutoffLabel.SetIntValue(150, "Hz");

	_bandPassControls.LPFFrequencyCutoffSlider.UpdateRange(6100, 6150, 6200);
	_bandPassControls.LPFFrequencyCutoffLabel.SetIntValue(6150, "Hz");

	_bandPassControls.BandPassWidthLabel.SetIntValue(6000, "Hz");
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void AMModulationView::OnHPFCutoffFrequencyChanged(int value)
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
void AMModulationView::OnLPFCutoffFrequencyChanged(int value)
{
	_bandPassControls.LPFFrequencyCutoffLabel.SetIntValue(value, "Hz");
	_bandPassControls.LPFFrequencyCutoffLabel.Draw();

	_bandPassControls.BandPassWidthLabel.SetIntValue(
		value-_bandPassControls.HPFFrequencyCutoffSlider.GetValue(), "Hz");
	_bandPassControls.BandPassWidthLabel.Draw();
}

}