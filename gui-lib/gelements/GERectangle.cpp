
#include "GERectangle.hpp"

namespace gui
{
	
	/*------------------------------------------------------------//
	//
	//------------------------------------------------------------*/
	GERectangle::GERectangle(uint16_t x, uint16_t y, uint16_t width, uint16_t height,
		uint32_t color, IGElement * nextElement)
		: IGElement(x, y, nextElement), Color(color), _width(width), _height(height)
	{}

	/*------------------------------------------------------------//
	//
	//------------------------------------------------------------*/
	uint16_t GERectangle::GetWidth()
	{
		return _width;
	}

	/*------------------------------------------------------------//
	//
	//------------------------------------------------------------*/
	uint16_t GERectangle::GetHeight()
	{
		return _height;
	}

	/*------------------------------------------------------------//
	//
	//------------------------------------------------------------*/
	void GERectangle::SetWidth(uint16_t width)
	{
		_width = width;
	}

	/*------------------------------------------------------------//
	//
	//------------------------------------------------------------*/
	void GERectangle::SetHeight(uint16_t height)
	{
		_height = height;
	}

	/*------------------------------------------------------------//
	//
	//------------------------------------------------------------*/
	void GERectangle::DecoderWithDecoder(IGElementDecoder & decoder)
	{
		decoder.Decode(this);
	}
}