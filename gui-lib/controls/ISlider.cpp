#include "ISlider.hpp"
#include "ITouchScreenEventObserver.hpp"

namespace gui
{
	/*--------------------------------------------------------------------------//
	// constructors
	//--------------------------------------------------------------------------*/
	ISlider::ISlider(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
		uint16_t borderSize, int maxValue, int value, const Action<void(int)> &onValueChenged,
		GEPicture & disabledLeftTrack ,GEPicture & disabledPointer, GEPicture & disabledRightTrack,
		GEPicture & enabledLeftTrack, GEPicture & enabledPointer, GEPicture & enabledRightTrack,
		GEPicture & focusedPointer, GEPicture & pressedPointer, GEPicture & selectedPointer)
		:
		IToggleFocusUIControl(x, y, w, h, context), MaxValue{maxValue}, MinValue{0}, Value{value},
		_borderSize{borderSize}, _valueChangedCmd(onValueChenged), _disabledLeftTrack{disabledLeftTrack},
		_disabledPointer{disabledPointer}, _disabledRightTrack{disabledRightTrack}, _enabledLeftTrack{enabledLeftTrack},
		_enabledPointer{enabledPointer}, _enabledRightTrack{enabledRightTrack}, _focusedPointer{focusedPointer},
		_pressedPointer{pressedPointer}, _selectedPointer{selectedPointer}
	{
	}

