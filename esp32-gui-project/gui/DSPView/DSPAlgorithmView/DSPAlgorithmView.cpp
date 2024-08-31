
#include "DSPAlgorithmView.hpp"
#include "OGCommon.hpp"
#include "DSPAGCView.hpp"

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
DSPAlgorithmView::DSPAlgorithmView(const IUIContext & context)
	:OGTabControl5T(SCREEN_Y, SCREEN_HEIGHT, context,
		"AGC", "NR", "NB", "NOTCH", "SQLCH",
		_onAGCClikedCmd, _onNRClikedCmd, _onNBClikedCmd, _onNotchClikedCmd, _onSquelschClikedCmd),
	_onAGCClikedCmd(this, &DSPAlgorithmView::OnAGCClicked),
	_onNRClikedCmd(this, &DSPAlgorithmView::OnNRClicked),
	_onNBClikedCmd(this, &DSPAlgorithmView::OnNBClicked),
	_onNotchClikedCmd(this, &DSPAlgorithmView::OnNotchClicked),
	_onSquelschClikedCmd(this, &DSPAlgorithmView::OnSquelchClicked),
	_subGroup{new DSPAGCView(context)}
{
	AddChild(_subGroup.get());
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void DSPAlgorithmView::OnAGCClicked(IRadioButton *)
{
	RemoveChild(_subGroup.get());
	_subGroup.reset();
	_subGroup = std::make_unique<DSPAGCView>(_context);
	AddChild(_subGroup.get());
	_subGroup->Draw();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void DSPAlgorithmView::OnNRClicked(IRadioButton *)
{
	RemoveChild(_subGroup.get());
	_subGroup.reset();
	_subGroup = std::make_unique<DSPAGCView>(_context);
	AddChild(_subGroup.get());
	_subGroup->Draw();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void DSPAlgorithmView::OnNBClicked(IRadioButton *)
{
	RemoveChild(_subGroup.get());
	_subGroup.reset();
	_subGroup = std::make_unique<DSPAGCView>(_context);
	AddChild(_subGroup.get());
	_subGroup->Draw();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void DSPAlgorithmView::OnNotchClicked(IRadioButton *)
{
	RemoveChild(_subGroup.get());
	_subGroup.reset();
	_subGroup = std::make_unique<DSPAGCView>(_context);
	AddChild(_subGroup.get());
	_subGroup->Draw();
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void DSPAlgorithmView::OnSquelchClicked(IRadioButton *)
{
	RemoveChild(_subGroup.get());
	_subGroup.reset();
	_subGroup = std::make_unique<DSPAGCView>(_context);
	AddChild(_subGroup.get());
	_subGroup->Draw();
}

}
