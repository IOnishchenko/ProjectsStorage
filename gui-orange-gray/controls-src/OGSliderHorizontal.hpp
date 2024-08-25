#ifndef GUI_ORANGE_GRAY_SLIDER_HORIZONTAL_HPP
#define GUI_ORANGE_GRAY_SLIDER_HORIZONTAL_HPP

#include "ISlider.hpp"
#include "GEPicture.hpp"

namespace gui
{
	class OGSliderHorizontal : public ISlider
	{
	public:
		// constructor
		OGSliderHorizontal(uint16_t x, uint16_t y, uint16_t width,
			int maxValue, int value, const IUIContext & context, const Action<void(int)> & valueChanged);

		// destructor
		~OGSliderHorizontal() override = default;

	private:
		// fields
		GEPicture _disabledLeftTrackPic;
		GEPicture _disabledPointerPic;
		GEPicture _disabledRightTrackPic;

		GEPicture _enabledLeftTrackPic;
		GEPicture _enabledPointerPic;
		GEPicture _enabledRightTrackPic;

		GEPicture _focusedPointerPic;
		GEPicture _pressedPointerPic;
		GEPicture _selectedPointerPic;
	};
}

#endif // GUI_ORANGE_GRAY_SLIDER_HORIZONTAL_HPP