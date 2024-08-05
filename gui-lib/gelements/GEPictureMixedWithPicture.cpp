#include "GEPictureMixedWithPicture.hpp"

namespace gui
{
	/*------------------------------------------------------------//
	// constructor for L4, L8 pictures
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
	// constructor for L4, L8 pictures
	//------------------------------------------------------------*/
	GEPictureMixedWithPicture::GEPictureMixedWithPicture(const PictureObject * fbitmap, const PictureObject * bbitmap,
		IGElement * nextElement)
		:GEPicture(fbitmap, nextElement), Background{0, 0, 0xff00'0000, bbitmap}
	{
	}

	/*------------------------------------------------------------//
	// constructor for A4, A8 pictures
	//------------------------------------------------------------*/
	GEPictureMixedWithPicture::GEPictureMixedWithPicture(uint16_t x, uint16_t y, uint16_t width, uint16_t height,
		uint16_t fskippedLines, uint16_t fskippedRows, uint32_t fcolor, const PictureObject * fbitmap,
		uint16_t bskippedLines, uint16_t bskippedRows, uint32_t bcolor, const PictureObject * bbitmap,
		IGElement * nextElement)
		:GEPicture(x, y, width, height, fskippedLines, fskippedRows, fcolor, fbitmap, nextElement),
		Background{bskippedLines, bskippedRows, bcolor, bbitmap}
	{
	}

	/*------------------------------------------------------------//
	// constructor for A4, A8 pictures
	//------------------------------------------------------------*/
	GEPictureMixedWithPicture::GEPictureMixedWithPicture(uint32_t fcolor, const PictureObject * fbitmap,
		uint32_t bcolor, const PictureObject * bbitmap, IGElement * nextElement)
		:GEPicture(fcolor, fbitmap, nextElement), Background{0, 0, bcolor, bbitmap}
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
