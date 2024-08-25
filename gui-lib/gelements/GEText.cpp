#include "GEText.hpp"

namespace gui
{
	/*------------------------------------------------------------//
	// Constructor
	//------------------------------------------------------------*/
	GEText::GEText(uint16_t x, uint16_t y, uint16_t width, uint16_t height,
		const std::string_view & txt, uint32_t foreground, uint32_t background,
		const Font & font, IGElement * nextElement)
		:GEPictureMixedWithColor(x, y, width, height, 0, 0, nullptr,
		foreground, background, nextElement),
		Text{txt}, _font{font}, _currectIndex{0}, _baseX{x}
	{
	}

	/*------------------------------------------------------------//
	// Gets a text width (pixels)
	//------------------------------------------------------------*/
	uint16_t GEText::GetWidth()
	{
		return Foreground.Bitmap->width;
	}

	/*------------------------------------------------------------//
	// Gets a text height (pixels)
	//------------------------------------------------------------*/
	uint16_t GEText::GetHeight()
	{
		return Font::GetCharacterHeightInPixels(_font);
	}

	/*------------------------------------------------------------//
	//
	//------------------------------------------------------------*/
	IGElement * GEText::GetChild()
	{
		if((Text.length() - 1) > _currectIndex)
		{
			++_currectIndex;
			X += Foreground.Bitmap->width;
			Foreground.Bitmap = Font::GetCharacterGraphicData(_font, Text[_currectIndex]);
			return this;
		}
		_currectIndex = 0;
		return _gelement;
	}

	/*------------------------------------------------------------//
	//
	//------------------------------------------------------------*/
	void GEText::DecodeWithDecoder(IGElementDecoder & decoder)
	{
		decoder.Decode(this);
	}

	/*------------------------------------------------------------//
	//
	//------------------------------------------------------------*/
	uint16_t GEText::GetCurrentCharacterIndex() const
	{
		return _currectIndex;
	}

	/*------------------------------------------------------------//
	//
	//------------------------------------------------------------*/
	IGElement * GEText::PrepareForDrawing()
	{
		// restore default settings
		X = _baseX;
		_currectIndex = 0;
		Foreground.Bitmap = Font::GetCharacterGraphicData(_font, Text[_currectIndex]);
		return _gelement;
	}

	/*------------------------------------------------------------//
	//
	//------------------------------------------------------------*/
	void GEText::SetHorizontalPositionInCenter(uint16_t regionWidth, int16_t offset)
	{
		_baseX = GEText::Center_X(regionWidth, Text, _font) + offset;
	}

	/*------------------------------------------------------------//
	//
	//------------------------------------------------------------*/
	void GEText::SetVerticalPositionInCenter(uint16_t regionHeight, int16_t offset)
	{
		Y = GEText::Center_Y(regionHeight, _font) + offset;
	}

	/*------------------------------------------------------------//
	//
	//------------------------------------------------------------*/
	uint16_t GEText::GetTextWidth()
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