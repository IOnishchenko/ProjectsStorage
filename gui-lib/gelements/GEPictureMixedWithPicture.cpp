#include "GEPictureMixedWithPicture.hpp"

namespace gui
{
	/*------------------------------------------------------------//
	// foreground is AL44
	// background is L4, L8
	//------------------------------------------------------------*/
	GEPictureMixedWithPicture::GEPictureMixedWithPicture(uint16_t x, uint16_t y, uint16_t width, uint16_t height,
		uint16_t fskippedLines, uint16_t fskippedRows, const PictureObject * fbitmap,
		uint16_t bskippedLines, uint16_t bskippedRows, const PictureObject * bbitmap,
		IGElement * nextElement)
		:GEPicture(x, y, width, height, fskippedLines, fskippedRows, fbitmap, nextElement),
		Background{bskippedLines, bskippedRows, 0xff00'0000, bbitmap}
	{
	}

	/*------------------------------------------------------------//
	// foreground is A4, A8
	// background is L4, L8
	//------------------------------------------------------------*/
	GEPictureMixedWithPicture::GEPictureMixedWithPicture(uint16_t x, uint16_t y, uint16_t width, uint16_t height,
		uint16_t fskippedLines, uint16_t fskippedRows, uint32_t fcolor, const PictureObject * fbitmap,
		uint16_t bskippedLines, uint16_t bskippedRows, const PictureObject * bbitmap,
		IGElement * nextElement)
		:GEPicture(x, y, width, height, fskippedLines, fskippedRows, fcolor, fbitmap, nextElement),
		Background{bskippedLines, bskippedRows, 0xff00'0000, bbitmap}
	{
	}

	/*------------------------------------------------------------//
	//
	//------------------------------------------------------------*/
	void GEPictureMixedWithPicture::DecodeWithDecoder(IGElementDecoder & decoder)
	{
		decoder.Decode(this);
	}
} // namespace gui
