#include "ISlider.hpp"
#include "ITouchScreenEventObserver.hpp"

namespace gui
{
	/*--------------------------------------------------------------------------//
	// constructors
	//--------------------------------------------------------------------------*/
	ISlider::ISlider(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
		uint16_t borderSize, int maxValue, int value, const Action<void(int)> &onValueChenged,
		const GEPicture &thumb, const GEPicture &leftTrack, const GEPicture &rightTrack)
		:IUIControl(x, y, w, h, context), MaxValue{0}, MinValue{0}, Value{value}, _borderSize{borderSize},
		LeftTrack{leftTrack}, Thumb{thumb}, RightTrack{rightTrack}, _valueChengedCmd{onValueChenged}
	{
		SyncThumbPositionWithValue();
		context.TouchScreenObserver->Subscribe(this);
	}

	/*--------------------------------------------------------------------------//
	// destructor
	//--------------------------------------------------------------------------*/
	ISlider::~ISlider()
	{
		_context.TouchScreenObserver->Unsubscribe(this);
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void ISlider::OnPress(TouchScreenEven & event)
	{
		uint16_t xpen = event.x - X;
		uint16_t xthumb = Thumb.X;
		// check if the thumb is under the pen
		if((xpen > xthumb)&&(xpen < (xthumb + Thumb.GetWidth())))
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
			_valueChengedCmd(value);
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

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void ISlider::OnKeyPress(KeyEvent & event)
	{

	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void ISlider::OnKeyRelease(KeyEvent & event)
	{

	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void ISlider::OnKeyLongPress(KeyEvent & event)
	{

	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void ISlider::SetValue(int value)
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
	int ISlider::GetValue()
	{
		return Value;
	}
	
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	IGElement * ISlider::GetGraphicElement()
	{
		return &LeftTrack;
	}
	
	/*--------------------------------------------------------------------------//
	// ---------------------- Protected Methods --------------------------------
	//--------------------------------------------------------------------------*/
	
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	uint16_t ISlider::MoveThumbToPosition(uint16_t xpen)
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
	void ISlider::SyncThumbPositionWithValue()
	{
		float width = (Width - _borderSize*2 - Thumb.GetWidth());
		float step = width/(MaxValue - MinValue);
		uint16_t x = step * (Value - MinValue) + _borderSize;
		SetGraphicElemntsWithThumbPosition(x);
	}
	
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	int ISlider::CalculateNewValue(uint16_t x)
	{
		float width = (Width - _borderSize*2 - Thumb.GetWidth());
		float step = width/(MaxValue - MinValue);		
		return (x - _borderSize)/step + MinValue;
	}
	
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void ISlider::SetGraphicElemntsWithThumbPosition(uint16_t x)
	{
		// left track gelement
		LeftTrack.Width = x;
		
		// thumb gelement
		Thumb.X = x;
		
		// right track gelement
		x += Thumb.GetWidth(); // x to begin right track drawing
		RightTrack.X = x;
		RightTrack.Width = Width - x;
		RightTrack.Foreground.SkippedRows =
			RightTrack.Foreground.Bitmap->width - RightTrack.Width;
	}
}