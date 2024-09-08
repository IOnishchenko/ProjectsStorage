#include "SetFiltersDialog.hpp"
#include "OGCommon.hpp"
#include "IFocusManager.hpp"
#include "IWindowManager.hpp"
#include "windows.h"

namespace gui
{
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	constexpr uint16_t WIN_CONTENT_OFFSET = 10;

	constexpr uint16_t WIN_CONTENT_Y0 = WINDOW_Y + WINDOW_HEADER_HEIGHT + 40;
	constexpr uint16_t WIN_CONTENT_X0 = WINDOW_X+WIN_CONTENT_OFFSET;

	constexpr uint16_t HPF_SLIDER_WIDTH = 70;
	constexpr uint16_t LPF_SLIDER_WIDTH = 120;
	constexpr uint16_t SLIDER0_X = WINDOW_X+(WINDOW_WIDTH-HPF_SLIDER_WIDTH-LPF_SLIDER_WIDTH)/2;
	constexpr uint16_t SLIDER1_X = SLIDER0_X+HPF_SLIDER_WIDTH;

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	SetFiltersDialog::SetFiltersDialog(const IUIContext & context)
		:
		OGDialogCloseBase(context, "Set Band Pass", &_legtLine),
		_hpfFrequencyChangedCmd(this, &SetFiltersDialog::OnHPFFrequencyChanged),
		_lpfFrequencyChangedCmd(this, &SetFiltersDialog::OnLPFFrequencyChanged),
		_hpfSlider(SLIDER0_X, WIN_CONTENT_Y0, HPF_SLIDER_WIDTH,
			33, 10, _modalWindowContext, _hpfFrequencyChangedCmd),
		_lpfSlider(SLIDER1_X, WIN_CONTENT_Y0, LPF_SLIDER_WIDTH,
			100, 70, _modalWindowContext, _hpfFrequencyChangedCmd),
		
		_rightLine(SLIDER0_X-WINDOW_X-2, WIN_CONTENT_Y0-WINDOW_Y-2, 2,
			_lpfSlider.Height+4, BACKGROUND_LIGHT, nullptr),
		_topLine(SLIDER0_X-WINDOW_X, WIN_CONTENT_Y0-WINDOW_Y-2,
			HPF_SLIDER_WIDTH+LPF_SLIDER_WIDTH, 2, BACKGROUND_LIGHT, &_rightLine),
		_bottomLine(SLIDER0_X-WINDOW_X, WIN_CONTENT_Y0-WINDOW_Y+_lpfSlider.Height,
			HPF_SLIDER_WIDTH+LPF_SLIDER_WIDTH, 2, BACKGROUND_LIGHT, &_topLine),
		_legtLine(SLIDER0_X-WINDOW_X+HPF_SLIDER_WIDTH+LPF_SLIDER_WIDTH, WIN_CONTENT_Y0-WINDOW_Y-2,
			2, _lpfSlider.Height+4, BACKGROUND_LIGHT, &_bottomLine)
	{
		AddChild(&_hpfSlider);
		AddChild(&_lpfSlider);
		_modalWindowContext.FocusManager->RegisterHandler(100, &_hpfSlider);
		_modalWindowContext.FocusManager->RegisterHandler(100, &_lpfSlider);
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	SetFiltersDialog::~SetFiltersDialog()
	{
		_modalWindowContext.FocusManager->UnregisterHandler(&_hpfSlider);
		_modalWindowContext.FocusManager->UnregisterHandler(&_lpfSlider);
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void SetFiltersDialog::OnHPFFrequencyChanged(int value)
	{
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void SetFiltersDialog::OnLPFFrequencyChanged(int value)
	{
	}
}