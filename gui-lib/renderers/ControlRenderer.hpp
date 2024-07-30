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
		class UIControlDecorator
		{
		public:
			IUIControl & Control;
			int16_t skippedRows;
			int16_t skippedLinesOnTop;
			int16_t skippedLinesOnBottom;
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
			// create gframe objects
			int16_t frameWidth = GBufferSize/(GFrameNumber*control.Height);
			int16_t remainingWidth = control.Width;
			int16_t x0 = control.X;

			// config GFrame objects
			for(int16_t i = 0; i < GFrameNumber; i++)
			{
				_frame[i].Y = 0;
				_frame[i].skippedRows = 0;
				_frame[i].skippedLines = 0;
				_frame[i].Height = control.Height;
				_frame[i].GRam = &_gdata[i * (frameWidth * control.Height)];
			}

			// create UIControl decorator
			UIControlDecorator decor;
			decor.Control = control;
			decor.skippedRows = 0;
			decor.skippedLinesOnTop = 0;
			decor.skippedLinesOnBottom = 0;

			// config LCD to start writing to the region
			_lcd.set_region(control.X, control.Y, control.Width, control.Height);
			_lcd.start_writing_gdata();

			while(remainingWidth)
			{
				int16_t width = (remainingWidth > frameWidth)
					? frameWidth : remainingWidth;
				_frame[_frameIndex].X = x0;
				_frame[_frameIndex].Width = width;

				// decode data to current frame
				DrawToGFrame(_frame[_frameIndex], decor);

				// write the frame to LCD module
				_lcd.write_gdata(_frame[_frameIndex].GRam,
					width * control.Height * sizeof(TColor))

				// update variables fot next iteration
				remainingWidth -= width;
				x0 += width;
				decor.skippedRows += width;
				_frameIndex++;
				if(_frameIndex == GFrameNumber)
					_frameIndex = 0;
			}
		}
		
		/*----------------------------------------------------------------//
		//
		//----------------------------------------------------------------*/
		void Draw(const Group & group) override
		{
		}

	private:
		lcd_driver & _lcd;
		TColor _gdata[GBufferSize];
		GFrame _frame[GFrameNumber];
		uint16_t _frameIndex = 0;

		/*----------------------------------------------------------------//
		//
		//----------------------------------------------------------------*/
		void DrawToGFrame(GFrame & dstFrame, const UIControlDecorator & control)
		{

		}

	};
}

#endif // GUI_CONTROL_RENDERER_HPP