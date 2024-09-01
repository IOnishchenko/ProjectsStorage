
#ifndef GUI_DSP_NOTCH_VIEW_HPP
#define GUI_DSP_NOTCH_VIEW_HPP

#include "DSPAlgorithmViewBase.hpp"
#include "GERectangle.hpp"
#include "Command.hpp"

namespace gui
{
	class DSPNotchView : public DSPAlgorithmViewBase
	{
	public:
		// constructor
		DSPNotchView(const IUIContext & context);

		// destructor
		~DSPNotchView() override;
	
	private:
		// commands
		Command<DSPNotchView, ICheckBox *> _onNotchEnabledCmd;
		Command<DSPNotchView, ICheckBox *> _onNotchDisabledCmd;

		// fields
		GERectangle _settingsBackground;

		// methods
		void OnNotchEnabled(ICheckBox *);
		void OnNotchDisabled(ICheckBox *);
	};
}

#endif // GUI_DSP_NOTCH_VIEW_HPP