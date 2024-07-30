#ifndef GUI_ICHECK_BOX_HPP
#define GUI_ICHECK_BOX_HPP

#include "IUIControl.hpp"
#include "ITouchScreenEventHandler.hpp"
#include "IFocusEventHandler.hpp"
#include "IKeyboardEventHandler.hpp"
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
	class ICheckBox : public IUIControl,
		public ITouchScreenEventHandler, public IFocusEventHandler,
		public IKeyboardEventHandler
	{
		
	public:
		// constructor
		ICheckBox(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
			const Action<void(ICheckBox *)> &checkedCmd, const Action<void(ICheckBox *)> &uncheckedCmd,
			IGElement * unchecked, IGElement * pressed, IGElement * checked);
		
		// destructor
		~ICheckBox() override;

		// IUIControl methods
		IGElement * GetGraphicElement() override;

		// ITouchScreenEventHandler methods
		void OnPress(ITouchScreenEventHandler *, TouchScreenEven & event) override;
		void OnRelease(ITouchScreenEventHandler *, TouchScreenEven & event) override;
		void OnPenLeave(ITouchScreenEventHandler *, TouchScreenEven & event) override;
		bool IsUnderTouch(uint16_t x, uint16_t y) override;

		// IFocusEventHandler methods
		void OnFocused(IFocusEventHandler *) override;
		void OnFocusLost(IFocusEventHandler *) override;

		// IKeyboardEventHandler methods
		void OnKeyPress(IKeyboardEventHandler *, KeyEvent & event) override;
		void OnKeyRelease(IKeyboardEventHandler *, KeyEvent & event) override;

		// methods
		CheckBoxState GetState();
		void SetState(CheckBoxState state);
		
	protected:
		CheckBoxState _state;
		CheckBoxState _visualState;
		const Action<void(ICheckBox *)> &_checkedCmd;
		const Action<void(ICheckBox *)> &_uncheckedCmd;
		IGElement * _uncheckedGEl;
		IGElement * _pressedGEl;
		IGElement * _checkedGEl;
	};
}

#endif // GUI_ICHECK_BOX_HPP