#ifndef GUI_CUSTOM_UICONTROL_HPF_SLIDER_HPP
#define GUI_CUSTOM_UICONTROL_HPF_SLIDER_HPP

#include "ISlider.hpp"

namespace gui
{
namespace custom
{
	class HPFSlider : public ISlider
	{
	public:
		// constructor
		HPFSlider(uint16_t x, uint16_t y, uint16_t width,
			int maxValue, int value, const IUIContext & context, const Action<void(int)> & valueChanged);

		// destructor
		~HPFSlider() override = default;

		// methods
		IGElement * GetGraphicElement() override;
	
	private:
		// fields
		GEPicture _leftTrackPic;

		GEPicture _disabledPointerPic;
		GEPicture _disabledRightTrackPic;

		GEPicture _enabledPointerPic;
		GEPicture _enabledRightTrackPic;

		GEPicture _focusedPointerPic;
		GEPicture _focusedRightTrackPic;

		GEPicture _pressedPointerPic;
		GEPicture _pressedRightTrackPic;

		GEPicture _selectedPointerPic;
		GEPicture _selectedRightTrackPic;
	};
}
}

#endif // GUI_CUSTOM_UICONTROL_HPF_SLIDER_HPP