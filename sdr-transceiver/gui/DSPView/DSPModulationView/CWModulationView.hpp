
#ifndef GUI_CW_MODULATION_VIEW_HPP
#define GUI_CW_MODULATION_VIEW_HPP

#include "ModulationViewBase.hpp"
#include "Command.hpp"

namespace gui
{
	class CWModulationView : public ModulationViewBase
	{
	public:
		// constructor
		CWModulationView(const IUIContext & context);

		// destructor
		~CWModulationView() override = default;

	private:
		// Commands
		Command<CWModulationView, int> _onHPFCutoffChanged;
		Command<CWModulationView, int> _onLPFCutoffChanged;

		// methods
		void OnHPFCutoffFrequencyChanged(int value);
		void OnLPFCutoffFrequencyChanged(int value);
	};
}

#endif // GUI_CW_MODULATION_VIEW_HPP
