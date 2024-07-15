#ifndef GUI_GE_TEXT_HPP
#define GUI_GE_TEXT_HPP

#include "IGElement.hpp"
#include "Font.hpp"
#include <string_view>

namespace gui
{
	/*------------------------------------------------------------//
	// 
	//------------------------------------------------------------*/
	class GEText : public IGElement
	{
	public:
	
		// fields
		uint32_t Foreground;
		uint32_t Background;
		std::string_view Text;
	
		// constructor
		GEText(uint16_t x, uint16_t y, const std::string_view & txt, uint32_t foreground, uint32_t background,
			const Font & font, IGElement * nextElement);

		// destructor
		~GEText() override = default;

		// public methods		
		uint16_t GetWidth() override;
		uint16_t GetHeight() override;
		IGElement * GetChild() override;
		void DrawWithRenderer(uint16_t x, uint16_t y, IRenderer & renderer) override;

		GEText& operator=(const std::string_view & txt);

	private:
		uint32_t _currectIndex;
		const Font & _font;
	};
}

#endif // GUI_GE_TEXT_HPP