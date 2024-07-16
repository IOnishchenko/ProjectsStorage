#ifndef GUI_GEPICTURE_HPP
#define GUI_GEPICTURE_HPP

#include "picture_types.h"
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
			const PictureDataItem &Bitmap;
		};

		// fields
		uint16_t Width;
		uint16_t Height;
		PictureData Foreground;

		// constructor
		GEPicture(uint16_t x, uint16_t y, uint16_t width, uint16_t height,
			uint16_t skippedLines, uint16_t skippedRows, const PictureDataItem &bitmap, IGElement * nextElemen);

		GEPicture(const PictureDataItem &bitmap, IGElement * nextElemen);

		// destructor
		~GEPicture() override = default;

		// IGElement methods
		void DrawWithRenderer(uint16_t x, uint16_t y, IRenderer & renderer) override;
		uint16_t GetWidth() override;
		uint16_t GetHeight() override;
		// methods
		virtual void SetDrawingRegion(uint16_t skippedLines, uint16_t skippedRows, uint16_t width,uint16_t height);
	};
}

#endif // GUI_GEPICTURE_HPP