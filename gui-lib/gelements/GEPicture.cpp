#include "GEPicture.hpp"

namespace gui
{
	/*------------------------------------------------------------//
	// constructor
	//------------------------------------------------------------*/
	GEPicture::GEPicture(uint16_t x, uint16_t y, uint16_t width, uint16_t height,
		uint16_t skippedLines, uint16_t skippedRows, const PictureDataItem &bitmap, IGElement * nextElement)
		: IGElement(x, y, nextElement), Width{width}, Height{height}, Foreground{skippedLines, skippedRows, bitmap}
	{
	}

	
	/*------------------------------------------------------------//
	// constructor
	//------------------------------------------------------------*/
	GEPicture::GEPicture(const PictureDataItem &bitmap, IGElement * nextElement)
		: IGElement(0, 0, nextElement), Width{bitmap.width}, Height{bitmap.height},
		Foreground{0, 0, bitmap}
	{
	}
	
	/*------------------------------------------------------------//
	// Returns Picture width (pixels)
	//------------------------------------------------------------*/
	uint16_t GEPicture::GetWidth()
	{
		return Width;
	}
	
	/*------------------------------------------------------------//
	// Returns Picture height (pixels)
	//------------------------------------------------------------*/
	uint16_t GEPicture::GetHeight()
	{
		return Height;
	}

	/*------------------------------------------------------------//
	// Draws the graphic element by hardware features
	//------------------------------------------------------------*/
	void GEPicture::DrawWithRenderer(uint16_t x, uint16_t y, IRenderer & renderer)
	{
		renderer.Draw(this, x, y);
	}

	/*------------------------------------------------------------//
	// Sets new parameters for next drawing
	//------------------------------------------------------------*/
	void GEPicture::SetDrawingRegion(uint16_t skippedLines, uint16_t skippedRows,
		uint16_t width,uint16_t height)
	{

	}
}