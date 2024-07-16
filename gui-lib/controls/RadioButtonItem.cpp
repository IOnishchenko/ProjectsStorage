#include "RadioButtonItem.hpp"

namespace gui
{
	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	RadioButtonItem::RadioButtonItem(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
		IGElement * normal, IGElement * pressed, IGElement * selected,
		const Action<void(RadioButtonItem *)> * selCmd)
		:IUIControl(x, y, w, h, context), OnItemSelected{selCmd}, _state{RadioButtonItem::State::Normal},
		_normalGEl{normal}, _pressedGEl{pressed}, _selectedGEl{selected}
	{
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	IGElement * RadioButtonItem::GetGraphicElement()
	{
		switch(_state)
		{
			case RadioButtonItem::State::Selected:
				return _selectedGEl;
			case RadioButtonItem::State::Normal:
				return _normalGEl;
			case RadioButtonItem::State::Pressed:
				return _pressedGEl;
			default:
				return nullptr;
		}
	}
}