#include "GEText.hpp"

namespace gui
{
	/*------------------------------------------------------------//
	// Constructor
	//------------------------------------------------------------*/
	GEText::GEText(uint16_t x, uint16_t y, uint16_t width, uint16_t height,
		const std::string_view & txt, uint32_t foreground, uint32_t background,
		const Font & font, IGElement * nextElement)
		:GEPictureMixedWithColor(x, y, width, height, 0, 0,
		&Font::GetFirstCharacterGraphicData(font), background, nextElement),
		_font{font}, _currectIndex{0}
	{
	}

	/*------------------------------------------------------------//
	// Gets a text width (pixels)
	//------------------------------------------------------------*/
	uint16_t GEText::GetWidth()
	{
		return Font::GetTextLineWidthInPixels(_font, Text);
	}

	/*------------------------------------------------------------//
	// Gets a text height (pixels)
	//------------------------------------------------------------*/
	uint16_t GEText::GetHeight()
	{
		return Font::GetCharacterHeightInPixels(_font);
	}

	/*------------------------------------------------------------//
	//
	//------------------------------------------------------------*/
	IGElement * GEText::GetChild()
	{
		if((Text.length() - 1) > _currectIndex)
		{
			++_currectIndex;
			Foreground.Bitmap = &Font::GetCharacterGraphicData(_font, Text[_currectIndex]);
			return this;
		}
		_currectIndex = 0;
		return _gelement;
	}

	/*------------------------------------------------------------//
	//
	//------------------------------------------------------------*/
	void GEText::DecodeWithDecoder(IGElementDecoder & decoder)
	{
		decoder.Decode(this);
	}

	/*------------------------------------------------------------//
	//
	//------------------------------------------------------------*/
	uint16_t GEText::GetCurrentCharacterIndex() const
	{
		return _currectIndex;
	}

	/*------------------------------------------------------------//
	//
	//------------------------------------------------------------*/
	GEText& GEText::operator=(const std::string_view & txt)
	{
		Text = txt;
		return *this;
	}
}