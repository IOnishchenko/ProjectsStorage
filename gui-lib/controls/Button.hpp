#ifndef GUI_BUTTON_HPP
#define GUI_BUTTON_HPP

#include "IUIControl.hpp"
#include "ITouchScreenEventHandler.hpp"
#include "Action.hpp"

namespace gui
{
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	class Button : public IUIControl, public ITouchScreenEventHandler
	{
		enum class ButtonState
		{
			Normal,
			Pressed,
		};
		
		public:
			// constructor
			Button(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
				IGElement & normalGEl, IGElement & pressedGEl, const Action<void(Button *)> & clickCmd);

			// destructor
			~Button() override = default;
			
			// methods
			IGElement * GetGraphicElement() override;
			void OnPress(TouchScreenEven &) override;
			void OnRelease(TouchScreenEven &) override;
			void OnPenLeave(TouchScreenEven &) override;
		
		protected:
			bool _isDrawn = false;
			ButtonState _state;
			const Action<void(Button *)> &_clickCmd;
			IGElement * _normalBG;
			IGElement * _pressedBG;
	};
}

#endif // BUTTON_H