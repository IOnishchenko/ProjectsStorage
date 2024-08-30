#ifndef GUI_ORANGE_GRAY_HORIZONTAL_SLIDER_LABEL_HPP
#define GUI_ORANGE_GRAY_HORIZONTAL_SLIDER_LABEL_HPP

#include "OGSliderHorizontal.hpp"
#include "Label.hpp"

namespace gui
{
	class OGHorizontalSliderLabel
	{
	public:
		// constructor
		OGHorizontalSliderLabel(uint16_t x, uint16_t y, uint16_t width, int maxValue, int value,
			const IUIContext & context, const Action<void(int)> & valueChanged);

		// destructor
		virtual ~OGHorizontalSliderLabel() = default;

		// methods
		virtual void SetEnable(bool ena);
	
		// fields
		Label Text;
		OGSliderHorizontal Slider;
	};
}

#endif // GUI_ORANGE_GRAY_HORIZONTAL_SLIDER_LABEL_HPP