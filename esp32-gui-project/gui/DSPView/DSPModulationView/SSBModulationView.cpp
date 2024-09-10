#include "SSBModulationView.hpp"
#include "OGCommon.hpp"
#include "IFocusManager.hpp"

namespace gui
{
/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
constexpr uint16_t SCREEN_Y = TABCONTROL_HEIGHT * 2;
constexpr uint16_t SCREEN_HEIGHT = FULL_SCREEN_HEIGHT-BOTTOM_MENU_HEIGHT-SCREEN_Y;
constexpr uint16_t FREE_SPACE_Y = SCREEN_Y+TEXT_HEIGHT*3+MARGIN*2;

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
SSBModulationView::SSBModulationView(const IUIContext & context)
	:
	ModulationViewBase(context, _onHPFCutoffChangedCmd, _onLPFCutoffChangedCmd),
	_onHPFCutoffChangedCmd(this, &SSBModulationView::OnHPFCutoffFrequencyChanged),
	_onLPFCutoffChangedCmd(this, &SSBModulationView::OnLPFCutoffFrequencyChanged),
	_onCESSBEnabledCmd(this, &SSBModulationView::OnCESSBEnabled),
	_onCESSBDisabledCmd(this, &SSBModulationView::OnCESSBDisabled),
	_enaCESSB(COLUMN0_X, FREE_SPACE_Y+(ROW_HEIGHT-TEXT_HEIGHT)/2, context,
		_onCESSBEnabledCmd, _onCESSBDisabledCmd, "Disable CESSB:", "Enable CESSB")
{
	AddChild(&_enaCESSB);

	context.FocusManager->RegisterHandler(100, &_enaCESSB);

	_bandPassControls.HPFFrequencyCutoffSlider.UpdateRange(200, 250, 300);
	_bandPassControls.HPFFrequencyCutoffLabel.SetIntValue(250, "Hz");

	_bandPassControls.LPFFrequencyCutoffSlider.UpdateRange(2900, 2950, 3000);
	_bandPassControls.LPFFrequencyCutoffLabel.SetIntValue(2950, "Hz");

	_bandPassControls.BandPassWidthLabel.SetIntValue(2950-250, "Hz");
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
SSBModulationView::~SSBModulationView()
{
	_context.FocusManager->UnregisterHandler(&_enaCESSB);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void SSBModulationView::OnHPFCutoffFrequencyChanged(int value)
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
void SSBModulationView::OnLPFCutoffFrequencyChanged(int value)
{
	_bandPassControls.LPFFrequencyCutoffLabel.SetIntValue(value, "Hz");
	_bandPassControls.LPFFrequencyCutoffLabel.Draw();

	_bandPassControls.BandPassWidthLabel.SetIntValue(
		value-_bandPassControls.HPFFrequencyCutoffSlider.GetValue(), "Hz");
	_bandPassControls.BandPassWidthLabel.Draw();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void SSBModulationView::OnCESSBEnabled(ICheckBox *)
{

}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void SSBModulationView::OnCESSBDisabled(ICheckBox *)
{

}



}