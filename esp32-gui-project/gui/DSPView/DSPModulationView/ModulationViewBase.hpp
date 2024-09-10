#ifndef GUI_MODULATION_VIEW_BASE_HPP
#define GUI_MODULATION_VIEW_BASE_HPP

#include "Group.hpp"
#include "BandPassSliderWithLabel.hpp"
#include "Action.hpp"
#include "GEText.hpp"
#include "GERectangle.hpp"

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
		custom::BandPassSliderWithLabel _bandPassControls;

		GEText _headerText0;
		GEText _headerText1;
		GEText _headerText2;

		GERectangle _background;
	};
}

#endif // GUI_MODULATION_VIEW_BASE_HPP
