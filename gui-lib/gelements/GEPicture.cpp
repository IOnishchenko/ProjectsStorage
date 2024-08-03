#include "GEPicture.hpp"

namespace gui
{
	/*------------------------------------------------------------//
	// constructor for L4, L8 pictures
	//------------------------------------------------------------*/
	GEPicture::GEPicture(uint16_t x, uint16_t y, uint16_t width, uint16_t height,
		uint16_t skippedLines, uint16_t skippedRows,
		const PictureObject * bitmap, IGElement * nextElement)
		: IGElement(x, y, nextElement), Width{width}, Height{height},
		Foreground{skippedLines, skippedRows, 0xff000000, bitmap}
	{
	}

	/*------------------------------------------------------------//
	// constructor for L4, L8 pictures
	//------------------------------------------------------------*/
	GEPicture::GEPicture(const PictureObject * bitmap, IGElement * nextElement)
		: IGElement(0, 0, nextElement), Width{bitmap->width}, Height{bitmap->height},
		Foreground{0, 0, 0xff000000, bitmap}
	{
	}

	/*------------------------------------------------------------//
	// constructor for A4, A8 pictures
	//------------------------------------------------------------*/
	GEPicture::GEPicture(uint16_t x, uint16_t y, uint16_t width, uint16_t height,
		uint16_t skippedLines, uint16_t skippedRows, uint32_t color,
		const PictureObject * bitmap, IGElement * nextElement)
		: IGElement(x, y, nextElement), Width{width}, Height{height},
		Foreground{skippedLines, skippedRows, color, bitmap}
	{
	}

	/*------------------------------------------------------------//
	// constructor for A4, A8 pictures
	//------------------------------------------------------------*/
	GEPicture::GEPicture(uint32_t color, const PictureObject * bitmap, IGElement * nextElement)
		: IGElement(0, 0, nextElement), Width{bitmap->width}, Height{bitmap->height},
		Foreground{0, 0, color, bitmap}
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
	//
	//------------------------------------------------------------*/
	void GEPicture::DecoderWithDecoder(IGElementDecoder & decoder)
	{
		decoder.Decode(this);
	}
}