#ifndef GUI_ORANGE_GRAY_CHECKBOX_H18_HPP
#define GUI_ORANGE_GRAY_CHECKBOX_H18_HPP

#include "ICheckBox.hpp"
#include "GEPicture.hpp"
#include "GEText.hpp"
#include "GERectangle.hpp"

namespace gui
{
	class OGCheckBoxH18 : public ICheckBox
	{
	public:
		// constructor
		OGCheckBoxH18(uint16_t x, uint16_t y, const IUIContext & context,
			const Action<void(ICheckBox *)> & checkedCmd, const Action<void(ICheckBox *)> & uncheckedCmd,
			const std::string_view & checkedText, const std::string_view & uncheckedText);

		// destructor
		~OGCheckBoxH18() override = default;

		// methods
		IGElement * GetGraphicElement() override;

	private:
		// fields
		GEPicture _checkedDisabledPic;
		GEPicture _uncheckedDisabledPic;
		GEPicture _checkedEnabledPic;
		GEPicture _uncheckedEnabledPic;
		GEPicture _checkedFocusedPic;
		GEPicture _uncheckedFocusedPic;
		GEPicture _checkedPressedPic;
		GEPicture _uncheckedPressedPic;

		GERectangle _backgroundChecked;
		GEText _checkedText;
		GERectangle _backgroundUncheked;
		GEText _uncheckedText;
	};
}

#endif // GUI_ORANGE_GRAY_CHECKBOX_H18_HPP
