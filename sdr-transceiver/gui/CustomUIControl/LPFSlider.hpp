#ifndef GUI_CUSTOM_UICONTROL_LPF_SLIDER_HPP
#define GUI_CUSTOM_UICONTROL_LPF_SLIDER_HPP

#include "ISlider.hpp"

namespace gui
{
namespace custom
{
	class LPFSlider : public ISlider
	{
	public:
		// constructor
		LPFSlider(uint16_t x, uint16_t y, uint16_t width,
			int maxValue, int value, const IUIContext & context, const Action<void(int)> & valueChanged);

		// destructor
		~LPFSlider() override = default;

		// methods
		IGElement * GetGraphicElement() override;
	
	private:
		// fields
		GEPicture _rightTrackPic;

		GEPicture _disabledPointerPic;
		GEPicture _disabledLeftTrackPic;

		GEPicture _enabledPointerPic;
		GEPicture _enabledLeftTrackPic;

		GEPicture _focusedPointerPic;
		GEPicture _focusedLeftTrackPic;

		GEPicture _pressedPointerPic;
		GEPicture _pressedLeftTrackPic;

		GEPicture _selectedPointerPic;
		GEPicture _selectedLeftTrackPic;
	};
}
}

#endif // GUI_CUSTOM_UICONTROL_LPF_SLIDER_HPP