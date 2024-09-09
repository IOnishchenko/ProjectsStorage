#include "SetFiltersDialog.hpp"
#include "OGCommon.hpp"
#include "IFocusManager.hpp"
#include "IWindowManager.hpp"
#include "windows.h"
#include "Font.hpp"

namespace gui
{
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	constexpr uint16_t WIN_CONTENT_OFFSET = 10;

	constexpr uint16_t WIN_CONTENT_Y0 = WINDOW_Y + WINDOW_HEADER_HEIGHT + 40 - TEXT_HEIGHT;
	constexpr uint16_t WIN_CONTENT_X0 = WINDOW_X+WIN_CONTENT_OFFSET;

	constexpr uint16_t SLIDER_HEIGHT = 18;
	constexpr uint16_t HPF_SLIDER_WIDTH = 70;
	constexpr uint16_t LPF_SLIDER_WIDTH = 120;
	constexpr uint16_t SLIDER0_X = WINDOW_X+(WINDOW_WIDTH-HPF_SLIDER_WIDTH-LPF_SLIDER_WIDTH)/2;
	constexpr uint16_t SLIDER1_X = SLIDER0_X+HPF_SLIDER_WIDTH;

	constexpr uint16_t LABEL_BAND_Y = WIN_CONTENT_Y0-MARGIN;
	constexpr uint16_t SLIDER_Y = LABEL_BAND_Y+TEXT_HEIGHT;
	constexpr uint16_t LABEL_PF_Y = SLIDER_Y+SLIDER_HEIGHT+2+MARGIN;
	constexpr uint16_t LABEL_WIDTH = 60;

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	SetFiltersDialog::SetFiltersDialog(const IUIContext & context)
		:
		OGDialogCloseBase(context, "Set Band Pass", &_bottomLine),
		_hpfFrequencyChangedCmd(this, &SetFiltersDialog::OnHPFFrequencyChanged),
		_lpfFrequencyChangedCmd(this, &SetFiltersDialog::OnLPFFrequencyChanged),

		_hpfSlider(SLIDER0_X, SLIDER_Y, HPF_SLIDER_WIDTH,
			33, 10, _modalWindowContext, _hpfFrequencyChangedCmd),
		_lpfSlider(SLIDER1_X, SLIDER_Y, LPF_SLIDER_WIDTH,
			100, 70, _modalWindowContext, _lpfFrequencyChangedCmd),

		_hpfLabel(SLIDER0_X, LABEL_PF_Y, LABEL_WIDTH, TEXT_HEIGHT,
			context, TEXT_COLOR_DISABLED, BACKGROUND_DARK, TEXT_COLOR, BACKGROUND_DARK, Font18),

		_lpfLabel(SLIDER0_X+HPF_SLIDER_WIDTH+LPF_SLIDER_WIDTH-LABEL_WIDTH, LABEL_PF_Y, LABEL_WIDTH,
			TEXT_HEIGHT, context, TEXT_COLOR_DISABLED, BACKGROUND_DARK, TEXT_COLOR, BACKGROUND_DARK, Font18),

		_bandLabel(WINDOW_X+(WINDOW_WIDTH-LABEL_WIDTH)/2, LABEL_BAND_Y, LABEL_WIDTH, TEXT_HEIGHT,
			context, TEXT_COLOR_DISABLED, BACKGROUND_DARK, TEXT_COLOR, BACKGROUND_DARK, Font18),
		
		// _rightLine(SLIDER0_X-WINDOW_X-2, SLIDER_Y-WINDOW_Y-2, 2,
		// 	_lpfSlider.Height+4, BACKGROUND_LIGHT, nullptr),
		// _topLine(SLIDER0_X-WINDOW_X, SLIDER_Y-WINDOW_Y-2,
		// 	HPF_SLIDER_WIDTH+LPF_SLIDER_WIDTH, 2, BACKGROUND_LIGHT, &_rightLine),
		_bottomLine(SLIDER0_X-WINDOW_X, SLIDER_Y-WINDOW_Y+_lpfSlider.Height,
			HPF_SLIDER_WIDTH+LPF_SLIDER_WIDTH, 2, BACKGROUND_LIGHT, nullptr)
		// _legtLine(SLIDER0_X-WINDOW_X+HPF_SLIDER_WIDTH+LPF_SLIDER_WIDTH, SLIDER_Y-WINDOW_Y-2,
		// 	2, _lpfSlider.Height+4, BACKGROUND_LIGHT, &_bottomLine)
	{
		AddChild(&_hpfSlider);
		AddChild(&_lpfSlider);

		AddChild(&_hpfLabel);
		AddChild(&_lpfLabel);
		AddChild(&_bandLabel);

		_modalWindowContext.FocusManager->RegisterHandler(100, &_hpfSlider);
		_modalWindowContext.FocusManager->RegisterHandler(100, &_lpfSlider);

		_hpfSlider.SetMaxValue(300);
		_hpfSlider.SetMinValue(200);
		_hpfSlider.SetValue(250);
		_hpfLabel.SetIntValue(250, "Hz");

		_lpfSlider.SetMaxValue(3300);
		_lpfSlider.SetMinValue(3200);
		_lpfSlider.SetValue(3250);
		_lpfLabel.SetIntValue(3250, "Hz");

		_bandLabel.SetIntValue(3000, "Hz");
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
		_hpfLabel.SetIntValue(value, "Hz");
		_hpfLabel.Draw();

		_bandLabel.SetIntValue(_lpfSlider.GetValue() - value, "Hz");
		_bandLabel.Draw();
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void SetFiltersDialog::OnLPFFrequencyChanged(int value)
	{
		_lpfLabel.SetIntValue(value, "Hz");
		_lpfLabel.Draw();

		_bandLabel.SetIntValue(value - _hpfSlider.GetValue(), "Hz");
		_bandLabel.Draw();
	}
}