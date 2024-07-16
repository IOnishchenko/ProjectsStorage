#include "Font.hpp"

namespace gui
{
	/*------------------------------------------------------------//
	//
	//------------------------------------------------------------*/
	uint16_t Font::GetCharacterWidthInPixels(const Font & font, uint8_t c)
	{
		return Font::GetCharacterGraphicData(font, c).width;
	}

	/*------------------------------------------------------------//
	//
	//------------------------------------------------------------*/
	uint16_t Font::GetCharacterHeightInPixels(const Font & font)
	{
		return font._fontGraphicData.items[0]->height;
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
	const PictureDataItem & Font::GetCharacterGraphicData(const Font & font, uint8_t scode)
	{
		return *font._fontGraphicData.items[scode - CHARACTER_FIRST_CODE];
	}

	/*------------------------------------------------------------//
	// constructor
	//------------------------------------------------------------*/
	Font::Font(const PictureCollection & fontGraphicData)
		: _fontGraphicData{fontGraphicData}
	{
	}
}