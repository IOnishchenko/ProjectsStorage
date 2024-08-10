#ifndef GUI_TEXT_VIEV_HPP
#define GUI_TEXT_VIEV_HPP

#include "IUIControl.hpp"
#include "GEText.hpp"
#include "GERectangle.hpp"
#include "Font.hpp"
#include <list>
#include <string>

namespace gui
{

/*----------------------------------------------------------------//
//
//----------------------------------------------------------------*/
class TextView : public IUIControl
{
public:
	// constructor
	TextView(uint16_t x, uint16_t y, uint16_t width, uint16_t height, const IUIContext & context,
		uint16_t margin, uint32_t foreground, uint32_t background, const std::string_view & line,
		const Font & font);

	TextView(uint16_t x, uint16_t y, uint16_t width, uint16_t height, const IUIContext & context,
		uint16_t margin, uint32_t foreground, uint32_t background, const Font & font);

	// destructor
	~TextView() override = default;

	// fields
	uint32_t Foreground;
	uint32_t Background;

	// If true the object will be redrawn when each new line is added
	// If false all new lines will be created then the object will be redrawn
	bool RedrawEachLine = false;

	// methods
	IGElement * GetGraphicElement() override;
	
	void AddLine(const std::string_view & line);
	void Clean();

private:
	// methods
	void UpdateGElementsAndRedraw();

	// fields
	uint16_t _maxLineNumber;
	std::list<std::string> _textLines;
	std::list<GEText> _lineElements;
	const Font & _font;
	uint16_t _margin;
	uint16_t _textWidth;

	//background
	GERectangle _background;
};

}

#endif // GUI_TEXT_VIEV_HPP