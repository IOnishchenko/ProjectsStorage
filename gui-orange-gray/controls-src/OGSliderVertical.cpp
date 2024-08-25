#include "OGSliderVertical.hpp"
#include "vslider.h"

namespace gui
{
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	constexpr uint16_t WIDTH = 12;
	constexpr uint16_t BORDER_SIZE = 3;

	/*--------------------------------------------------------------------------//
	// constructors
	//--------------------------------------------------------------------------*/
	OGSliderVertical::OGSliderVertical(uint16_t x, uint16_t y, uint16_t height,
		int maxValue, int value, const IUIContext & context, const Action<void(int)> & valueChanged)
		:ISliderVertical(x, y, WIDTH, height, context, BORDER_SIZE, maxValue, value, valueChanged,
			_disabledTopTrackPic , _disabledPointerPic, _disabledBottomTrackPic, _enabledTopTrackPic,
			_enabledPointerPic, _enabledBottomTrackPic, _focusedPointerPic, _pressedPointerPic,
			_selectedPointerPic),
		_disabledTopTrackPic(&toptrack12x200disabled, &_disabledBottomTrackPic),
		_disabledPointerPic(&vpointer12x12disabled, nullptr),
		_disabledBottomTrackPic(&bottomtrack12x200disabled, &_disabledPointerPic),
		_enabledTopTrackPic(&toptrack12x200enabled, &_enabledBottomTrackPic),
		_enabledPointerPic(&vpointer12x12enabled, nullptr),
		_enabledBottomTrackPic(&bottomtrack12x200enabled, &_enabledPointerPic),
		_focusedPointerPic(&vpointer12x12focused, nullptr),
		_pressedPointerPic(&vpointer12x12pressed, nullptr),
		_selectedPointerPic(&vpointer12x12selected, nullptr)
	{
		SyncThumbPositionWithValue();
	}
}