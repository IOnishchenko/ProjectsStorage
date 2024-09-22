#include "NumericUpDown.hpp"
#include "IEncoderEventManager.hpp"
#include "ITouchScreenEventObserver.hpp"
#include <sstream>
#include <iomanip>

namespace gui
{
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	NumericUpDown::NumericUpDown(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
		IGElement & disabledGEl, IGElement & enabledGEl, IGElement & focusedGEl,
		IGElement & pressedGEl, IGElement & selectedGEl,
		uint32_t disForeground, uint32_t disBackground,
		uint32_t enaForeground, uint32_t enaBackground,
		uint32_t focForeground, uint32_t focBackground,
		uint32_t presForeground, uint32_t presBackground,
		uint32_t selForeground, uint32_t selBackground,
		const Font & font, const Action<void(const Parameters &)> & valueChanged)
		
		:
		IToggleFocusUIControl(x, y, w, h, context),
		_textGelement(0, GEText::Center_Y(h, font) + 2, w,
			Font::GetCharacterHeightInPixels(font), "", enaForeground,
			enaBackground, font, nullptr),
		_valueChangedCmd{valueChanged}, _disabledGEl{disabledGEl},
		_enabledGEl{enabledGEl}, _focusedGEl{focusedGEl},
		_pressedGEl{pressedGEl}, _selectedGEl{selectedGEl},

		_disForeground{disForeground}, _disBackground{disBackground},
		_enaForeground{enaForeground}, _enaBackground{enaBackground},
		_focForeground{focForeground}, _focBackground{focBackground},
		_presForeground{presForeground}, _presBackground{presBackground},
		_selForeground{selForeground}, _selBackground{selBackground}
	{
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void NumericUpDown::SetFloatValue(float value, int precision, bool alwaysDotVisible, const std::string & unit)
	{
		PrepareStringData(value, precision, alwaysDotVisible);
		_text += unit;
		_textGelement = _text;
	}
	
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void NumericUpDown::SetFloatValue(float value, int precision, bool alwaysDotVisible)
	{
		PrepareStringData(value, precision, alwaysDotVisible);
		_textGelement = _text;
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void NumericUpDown::SetIntValue(int value, const std::string & unit)
	{
		SetIntValue(value);
		_text += unit;
		_textGelement = _text;
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void NumericUpDown::SetIntValue(int value)
	{
		_text = std::to_string(value);
		for(int i = _text.length() - 3; i >= 0; i -= 3)
		{
			_text.insert(i, 1, '.');
		}
		_textGelement = _text;
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	IGElement * NumericUpDown::GetGraphicElement()
	{
		_textGelement.SetHorizontalPositionInCenter(Width, 0);
		switch(_state)
		{
			case State::Disabled:
				_textGelement.Foreground.Color = _disForeground;
				_textGelement.BackgroundColor = _disBackground;
				for(auto * itm = &_disabledGEl; itm; itm = itm->PrepareForDrawing());
				return &_disabledGEl;
			case State::Enabled:
				_textGelement.Foreground.Color = _enaForeground;
				_textGelement.BackgroundColor = _enaBackground;
				for(auto * itm = &_enabledGEl; itm; itm = itm->PrepareForDrawing());
				return &_enabledGEl;
			case State::Focused:
				_textGelement.Foreground.Color = _focForeground;
				_textGelement.BackgroundColor = _focBackground;
				for(auto * itm = &_focusedGEl; itm; itm = itm->PrepareForDrawing());
				return &_focusedGEl;
			case State::Pressed:
				_textGelement.Foreground.Color = _presForeground;
				_textGelement.BackgroundColor = _presBackground;
				for(auto * itm = &_pressedGEl; itm; itm = itm->PrepareForDrawing());
				return &_pressedGEl;
			case State::Selected:
				_textGelement.Foreground.Color = _selForeground;
				_textGelement.BackgroundColor = _selBackground;
				for(auto * itm = &_pressedGEl; itm; itm = itm->PrepareForDrawing());
				return &_selectedGEl;
			default:
				return nullptr;
		}
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void NumericUpDown::SetEnable(bool value)
	{
		_state = value ? State::Enabled :State::Disabled;
		IUIControl::SetEnable(value);
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void NumericUpDown::OnPress(TouchScreenEven & event)
	{
		_lockManagers = _state != State::Selected;
		_state = State::Pressed;
		Draw();
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void NumericUpDown::OnRelease(TouchScreenEven & event)
	{
		if(_lockManagers)
		{
			_context.EncoderEventManager->RegisterHandler(this);
			_state = State::Selected;
		}
		else
		{
			_context.EncoderEventManager->UnregisterHandler(this);
			_state = State::Enabled;
		}
		Draw();
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void NumericUpDown::OnPenLeave(TouchScreenEven & event)
	{
		_state = _lockManagers ?
			State::Selected : State::Enabled;
		Draw();
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	bool NumericUpDown::IsUnderTouch(uint16_t x, uint16_t y)
	{
		if(!_enable)
			return false;

		return IUIControl::IsPositionInsideControl(x, y);
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void NumericUpDown::OnEncoderMoved(EncoderEvent & event)
	{
		Parameters params =
		{
			.Instance = this,
			.EventType = event.Direction == EncoderDirection::ENC_INCREASE ?
				Direction::Increase : Direction::Decrease,
		};
		_valueChangedCmd(params);
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	NumericUpDown& NumericUpDown::operator=(const char * txt)
	{
		_text = txt;
		_textGelement = _text;
		return *this;
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	NumericUpDown& NumericUpDown::operator=(const std::string & txt)
	{
		_text = txt;
		_textGelement = _text;
		return *this;
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	NumericUpDown & NumericUpDown::operator=(const std::string_view & txt)
	{
		_text = txt;
		_textGelement = _text;
		return *this;
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	inline void NumericUpDown::PrepareStringData(float value, int precision, bool alwaysDotVisible)
	{
		std::stringstream out;
		out << std::setprecision(precision);
		out << std::fixed;
		out << value;
		_text = out.str();

		if(!alwaysDotVisible)
		{
			auto length = _text.length() - 1;
			for(int i = 0; i < precision + 1; ++i)
			{
				if(_text[length - i] == '.')
				{
					_text = _text.substr(0, length - i);
					break;
				}
				
				if(_text[length - i] != '0')
				{
					if(i != 0)
						_text = _text.substr(0, length - i + 1);
					break;
				}
			}
		}
	}
}