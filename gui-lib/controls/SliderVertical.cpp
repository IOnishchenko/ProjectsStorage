#include "SliderVertical.hpp"

namespace gui
{
	/*--------------------------------------------------------------------------//
	// constructors
	//--------------------------------------------------------------------------*/
	SliderVertical::SliderVertical(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
		uint16_t borderSize, int maxValue, int value, const Action<void(int)> & onValueChenged,
		const GEPicture & thumb, const GEPicture & topTrack, const GEPicture & bottomTrack)
		:IUIControl(x, y, w, h, context), MaxValue{0}, MinValue{0}, Value{value}, _borderSize{borderSize},
		TopTrack{topTrack}, Thumb{thumb}, BottomTrack{bottomTrack}, _valueChangedCmd{onValueChenged}
	{
		SyncThumbPositionWithValue();
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void SliderVertical::OnPress(ITouchScreenEventHandler & event)
	{
		uint16_t ypen = _context.LastTouchScreenEvent.y - Y;
		uint16_t ythumb = Thumb.Y;
		// check if the thumb is under the pen
		if((ypen > ythumb)&&(ypen < (ythumb + Thumb.GetHeight())))
			return;

		OnPenMove(event);
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void SliderVertical::OnRelease(ITouchScreenEventHandler &)
	{
		SyncThumbPositionWithValue();
		Draw();
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void SliderVertical::OnPenEnter(ITouchScreenEventHandler & event)
	{
		OnPenMove(event);
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void SliderVertical::OnPenLeave(ITouchScreenEventHandler & event)
	{
		OnRelease(event);
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void SliderVertical::OnPenMove(ITouchScreenEventHandler &)
	{
		auto ypen = _context.LastTouchScreenEvent.y - Y;
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
	void SliderVertical::OnEncoderMoved(EncoderEvent & action)
	{
		switch(action.Direction)
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
	void SliderVertical::SetValue(int value)
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
	int SliderVertical::GetValue()
	{
		return Value;
	}
	
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	IGElement * SliderVertical::GetGraphicElement()
	{
		return &TopTrack;
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	uint16_t SliderVertical::MoveThumbToPosition(uint16_t ypen)
	{
		uint16_t yn; // new position to value calculate
		uint16_t thumbHeight = Thumb.GetHeight();
		
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
	void SliderVertical::SyncThumbPositionWithValue()
	{
		float height = (Height - _borderSize*2 - Thumb.GetHeight());
		float step = height/(MaxValue - MinValue);
		uint16_t y = step * (Value - MinValue) + _borderSize;
		SetGraphicElemntsWithThumbPosition(y);
	}
	
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	int SliderVertical::CalculateNewValue(uint16_t y)
	{
		float height = (Height - _borderSize*2 - Thumb.GetHeight());
		float step = height/(MaxValue - MinValue);		
		return (y - _borderSize)/step + MinValue;
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void SliderVertical::SetGraphicElemntsWithThumbPosition(uint16_t y)
	{
		// need an even value
		if(y & 0x01)
			y++;

		TopTrack.Height = y;

		Thumb.Y = y;
		y += Thumb.GetHeight();

		BottomTrack.Y = y;
		BottomTrack.Height = Height - TopTrack.GetHeight() - Thumb.GetHeight();
		if(BottomTrack.Height & 0x01)
			BottomTrack.Height--;

		BottomTrack.Foreground.SkippedLines =
			BottomTrack.Foreground.Bitmap.height - BottomTrack.Height;
	}
}