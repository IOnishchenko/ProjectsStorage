#ifndef GUI_IRADIO_BUTTON_GROUP_HPP
#define GUI_IRADIO_BUTTON_GROUP_HPP

#include "IRadioButton.hpp"
#include "Group.hpp"

namespace gui
{
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	class IRadioButtonGroup : public Group
	{
		friend class IRadioButton;

	public:
		// constructors
		IRadioButtonGroup(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
			const std::initializer_list<IUIControl *> & items, IGElement * gelement);

		// destructor
		~IRadioButtonGroup() override = default;
		
	protected:

		// methods
		void RadioButtonCallBack(IRadioButton * rbutton);
	};
}

#endif // GUI_IRADIO_BUTTON_GROUP_HPP