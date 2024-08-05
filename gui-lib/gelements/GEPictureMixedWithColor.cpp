#include "GEPictureMixedWithColor.hpp"

namespace gui
{
	/*------------------------------------------------------------//
	// constructor for L4, L8 pictures
	//------------------------------------------------------------*/
	GEPictureMixedWithColor::GEPictureMixedWithColor(uint16_t x, uint16_t y, uint16_t width, uint16_t height,
		uint16_t skippedLines, uint16_t skippedRows, const PictureObject *  bitmap,
		uint32_t backgroundColor, IGElement * nextElement)
		:GEPicture(x, y, width, height, skippedLines, skippedRows, bitmap, nextElement),
		BackgroundColor{backgroundColor}
	{
	}

	/*------------------------------------------------------------//
	// constructor for L4, L8 pictures
	//------------------------------------------------------------*/
	GEPictureMixedWithColor::GEPictureMixedWithColor(const PictureObject * bitmap, uint32_t backgroundColor,
		IGElement * nextElemen)
		:GEPicture(bitmap, nextElemen),	BackgroundColor{backgroundColor}
	{
	}

	/*------------------------------------------------------------//
	// constructor for A4, A8 pictures
	//------------------------------------------------------------*/
	GEPictureMixedWithColor::GEPictureMixedWithColor(uint16_t x, uint16_t y, uint16_t width, uint16_t height,
		uint16_t skippedLines, uint16_t skippedRows, const PictureObject * bitmap,
		uint32_t foregroundColor, uint32_t backgroundColor, IGElement * nextElement)
		:GEPicture(x, y, width, height, skippedLines, skippedRows, foregroundColor, bitmap, nextElement),
		BackgroundColor{backgroundColor}
	{
	}

	/*------------------------------------------------------------//
	// constructor for A4, A8 pictures
	//------------------------------------------------------------*/
	GEPictureMixedWithColor::GEPictureMixedWithColor(const PictureObject * bitmap,
		uint32_t foregroundColor, uint32_t backgroundColor, IGElement * nextElemen)
		:GEPicture(foregroundColor, bitmap, nextElemen), BackgroundColor{backgroundColor}
	{
	}

	/*------------------------------------------------------------//
	//
	//------------------------------------------------------------*/
	void GEPictureMixedWithColor::DecodeWithDecoder(IGElementDecoder & decoder)
	{
		decoder.Decode(this);
	}
} // namespace gui
