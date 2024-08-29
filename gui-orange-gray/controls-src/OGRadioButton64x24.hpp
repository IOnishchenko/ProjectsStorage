#ifndef GUI_ORANGE_GRAY_RADIO_BUTTON_64x24_HPP
#define GUI_ORANGE_GRAY_RADIO_BUTTON_64x24_HPP

#include "IUIContext.hpp"
#include "IRadioButton.hpp"
#include "GEText.hpp"
#include "GEPicture.hpp"

namespace gui
{
	class OGRadioButton64x24 : public IRadioButton
	{
	public:
		// constructor
		OGRadioButton64x24(uint16_t x, uint16_t y, const std::string_view & text,
			const IUIContext & context, const Action<void(IRadioButton *)> & selCmd);

		// destructor
		~OGRadioButton64x24() override = default;

		// methods
		// IUIControl methods
		IGElement * GetGraphicElement() override;
	
	private:
		// fields
		GEText _text;
		GEPicture _disabledPic;
		GEPicture _enabledPic;
		GEPicture _focusedPic;
		GEPicture _pressedPic;
		GEPicture _selectedPic;
	};
}

#endif // GUI_ORANGE_GRAY_RADIO_BUTTON_64x24_HPP