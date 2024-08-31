
#include "DSPModulationView.hpp"
#include "OGCommon.hpp"
#include "AMModulationView.hpp"
#include "CWModulationView.hpp"
#include "FMModulationView.hpp"
#include "SSBModulationView.hpp"

namespace gui
{

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
constexpr uint16_t SCREEN_Y = TABCONTROL_HEIGHT;
constexpr uint16_t SCREEN_HEIGHT = FULL_SCREEN_HEIGHT-BOTTOM_MENU_HEIGHT-SCREEN_Y;

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
DSPModulationView::DSPModulationView(const IUIContext & context)
	:OGTabControl5T(SCREEN_Y, SCREEN_HEIGHT, context,
		"AM", "SSB", "FM", "CW", "TODO",
		_onAMClikedCmd, _onSSBClikedCmd, _onFMClikedCmd, _onCWClikedCmd, _onTODOClikedCmd),
	_onAMClikedCmd(this, &DSPModulationView::OnAMClicked),
	_onSSBClikedCmd(this, &DSPModulationView::OnSSBClicked),
	_onFMClikedCmd(this, &DSPModulationView::OnFMClicked),
	_onCWClikedCmd(this, &DSPModulationView::OnCWClicked),
	_onTODOClikedCmd(this, &DSPModulationView::OnTODOClicked),
	_subGroup{new AMModulationView(context)}
{
	AddChild(_subGroup.get());
	_tab5RButton.SetEnable(false);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void DSPModulationView::OnAMClicked(IRadioButton *)
{
	RemoveChild(_subGroup.get());
	_subGroup.reset();
	_subGroup = std::make_unique<AMModulationView>(_context);
	AddChild(_subGroup.get());
	_subGroup->Draw();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void DSPModulationView::OnSSBClicked(IRadioButton *)
{
	RemoveChild(_subGroup.get());
	_subGroup.reset();
	_subGroup = std::make_unique<SSBModulationView>(_context);
	AddChild(_subGroup.get());
	_subGroup->Draw();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void DSPModulationView::OnFMClicked(IRadioButton *)
{
	RemoveChild(_subGroup.get());
	_subGroup.reset();
	_subGroup = std::make_unique<FMModulationView>(_context);
	AddChild(_subGroup.get());
	_subGroup->Draw();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void DSPModulationView::OnCWClicked(IRadioButton *)
{
	RemoveChild(_subGroup.get());
	_subGroup.reset();
	_subGroup = std::make_unique<CWModulationView>(_context);
	AddChild(_subGroup.get());
	_subGroup->Draw();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void DSPModulationView::OnTODOClicked(IRadioButton *)
{
	// RemoveChild(_subGroup.get());
	// _subGroup.reset();
	// _subGroup = std::make_unique<CWModulationView>(_context);
	// AddChild(_subGroup.get());
	// _subGroup->Draw();
}

}