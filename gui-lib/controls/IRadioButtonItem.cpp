#include "IRadioButtonItem.hpp"

namespace gui
{
	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	IRadioButtonItem::IRadioButtonItem(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
		IGElement * normal, IGElement * pressed, IGElement * selected,
		const Action<void(IRadioButtonItem *)> * selCmd)
		:IUIControl(x, y, w, h, context), OnItemSelected{selCmd}, _state{IRadioButtonItem::State::Normal},
		_normalGEl{normal}, _pressedGEl{pressed}, _selectedGEl{selected}
	{
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	IGElement * IRadioButtonItem::GetGraphicElement()
	{
		switch(_state)
		{
			case IRadioButtonItem::State::Selected:
				return _selectedGEl;
			case IRadioButtonItem::State::Normal:
				return _normalGEl;
			case IRadioButtonItem::State::Pressed:
				return _pressedGEl;
			default:
				return nullptr;
		}
	}
}