#ifndef GUI_MODULATION_VIEW_BASE_HPP
#define GUI_MODULATION_VIEW_BASE_HPP

#include "Group.hpp"
#include "OGSliderHorizontal.hpp"
#include "HPFSliderWithHeader.hpp"
#include "LPFSliderWithHeader.hpp"
#include "Command.hpp"
#include "GERectangle.hpp"
#include "GEText.hpp"

namespace gui
{
	/*-----------------------------------------------------------------//
	//
	//-----------------------------------------------------------------*/
	class ModulationViewBase : public Group
	{
	public:
		// constructor
		ModulationViewBase(const IUIContext & context,
			const Action<void(int)> & hpfCutofChanged,
			const Action<void(int)> & lpfCutofChanged);

		// destructor
		~ModulationViewBase() override;

	protected:
		// fields
		custom::HPFSliderWithHeader _hpfCutoffSlider;
		custom::LPFSliderWithHeader _lpfCutoffSlider;

		GERectangle _background;
	};
}

#endif // GUI_MODULATION_VIEW_BASE_HPP
