#ifndef GUI_DSP_VIEW_HPP
#define GUI_DSP_VIEW_HPP

#include "OGTabControl2T.hpp"
#include "IUIContext.hpp"
#include "Command.hpp"
#include <memory>

namespace gui
{
	class DSPView : public OGTabControl2T
	{
	public:
		// constructor
		DSPView(const IUIContext & context);

		// destructor
		~DSPView() override = default;

	private:
		// commands
		Command<DSPView, IRadioButton *> _onModulationClikedCmd;
		Command<DSPView, IRadioButton *> _onAlgorithmClikedCmd;

		// fields
		std::unique_ptr<IUIControl> _subGroup;

		// methods
		void OnModulationClicked(IRadioButton *);
		void OnAlgorithmClicked(IRadioButton *);
	};
}

#endif // GUI_DSP_VIEW_HPP