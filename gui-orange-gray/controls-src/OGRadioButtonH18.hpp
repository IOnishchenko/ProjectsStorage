#ifndef GUI_ORANGE_GRAY_RADIO_BUTTON_HEIGHT_18_HPP
#define GUI_ORANGE_GRAY_RADIO_BUTTON_HEIGHT_18_HPP

#include "IUIContext.hpp"
#include "IRadioButton.hpp"
#include "GEText.hpp"
#include "GEPicture.hpp"
#include "GERectangle.hpp"

namespace gui
{
	class OGRadioButtonH18 : public IRadioButton
	{
	public:
		// constructor
		OGRadioButtonH18(uint16_t x, uint16_t y, const std::string_view & text,
			const IUIContext & context, const Action<void(IRadioButton *)> & selCmd);

		// destructor
		~OGRadioButtonH18() override = default;

		// methods
		// IUIControl methods
		IGElement * GetGraphicElement() override;
	
	private:
		// fields
		GEText _text;
		GERectangle _background;
		
		GEPicture _disabledPic;
		GEPicture _enabledPic;
		GEPicture _focusedPic;
		GEPicture _pressedPic;
		GEPicture _selectedPic;
	};
}

#endif // GUI_ORANGE_GRAY_RADIO_BUTTON_HEIGHT_18_HPP