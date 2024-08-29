#include "OGNumericUpDown.hpp"
#include "OGCommon.hpp"
#include "button193x44.h"

namespace gui
{
	constexpr uint16_t WIDTH = 193;
	constexpr uint16_t HEIGHT = 44;

	/*--------------------------------------------------------------------------//
	// Constructor
	//--------------------------------------------------------------------------*/
	OGNumericUpDown::OGNumericUpDown(uint16_t x, uint16_t y,	const IUIContext & context,
		const Action<void(const Parameters &)> & valueChanged)
		:NumericUpDown(x, y, WIDTH, HEIGHT, context, _disabledPic, _enabledPic, _focusedPic,
		_pressedPic, _selectedPic, TEXT_COLOR_DISABLED, BACKGROUND_DISABLED, TEXT_COLOR,
		BACKGROUND_GRAY, TEXT_COLOR, BACKGROUND_GRAY, TEXT_COLOR, BACKGROUND_LIGHT,
		TEXT_COLOR, BACKGROUND_GRAY, Font32, valueChanged),
		_disabledPic(&button193x44disabled, &_textGelement),
		_enabledPic(&button193x44enabled, &_textGelement),
		_focusedPic(&button193x44focused, &_textGelement),
		_pressedPic(&button193x44pressed, &_textGelement),
		_selectedPic(&button193x44enabled, &_textGelement)
	{
	}
}