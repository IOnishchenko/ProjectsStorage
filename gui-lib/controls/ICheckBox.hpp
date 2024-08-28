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
	class ICheckBox : public IUIControl,
		public ITouchScreenEventHandler, public IFocusEventHandler,
		public IKeyboardEventHandler
	{
	public:
		enum class State
		{
			CheckedDisabled,
			UncheckedDisabled,
			CheckedEnabled,
			UncheckedEnabled,
			CheckedFocused,
			UncheckedFocused,
			CheckedPressed,
			UncheckedPressed,
		};

		// constructor
		ICheckBox(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
			const Action<void(ICheckBox *)> &checkedCmd, const Action<void(ICheckBox *)> &uncheckedCmd,
			IGElement & checkedDisabledGEl, IGElement & uncheckedDisabledGEl,
			IGElement & checkedEnabledGEl, IGElement & uncheckedEnabledGEl,
			IGElement & checkedFocusedGEl, IGElement & uncheckedFocusedGEl,
			IGElement & checkedPressedGEl, IGElement & uncheckedPressedGEl);
		
		// destructor
		~ICheckBox() override;

		// IUIControl methods
		IGElement * GetGraphicElement() override;
		void SetEnable(bool value) override;

		// ITouchScreenEventHandler methods
		void OnPress(TouchScreenEven & event) override;
		void OnRelease(TouchScreenEven & event) override;
		void OnPenLeave(TouchScreenEven & event) override;
		bool IsUnderTouch(uint16_t x, uint16_t y) override;

		// IFocusEventHandler methods
		bool OnFocused() override;
		void OnFocusLost() override;

		// IKeyboardEventHandler methods
		void OnKeyPress(KeyEvent & event) override;
		void OnKeyRelease(KeyEvent & event) override;

		// methods
		bool IsChecked();
		void Check();
		void Uncheck();
		
	protected:
		// commands
		const Action<void(ICheckBox *)> &_checkedCmd;
		const Action<void(ICheckBox *)> &_uncheckedCmd;

		// fields
		State _state = State::UncheckedEnabled;
		State _visualState = State::UncheckedEnabled;
		IGElement & _checkedDisabledGEl;
		IGElement & _uncheckedDisabledGEl;
		IGElement & _checkedEnabledGEl;
		IGElement & _uncheckedEnabledGEl;
		IGElement & _checkedFocusedGEl;
		IGElement & _uncheckedFocusedGEl;
		IGElement & _checkedPressedGEl;
		IGElement & _uncheckedPressedGEl;

		// methods
		void SetPressedState();
		void HandleOnReleaseEvent();
	};
}

#endif // GUI_ICHECK_BOX_HPP