	/*--------------------------------------------------------------------------//
	// destructor
	//--------------------------------------------------------------------------*/
	ISlider::~ISlider()
	{
		//_context.TouchScreenObserver->Unsubscribe(this);
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void ISlider::OnPress(TouchScreenEven & event)
	{
		uint16_t xpen = event.x - X;
		uint16_t xthumb = _enabledPointer.X;
		// check if the thumb is under the pen
		if((xpen > xthumb)&&(xpen < (xthumb + _enabledPointer.GetWidth())))
			return;

		OnPenMove(event);
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void ISlider::OnRelease(TouchScreenEven & event)
	{
		SyncThumbPositionWithValue();
		Draw();
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void ISlider::OnPenEnter(TouchScreenEven & event)
	{
		OnPenMove(event);
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void ISlider::OnPenLeave(TouchScreenEven & event)
	{
		OnRelease(event);
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void ISlider::OnPenMove(TouchScreenEven & event)
	{
		auto xpen = event.x - X;
		if(!((xpen >= _borderSize) && (xpen <= (Width - _borderSize))))
			return;
		// move thumb to position
		xpen = MoveThumbToPosition(xpen);
		// update value according new the thumb position
		int value = CalculateNewValue(xpen);
		if(value != Value)
		{
			Value = value;
			_valueChangedCmd(value);
		}
		Draw();
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	bool ISlider::IsUnderTouch(uint16_t x, uint16_t y)
	{
		return IsPositionInsideControl(x, y);
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void ISlider::OnEncoderMoved(EncoderEvent & event)
	{
		switch(event.Direction)
		{
			case EncoderDirection::ENC_INCREASE:
			{
				if(Value < MaxValue)
					UpdateValue(Value + 1);
				break;
			}
			case EncoderDirection::ENC_DECREASE:
			{
				if(Value > MinValue)
					UpdateValue(Value - 1);
				break;
			}
		}
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	IGElement * ISlider::GetGraphicElement()
	{
		switch(_state)
		{
			case State::Disabled:
				for(IGElement * itm = &_disabledLeftTrack; itm; itm = itm->PrepareForDrawing());
				_disabledLeftTrack.Width = _enabledLeftTrack.Width;
				_disabledPointer.X = _enabledPointer.X;
				_disabledRightTrack.X = _enabledRightTrack.X;
				_disabledRightTrack.Width = _enabledRightTrack.Width;
				_disabledRightTrack.Foreground.SkippedRows = _enabledRightTrack.Foreground.SkippedRows;
				return &_disabledLeftTrack;
			case State::Enabled:
				for(IGElement * itm = &_enabledLeftTrack; itm; itm = itm->PrepareForDrawing());
				_enabledRightTrack.SetChild(&_enabledPointer);
				return &_enabledLeftTrack;
			case State::Focused:
				for(IGElement * itm = &_enabledLeftTrack; itm; itm = itm->PrepareForDrawing());
				_focusedPointer.X = _enabledPointer.X;
				_enabledRightTrack.SetChild(&_focusedPointer);
				return &_enabledLeftTrack;
			case State::Pressed:
				for(IGElement * itm = &_enabledLeftTrack; itm; itm = itm->PrepareForDrawing());
				_pressedPointer.X = _enabledPointer.X;
				_enabledRightTrack.SetChild(&_pressedPointer);
				return &_enabledLeftTrack;
			case State::Selected:
				for(IGElement * itm = &_enabledLeftTrack; itm; itm = itm->PrepareForDrawing());
				_selectedPointer.X = _enabledPointer.X;
				_enabledRightTrack.SetChild(&_selectedPointer);
				return &_enabledLeftTrack;
			default:
				return nullptr;
		}
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	int ISlider::GetValue()
	{
		return Value;
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void ISlider::SetValue(int value)
	{
		Value = value;
		SyncThumbPositionWithValue();
	}
	
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void ISlider::SetMaxValue(int value)
	{
		MaxValue = value;
		SyncThumbPositionWithValue();
	}
	
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void ISlider::SetMinValue(int value)
	{
		MinValue = value;
		SyncThumbPositionWithValue();
	}
	
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void ISlider::UpdateRange(int minValue, int value, int maxValue)
	{
		MinValue = minValue;
		Value = value;
		MaxValue = maxValue;
		SyncThumbPositionWithValue();
	}
	
	/*--------------------------------------------------------------------------//
	// ---------------------- Protected Methods --------------------------------
	//--------------------------------------------------------------------------*/

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void ISlider::UpdateValue(int value)
	{
		if(Value == value)
			return;
		
		Value = value;
		
		SyncThumbPositionWithValue();
		_valueChangedCmd(value);
		Draw();
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	uint16_t ISlider::MoveThumbToPosition(uint16_t xpen)
	{
		uint16_t xn; // new position to value calculate
		uint16_t thumbWidth = _enabledPointer.GetWidth();
		
		// right the thumb position calculation
		if(xpen < (thumbWidth/2 + _borderSize)) // move left
			xn = _borderSize;
		else if(xpen > (Width - thumbWidth/2 - _borderSize)) // move right
			xn = Width - thumbWidth - _borderSize;
		else
			xn = xpen - thumbWidth/2;
		
		SetGraphicElemntsWithThumbPosition(xn);
		return xn;
	}
	
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void ISlider::SyncThumbPositionWithValue()
	{
		float width = (Width - _borderSize*2 - _enabledPointer.GetWidth());
		float step = width/(MaxValue - MinValue);
		uint16_t x = step * (Value - MinValue) + _borderSize;
		SetGraphicElemntsWithThumbPosition(x);
	}
	
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	int ISlider::CalculateNewValue(uint16_t x)
	{
		float width = (Width - _borderSize*2 - _enabledPointer.GetWidth());
		float step = width/(MaxValue - MinValue);		
		return (x - _borderSize)/step + MinValue;
	}
	
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void ISlider::SetGraphicElemntsWithThumbPosition(uint16_t x)
	{
		// left track gelement
		_enabledLeftTrack.Width = x;
		
		// thumb gelement
		_enabledPointer.X = x;
		
		// right track gelement
		x += _enabledPointer.GetWidth();
		_enabledRightTrack.X = x;
		_enabledRightTrack.Width = Width - x;
		_enabledRightTrack.Foreground.SkippedRows =
			_enabledRightTrack.Foreground.Bitmap->width - _enabledRightTrack.Width;
	}
}