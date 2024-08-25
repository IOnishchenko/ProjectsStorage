#ifndef GUI_ISLIDER_VERTICAL_HPP
#define GUI_ISLIDER_VERTICAL_HPP

#include "IUIControl.hpp"
#include "ITouchScreenEventHandler.hpp"
#include "IToggleFocusUIControl.hpp"
#include "GEPicture.hpp"
#include "Action.hpp"

namespace gui
{	
	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	class ISliderVertical : public IToggleFocusUIControl, 
		public ITouchScreenEventHandler
	{
	public:
		// properties
		int MaxValue;
		int MinValue;
		int Value;
		
		// constructors
		ISliderVertical(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
			uint16_t borderSize, int maxValue, int value, const Action<void(int)> & onValueChenged,
			GEPicture & disabledTopTrack ,GEPicture & disabledPointer, GEPicture & disabledBottomTrack,
			GEPicture & enabledTopTrack, GEPicture & enabledPointer, GEPicture & enabledBottomTrack,
			GEPicture & focusedPointer, GEPicture & pressedPointer, GEPicture & selectedPointer);
		
		// dectructor
		~ISliderVertical() override;

		// ITouchScreenEventHandler methods
		void OnPress( TouchScreenEven & event) override;
		void OnRelease(TouchScreenEven & event) override;
		void OnPenEnter(TouchScreenEven & event) override;
		void OnPenLeave(TouchScreenEven & event) override;
		void OnPenMove(TouchScreenEven & event) override;
		bool IsUnderTouch(uint16_t x, uint16_t y) override;

		// IEncoderEventHandler methods
		void OnEncoderMoved(EncoderEvent & event) override;

		// IUIControl methods
		IGElement * GetGraphicElement() override;
	
		// methods
		int GetValue();
			
	protected:
		// proprties
		const uint16_t _borderSize;

		// methods
		void SetValue(int value);
		uint16_t MoveThumbToPosition(uint16_t);
		virtual void SyncThumbPositionWithValue();
		virtual int CalculateNewValue(uint16_t x);
		void SetGraphicElemntsWithThumbPosition(uint16_t);

	private:
		const Action<void(int)> & _valueChangedCmd;
		GEPicture & _disabledTopTrack;
		GEPicture & _disabledPointer;
		GEPicture & _disabledBottomTrack;

		GEPicture & _enabledTopTrack;
		GEPicture & _enabledPointer;
		GEPicture & _enabledBottomTrack;

		GEPicture & _focusedPointer;
		GEPicture & _pressedPointer;
		GEPicture & _selectedPointer;
	};
}

#endif // GUI_ISLIDER_VERTICAL_HPP