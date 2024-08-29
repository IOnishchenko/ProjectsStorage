#include "IRadioButtonGroup.hpp"

namespace gui
{
	/*--------------------------------------------------------------------------//
	// Constructor
	//--------------------------------------------------------------------------*/
	IRadioButtonGroup::IRadioButtonGroup(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
		const std::initializer_list<IUIControl *> & items, IGElement * gelement)
		:Group(x, y, w, h, context, items, gelement)
	{
		// add callback to radiobuttons
		for(auto itm : Controls)
		{
			(static_cast<IRadioButton *>(itm))->Group = this;
		}
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void IRadioButtonGroup::RadioButtonCallBack(IRadioButton * rbutton)
	{
		// IRadioButton::State state = rbutton->GetState();
		// if((state == IRadioButton::State::Selected)
		// 	|| (state == IRadioButton::State::SelectedFocused))
		// {
			// clear other selected
			for(auto itm : Controls)
			{
				auto rbttn = static_cast<IRadioButton *>(itm);
				if(rbttn != rbutton)
				{
					switch(rbttn->GetState())
					{
						case IRadioButton::State::Selected:
							rbttn->SetState(IRadioButton::State::Enabled);
							return;
						default:
							;
					}
				}
			}
		// }
	}
}