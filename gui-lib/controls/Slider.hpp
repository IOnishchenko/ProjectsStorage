#ifndef GUI_SLIDER_HPP
#define GUI_SLIDER_HPP

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
	class Slider : public IUIControl,
		public ITouchScreenEventHandler, public IEncoderEventHandler,
		public IFocusEventHandler, public IKeyboardEventHandler
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
		~Slider() override;

		// ITouchScreenEventHandler methods
		void OnPress(ITouchScreenEventHandler *, TouchScreenEven & event) override;
		void OnRelease(ITouchScreenEventHandler *, TouchScreenEven & event) override;
		void OnPenEnter(ITouchScreenEventHandler *, TouchScreenEven & event) override;
		void OnPenLeave(ITouchScreenEventHandler *, TouchScreenEven & event) override;
		void OnPenMove(ITouchScreenEventHandler *, TouchScreenEven & event) override;
		bool IsUnderTouch(uint16_t x, uint16_t y) override;

		// IFocusEventHandler method
		void OnFocused(IFocusEventHandler *) override;
		void OnFocusLost(IFocusEventHandler *) override;

		// IEncoderEventHandler methods
		void OnEncoderMoved(IEncoderEventHandler *, EncoderEvent & event) override;

		// IKeyboardEventHandler methods
		void OnKeyPress(IKeyboardEventHandler *, KeyEvent & event) override;
		void OnKeyRelease(IKeyboardEventHandler *, KeyEvent & event) override;
		void OnKeyLongPress(IKeyboardEventHandler *, KeyEvent & event) override;

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