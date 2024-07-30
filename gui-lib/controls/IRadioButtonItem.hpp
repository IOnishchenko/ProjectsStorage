#ifndef GUI_ICHECK_BOX_ITEM_HPP
#define GUI_ICHECK_BOX_ITEM_HPP

#include "IUIControl.hpp"
#include "Action.hpp"

namespace gui
{
	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	class IRadioButtonItem : public IUIControl
	{
	public:
		enum class State
		{
			Normal,
			Pressed,
			Selected
		};

		// constructor
		IRadioButtonItem(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
			IGElement * normal, IGElement * pressed, IGElement * selected,
			const Action<void(IRadioButtonItem *)> * selCmd);

		// destructor
		~IRadioButtonItem() override = default;

		// properties
		const Action<void(IRadioButtonItem *)> * OnItemSelected;

		// methods
		IGElement * GetGraphicElement() override;
		IRadioButtonItem::State GetState() {return _state;};
		
	protected:
		// fields
		IRadioButtonItem::State _state;
		IGElement * _normalGEl;
		IGElement * _pressedGEl;
		IGElement * _selectedGEl;
		
		friend class IRadioButton;
	};
}

#endif // GUI_ICHECK_BOX_ITEM_HPP