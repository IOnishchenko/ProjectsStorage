#ifndef GUI_DSP_ALGORITHM_VIEW_HPP
#define GUI_DSP_ALGORITHM_VIEW_HPP

#include "OGTabControl5T.hpp"
#include "IUIContext.hpp"
#include "Command.hpp"
#include <memory>

namespace gui
{
	class DSPAlgorithmView : public OGTabControl5T
	{
	public:
		// constructor
		DSPAlgorithmView(const IUIContext & context);

		// destructor
		~DSPAlgorithmView() override = default;

	private:
		// commands
		Command<DSPAlgorithmView, IRadioButton *> _onAGCClikedCmd;
		Command<DSPAlgorithmView, IRadioButton *> _onNRClikedCmd;
		Command<DSPAlgorithmView, IRadioButton *> _onNBClikedCmd;
		Command<DSPAlgorithmView, IRadioButton *> _onNotchClikedCmd;
		Command<DSPAlgorithmView, IRadioButton *> _onSquelschClikedCmd;

		// fields
		std::unique_ptr<IUIControl> _subGroup;

		// methods
		void OnAGCClicked(IRadioButton *);
		void OnNRClicked(IRadioButton *);
		void OnNBClicked(IRadioButton *);
		void OnNotchClicked(IRadioButton *);
		void OnSquelchClicked(IRadioButton *);
	};
}

#endif // GUI_DSP_ALGORITHM_VIEW_HPP