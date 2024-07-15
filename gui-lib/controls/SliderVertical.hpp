#ifndef GUI_SLIDER_VERTICAL_HPP
#define GUI_SLIDER_VERTICAL_HPP

#include "IUIControl.hpp"
#include "ITouchScreenEventHandler.hpp"
#include "IEncoderEventHandler.hpp"
#include "GEPicture.hpp"
#include "Action.hpp"

namespace gui
{	
	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	class SliderVertical : public IUIControl, public ITouchScreenEventHandler, public IEncoderEventHandler
	{
	public:
		// properties
		int MaxValue;
		int MinValue;
		int Value;
		
		// constructors
		SliderVertical(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
			uint16_t borderSize, int maxValue, int value, const Action<void(int)> & onValueChenged,
			const GEPicture & thumb, const GEPicture & topTrack, const GEPicture & bottomTrack);
		
		// dectructor
		~SliderVertical() override = default;

		// ITouchScreenEventHandler methods
		void OnPress(TouchScreenEven &) override;
		void OnRelease(TouchScreenEven &) override;
		void OnPenEnter(TouchScreenEven &) override;
		void OnPenLeave(TouchScreenEven &) override;
		void OnPenMove(TouchScreenEven &) override;
		// IEncoderEventHandler methods
		void OnEncoderMoved(EncoderEvent &) override;
		// UIControl methods
		//void OnInitialize(int) override;
		IGElement * GetGraphicElement() override;
		// methods
		int GetValue();
			
	protected:
		// proprties
		GEPicture TopTrack;
		GEPicture Thumb;
		GEPicture BottomTrack;
		
		const uint16_t _borderSize;
		const Action<void(int)> & _valueChangedCmd;
		// methods
		void SetValue(int value);
		uint16_t MoveThumbToPosition(uint16_t);
		virtual void SyncThumbPositionWithValue();
		virtual int CalculateNewValue(uint16_t x);
		void SetGraphicElemntsWithThumbPosition(uint16_t);
	};
}

#endif // GUI_SLIDER_VERTICAL_HPP