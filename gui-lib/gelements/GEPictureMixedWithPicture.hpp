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
		// foreground is A4, A8
		// background is L4, L8
		GEPictureMixedWithPicture(uint16_t x, uint16_t y, uint16_t width, uint16_t height,
			uint16_t fskippedLines, uint16_t fskippedRows, uint32_t fcolor, const PictureObject * fbitmap,
			uint16_t bskippedLines, uint16_t bskippedRows, const PictureObject * bbitmap,
			IGElement * nextElement);
		
		// foreground is AL44
		// background is L4, L8
		GEPictureMixedWithPicture(uint16_t x, uint16_t y, uint16_t width, uint16_t height,
			uint16_t fskippedLines, uint16_t fskippedRows, const PictureObject * fbitmap,
			uint16_t bskippedLines, uint16_t bskippedRows, const PictureObject * bbitmap,
			IGElement * nextElement);

		// destructor
		~GEPictureMixedWithPicture() override = default;

		// methods
		void DecodeWithDecoder(IGElementDecoder & decoder) override;
	};
}

#endif // GUI_GEPICTURE_MIXED_WITH_PICTUREH_HPP