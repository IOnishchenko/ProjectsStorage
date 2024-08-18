#ifndef GUI_ISLIDER_HPP
#define GUI_ISLIDER_HPP

#include "IUIControl.hpp"
#include "ITouchScreenEventHandler.hpp"
#include "IEncoderEventHandler.hpp"
#include "IFocusEventHandler.hpp"
#include "IKeyboardEventHandler.hpp"
#include "GEPicture.hpp"
#include "Action.hpp"

namespace gui
{	
	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	class ISlider : public IUIControl,
		public ITouchScreenEventHandler, public IEncoderEventHandler,
		public IFocusEventHandler, public IKeyboardEventHandler
	{
	public:
		// properties
		int MaxValue;
		int MinValue;
		int Value;
		
		// constructors
		ISlider(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
			uint16_t borderSize, int maxValue, int value, const Action<void(int)> & onValueChenged,
			const GEPicture & thumb, const GEPicture & leftTrack, const GEPicture & rightTrack);
		
		// dectructor
		~ISlider() override;

		// ITouchScreenEventHandler methods
		void OnPress(TouchScreenEven & event) override;
		void OnRelease(TouchScreenEven & event) override;
		void OnPenEnter(TouchScreenEven & event) override;
		void OnPenLeave(TouchScreenEven & event) override;
		void OnPenMove(TouchScreenEven & event) override;
		bool IsUnderTouch(uint16_t x, uint16_t y) override;

		// IFocusEventHandler method
		bool OnFocused() override;
		void OnFocusLost() override;

		// IEncoderEventHandler methods
		void OnEncoderMoved(EncoderEvent & event) override;

		// IKeyboardEventHandler methods
		void OnKeyPress(KeyEvent & event) override;
		void OnKeyRelease(KeyEvent & event) override;
		void OnKeyLongPress(KeyEvent & event) override;

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

#endif // GUI_ISLIDER_HPP