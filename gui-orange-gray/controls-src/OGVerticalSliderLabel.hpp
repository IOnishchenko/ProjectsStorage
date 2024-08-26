#ifndef GUI_ORANGE_GRAY_VERTICAL_SLIDER_LABEL_HPP
#define GUI_ORANGE_GRAY_VERTICAL_SLIDER_LABEL_HPP

#include "OGSliderVertical.hpp"
#include "Label.hpp"

namespace gui
{
	class OGVerticalSliderLabel
	{
	public:
		// constructor
		OGVerticalSliderLabel(uint16_t x, uint16_t y, uint16_t height, int maxValue, int value,
			const IUIContext & context, const Action<void(int)> & valueChanged);

		// destructor
		~OGVerticalSliderLabel() = default;

		// field
		Label Text;
		OGSliderVertical Slider;
	};
}

#endif // GUI_ORANGE_GRAY_VERTICAL_SLIDER_LABEL_HPP