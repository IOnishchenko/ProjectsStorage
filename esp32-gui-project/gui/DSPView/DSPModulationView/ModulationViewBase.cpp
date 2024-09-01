
#include "ModulationViewBase.hpp"
#include "IFocusManager.hpp"
#include "OGCommon.hpp"

namespace gui
{
/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
constexpr uint16_t SCREEN_Y = TABCONTROL_HEIGHT * 2;
constexpr uint16_t SCREEN_HEIGHT = FULL_SCREEN_HEIGHT-BOTTOM_MENU_HEIGHT-SCREEN_Y;

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
ModulationViewBase::ModulationViewBase(const IUIContext & context,
	const Action<void(int)> & hpfCutofChanged,
	const Action<void(int)> & lpfCutofChanged)
	:
	Group(0, SCREEN_Y, FULL_SCREEN_WIDTH, SCREEN_HEIGHT, context,
	{
		&_hpfCutoffSlider.Text, &_hpfCutoffSlider,
		&_lpfCutoffSlider.Text, &_lpfCutoffSlider,
	}, &_background),
	_hpfCutoffSlider(SCREEN_Y, SCREEN_Y+MARGIN*2, 100, 10, context, hpfCutofChanged,
		"HPF Cutoff", "Frequency:", nullptr),
	_lpfCutoffSlider(SCREEN_Y, SCREEN_Y+MARGIN*3+ROW_HEIGHT, 30, 5, context,
		lpfCutofChanged, "LPF Cutoff", "Frequency:", _hpfCutoffSlider.Header),

	_background(0, 0, FULL_SCREEN_WIDTH, SCREEN_HEIGHT, BACKGROUND_DARK, _lpfCutoffSlider.Header)
{
	context.FocusManager->RegisterHandler(100, &_hpfCutoffSlider);
	context.FocusManager->RegisterHandler(100, &_lpfCutoffSlider);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
ModulationViewBase::~ModulationViewBase()
{
	_context.FocusManager->UnregisterHandler(&_hpfCutoffSlider);
	_context.FocusManager->UnregisterHandler(&_lpfCutoffSlider);
}

}