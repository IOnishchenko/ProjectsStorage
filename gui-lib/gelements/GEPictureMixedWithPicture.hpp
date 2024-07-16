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
		PictureData BackgroundPicture;

		// constructor
		GEPictureMixedWithPicture(uint16_t x, uint16_t y, uint16_t width, uint16_t height,
			uint16_t fskippedLines, uint16_t fskippedRows, const PictureDataItem & fbitmap,
			uint16_t bskippedLines, uint16_t bskippedRows, const PictureDataItem & bbitmap,
			IGElement * nextElemen);

		GEPictureMixedWithPicture(const PictureDataItem & fbitmap, const PictureDataItem & bbitmap,
			IGElement * nextElemen);

		// destructor
		~GEPictureMixedWithPicture() override = default;

		// methods
		void DrawWithRenderer(uint16_t x, uint16_t y, IRenderer & renderer) override;
		void SetDrawingRegion(uint16_t skippedLines, uint16_t skippedRows,
			uint16_t width,uint16_t height) override;
	};
}

#endif // GUI_GEPICTURE_MIXED_WITH_PICTUREH_HPP