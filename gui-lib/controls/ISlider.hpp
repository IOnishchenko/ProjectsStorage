#ifndef GUI_ISLIDER_HPP
#define GUI_ISLIDER_HPP

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
	class ISlider : public IToggleFocusUIControl,
		public ITouchScreenEventHandler
	{
	public:
		// constructors
		ISlider(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
			uint16_t borderSize, int maxValue, int value, const Action<void(int)> & onValueChenged,
			GEPicture & disabledLeftTrack ,GEPicture & disabledPointer, GEPicture & disabledRightTrack,
			GEPicture & enabledLeftTrack, GEPicture & enabledPointer, GEPicture & enabledRightTrack,
			GEPicture & focusedPointer, GEPicture & pressedPointer, GEPicture & selectedPointer);
		
		// dectructor
		~ISlider() override;

		// ITouchScreenEventHandler methods
		void OnPress(TouchScreenEven & event) override;
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
		void SetValue(int value);
		void SetMaxValue(int value);
		void SetMinValue(int value);
		void UpdateRange(int minValue, int value, int maxValue);
			
	protected:
		// properties
		int MaxValue;
		int MinValue;
		int Value;

		// fields
		const uint16_t _borderSize;

		// methods
		void UpdateValue(int value);
		uint16_t MoveThumbToPosition(uint16_t);
		virtual void SyncThumbPositionWithValue();
		virtual int CalculateNewValue(uint16_t x);
		void SetGraphicElemntsWithThumbPosition(uint16_t);

	private:
		const Action<void(int)> & _valueChangedCmd;
		GEPicture & _disabledLeftTrack;
		GEPicture & _disabledPointer;
		GEPicture & _disabledRightTrack;

		GEPicture & _enabledLeftTrack;
		GEPicture & _enabledPointer;
		GEPicture & _enabledRightTrack;

		GEPicture & _focusedPointer;
		GEPicture & _pressedPointer;
		GEPicture & _selectedPointer;
	};
}

#endif // GUI_ISLIDER_HPP