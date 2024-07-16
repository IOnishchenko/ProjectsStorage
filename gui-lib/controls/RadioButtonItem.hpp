#ifndef GUI_CHECK_BOX_ITEM_HPP
#define GUI_CHECK_BOX_ITEM_HPP

#include "IUIControl.hpp"
#include "Action.hpp"

namespace gui
{
	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	class RadioButtonItem : public IUIControl
	{
	public:
		enum class State
		{
			Normal,
			Pressed,
			Selected
		};

		// constructor
		RadioButtonItem(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
			IGElement * normal, IGElement * pressed, IGElement * selected,
			const Action<void(RadioButtonItem *)> * selCmd);

		// destructor
		~RadioButtonItem() override = default;
		
		// properties
		const Action<void(RadioButtonItem *)> * OnItemSelected;

		// methods
		IGElement * GetGraphicElement() override;
		RadioButtonItem::State GetState() {return _state;};
		
	protected:
		// fields
		RadioButtonItem::State _state;
		IGElement * _normalGEl;
		IGElement * _pressedGEl;
		IGElement * _selectedGEl;
		
		friend class RadioButton;
	};
}

#endif // CHECK_BOX_ITEM_H