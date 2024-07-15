#include "GEPictureMixedWithPicture.hpp"

namespace gui
{
	/*------------------------------------------------------------//
	// constructor
	//------------------------------------------------------------*/
	GEPictureMixedWithPicture::GEPictureMixedWithPicture(uint16_t x, uint16_t y, uint16_t width, uint16_t height,
		uint16_t fskippedLines, uint16_t fskippedRows, const PictureDataItem &fbitmap,
		uint16_t bskippedLines, uint16_t bskippedRows, const PictureDataItem &bbitmap,
		IGElement * nextElemen)
		:GEPicture(x, y, width, height, fskippedLines, fskippedRows, fbitmap, nextElemen),
		BackgroundPicture{bskippedLines, bskippedRows, bbitmap}
	{
	}

	/*------------------------------------------------------------//
	// constructor
	//------------------------------------------------------------*/
	GEPicture(const PictureDataItem &fbitmap, const PictureDataItem &bbitmap, IGElement * nextElemen)
		:GEPicture(fbitmap, nextElemen), BackgroundPicture{0, 0, bbitmap}
	{
	}

	/*------------------------------------------------------------//
	// Draws the graphic element by hardware features
	//------------------------------------------------------------*/
	void GEPictureMixedWithPicture::DrawWithRenderer(uint16_t x, uint16_t y, IRenderer & renderer)
	{
		renderer.Draw(this, x, y);
	}

	/*------------------------------------------------------------//
	// Sets new parameters for next drawing
	//------------------------------------------------------------*/
	void GEPictureMixedWithPicture::SetDrawingRegion(uint16_t skippedLines, uint16_t skippedRows,
		uint16_t width,uint16_t height)
	{

	}
} // namespace gui
