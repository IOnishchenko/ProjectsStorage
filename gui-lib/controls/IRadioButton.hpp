#ifndef GUI_IRADIO_BUTTON_HPP
#define GUI_IRADIO_BUTTON_HPP

#include "IRadioButtonItem.hpp"
#include "ITouchScreenEventHandler.hpp"
#include "IFocusEventHandler.hpp"
#include "IKeyboardEventHandler.hpp"
#include "Group.hpp"

namespace gui
{
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	class IRadioButton : public Group,
		public ITouchScreenEventHandler, public IFocusEventHandler,
		public IKeyboardEventHandler
	{
	public:
		// constructors
		IRadioButton(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
			const std::initializer_list<IUIControl *> & items, IGElement * gelement);

		IRadioButton(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
			const std::forward_list<IUIControl *> & items, IGElement * gelement);

		// destructor
		~IRadioButton() override;
		
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

		void SetSelected(IRadioButtonItem * selected);
		void ClearSelection();
		
	protected:
		IRadioButtonItem * FindItemWithState(IRadioButtonItem::State state) const;
	};
}

#endif // GUI_IRADIO_BUTTON_HPP