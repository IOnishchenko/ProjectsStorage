#ifndef GUI_FONT_HPP
#define GUI_FONT_HPP

#include "gui_resource_types.h"
#include <string_view>

namespace gui
{
	constexpr uint8_t CHARACTER_FIRST_CODE = ' ';
	constexpr uint8_t CHARACTER_LAST_CODE = 0x7fU;

	class Font
	{
	public:
		// constructor
		explicit Font(const PictureObject * const * fontGraphicData);

		// destructor
		virtual ~Font() = default;

	private:
		// fields
		const PictureObject * const * _fontGraphicData; 
	
	public:
		// static functions
		/*------------------------------------------------------------//
		//
		//------------------------------------------------------------*/
		constexpr static uint16_t GetCharacterWidthInPixels(const Font & font, uint8_t c)
		{
			return (c < CHARACTER_FIRST_CODE) ?
				Font::GetCharacterGraphicData(font, CHARACTER_FIRST_CODE)->width :
				Font::GetCharacterGraphicData(font, c)->width;
		}

		/*------------------------------------------------------------//
		//
		//------------------------------------------------------------*/
		constexpr static uint16_t GetCharacterHeightInPixels(const Font & font)
		{
			return font._fontGraphicData[0]->height;
		}

		/*------------------------------------------------------------//
		//
		//------------------------------------------------------------*/
		constexpr static uint16_t GetTextLineWidthInPixels(const Font & font, const std::string_view & text)
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
		constexpr static const PictureObject * GetCharacterGraphicData(const Font & font, uint8_t scode)
		{
			if((scode < CHARACTER_FIRST_CODE) || (scode > CHARACTER_LAST_CODE))
				return font._fontGraphicData[0];

			return font._fontGraphicData[scode - CHARACTER_FIRST_CODE];
		}

		/*------------------------------------------------------------//
		//
		//------------------------------------------------------------*/
		constexpr static const PictureObject * GetFirstCharacterGraphicData(const Font & font)
		{
			return font._fontGraphicData[0];
		}
	};
}

#endif // GUI_FONT_HPP