#ifndef GUI_RADIO_BUTTON_HPP
#define GUI_RADIO_BUTTON_HPP

#include "RadioButtonItem.hpp"
#include "ITouchScreenEventHandler.hpp"
#include "Group.hpp"

namespace gui
{
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	class RadioButton : public ITouchScreenEventHandler, public Group
	{
	public:
		// constructors
		RadioButton(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
			const std::initializer_list<IUIControl *> & items, IGElement * gelement);

		RadioButton(uint16_t x, uint16_t y, uint16_t w, uint16_t h,
			const std::forward_list<IUIControl *> & items, IGElement * gelement);

		// destructor
		~RadioButton() override = default;
		
		// methods
		void OnPress(TouchScreenEven &) override;
		void OnRelease(TouchScreenEven &) override;
		void OnPenLeave(TouchScreenEven &) override;
		void OnPenMove(TouchScreenEven &) override;
		
		IGElement * GetIGElement() override;
		void SetSelected(RadioButtonItem * selected);
		void ClearSelection();
		
	protected:
		RadioButtonItem * FindItemWithState(RadioButtonItem::State state) const;
	};
}

#endif // RADIO_BUTTON_H