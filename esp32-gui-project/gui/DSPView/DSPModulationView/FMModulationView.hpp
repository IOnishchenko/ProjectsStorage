#ifndef GUI_FM_MODULATION_VIEW_HPP
#define GUI_FM_MODULATION_VIEW_HPP

#include "ModulationViewBase.hpp"
#include "Command.hpp"

namespace gui
{
	class FMModulationView : public ModulationViewBase
	{
	public:
		// constructor
		FMModulationView(const IUIContext & context);

		// destructor
		~FMModulationView() override = default;

	private:
		// Commands
		Command<FMModulationView, int> _onHPFCutoffChanged;
		Command<FMModulationView, int> _onLPFCutoffChanged;

		// methods
		void OnHPFCutoffFrequencyChanged(int value);
		void OnLPFCutoffFrequencyChanged(int value);
	};
}

#endif // GUI_FM_MODULATION_VIEW_HPP