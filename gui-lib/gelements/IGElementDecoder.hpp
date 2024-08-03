#ifndef GUI_IPICTURE_DECODER_HPP
#define GUI_IPICTURE_DECODER_HPP

namespace gui
{
	class GEText;
	class GERectangle;
	class GEPicture;
	class GEPictureMixedWithColor;
	class GEPictureMixedWithPicture;
	
	struct IGElementDecoder
	{
		struct Picture2D
		{
			uint16_t skippedRows = 0;
			uint16_t skippedLinesOnTop = 0;
			uint16_t skippedLinesOnBottom = 0;
			uint16_t width = 0;
			uint16_t height = 0;
		};

		struct Frame2D
		{
			uint16_t skippedLines = 0;
			void * gdata = 0;
		};
		
		// dectructor
		virtual ~IGElementDecoder() = default;

		// methods
		virtual void Decode(const GERectangle * gel) = 0;
		virtual void Decode(const GEPicture * gel) = 0;
		virtual void Decode(const GEPictureMixedWithColor * gel) = 0;
		virtual void Decode(const GEPictureMixedWithPicture * gel) = 0;

		// fields
		Picture2D Picture;	// represents data to drawing
		Frame2D Frame;		// represents memory region to draw the picture
	};
}

#endif // GUI_IPICTURE_DECODER_HPP