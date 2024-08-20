#ifndef GUI_ORANGE_GRAY_BUTTON_100x22_HPP
#define GUI_ORANGE_GRAY_BUTTON_100x22_HPP

#include "stdint.h"
#include "IButton.hpp"
#include <string_view>
#include "GEText.hpp"
#include "GEPicture.hpp"

namespace gui
{
	class OGButton100x22 : public IButton
	{
	public:
		// constructor
		OGButton100x22(uint16_t x, uint16_t y, const std::string_view & text,
			const IUIContext & context, const Action<void(IButton*)> & clickCmd);

		// destructor
		~OGButton100x22() override = default;

		// methods
		IGElement * GetGraphicElement() override;

	private:
		// fields
		GEText _text;
		GEPicture _disabledPic;
		GEPicture _enabledPic;
		GEPicture _focusedPic;
		GEPicture _pressedPic;
	};
}


#endif // GUI_ORANGE_GRAY_BUTTON_100x22_HPP