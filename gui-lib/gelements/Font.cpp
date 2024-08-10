#include "Font.hpp"
#include <cstdio>

namespace gui
{
	/*------------------------------------------------------------//
	//
	//------------------------------------------------------------*/
	uint16_t Font::GetCharacterWidthInPixels(const Font & font, uint8_t c)
	{
		return (c < CHARACTER_FIRST_CODE) ?
			Font::GetCharacterGraphicData(font, CHARACTER_FIRST_CODE)->width :
			Font::GetCharacterGraphicData(font, c)->width;
	}

	/*------------------------------------------------------------//
	//
	//------------------------------------------------------------*/
	uint16_t Font::GetCharacterHeightInPixels(const Font & font)
	{
		return font._fontGraphicData[0]->height;
	}

	/*------------------------------------------------------------//
	//
	//------------------------------------------------------------*/
	uint16_t Font::GetTextLineWidthInPixels(const Font & font, const std::string_view & text)
	{
		uint16_t width = 0;
		for(size_t i = 0; i < text.length(); ++i)
		{
			width += Font::GetCharacterWidthInPixels(font, text[i]);
		}
		return width;
	}

	/*------------------------------------------------------------//
	//
	//------------------------------------------------------------*/
	const PictureObject * Font::GetCharacterGraphicData(const Font & font, uint8_t scode)
	{
		if((scode < CHARACTER_FIRST_CODE) || (scode > CHARACTER_LAST_CODE))
			return font._fontGraphicData[0];

		return font._fontGraphicData[scode - CHARACTER_FIRST_CODE];
	}

	/*------------------------------------------------------------//
	//
	//------------------------------------------------------------*/
	const PictureObject * Font::GetFirstCharacterGraphicData(const Font & font)
	{
		return font._fontGraphicData[0];
	}

	/*------------------------------------------------------------//
	// constructor
	//------------------------------------------------------------*/
	Font::Font(const PictureObject * const * fontGraphicData)
		: _fontGraphicData{fontGraphicData}
	{
	}
}