#include "ISliderVertical.hpp"
#include "ITouchScreenEventObserver.hpp"

namespace gui
{
	/*--------------------------------------------------------------------------//
	// constructors
	//--------------------------------------------------------------------------*/
	ISliderVertical::ISliderVertical(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
		uint16_t borderSize, int maxValue, int value, const Action<void(int)> &onValueChenged,
		GEPicture & disabledTopTrack ,GEPicture & disabledPointer, GEPicture & disabledBottomTrack,
		GEPicture & enabledTopTrack, GEPicture & enabledPointer, GEPicture & enabledBottomTrack,
		GEPicture & focusedPointer, GEPicture & pressedPointer, GEPicture & selectedPointer)
		:
		IToggleFocusUIControl(x, y, w, h, context), MaxValue{maxValue}, MinValue{0}, Value{value},
		_borderSize{borderSize}, _valueChangedCmd(onValueChenged), _disabledTopTrack{disabledTopTrack},
		_disabledPointer{disabledPointer}, _disabledBottomTrack{disabledBottomTrack}, _enabledTopTrack{enabledTopTrack},
		_enabledPointer{enabledPointer}, _enabledBottomTrack{enabledBottomTrack}, _focusedPointer{focusedPointer},
		_pressedPointer{pressedPointer}, _selectedPointer{selectedPointer}
	{
	}

	/*--------------------------------------------------------------------------//
	// destructor
	//--------------------------------------------------------------------------*/
	ISliderVertical::~ISliderVertical()
	{
		//_context.TouchScreenObserver->Unsubscribe(this);
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void ISliderVertical::OnPress(TouchScreenEven & event)
	{
		uint16_t ypen = event.y - Y;
		uint16_t ythumb = _enabledPointer.Y;
		// check if the thumb is under the pen
		if((ypen > ythumb)&&(ypen < (ythumb + _enabledPointer.GetHeight())))
			return;

		OnPenMove(event);
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void ISliderVertical::OnRelease(TouchScreenEven & event)
	{
		SyncThumbPositionWithValue();
		Draw();
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void ISliderVertical::OnPenEnter(TouchScreenEven & event)
	{
		OnPenMove(event);
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void ISliderVertical::OnPenLeave(TouchScreenEven & event)
	{
		OnRelease(event);
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void ISliderVertical::OnPenMove(TouchScreenEven & event)
	{
		auto ypen = event.y - Y;
		if(!((ypen >= _borderSize) && (ypen <= (Height - _borderSize))))
			return;
		// move thumb to position
		ypen = MoveThumbToPosition(ypen);
		// update value according new the thumb position
		int value = CalculateNewValue(ypen);
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
	bool ISliderVertical::IsUnderTouch(uint16_t x, uint16_t y)
	{
		return IsPositionInsideControl(x, y);
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void ISliderVertical::OnEncoderMoved(EncoderEvent & event)
	{
		switch(event.Direction)
		{
			case EncoderDirection::ENC_INCREASE:
			{
				if(Value > MinValue)
					SetValue(Value - 1);
				break;
			}
			case EncoderDirection::ENC_DECREASE:
			{
				if(Value < MaxValue)
					SetValue(Value + 1);
				break;
			}
		}
	}
	
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	IGElement * ISliderVertical::GetGraphicElement()
	{
		switch(_state)
		{
			case State::Disabled:
				for(IGElement * itm = &_disabledTopTrack; itm; itm = itm->PrepareForDrawing());
				_disabledTopTrack.Height = _enabledTopTrack.Height;
				_disabledPointer.Y = _enabledPointer.Y;
				_enabledBottomTrack.Y = _enabledBottomTrack.Y;
				_enabledBottomTrack.Height = _enabledBottomTrack.Height;
				_enabledBottomTrack.Foreground.SkippedLines = _enabledBottomTrack.Foreground.SkippedLines;
				return &_disabledTopTrack;
			case State::Enabled:
				for(IGElement * itm = &_enabledTopTrack; itm; itm = itm->PrepareForDrawing());
				_enabledBottomTrack.SetChild(&_enabledPointer);
				return &_enabledTopTrack;
			case State::Focused:
				for(IGElement * itm = &_enabledTopTrack; itm; itm = itm->PrepareForDrawing());
				_focusedPointer.Y = _enabledPointer.Y;
				_enabledBottomTrack.SetChild(&_focusedPointer);
				return &_enabledTopTrack;
			case State::Pressed:
				for(IGElement * itm = &_enabledTopTrack; itm; itm = itm->PrepareForDrawing());
				_pressedPointer.Y = _enabledPointer.Y;
				_enabledBottomTrack.SetChild(&_pressedPointer);
				return &_enabledTopTrack;
			case State::Selected:
				for(IGElement * itm = &_enabledTopTrack; itm; itm = itm->PrepareForDrawing());
				_selectedPointer.Y = _enabledPointer.Y;
				_enabledBottomTrack.SetChild(&_selectedPointer);
				return &_enabledTopTrack;
			default:
				return nullptr;
		}
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	int ISliderVertical::GetValue()
	{
		return Value;
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void ISliderVertical::SetValue(int value)
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
	uint16_t ISliderVertical::MoveThumbToPosition(uint16_t ypen)
	{
		uint16_t yn; // new position to value calculate
		uint16_t thumbHeight = _enabledPointer.GetHeight();
		
		if(ypen < (thumbHeight/2 + _borderSize))
			yn = _borderSize;
		else if(ypen > (Height - thumbHeight/2 - _borderSize))
			yn = Height - thumbHeight - _borderSize;
		else
			yn = ypen - thumbHeight/2;
		
		SetGraphicElemntsWithThumbPosition(yn);
		return yn;
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void ISliderVertical::SyncThumbPositionWithValue()
	{
		float height = (Height - _borderSize*2 - _enabledPointer.GetHeight());
		float step = height/(MaxValue - MinValue);
		uint16_t y = step * (Value - MinValue) + _borderSize;
		SetGraphicElemntsWithThumbPosition(y);
	}
	
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	int ISliderVertical::CalculateNewValue(uint16_t y)
	{
		float height = (Height - _borderSize*2 - _enabledPointer.GetHeight());
		float step = height/(MaxValue - MinValue);		
		return (y - _borderSize)/step + MinValue;
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void ISliderVertical::SetGraphicElemntsWithThumbPosition(uint16_t y)
	{
		// need an even value
		if(y & 0x01)
			y++;

		_enabledTopTrack.Height = y;

		_enabledPointer.Y = y;
		y += _enabledPointer.GetHeight();

		_enabledBottomTrack.Y = y;
		_enabledBottomTrack.Height = Height - 
			_enabledTopTrack.GetHeight() - _enabledPointer.GetHeight();

		if(_enabledBottomTrack.Height & 0x01)
			_enabledBottomTrack.Height--;

		_enabledBottomTrack.Foreground.SkippedLines =
			_enabledBottomTrack.Foreground.Bitmap->height - _enabledBottomTrack.Height;
	}
}