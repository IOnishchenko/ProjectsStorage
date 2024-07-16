#ifndef GUI_CHECK_BOX_HPP
#define GUI_CHECK_BOX_HPP

#include "IUIControl.hpp"
#include "ITouchScreenEventHandler.hpp"
#include "IGElement.hpp"
#include "Action.hpp"

namespace gui
{
	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	enum class CheckBoxState
	{
		Unchecked,
		Pressed,
		Checked
	};
	
	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	class CheckBox : public IUIControl, public ITouchScreenEventHandler
	{
		
	public:
		// constructor
		CheckBox(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
			const Action<void(CheckBox *)> &checkedCmd, const Action<void(CheckBox *)> &uncheckedCmd,
			IGElement * unchecked, IGElement * pressed, IGElement * checked);
		
		// destructor
		~CheckBox() override = default;

		// IUIControl methods
		IGElement * GetGraphicElement() override;
		// ITouchScreenEventHandler methods
		void OnPress(ITouchScreenEventHandler & penInfo) override;
		void OnRelease(ITouchScreenEventHandler & penInfo) override;
		void OnPenLeave(ITouchScreenEventHandler & penInfo) override;
		// methods
		CheckBoxState GetState();
		void SetState(CheckBoxState state);
		
	protected:
		CheckBoxState _state;
		CheckBoxState _visualState;
		const Action<void(CheckBox *)> &_checkedCmd;
		const Action<void(CheckBox *)> &_uncheckedCmd;
		IGElement * _uncheckedGEl;
		IGElement * _pressedGEl;
		IGElement * _checkedGEl;
	};
}

#endif // GUI_CHECK_BOX_HPP