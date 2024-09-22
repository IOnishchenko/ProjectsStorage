#include "Label.hpp"
#include <sstream>
#include <iomanip>

namespace gui
{
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	Label::Label(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
		IGElement & disabledGEl, IGElement & enabledGEl,
		uint32_t disForegroubd, uint32_t disBackground,
		uint32_t enaForeground, uint32_t enaBackground,
		const Font & font, uint16_t textOffset)
		:
		IUIControl(x, y, w, h, context),
		_textGelement(textOffset, (h - Font::GetCharacterHeightInPixels(font))/2, w,
			Font::GetCharacterHeightInPixels(font), "UNK",
			enaForeground, enaBackground, font, nullptr),
		_defaultBackground{nullptr}, _disabledGEl{disabledGEl}, _enabledGEl{enabledGEl},
		_disForeground{disForegroubd}, _disBackground{disBackground},
		_enaForeground{enaForeground}, _enaBackground{enaBackground}
	{
	}

	/*-----------------------------------------------------------------//
	//
	//-----------------------------------------------------------------*/
	Label::Label(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
		uint32_t disForegroubd, uint32_t disBackground,
		uint32_t enaForeground, uint32_t enaBackground,
		const Font & font, uint16_t textOffset)
		:
		IUIControl(x, y, w, h, context),
		_textGelement(textOffset, (h - Font::GetCharacterHeightInPixels(font))/2, w,
			Font::GetCharacterHeightInPixels(font), "UNK",
			enaForeground, enaBackground, font, nullptr),
		_defaultBackground{new GERectangle(0, 0, w, h, enaBackground, &_textGelement)},
		_disabledGEl{*_defaultBackground.get()}, _enabledGEl{*_defaultBackground.get()},
		_disForeground{disForegroubd}, _disBackground{disBackground},
		_enaForeground{enaForeground}, _enaBackground{enaBackground}
	{
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void Label::SetFloatValue(float value, const std::string & unit, int precision, bool alwaysDotVisible)
	{
		PrepareStringData(value, precision, alwaysDotVisible);
		_text += unit;
		_textGelement = _text;
	}
	
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void Label::SetFloatValue(float value, int precision, bool alwaysDotVisible)
	{
		PrepareStringData(value, precision, alwaysDotVisible);
		_textGelement = _text;
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void Label::SetIntValue(int value, const std::string & unit)
	{
		_text = std::to_string(value);
		_text += unit;
		_textGelement = _text;
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void Label::SetIntValue(int value)
	{
		_text = std::to_string(value);
		_textGelement = _text;
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	IGElement * Label::GetGraphicElement()
	{
		_textGelement.SetHorizontalPositionInCenter(Width, 0);
		if((_enabledGEl.GetHeight() > _textGelement.GetHeight()) ||
			(_enabledGEl.GetWidth() > _textGelement.GetTextWidth()))
		{
			if(_enable)
			{
				for(IGElement * itm = &_enabledGEl; itm; itm = itm->PrepareForDrawing());
				return &_enabledGEl;
			}
			else
			{
				for(IGElement * itm = &_disabledGEl; itm; itm = itm->PrepareForDrawing());
				return &_disabledGEl;
			}
		}
		else
		{
			for(IGElement * itm = &_textGelement; itm; itm = itm->PrepareForDrawing());
			return &_textGelement;
		}
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	void Label::SetEnable(bool value)
	{
		if(value)
		{
			_textGelement.BackgroundColor = _enaBackground;
			_textGelement.Foreground.Color = _enaForeground;
		}
		else
		{
			_textGelement.BackgroundColor = _disBackground;
			_textGelement.Foreground.Color = _disForeground;
		}
		IUIControl::SetEnable(value);
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	Label& Label::operator=(const char * txt)
	{
		_text = txt;
		_textGelement = _text;
		return *this;
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	Label& Label::operator=(const std::string & txt)
	{
		_text = txt;
		_textGelement = _text;
		return *this;
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	Label & Label::operator=(const std::string_view & txt)
	{
		_text = txt;
		_textGelement = _text;
		return *this;
	}

	/*--------------------------------------------------------------------------//
	//
	//--------------------------------------------------------------------------*/
	inline void Label::PrepareStringData(float value, int precision, bool alwaysDotVisible)
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