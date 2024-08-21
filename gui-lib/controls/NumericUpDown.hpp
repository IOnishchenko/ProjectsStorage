#ifndef GUI_NUMERIC_UP_DOWN_HPP
#define GUI_NUMERIC_UP_DOWN_HPP

#include "IUIControl.hpp"
#include "IEncoderEventHandler.hpp"
#include "IKeyboardEventHandler.hpp"
#include "ITouchScreenEventHandler.hpp"
#include "IFocusEventHandler.hpp"
#include "Action.hpp"
#include "GERectangle.hpp"
#include "GEText.hpp"
#include <string>

namespace gui
{
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	class NumericUpDown : public IUIControl,
		public ITouchScreenEventHandler,
		public IFocusEventHandler,
		public IEncoderEventHandler,
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
		};

		enum class Direction
		{
			Increase,
			Decrease,
			Undefined
		};

		struct Parameters
		{
			const NumericUpDown * Instance;
			Direction EventType;
		};

	public:
		// constructor
		NumericUpDown(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
			IGElement & disabledGEl, IGElement & enabledGEl, IGElement & focused,
			IGElement & pressedGEl, IGElement & selectedGEl,
			uint32_t disForegroubd, uint32_t disBackground,
			uint32_t enaForeground, uint32_t enaBackground,
			uint32_t focForeground, uint32_t focBackground,
			uint32_t presForeground, uint32_t presBackground,
			uint32_t selForeground, uint32_t selBackground,
			const Font & font, const Action<void(const Parameters &)> & valueChanged);

		// destructor
		~NumericUpDown() override = default;

		// methods
		void SetFloatValue(float value, int precision, bool alwaysDotVisible, const std::string & unit);
		void SetFloatValue(float value, int precision, bool alwaysDotVisible);
		void SetIntValue(int value, const std::string & unit);
		void SetIntValue(int value);

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

		// IEncoderEventHandler metod
		void OnEncoderMoved(EncoderEvent & event) override;

		// IKeyboardEventHandler methods
		void OnKeyPress(KeyEvent & event) override;
		void OnKeyRelease(KeyEvent & event) override;

		// operators
		NumericUpDown& operator=(const char * txt);
		NumericUpDown& operator=(const std::string & txt);
		NumericUpDown& operator=(const std::string_view & txt);

	protected:
		// fields
		State _state = State::Enabled;
		std::string _text;
		GEText _textGelement;
		bool _lockManagers = false;

		const Action<void(const Parameters &)> & _valueChangedCmd;
		IGElement & _disabledGEl;
		IGElement & _enabledGEl;
		IGElement & _focusedGEl;
		IGElement & _pressedGEl;
		IGElement & _selectedGEl;

		uint32_t _disForeground, _disBackground;
		uint32_t _enaForeground, _enaBackground;
		uint32_t _focForeground, _focBackground;
		uint32_t _presForeground, _presBackground;
		uint32_t _selForeground, _selBackground;

		// method
		void PrepareStringData(float value, int precision, bool alwaysDotVisible);
	};
}

#endif // GUI_NUMERIC_UP_DOWN_HPP