#ifndef GUI_RADIO_BUTTON_HPP
#define GUI_RADIO_BUTTON_HPP

#include "RadioButtonItem.hpp"
#include "ITouchScreenEventHandler.hpp"
#include "IFocusEventHandler.hpp"
#include "IKeyboardEventHandler.hpp"
#include "Group.hpp"

namespace gui
{
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	class RadioButton : public Group,
		public ITouchScreenEventHandler, public IFocusEventHandler,
		public IKeyboardEventHandler
	{
	public:
		// constructors
		RadioButton(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
			const std::initializer_list<IUIControl *> & items, IGElement * gelement);

		RadioButton(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
			const std::forward_list<IUIControl *> & items, IGElement * gelement);

		// destructor
		~RadioButton() override;
		
		// methods
		// ITouchScreenEventHandler methods
		void OnPress(ITouchScreenEventHandler *, TouchScreenEven & event) override;
		void OnRelease(ITouchScreenEventHandler *, TouchScreenEven & event) override;
		void OnPenLeave(ITouchScreenEventHandler *, TouchScreenEven & event) override;
		void OnPenMove(ITouchScreenEventHandler *, TouchScreenEven & event) override;
		bool IsUnderTouch(uint16_t x, uint16_t y) override;

		// IFocusEventHandler methods
		void OnFocused(IFocusEventHandler *) override;
		void OnFocusLost(IFocusEventHandler *) override;

		// IKeyboardEventHandler methods
		void OnKeyPress(IKeyboardEventHandler *, KeyEvent & event) override;
		void OnKeyRelease(IKeyboardEventHandler *, KeyEvent & event) override;

		void SetSelected(RadioButtonItem * selected);
		void ClearSelection();
		
	protected:
		RadioButtonItem * FindItemWithState(RadioButtonItem::State state) const;
	};
}

#endif // RADIO_BUTTON_H