#include "Label.hpp"
#include <sstream>
#include <iomanip>

namespace gui
{
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	Label::Label(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
		uint32_t foregroundRGB, uint32_t backgroundRGB, const Font & font, uint16_t textOffset)
		:IUIControl(x, y, w, h, context), _background(0, 0, w, h, backgroundRGB, &_textGelement),
		_textGelement(textOffset, (h - Font::GetCharacterHeightInPixels(font))/2, w, h,
		"", foregroundRGB, backgroundRGB, font, nullptr)
	{
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
	void Label::SetFloatValueToLabelWithSuffix(float value, const std::string & unit, int precision, bool alwaysDotVisible)
	{
		PrepareStringData(value, precision, alwaysDotVisible);
		_text += unit;
		_textGelement = _text;
	}
	
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void Label::SetFloatValueToLabe(float value, int precision, bool alwaysDotVisible)
	{
		PrepareStringData(value, precision, alwaysDotVisible);
		_textGelement = _text;
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void Label::SetIntValueToLabel(int value)
	{
		_text = std::to_string(value);
		_textGelement = _text;
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

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	IGElement * Label::GetGraphicElement()
	{
		if((_background.GetHeight() > _textGelement.GetHeight()) || (_background.GetWidth() > _textGelement.GetWidth()))
		{
			return &_background;
		}
		else
		{
			return &_textGelement;
		}
	}
}