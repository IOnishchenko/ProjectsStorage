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
constexpr uint16_t FREE_SPACE_Y = SCREEN_Y+ROW_HEIGHT*2+MARGIN*4;

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

	_hpfCutoffSlider.Slider.UpdateRange(200, 250, 300);
	_hpfCutoffSlider.Text.SetIntValue(250);

	_lpfCutoffSlider.Slider.UpdateRange(2900, 2950, 3000);
	_lpfCutoffSlider.Text.SetIntValue(2950);

	context.FocusManager->RegisterHandler(100, &_enaCESSB);
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
	_hpfCutoffSlider.Text.SetIntValue(value);
	_hpfCutoffSlider.Text.Draw();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void SSBModulationView::OnLPFCutoffFrequencyChanged(int value)
{
	_lpfCutoffSlider.Text.SetIntValue(value);
	_lpfCutoffSlider.Text.Draw();
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