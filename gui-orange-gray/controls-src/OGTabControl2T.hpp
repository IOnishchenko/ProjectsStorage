#ifndef GUI_ORANGE_GRAY_TAB_CONTROL_2T_HPP
#define GUI_ORANGE_GRAY_TAB_CONTROL_2T_HPP

#include "Group.hpp"
#include "IUIContext.hpp"
#include "OGTab160x24.hpp"
#include "IRadioButtonGroup.hpp"
#include "Action.hpp"

namespace gui
{
	class OGTabControl2T : public Group
	{
	public:
		// constructor
		OGTabControl2T(uint16_t y, uint16_t height, const IUIContext & context,
			const std::string_view & text1, const std::string_view & text2,
			const Action<void(IRadioButton *)> & onTab1Selected,
			const Action<void(IRadioButton *)> & onTab2Selected);

		// destructor
		~OGTabControl2T() override;

	protected:
		// field
		OGTab160x24 _tab1RButton;
		OGTab160x24 _tab2RButton;
		IRadioButtonGroup _group;
	};
}

#endif // GUI_ORANGE_GRAY_TAB_CONTROL_2T_HPP