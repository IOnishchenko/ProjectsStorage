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
	for(IGElement * itm = &_background; itm; itm = itm->PrepareForDrawing());
	return &_background;
}

/*----------------------------------------------------------------//
//
//----------------------------------------------------------------*/
void TextView::AddLine(const std::string_view &line)
{
	uint16_t lineLength = line.size();
	uint16_t startIndex = 0, spaceIndex = 0, endIndex = 0;
	uint16_t substringWidth = 0, spaceSubstingWidth = 0;

	bool updateGraphic = false;
	for(; endIndex < lineLength; endIndex++)
	{
		uint8_t c = line[endIndex];
		// if new line
		if(c == '\n')
		{
			if(startIndex != endIndex)
			{
				// create line text item for curren substring
				if(_textLines.size() == _maxLineNumber)
					_textLines.pop_front();

				_textLines.push_back(std::string(line.substr(startIndex, endIndex - startIndex)));
				startIndex = endIndex + 1;
				spaceIndex = startIndex;
				substringWidth = 0;
				updateGraphic = true;

				// redraw 
				if(RedrawEachLine)
					UpdateGElementsAndRedraw();
			}
			continue;
		}

		substringWidth += Font::GetCharacterWidthInPixels(_font, c);

		if(c <= ' ')
		{
			spaceIndex = endIndex;
			spaceSubstingWidth = substringWidth;
		}

		if(substringWidth > _textWidth)
		{
			if(_textLines.size() == _maxLineNumber)
				_textLines.pop_front();
			
			_textLines.push_back(std::string(line.substr(startIndex, spaceIndex - startIndex)));
			
			substringWidth -= spaceSubstingWidth;
			spaceSubstingWidth = substringWidth;
			startIndex = spaceIndex + 1;
			spaceIndex = endIndex;
			updateGraphic = true;

			// redraw 
			if(RedrawEachLine)
				UpdateGElementsAndRedraw();
		}
	}

	if(substringWidth)
	{
		if(_textLines.size() == _maxLineNumber)
			_textLines.pop_front();
		
		_textLines.push_back(std::string(line.substr(startIndex)));
		updateGraphic = true;

		// redraw 
		if(RedrawEachLine)
			UpdateGElementsAndRedraw();
	}

	// update GEText elements
	if((!RedrawEachLine) && updateGraphic)
		UpdateGElementsAndRedraw();
}

/*----------------------------------------------------------------//
//
//----------------------------------------------------------------*/
inline void TextView::UpdateGElementsAndRedraw()
{
	uint16_t newElementsCount = _textLines.size() - _lineElements.size();
	uint16_t fontHeight = Font::GetCharacterHeightInPixels(_font);
	uint16_t h = fontHeight + _margin;
	uint16_t y = _lineElements.empty() ? 0 : _lineElements.back().Y + h;
	// create new GEText if needed
	while(newElementsCount)
	{
		if(_lineElements.empty())
			_lineElements.push_back({_margin, y, _textWidth, fontHeight,
				"", Foreground, Background, _font, nullptr});
		else
			_lineElements.push_back({_margin, y, _textWidth, fontHeight,
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

	Draw();
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
	Foreground{foreground}, Background{background},_font{font}, _margin{margin}, _textWidth(width - 2 * margin),
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
	Foreground{foreground}, Background{background}, _font{font}, _margin{margin}, _textWidth(width - 2 * margin),
	_background(0, 0, width, height, background, nullptr)
{
	// calculate max number of lines
	_maxLineNumber = height / (Font::GetCharacterHeightInPixels(font) + margin);
}

}