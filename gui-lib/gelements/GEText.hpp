#ifndef GUI_GE_TEXT_HPP
#define GUI_GE_TEXT_HPP

#include "GEPictureMixedWithColor.hpp"
#include "Font.hpp"
#include <string_view>

namespace gui
{
	/*------------------------------------------------------------//
	// 
	//------------------------------------------------------------*/
	class GEText : public GEPictureMixedWithColor
	{
	public:
	
		// fields
		std::string_view Text;

		// constructor
		GEText(uint16_t x, uint16_t y, uint16_t width, uint16_t height, const std::string_view & txt,
			uint32_t foreground, uint32_t background, const Font & font, IGElement * nextElement);

		// destructor
		~GEText() override = default;

		// IGElement methods	
		uint16_t GetWidth() override;
		uint16_t GetHeight() override;
		IGElement * GetChild() override;
		void DecodeWithDecoder(IGElementDecoder & decoder) override;

		// methods
		uint16_t GetCurrentCharacterIndex() const;

		GEText& operator=(const std::string_view & txt);

	private:
		const Font & _font;
		uint16_t _currectIndex;
	};
}

#endif // GUI_GE_TEXT_HPP