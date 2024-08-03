#ifndef GUI_GEPICTURE_HPP
#define GUI_GEPICTURE_HPP

#include "gui_resource_types.h"
#include "IGElement.hpp"

namespace gui
{
	/*----------------------------------------------------------------//
	// Abstract class
	//----------------------------------------------------------------*/
	class GEPicture : public IGElement
	{
	public:
		// internal types
		struct PictureData
		{
			uint16_t SkippedLines;
			uint16_t SkippedRows;
			uint32_t Color;
			const PictureObject * Bitmap;
		};

		// fields
		uint16_t Width;
		uint16_t Height;
		PictureData Foreground;

		// constructor
		// L4, L8 pictures
		GEPicture(uint16_t x, uint16_t y, uint16_t width, uint16_t height,
			uint16_t skippedLines, uint16_t skippedRows, const PictureObject * bitmap, IGElement * nextElemen);
		// L4, L8 pictures
		GEPicture(const PictureObject * bitmap, IGElement * nextElemen);

		// A4, A8 pictures
		GEPicture(uint16_t x, uint16_t y, uint16_t width, uint16_t height,
			uint16_t skippedLines, uint16_t skippedRows, uint32_t color,
			const PictureObject * bitmap, IGElement * nextElemen);
		// A4, A8 pictures
		GEPicture(uint32_t color, const PictureObject * bitmap, IGElement * nextElemen);

		// destructor
		~GEPicture() override = default;

		// IGElement methods
		uint16_t GetWidth() override;
		uint16_t GetHeight() override;
		void DecoderWithDecoder(IGElementDecoder & decoder) override;
	};
}

#endif // GUI_GEPICTURE_HPP