#ifndef GUI_CUSTOM_CONTROL_LPF_SLIDER_WITH_HEADER_HPP
#define GUI_CUSTOM_CONTROL_LPF_SLIDER_WITH_HEADER_HPP

#include "LPFSlider.hpp"
#include "Label.hpp"
#include "GEText.hpp"
#include "GERectangle.hpp"
#include "Action.hpp"
#include <string_view>

namespace gui
{
namespace custom
{
	class LPFSliderWithHeader : public LPFSlider
	{
	public:
		// constructor
		LPFSliderWithHeader(uint16_t groupY, uint16_t y, int maxValue, int value,
			const IUIContext & context, const Action<void(int)> & valueChanged,
			const std::string_view & header, IGElement * gelement);

		LPFSliderWithHeader(uint16_t groupY, uint16_t y, int maxValue, int value,
			const IUIContext & context, const Action<void(int)> & valueChanged,
			const std::string_view & header0, const std::string_view & header1,
			IGElement * gelement);

		// destructor
		~LPFSliderWithHeader() override;

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

#endif // GUI_CUSTOM_CONTROL_LPF_SLIDER_WITH_HEADER_HPP
