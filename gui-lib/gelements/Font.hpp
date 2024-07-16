#ifndef GUI_FONT_HPP
#define GUI_FONT_HPP

#include "picture_types.h"
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
		static const PictureDataItem & GetCharacterGraphicData(const Font & font, uint8_t scode);

		// constructor
		Font(const PictureCollection & fontGraphicData);

	private:
		// fields
		const PictureCollection & _fontGraphicData; 
	};
}

#endif // GUI_FONT_HPP