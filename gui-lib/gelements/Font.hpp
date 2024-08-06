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
		// static functions
		static uint16_t GetCharacterWidthInPixels(const Font & font, uint8_t c);
		static uint16_t GetCharacterHeightInPixels(const Font & font);
		static uint16_t GetTextLineWidthInPixels(const Font & font, const std::string_view & text);
		static const PictureObject * GetCharacterGraphicData(const Font & font, uint8_t scode);
		static const PictureObject * GetFirstCharacterGraphicData(const Font & font);

		// constructor
		explicit Font(const PictureObject * const * fontGraphicData);

	private:
		// fields
		const PictureObject * const * _fontGraphicData; 
	};
}

#endif // GUI_FONT_HPP