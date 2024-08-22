#ifndef GUI_RADIO_BUTTO_HPP
#define GUI_RADIO_BUTTO_HPP

#include "IUIControl.hpp"
#include "IFocusEventHandler.hpp"
#include "IKeyboardEventHandler.hpp"
#include "ITouchScreenEventHandler.hpp"
#include "Action.hpp"

namespace gui
{
	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	class IRadioButtonGroup;

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	class IRadioButton : public IUIControl,
		public ITouchScreenEventHandler,
		public IFocusEventHandler,
		public IKeyboardEventHandler
	{
	public:
		enum class State
		{
			Disabled,
			Enabled,
			Focused,
			Pressed,
			Selected,
			SelectedFocused,
		};

		// constructor
		IRadioButton(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
			IGElement & disabledGEl, IGElement & enabledGEl, IGElement & focusedGEl,
			IGElement & pressedGEl, IGElement & selectedGEl, IGElement & selectedFocusedGEl,
			const Action<void(IRadioButton *)> & selCmd);

		// destructor
		~IRadioButton() override = default;

		// IUIControl methods
		IGElement * GetGraphicElement() override;

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
		
		// method
		IRadioButton::State GetState();
		void SetAsSelectedInitially();
		
	protected:
		// fields
		const Action<void(IRadioButton *)> & _onItemSelected;

		State _state = State::Enabled;
		State _logicState = State::Enabled;

		IGElement & _disabledGEl;
		IGElement & _enabledGEl;
		IGElement & _focusedGEl;
		IGElement & _pressedGEl;
		IGElement & _selectedGEl;
		IGElement & _selectedFocusedGEl;

		IRadioButtonGroup * Group = nullptr;

		// methods
		void SetState(State state);
		void HandleOnRelease();
		
		friend class IRadioButtonGroup;
	};
}

#endif // GUI_RADIO_BUTTO_HPP