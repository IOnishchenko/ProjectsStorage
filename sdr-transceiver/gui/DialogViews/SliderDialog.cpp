#include "SliderDialog.hpp"
#include "IFocusManager.hpp"

namespace gui
{
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	constexpr uint16_t WIN_CONTENT_Y0 = WINDOW240x110_Y + WINDOW240x110_HEADER_HEIGHT + 12;
	constexpr uint16_t WIN_CONTENT_OFFSET = 10;
	constexpr uint16_t WIN_CONTENT_X0 = WINDOW240x110_X+WIN_CONTENT_OFFSET;
	constexpr uint16_t SLIDER_WIDTH = WINDOW240x110_WIDTH - WIN_CONTENT_OFFSET*3;

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	SliderDialog::SliderDialog(const IUIContext & context, const std::string_view & headerText,
		int maxValue, int value, const Action<void(int)> & valueChanged)
		:
		OGDialogCloseBase240x110(context, headerText),
		_slider(WIN_CONTENT_X0, WIN_CONTENT_Y0, SLIDER_WIDTH, maxValue, value, _modalWindowContext,
			valueChanged)
	{
		AddChild(&_slider);
		AddChild(&_slider.Text);
		_modalWindowContext.FocusManager->RegisterHandler(100, &_slider);
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	SliderDialog::~SliderDialog()
	{
		_modalWindowContext.FocusManager->UnregisterHandler(&_slider);
	}
}