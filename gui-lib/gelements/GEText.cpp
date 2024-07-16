#include "GEText.hpp"

namespace gui
{
	/*------------------------------------------------------------//
	// Constructor
	//------------------------------------------------------------*/
	GEText::GEText(uint16_t x, uint16_t y, const std::string_view & txt, uint32_t foreground, uint32_t background,
		const Font & font, IGElement * nextElement)
		: IGElement(x, y, nextElement), Text{txt}, Foreground{foreground}, Background{background},
		_font{font}, _currectIndex{0}
	{
	}

	/*------------------------------------------------------------//
	// Draws the graphic element by hardware features
	//------------------------------------------------------------*/
	void GEText::DrawWithRenderer(uint16_t x, uint16_t y, IRenderer & renderer)
	{
		renderer.Draw(this, x, y);
	}

	/*------------------------------------------------------------//
	//
	//------------------------------------------------------------*/
	IGElement * GEText::GetChild()
	{
		if((Text.length()-1) > _currectIndex)
		{
			++_currectIndex;
			return this;
		}
		_currectIndex = 0;
		return _gelement;
	}

	/*------------------------------------------------------------//
	// Gets a text height (pixels)
	//------------------------------------------------------------*/
	uint16_t GEText::GetHeight()
	{
		return Font::GetCharacterHeightInPixels(_font);
	}
	
	/*------------------------------------------------------------//
	// Gets a text width (pixels)
	//------------------------------------------------------------*/
	uint16_t GEText::GetWidth()
	{
		return Font::GetTextLineWidthInPixels(_font, Text);
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