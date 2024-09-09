#ifndef GUI_CUSTOM_CONTROL_HPF_SLIDER_WITH_HEADER_HPP
#define GUI_CUSTOM_CONTROL_HPF_SLIDER_WITH_HEADER_HPP

#include "HPFSlider.hpp"
#include "Label.hpp"
#include "GEText.hpp"
#include "GERectangle.hpp"
#include "Action.hpp"
#include <string_view>

namespace gui
{
namespace custom
{
	class HPFSliderWithHeader : public HPFSlider
	{
	public:
		// constructor
		HPFSliderWithHeader(uint16_t groupY, uint16_t y, int maxValue, int value,
			const IUIContext & context, const Action<void(int)> & valueChanged,
			const std::string_view & header, IGElement * gelement);

		HPFSliderWithHeader(uint16_t groupY, uint16_t y, int maxValue, int value,
			const IUIContext & context, const Action<void(int)> & valueChanged,
			const std::string_view & header0, const std::string_view & header1,
			IGElement * gelement);

		// destructor
		~HPFSliderWithHeader() override;

		// methods
		void SetEnable(bool ena) override;

		// fields
		Label Text;
		GEText * Header;
	
	private:
		GEText * _secondLineHeader;
		GERectangle _lineBackground;
	};
}
}

#endif // GUI_CUSTOM_CONTROL_HPF_SLIDER_WITH_HEADER_HPP
