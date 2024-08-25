#include "OGSliderHorizontal.hpp"
#include "hslider.h"

namespace gui
{
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	constexpr uint16_t HEIGHT = 12;
	constexpr uint16_t BORDER_SIZE = 3;

	/*--------------------------------------------------------------------------//
	// constructors
	//--------------------------------------------------------------------------*/
	OGSliderHorizontal::OGSliderHorizontal(uint16_t x, uint16_t y, uint16_t width,
		int maxValue, int value, const IUIContext & context, const Action<void(int)> & valueChanged)
		:ISlider(x, y, width, HEIGHT, context, BORDER_SIZE, maxValue, value, valueChanged,
			_disabledLeftTrackPic , _disabledPointerPic, _disabledRightTrackPic, _enabledLeftTrackPic,
			_enabledPointerPic, _enabledRightTrackPic, _focusedPointerPic, _pressedPointerPic,
			_selectedPointerPic),
		_disabledLeftTrackPic(&lefttrack12x280disabled, &_disabledRightTrackPic),
		_disabledPointerPic(&hpointer12x12disabled, nullptr),
		_disabledRightTrackPic(&righttrack12x280disabled, &_disabledPointerPic),
		_enabledLeftTrackPic(&lefttrack12x280enabled, &_enabledRightTrackPic),
		_enabledPointerPic(&hpointer12x12enabled, nullptr),
		_enabledRightTrackPic(&righttrack12x280enabled, &_enabledPointerPic),
		_focusedPointerPic(&hpointer12x12focused, nullptr),
		_pressedPointerPic(&hpointer12x12pressed, nullptr),
		_selectedPointerPic(&hpointer12x12selected, nullptr)
	{
		SyncThumbPositionWithValue();
	}
}