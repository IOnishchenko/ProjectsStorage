#ifndef GUI_SLIDER_HPP
#define GUI_SLIDER_HPP

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
	class Slider : public IUIControl, public ITouchScreenEventHandler, public IEncoderEventHandler
	{
	public:
		// properties
		int MaxValue;
		int MinValue;
		int Value;
		
		// constructors
		Slider(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
			uint16_t borderSize, int maxValue, int value, const Action<void(int)> & onValueChenged,
			const GEPicture & thumb, const GEPicture & leftTrack, const GEPicture & rightTrack);
		
		// dectructor
		~Slider() override = default;

		// ITouchScreenEventHandler methods
		void OnPress(ITouchScreenEventHandler &) override;
		void OnRelease(ITouchScreenEventHandler &) override;
		void OnPenEnter(ITouchScreenEventHandler &) override;
		void OnPenLeave(ITouchScreenEventHandler &) override;
		void OnPenMove(ITouchScreenEventHandler &) override;
		// IEncoderEventHandler methods
		void OnEncoderMoved(EncoderEvent &) override;
		// IUIControl methods
		IGElement * GetGraphicElement() override;
		// methods
		int GetValue();
			
	protected:
		// proprties
		const uint16_t _borderSize;
		GEPicture LeftTrack;
		GEPicture Thumb;
		GEPicture RightTrack;
		const Action<void(int)> & _valueChengedCmd;
		// methods
		void SetValue(int value);
		uint16_t MoveThumbToPosition(uint16_t);
		virtual void SyncThumbPositionWithValue();
		virtual int CalculateNewValue(uint16_t x);
		void SetGraphicElemntsWithThumbPosition(uint16_t);
	};
}

#endif // GUI_SLIDER_HPP