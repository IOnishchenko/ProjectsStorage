#ifndef GUI_ORANGE_GRAY_BUTTON_64x24_HPP
#define GUI_ORANGE_GRAY_BUTTON_64x24_HPP

#include "stdint.h"
#include "IButton.hpp"
#include <string_view>
#include "GEText.hpp"
#include "GEPicture.hpp"

namespace gui
{
	class OGButton64x24 : public IButton
	{
	public:
		// constructor
		OGButton64x24(uint16_t x, uint16_t y, const std::string_view & text,
			const IUIContext & context, const Action<void(IButton*)> & clickCmd);

		// destructor
		~OGButton64x24() override = default;

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


#endif // GUI_ORANGE_GRAY_BUTTON_64x24_HPP