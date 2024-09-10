
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
		&_bandPassControls.BandPassWidthLabel, &_bandPassControls.HPFFrequencyCutoffLabel,
		&_bandPassControls.HPFFrequencyCutoffSlider, &_bandPassControls.LPFFrequencyCutoffLabel,
		&_bandPassControls.LPFFrequencyCutoffSlider,
	}, &_background),

	_bandPassControls(*this, COLUMN1_X, SCREEN_Y+MARGIN, COLUMN1_WIDT, 60, 30, 100, 50,
		context, hpfCutofChanged, lpfCutofChanged),

	_headerText0(COLUMN0_X, MARGIN*2, COLUMN0_WIDT, TEXT_HEIGHT, "HPF and LPF",
		TEXT_COLOR, BACKGROUND_DARK, Font18, &_bandPassControls.BackgroundLine),
	_headerText1(COLUMN0_X, MARGIN*2+TEXT_HEIGHT, COLUMN0_WIDT, TEXT_HEIGHT, "Cutoff",
		TEXT_COLOR, BACKGROUND_DARK, Font18, &_headerText0),
	_headerText2(COLUMN0_X, MARGIN*2+TEXT_HEIGHT*2, COLUMN0_WIDT, TEXT_HEIGHT, "Frequency:",
		TEXT_COLOR, BACKGROUND_DARK, Font18, &_headerText1),

	_background(0, 0, FULL_SCREEN_WIDTH, SCREEN_HEIGHT, BACKGROUND_DARK, &_headerText2)
{
	context.FocusManager->RegisterHandler(100, &_bandPassControls.HPFFrequencyCutoffSlider);
	context.FocusManager->RegisterHandler(100, &_bandPassControls.LPFFrequencyCutoffSlider);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
ModulationViewBase::~ModulationViewBase()
{
	_context.FocusManager->UnregisterHandler(&_bandPassControls.HPFFrequencyCutoffSlider);
	_context.FocusManager->UnregisterHandler(&_bandPassControls.LPFFrequencyCutoffSlider);
}

}