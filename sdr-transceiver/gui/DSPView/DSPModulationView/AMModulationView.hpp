
#ifndef GUI_AM_MODULATION_VIEW_HPP
#define GUI_AM_MODULATION_VIEW_HPP

#include "ModulationViewBase.hpp"
#include "Command.hpp"

namespace gui
{
	class AMModulationView : public ModulationViewBase
	{
	public:
		// constructor
		AMModulationView(const IUIContext & context);

		// destructor
		~AMModulationView() override = default;

	private:
		// Commands
		Command<AMModulationView, int> _onHPFCutoffChanged;
		Command<AMModulationView, int> _onLPFCutoffChanged;

		// methods
		void OnHPFCutoffFrequencyChanged(int value);
		void OnLPFCutoffFrequencyChanged(int value);
	};
}

#endif // GUI_AM_MODULATION_VIEW_HPP