#ifndef GUI_ORANGE_GRAY_TAB_CONTROL_5T_HPP
#define GUI_ORANGE_GRAY_TAB_CONTROL_5T_HPP

#include "Group.hpp"
#include "IUIContext.hpp"
#include "OGTab64x24.hpp"
#include "IRadioButtonGroup.hpp"
#include "Action.hpp"

namespace gui
{
	class OGTabControl5T : public Group
	{
	public:
		// constructor
		OGTabControl5T(uint16_t y, uint16_t height, const IUIContext & context,
			const std::string_view & text1, const std::string_view & text2,
			const std::string_view & text3, const std::string_view & text4,
			const std::string_view & text5,
			const Action<void(IRadioButton *)> & onTab1Selected,
			const Action<void(IRadioButton *)> & onTab2Selected,
			const Action<void(IRadioButton *)> & onTab3Selected,
			const Action<void(IRadioButton *)> & onTab4Selected,
			const Action<void(IRadioButton *)> & onTab5Selected);

		// destructor
		~OGTabControl5T() override;

	protected:
		// field
		OGTab64x24 _tab1RButton;
		OGTab64x24 _tab2RButton;
		OGTab64x24 _tab3RButton;
		OGTab64x24 _tab4RButton;
		OGTab64x24 _tab5RButton;
		IRadioButtonGroup _group;
	};
}

#endif // GUI_ORANGE_GRAY_TAB_CONTROL_5T_HPP