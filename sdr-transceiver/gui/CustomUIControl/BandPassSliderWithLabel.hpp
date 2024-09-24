#ifndef GUI_CUSTOM_CONTROL_BAND_PASS_SLIDERE_WITH_LABEL_HPP
#define GUI_CUSTOM_CONTROL_BAND_PASS_SLIDERE_WITH_LABEL_HPP

#include "HPFSlider.hpp"
#include "LPFSlider.hpp"
#include "Label.hpp"
#include "GERectangle.hpp"
#include "Action.hpp"
#include "Group.hpp"

namespace gui
{
namespace custom
{
	class BandPassSliderWithLabel
	{
	public:
		// constructor
		BandPassSliderWithLabel(Group & baseGroup, uint16_t x, uint16_t y, uint16_t width,
			uint16_t hpfMaxValue, uint16_t hpfValue, uint16_t lpfMaxValue, uint16_t lpfValue,
			const IUIContext & context, const Action<void(int)> & hpfFrequecyChanged,
			const Action<void(int)> & lpfFrequecyChanged);

		// destructor
		virtual ~BandPassSliderWithLabel() = default;

		// field
		Label BandPassWidthLabel;
		custom::HPFSlider HPFFrequencyCutoffSlider;
		custom::LPFSlider LPFFrequencyCutoffSlider;
		Label HPFFrequencyCutoffLabel;
		Label LPFFrequencyCutoffLabel;
		GERectangle BackgroundLine;
	};
}
}
#endif // GUI_CUSTOM_CONTROL_BAND_PASS_SLIDERE_WITH_LABEL_HPP