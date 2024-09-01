
#ifndef GUI_DSP_NOISE_REDUCTION_VIEW_HPP
#define GUI_DSP_NOISE_REDUCTION_VIEW_HPP

#include "DSPAlgorithmViewBase.hpp"
#include "GERectangle.hpp"
#include "Command.hpp"

namespace gui
{
	class DSPNoiseReductionView : public DSPAlgorithmViewBase
	{
	public:
		// constructor
		DSPNoiseReductionView(const IUIContext & context);

		// destructor
		~DSPNoiseReductionView() override;
	
	private:
		// commands
		Command<DSPNoiseReductionView, ICheckBox *> _onNoiseReductionEnabledCmd;
		Command<DSPNoiseReductionView, ICheckBox *> _onNoiseReductionDisabledCmd;

		// fields
		GERectangle _settingsBackground;

		// methods
		void OnNoiseReductionEnabled(ICheckBox *);
		void OnNoiseReductionDisabled(ICheckBox *);
	};
}

#endif // GUI_DSP_NOISE_REDUCTION_VIEW_HPP