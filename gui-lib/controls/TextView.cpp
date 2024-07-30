#include "TextView.hpp"

/*----------------------------------------------------------------//
//
//----------------------------------------------------------------*/

namespace gui
{

/*----------------------------------------------------------------//
//
//----------------------------------------------------------------*/
IGElement * TextView::GetGraphicElement()
{
	return &_background;
}

/*----------------------------------------------------------------//
//
//----------------------------------------------------------------*/
void TextView::AddLine(const std::string_view &line)
{
	bool updateGraphic = false;
	volatile uint16_t h = Font::GetCharacterHeightInPixels(_font) + _margin;
	volatile uint16_t y = _lineElements.empty() ? 0 : _lineElements.back().Y + h;
	volatile uint16_t fullLength = Font::GetTextLineWidthInPixels(_font, line);
	volatile uint16_t index = 0;
	volatile uint16_t spIndex = 0;

	// parse string into string lines according to graphic width
	while(fullLength > Width)
	{
		uint16_t len = 0, spLength = 0;
		for(uint16_t i = index; len < Width; i++)
		{
			char c = line[i];
			if(c == '\n')
			{
				spIndex = i;
				spLength = len;
				break;
			}

			uint16_t w = Font::GetCharacterWidthInPixels(_font, c);
			
			if(c == ' ')
			{
				spIndex = i;
				spLength = len;
			}
			len += w;
		}

		if(spIndex != index)
		{
			if(_maxLineNumber == _textLines.size())
				_textLines.pop_front();
			
			_textLines.push_back(std::string(line.substr(index, spIndex - index)));
			updateGraphic = true;
		}
		index = spIndex + 1;
		fullLength -= spLength;
	}

	if(fullLength)
	{
		if(_maxLineNumber == _textLines.size())
			_textLines.pop_front();
		
		_textLines.push_back(std::string(line.substr(index)));
		updateGraphic = true;
	}

	// update GEText elements
	if(updateGraphic)
	{
		uint16_t newElementsCount = _textLines.size() - _lineElements.size();
		// create new GEText if needed
		while(newElementsCount)
		{
			if(_lineElements.empty())
				_lineElements.push_back({0, y, 0, Font::GetCharacterHeightInPixels(_font),
					"", Foreground, Background, _font, nullptr});
			else
				_lineElements.push_back({0, y, 0, Font::GetCharacterHeightInPixels(_font),
					"", Foreground, Background, _font, &_lineElements.back()});
			--newElementsCount;
			y += h;
		}

		_background.SetChild(&_lineElements.back());
		// update text in the GEText elements
		auto gelent = _lineElements.begin();
		for(std::string & txt : _textLines)
		{
			auto & g = *gelent;
			g.Text = txt;
			gelent++;
		}
	}
}

/*----------------------------------------------------------------//
//
//----------------------------------------------------------------*/
void TextView::Clean()
{
	_background.SetChild(nullptr);
	_lineElements.clear();
	_textLines.clear();
}

/*----------------------------------------------------------------//
//
//----------------------------------------------------------------*/
TextView::TextView(uint16_t x, uint16_t y, uint16_t width, uint16_t height, const IUIContext & context,
	uint16_t margin, uint32_t foreground, uint32_t background, const std::string_view & line,
	const Font & font)
	:IUIControl(x, y, width, height, context),
	Foreground{foreground}, Background{background},_font{font}, _margin{margin},
	_background(0, 0, width, height, background, nullptr)
{
	// calculate max number of lines
	_maxLineNumber = height / (Font::GetCharacterHeightInPixels(font) + margin);
	
	AddLine(line);
}

/*----------------------------------------------------------------//
//
//----------------------------------------------------------------*/
TextView::TextView(uint16_t x, uint16_t y, uint16_t width, uint16_t height, const IUIContext & context,
	uint16_t margin, uint32_t foreground, uint32_t background, const Font & font)
	:IUIControl(x, y, width, height, context),
	Foreground{foreground}, Background{background}, _font{font}, _margin{margin},
	_background(0, 0, width, height, background, nullptr)
{
	// calculate max number of lines
	_maxLineNumber = height / (Font::GetCharacterHeightInPixels(font) + margin);
}

}