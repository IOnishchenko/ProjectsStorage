#ifndef GUI_CUSTOM_CONTROL_SLIDER_WITH_HEADER_HPP
#define GUI_CUSTOM_CONTROL_SLIDER_WITH_HEADER_HPP

#include "OGHorizontalSliderLabel.hpp"
#include "GEText.hpp"
#include "Action.hpp"
#include <string_view>

namespace gui
{
namespace custom
{
	class SliderWithHeader : public OGHorizontalSliderLabel
	{
	public:
		// constructor
		SliderWithHeader(uint16_t groupY, uint16_t y, int maxValue, int value,
			const IUIContext & context, const Action<void(int)> & valueChanged,
			const std::string_view & header, IGElement * gelement);

		SliderWithHeader(uint16_t groupY, uint16_t y, int maxValue, int value,
			const IUIContext & context, const Action<void(int)> & valueChanged,
			const std::string_view & header0, const std::string_view & header1,
			IGElement * gelement);

		// destructor
		~SliderWithHeader() override;

		// fields
		GEText * Header;
	
	private:
		GEText * _secondLineHeader;
	};
}
}

#endif // GUI_CUSTOM_CONTROL_SLIDER_WITH_HEADER_HPP
