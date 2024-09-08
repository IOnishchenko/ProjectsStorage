#include "LPFSlider.hpp"
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
	LPFSlider::LPFSlider(uint16_t x, uint16_t y, uint16_t width,
		int maxValue, int value, const IUIContext & context, const Action<void(int)> & valueChanged)
		:
		ISlider(x, y, width, SLIDER_HEIGHT, context, BORDER_SIZE, maxValue, value, valueChanged,
			_disabledLeftTrackPic , _disabledPointerPic, _rightTrackPic,
			_enabledLeftTrackPic, _enabledPointerPic, _rightTrackPic,
			_focusedPointerPic, _pressedPointerPic, _selectedPointerPic),
		_rightTrackPic(0, 0, (width-SLIDER_POINTER_WIDTH)/2, SLIDER_HEIGHT, 0, 0, &background150x18,
			&_enabledPointerPic),
		_disabledPointerPic((width-SLIDER_POINTER_WIDTH)/2, 0, SLIDER_POINTER_WIDTH, SLIDER_HEIGHT,
			0, right150x18dis.width-SLIDER_POINTER_WIDTH, &right150x18dis, &_disabledLeftTrackPic),
		_disabledLeftTrackPic(&right150x18dis, nullptr),
		_enabledPointerPic((width-SLIDER_POINTER_WIDTH)/2, 0, SLIDER_POINTER_WIDTH, SLIDER_HEIGHT,
			0, right150x18ena.width-SLIDER_POINTER_WIDTH, &right150x18ena, &_enabledLeftTrackPic),
		_enabledLeftTrackPic(&right150x18ena, nullptr),
		_focusedPointerPic((width-SLIDER_POINTER_WIDTH)/2, 0, SLIDER_POINTER_WIDTH, SLIDER_HEIGHT,
			0, right150x18foc.width-SLIDER_POINTER_WIDTH, &right150x18foc, &_focusedLeftTrackPic),
		_focusedLeftTrackPic(&right150x18foc, nullptr),
		_pressedPointerPic((width-SLIDER_POINTER_WIDTH)/2, 0, SLIDER_POINTER_WIDTH, SLIDER_HEIGHT,
			0, right150x18press.width-SLIDER_POINTER_WIDTH, &right150x18press, &_pressedLeftTrackPic),
		_pressedLeftTrackPic(&right150x18press, nullptr),
		_selectedPointerPic((width-SLIDER_POINTER_WIDTH)/2, 0, SLIDER_POINTER_WIDTH, SLIDER_HEIGHT,
			0, right150x18sel.width-SLIDER_POINTER_WIDTH, &right150x18sel, &_selectedLeftTrackPic),
		_selectedLeftTrackPic(&right150x18sel, nullptr)
	{
		SyncThumbPositionWithValue();
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	IGElement * LPFSlider::GetGraphicElement()
	{
		switch(_state)
		{
			case State::Disabled:
				_rightTrackPic.SetChild(&_disabledPointerPic);
				_disabledPointerPic.X = _enabledPointerPic.X;
				_disabledLeftTrackPic.X = _enabledLeftTrackPic.X;
				_disabledLeftTrackPic.Width = _enabledLeftTrackPic.Width;
				_disabledLeftTrackPic.Foreground.SkippedRows = _enabledLeftTrackPic.Foreground.SkippedRows;
				break;
			case State::Enabled:
				_rightTrackPic.SetChild(&_enabledPointerPic);
				break;
			case State::Focused:
				_rightTrackPic.SetChild(&_focusedPointerPic);
				_focusedPointerPic.X = _enabledPointerPic.X;
				_focusedLeftTrackPic.X = _enabledLeftTrackPic.X;
				_focusedLeftTrackPic.Width = _enabledLeftTrackPic.Width;
				_focusedLeftTrackPic.Foreground.SkippedRows = _enabledLeftTrackPic.Foreground.SkippedRows;
				break;
			case State::Pressed:
				_rightTrackPic.SetChild(&_pressedPointerPic);
				_pressedPointerPic.X = _enabledPointerPic.X;
				_pressedLeftTrackPic.X = _enabledLeftTrackPic.X;
				_pressedLeftTrackPic.Width = _enabledLeftTrackPic.Width;
				_pressedLeftTrackPic.Foreground.SkippedRows = _enabledLeftTrackPic.Foreground.SkippedRows;
				break;
			case State::Selected:
				_rightTrackPic.SetChild(&_selectedPointerPic);
				_selectedPointerPic.X = _enabledPointerPic.X;
				_selectedLeftTrackPic.X = _enabledLeftTrackPic.X;
				_selectedLeftTrackPic.Width = _enabledLeftTrackPic.Width;
				_selectedLeftTrackPic.Foreground.SkippedRows = _enabledLeftTrackPic.Foreground.SkippedRows;
				break;
			default:
				return nullptr;
		}
		for(IGElement * itm = &_rightTrackPic; itm; itm = itm->PrepareForDrawing());
		return &_rightTrackPic;
	}

	/*-----------------------------------------------------------------//
	//
	//-----------------------------------------------------------------*/
}
}