#ifndef GUI_GEPICTURE_MIXED_WITH_PICTUREH_HPP
#define GUI_GEPICTURE_MIXED_WITH_PICTUREH_HPP

#include "GEPicture.hpp"

namespace gui
{
	/*----------------------------------------------------------------//
	// Abstract class
	//----------------------------------------------------------------*/
	class GEPictureMixedWithPicture : public GEPicture
	{
	public:

		// fields
		PictureData Background;

		// constructor
		// L4, L8 pictures
		GEPictureMixedWithPicture(uint16_t x, uint16_t y, uint16_t width, uint16_t height,
			uint16_t fskippedLines, uint16_t fskippedRows, const PictureObject * fbitmap,
			uint16_t bskippedLines, uint16_t bskippedRows, const PictureObject * bbitmap,
			IGElement * nextElement);
		// L4, L8 pictures
		GEPictureMixedWithPicture(const PictureObject * fbitmap, const PictureObject * bbitmap,
			IGElement * nextElement);

		// A4, A8 pictures
		GEPictureMixedWithPicture(uint16_t x, uint16_t y, uint16_t width, uint16_t height,
			uint16_t fskippedLines, uint16_t fskippedRows, uint32_t fcolor, const PictureObject * fbitmap,
			uint16_t bskippedLines, uint16_t bskippedRows, uint32_t bcolor, const PictureObject * bbitmap,
			IGElement * nextElement);
		// A4, A8 pictures
		GEPictureMixedWithPicture(uint32_t fcolor, const PictureObject * fbitmap, uint32_t bcolor,
			const PictureObject * bbitmap, IGElement * nextElement);

		// destructor
		~GEPictureMixedWithPicture() override = default;

		// methods
		void DecodeWithDecoder(IGElementDecoder & decoder) override;
	};
}

#endif // GUI_GEPICTURE_MIXED_WITH_PICTUREH_HPP