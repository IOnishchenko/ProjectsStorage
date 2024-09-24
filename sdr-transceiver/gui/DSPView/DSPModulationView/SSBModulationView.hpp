#ifndef GUI_SSB_MODULATION_VIEW_HPP
#define GUI_SSB_MODULATION_VIEW_HPP

#include "ModulationViewBase.hpp"
#include "OGCheckBoxH18.hpp"
#include "Command.hpp"

namespace gui
{
	class SSBModulationView : public ModulationViewBase
	{
	public:
		// constructor
		SSBModulationView(const IUIContext & context);

		// destructor
		~SSBModulationView() override;

	private:
		// Commands
		Command<SSBModulationView, int> _onHPFCutoffChangedCmd;
		Command<SSBModulationView, int> _onLPFCutoffChangedCmd;
		Command<SSBModulationView, ICheckBox *> _onCESSBEnabledCmd;
		Command<SSBModulationView, ICheckBox *> _onCESSBDisabledCmd;

		// fields
		OGCheckBoxH18 _enaCESSB;

		// methods
		void OnHPFCutoffFrequencyChanged(int value);
		void OnLPFCutoffFrequencyChanged(int value);
		void OnCESSBEnabled(ICheckBox *);
		void OnCESSBDisabled(ICheckBox *);
	};
}

#endif // GUI_SSB_MODULATION_VIEW_HPP
