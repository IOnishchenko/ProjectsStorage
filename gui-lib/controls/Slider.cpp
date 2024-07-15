#include "Slider.hpp"

namespace gui
{
	/*--------------------------------------------------------------------------//
	// constructors
	//--------------------------------------------------------------------------*/
	Slider::Slider(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
		uint16_t borderSize, int maxValue, int value, const Action<void(int)> &onValueChenged,
		const GEPicture &thumb, const GEPicture &leftTrack, const GEPicture &rightTrack)
		:UIControl(x, y, w, h, context), MaxValue{0}, MinValue{0}, Value{value}, _borderSize{borderSize},
		_valueChengedCmd{onValueChenged}, LeftTrack{LeftTrack}, Thumb{thumb}, RightTrack{RightTrack}
	{
		SyncThumbPositionWithValue();
	}

	/*--------------------------------------------------------------------------//
	// ------------------------- Public Methods --------------------------------
	//--------------------------------------------------------------------------*/
	
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void Slider::OnPress(TouchScreenEven & pen)
	{
		uint16_t xpen = pen.x - X;
		uint16_t xthumb = Thumb.X;
		// check if the thumb is under the pen
		if((xpen > xthumb)&&(xpen < (xthumb + Thumb.GetWidth())))
			return;

		OnPenMove(pen);
	}
	
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void Slider::OnRelease(TouchScreenEven & pen)
	{
		SyncThumbPositionWithValue();
		Draw();
	}
	
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void Slider::OnPenEnter(TouchScreenEven & pen)
	{
		OnPenMove(pen);
	}
	
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void Slider::OnPenLeave(TouchScreenEven & pen)
	{
		OnRelease(pen);
	}
	
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void Slider::OnPenMove(TouchScreenEven & pen)
	{
		auto xpen = pen.x - X;
		if(!((xpen >= _borderSize) && (xpen <= (Width - _borderSize))))
			return;
		// move thumb to position
		xpen = MoveThumbToPosition(xpen);
		// update value according new the thumb position
		int value = CalculateNewValue(xpen);
		if(value != Value)
		{
			Value = value;
			_valueChengedCmd(value);
		}
		Draw();
	}
	
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void Slider::OnEncoderMoved(EncoderEvent & action)
	{
		switch(action.Direction)
		{
			case EncoderDirection::ENC_INCREASE:
			{
				if(Value < MaxValue)
					SetValue(Value + 1);
				break;
			}
			case EncoderDirection::ENC_DECREASE:
			{
				if(Value > MinValue)
					SetValue(Value - 1);
				break;
			}
		}
	}
	
	// /*--------------------------------------------------------------------------//
	// // 
	// //--------------------------------------------------------------------------*/
	// void Slider::OnInitialize(int value)
	// {
	// 	SyncThumbPositionWithValue();
	// }
	
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void Slider::SetValue(int value)
	{
		if(Value == value)
			return;
		
		Value = value;
		
		SyncThumbPositionWithValue();
		_valueChengedCmd(value);
		Draw();
	}
	
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	int Slider::GetValue()
	{
		return Value;
	}
	
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	IGElement * Slider::GetGraphicElement()
	{
		return &LeftTrack;
	}
	
	/*--------------------------------------------------------------------------//
	// ---------------------- Protected Methods --------------------------------
	//--------------------------------------------------------------------------*/
	
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	uint16_t Slider::MoveThumbToPosition(uint16_t xpen)
	{
		uint16_t xn; // new position to value calculate
		uint16_t thumbWidth = Thumb.GetWidth();
		
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
	void Slider::SyncThumbPositionWithValue()
	{
		float width = (Width - _borderSize*2 - Thumb.GetWidth());
		float step = width/(MaxValue - MinValue);
		uint16_t x = step * (Value - MinValue) + _borderSize;
		SetGraphicElemntsWithThumbPosition(x);
	}
	
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	int Slider::CalculateNewValue(uint16_t x)
	{
		float width = (Width - _borderSize*2 - Thumb.GetWidth());
		float step = width/(MaxValue - MinValue);		
		return (x - _borderSize)/step + MinValue;
	}
	
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void Slider::SetGraphicElemntsWithThumbPosition(uint16_t x)
	{
		// left track gelement
		LeftTrack.PictureData.Width = x;
		
		// thumb gelement
		Thumb.X = x;
		
		// right track gelement
		x += Thumb.GetWidth(); // x to begin right track drawing
		RightTrack.X = x;
		RightTrack.PictureData.Width = Width - x;
		RightTrack.PictureData.SkippedRows = RightTrack.PictureData.Bitmap.width - RightTrack.GetWidth();
	}
}