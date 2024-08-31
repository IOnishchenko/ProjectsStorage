#include "DSPView.hpp"
#include "OGCommon.hpp"
#include "DSPModulationView.hpp"
#include "DSPAlgorithmView.hpp"

namespace gui
{

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
constexpr uint16_t SCREEN_Y = 0;
constexpr uint16_t SCREEN_HEIGHT = FULL_SCREEN_HEIGHT-BOTTOM_MENU_HEIGHT-SCREEN_Y;

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
DSPView::DSPView(const IUIContext & context)
	:OGTabControl2T(SCREEN_Y, SCREEN_HEIGHT, context, "MODULATIONS", "ALGORITHMS",
	_onModulationClikedCmd, _onAlgorithmClikedCmd),
	_onModulationClikedCmd(this, &DSPView::OnModulationClicked),
	_onAlgorithmClikedCmd(this, &DSPView::OnAlgorithmClicked),
	_subGroup{new DSPModulationView(context)}
{
	AddChild(_subGroup.get());
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void DSPView::OnModulationClicked(IRadioButton *)
{
	RemoveChild(_subGroup.get());
	_subGroup.reset();
	_subGroup = std::make_unique<DSPModulationView>(_context);
	AddChild(_subGroup.get());
	_subGroup->Draw();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void DSPView::OnAlgorithmClicked(IRadioButton *)
{
	RemoveChild(_subGroup.get());
	_subGroup.reset();
	_subGroup = std::make_unique<DSPAlgorithmView>(_context);
	AddChild(_subGroup.get());
	_subGroup->Draw();
}

}