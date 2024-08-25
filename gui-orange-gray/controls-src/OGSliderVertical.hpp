#ifndef GUI_ORANGE_GRAY_SLIDER_VERTICAL_HPP
#define GUI_ORANGE_GRAY_SLIDER_VERTICAL_HPP

#include "ISliderVertical.hpp"
#include "GEPicture.hpp"

namespace gui
{
	class OGSliderVertical : public ISliderVertical
	{
	public:
		// constructor
		OGSliderVertical(uint16_t x, uint16_t y, uint16_t height,
			int maxValue, int value, const IUIContext & context, const Action<void(int)> & valueChanged);

		// destructor
		~OGSliderVertical() override = default;

	private:
		// fields
		GEPicture _disabledTopTrackPic;
		GEPicture _disabledPointerPic;
		GEPicture _disabledBottomTrackPic;

		GEPicture _enabledTopTrackPic;
		GEPicture _enabledPointerPic;
		GEPicture _enabledBottomTrackPic;

		GEPicture _focusedPointerPic;
		GEPicture _pressedPointerPic;
		GEPicture _selectedPointerPic;
	};
}

#endif // GUI_ORANGE_GRAY_SLIDER_VERTICAL_HPP