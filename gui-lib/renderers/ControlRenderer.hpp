#ifndef GUI_CONTROL_RENDERER_HPP
#define GUI_CONTROL_RENDERER_HPP

#include "IUIControlRenderer.hpp"
#include "GFrame.hpp"
#include "lcd-driver.h"

namespace gui
{
	template<typename TColor, uint16_t GBufferSize, uint16_t GFrameNumber>
	class ControlRenderer : public IUIControlRenderer
	{
		struct Picture2D
		{
			uint16_t skippedRows;
			uint16_t skippedLinesOnTop;
			uint16_t skippedLinesOnBottom;
			IGElement & gel;
		};

		struct GFrame
		{
			uint16_t X;
			uint16_t Y;
			uint16_t Width;
			uint16_t Height;
			TColor GRam[GBufferSize];
		};

		struct Frame2D
		{
			uint16_t Width;
			uint16_t SkippedLines;
			TColor * GData;
		};

	public:
		// constructor
		//ControlRenderer(IPictureDecoder & renderer, lcd_driver & lcd);

		// destructor
		~ControlRenderer() override = default;

		// IUIControlRenderer methods
		/*----------------------------------------------------------------//
		//
		//----------------------------------------------------------------*/
		void Draw(const IUIControl & control) override
		{
			
		}
		
		/*----------------------------------------------------------------//
		//
		//----------------------------------------------------------------*/
		void Draw(const Group & group) override
		{
			uint16_t fwidth = GBufferSize/group.Height;
			uint16_t fullWidth = group.Width;
			if(fullWidth < fwidth)
				fwidth = fullWidth;
			uint16_t x0 = group.X;

			// send command to lcd to start gram data writing
			// TODO

			while(fullWidth)
			{
				GFrame * frameBuffer = _frame[_frameIndex];
				frameBuffer->X = x0;
				frameBuffer->Y = group.Y;
				frameBuffer->Width = fwidth;
				frameBuffer->Height = group.Height;

				for(auto item : group.Controls)
				{
					if(item->DoesOverlapRegion(x0, group.Y, fwidth, group.Height))
						// the control inside frame buffer region
						// write data to the frame buffer
						DrawUIControlGElements(frameBuffer, item);
				}

				// send data to lcd
				// TODO

				x0 += fwidth;
				fullWidth -= fwidth;
				if(fullWidth < fwidth)
					fwidth = fullWidth;

				_frameIndex++;
				if(_frameIndex == GFrameNumber)
					_frameIndex = 0;
			}
		}

	private:
		// methods

		/*----------------------------------------------------------------//
		//
		//----------------------------------------------------------------*/
		void DrawUIControlGElements(GFrame * frame, IUIControl * control)
		{
			IGElement * gel = control->GetGraphicElement();
			while(gel)
			{
				Frame2D frame2d;
				uint16_t dx = 
				frame2d.GData = 
				frame2d.SkippedLines
				DrawGElement(Frame2D & frame, Picture2D * gel)
				gel = gel->GetChild();
			}
		}

		/*----------------------------------------------------------------//
		//
		//----------------------------------------------------------------*/
		void DrawGElement(Frame2D & frame, Picture2D * gel)
		{

		}

		/*----------------------------------------------------------------//
		//
		//----------------------------------------------------------------*/
		// fields
		lcd_driver & _lcd;
		GFrame _frame[GFrameNumber];
		uint16_t _frameIndex = 0;



	};
}

#endif // GUI_CONTROL_RENDERER_HPP