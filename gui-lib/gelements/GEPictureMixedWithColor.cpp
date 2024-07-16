#include "GEPictureMixedWithColor.hpp"

namespace gui
{
	/*------------------------------------------------------------//
	// constructor
	//------------------------------------------------------------*/
	GEMixedPictureWithColor::GEMixedPictureWithColor(uint16_t x, uint16_t y, uint16_t width, uint16_t height,
		uint16_t skippedLines, uint16_t skippedRows, const PictureDataItem &bitmap,
		uint32_t backgroundColor, IGElement * nextElemen)
		:GEPicture(x, y, width, height, skippedLines, skippedRows, bitmap, nextElemen),
		BackgroundColor{backgroundColor}
	{
	}

	/*------------------------------------------------------------//
	// constructor
	//------------------------------------------------------------*/
	GEMixedPictureWithColor::GEMixedPictureWithColor(const PictureDataItem &bitmap, uint32_t backgroundColor,
		IGElement * nextElemen)
		:GEPicture(bitmap, nextElemen), BackgroundColor{backgroundColor}
	{
	}


	/*------------------------------------------------------------//
	// Draws the graphic element by hardware features
	//------------------------------------------------------------*/
	void GEMixedPictureWithColor::DrawWithRenderer(uint16_t x, uint16_t y, IRenderer & renderer)
	{
		renderer.Draw(this, x, y);
	}

	/*------------------------------------------------------------//
	// Sets new parameters for next drawing
	//------------------------------------------------------------*/
	void GEMixedPictureWithColor::SetDrawingRegion(uint16_t skippedLines, uint16_t skippedRows,
		uint16_t width,uint16_t height)
	{

	}
} // namespace gui
