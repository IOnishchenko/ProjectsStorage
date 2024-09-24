#include "HPFSlider.hpp"
#include "OGCommon.hpp"
#include "filter_slider.h"

namespace gui
{
namespace custom
{
	/*-----------------------------------------------------------------//
	//
	//-----------------------------------------------------------------*/
	constexpr uint16_t SLIDER_POINTER_WIDTH = 12;
	constexpr uint16_t SLIDER_HEIGHT = 18;
	constexpr uint16_t BORDER_SIZE = 3;

	/*-----------------------------------------------------------------//
	//
	//-----------------------------------------------------------------*/
	HPFSlider::HPFSlider(uint16_t x, uint16_t y, uint16_t width,
		int maxValue, int value, const IUIContext & context, const Action<void(int)> & valueChanged)
		:
		ISlider(x, y, width, SLIDER_HEIGHT, context, BORDER_SIZE, maxValue, value, valueChanged,
			_leftTrackPic , _disabledPointerPic, _disabledRightTrackPic,
			_leftTrackPic, _enabledPointerPic, _enabledRightTrackPic,
			_focusedPointerPic, _pressedPointerPic, _selectedPointerPic),
		_leftTrackPic(0, 0, (width-SLIDER_POINTER_WIDTH)/2, SLIDER_HEIGHT, 0, 0, &background150x18,
			&_enabledPointerPic),
		_disabledPointerPic((width-SLIDER_POINTER_WIDTH)/2, 0, SLIDER_POINTER_WIDTH, SLIDER_HEIGHT,
			0, 0, &left150x18dis, &_disabledRightTrackPic),
		_disabledRightTrackPic(&left150x18dis, nullptr),
		_enabledPointerPic((width-SLIDER_POINTER_WIDTH)/2, 0, SLIDER_POINTER_WIDTH, SLIDER_HEIGHT,
			0, 0, &left150x18ena, &_enabledRightTrackPic),
		_enabledRightTrackPic(&left150x18ena, nullptr),
		_focusedPointerPic((width-SLIDER_POINTER_WIDTH)/2, 0, SLIDER_POINTER_WIDTH, SLIDER_HEIGHT,
			0, 0, &left150x18foc, &_focusedRightTrackPic),
		_focusedRightTrackPic(&left150x18foc, nullptr),
		_pressedPointerPic((width-SLIDER_POINTER_WIDTH)/2, 0, SLIDER_POINTER_WIDTH, SLIDER_HEIGHT,
			0, 0, &left150x18press, &_pressedRightTrackPic),
		_pressedRightTrackPic(&left150x18press, nullptr),
		_selectedPointerPic((width-SLIDER_POINTER_WIDTH)/2, 0, SLIDER_POINTER_WIDTH, SLIDER_HEIGHT,
			0, 0, &left150x18sel, &_selectedRightTrackPic),
		_selectedRightTrackPic(&left150x18sel, nullptr)
	{
		SyncThumbPositionWithValue();
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	IGElement * HPFSlider::GetGraphicElement()
	{
		switch(_state)
		{
			case State::Disabled:
				_leftTrackPic.SetChild(&_disabledPointerPic);
				_disabledPointerPic.X = _enabledPointerPic.X;
				_disabledRightTrackPic.X = _enabledRightTrackPic.X;
				_disabledRightTrackPic.Width = _enabledRightTrackPic.Width;
				_disabledRightTrackPic.Foreground.SkippedRows = _enabledRightTrackPic.Foreground.SkippedRows;
				break;
			case State::Enabled:
				_leftTrackPic.SetChild(&_enabledPointerPic);
				break;
			case State::Focused:
				_leftTrackPic.SetChild(&_focusedPointerPic);
				_focusedPointerPic.X = _enabledPointerPic.X;
				_focusedRightTrackPic.X = _enabledRightTrackPic.X;
				_focusedRightTrackPic.Width = _enabledRightTrackPic.Width;
				_focusedRightTrackPic.Foreground.SkippedRows = _enabledRightTrackPic.Foreground.SkippedRows;
				break;
			case State::Pressed:
				_leftTrackPic.SetChild(&_pressedPointerPic);
				_pressedPointerPic.X = _enabledPointerPic.X;
				_pressedRightTrackPic.X = _enabledRightTrackPic.X;
				_pressedRightTrackPic.Width = _enabledRightTrackPic.Width;
				_pressedRightTrackPic.Foreground.SkippedRows = _enabledRightTrackPic.Foreground.SkippedRows;
				break;
			case State::Selected:
				_leftTrackPic.SetChild(&_selectedPointerPic);
				_selectedPointerPic.X = _enabledPointerPic.X;
				_selectedRightTrackPic.X = _enabledRightTrackPic.X;
				_selectedRightTrackPic.Width = _enabledRightTrackPic.Width;
				_selectedRightTrackPic.Foreground.SkippedRows = _enabledRightTrackPic.Foreground.SkippedRows;
				break;
			default:
				return nullptr;
		}
		for(IGElement * itm = &_leftTrackPic; itm; itm = itm->PrepareForDrawing());
		return &_leftTrackPic;
	}

	/*-----------------------------------------------------------------//
	//
	//-----------------------------------------------------------------*/
}
}