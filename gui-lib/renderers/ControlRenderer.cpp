#include "ControlRenderer.hpp"
#include "configuration.h"

/*----------------------------------------------------------------//
//
//----------------------------------------------------------------*/

namespace gui
{
	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template<typename TColor, uint16_t GBufferSize, uint16_t GFrameNumber>
	ControlRenderer<TColor, GBufferSize, GFrameNumber>::ControlRenderer(
		IGElementDecoder & decoder, lcd_driver & lcd)
		:_lcd{lcd}, _decoder{decoder}
	{
		// init frame structures
		for(int i = 0; i < GFrameNumber; i++)
		{
			_frame[i].GRam = _gdata[i];
		}
	}

	// IUIControlRenderer methods
	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template<typename TColor, uint16_t GBufferSize, uint16_t GFrameNumber>
	void ControlRenderer<TColor, GBufferSize, GFrameNumber>::DrawUIControl(IUIControl * control)
	{
		if(_state == State::Ready)
		{
			// switch to busy state
			_state = State::Drawing;

			InitializeAndDraw(control);
			
			// switch to ready state
			_state = State::Ready;
		}
		else
			Draw(control);
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template<typename TColor, uint16_t GBufferSize, uint16_t GFrameNumber>
	void ControlRenderer<TColor, GBufferSize, GFrameNumber>::DrawGroup(Group * group)
	{
		if(_state == State::Ready)
		{
			// switch to busy state
			_state = State::Drawing;

			InitializeAndDraw(group);

			// switch to ready state
			_state = State::Ready;
		}
		else
			Draw(group);
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template<typename TColor, uint16_t GBufferSize, uint16_t GFrameNumber>
	void ControlRenderer<TColor, GBufferSize, GFrameNumber>::DrawUIControlGElements(GFrame * frame, IUIControl * control)
	{
		for(IGElement * gel = control->GetGraphicElement(); gel; gel = gel->GetChild())
		{
			// frame2d data
			uint16_t fdx0, fdy0;
			// picture2d data
			uint16_t pdx0, pdy0, pw, pdy1, ph;

			uint16_t gelX0 = control->X + gel->X;
			uint16_t gelWidth = gel->GetWidth();
			uint16_t gelX1 = gelX0 + gelWidth;
			
			uint16_t gelY0 = control->Y + gel->Y;
			uint16_t gelHeight = gel->GetHeight();
			uint16_t gelY1 = gelY0 + gelHeight;
			
			uint16_t fx0 = frame->X;
			uint16_t fx1 = fx0 + frame->Width;
			uint16_t fy0 = frame->Y;
			uint16_t fy1 = fy0 + frame->Height;

			// check whether gel can be drawn in the frame buffer
			if(((gelX0 <= fx1) && (gelX1 >= fx0)) && ((gelY0 <= fy1) && (gelY1 >= fy0)))
			{
				// calculate X axis offsets
				if(fx0 > gelX0)
				{
					fdx0 = 0;
					pdx0 = fx0 - gelX0;
					pw = gelWidth - pdx0;
					if(pw > frame->Width)
						pw = frame->Width;
				}
				else
				{
					fdx0 = gelX0 - fx0;
					pdx0 = 0;
					pw = frame->Width - fdx0;
					if(pw > gelWidth)
						pw = gelWidth;
				}

				// calculate Y axis offsets
				if(fy0 > gelY0)
				{
					fdy0 = 0;
					pdy0 = fy0 - gelY0;
					ph = gelHeight - pdy0;
					if(ph > frame->Height)
						ph = frame->Height;
				}
				else
				{
					fdy0 = gelY0 - fy0;
					pdy0 = 0;
					ph = frame->Height - fdy0;
					if(ph > gelHeight)
						ph = gelHeight;
				}
				pdy1 = gelHeight - pdy0 - ph;

				// config decoder
				_decoder.Frame.gdata = frame->GRam + fdy0 + fdx0 * (frame->Height + frame->SkippedLines);
				_decoder.Frame.skippedLines = frame->Height - ph + frame->SkippedLines;

				_decoder.Picture.skippedLinesOnBottom = pdy1;
				_decoder.Picture.skippedLinesOnTop = pdy0;
				_decoder.Picture.skippedRows = pdx0;
				_decoder.Picture.width = pw;
				_decoder.Picture.height = ph;

				// decode GElement to frame
				gel->DecodeWithDecoder(_decoder);
			}
		}
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template<typename TColor, uint16_t GBufferSize, uint16_t GFrameNumber>
	inline void ControlRenderer<TColor, GBufferSize, GFrameNumber>::InitializeAndDraw(IUIControl * control)
	{
		// initialization
		uint16_t fwidth = GBufferSize/control->Height;
		uint16_t fullWidth = control->Width;
		if(fullWidth < fwidth)
			fwidth = fullWidth;
		uint16_t x0 = control->X;

		// send command to lcd to start gram data writing
		_lcd.set_region(control->X, control->Y, control->Width, control->Height);
		_lcd.start_writing_gdata();

		while(fullWidth)
		{
			GFrame * frameBuffer = &_frame[_frameIndex];
			frameBuffer->X = x0;
			frameBuffer->Y = control->Y;
			frameBuffer->Width = fwidth;
			frameBuffer->Height = control->Height;
			frameBuffer->SkippedLines = 0;

			DrawUIControlGElements(frameBuffer, control);

			// send data to lcd
			_lcd.write_gdata((const uint8_t *)frameBuffer->GRam, fwidth * control->Height * sizeof(TColor));

			x0 += fwidth;
			fullWidth -= fwidth;
			if(fullWidth < fwidth)
				fwidth = fullWidth;

			_frameIndex++;
			if(_frameIndex == GFrameNumber)
				_frameIndex = 0;
		}
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template<typename TColor, uint16_t GBufferSize, uint16_t GFrameNumber>
	inline void ControlRenderer<TColor, GBufferSize, GFrameNumber>::Draw(IUIControl * control)
	{
		// draw base group
		DrawUIControlGElements(&_frame[_frameIndex], control);
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template<typename TColor, uint16_t GBufferSize, uint16_t GFrameNumber>
	inline void ControlRenderer<TColor, GBufferSize, GFrameNumber>::InitializeAndDraw(Group * group)
	{
		// initialization
		uint16_t fwidth = GBufferSize/group->Height;
		_widthToDraw = group->Width;
		if(_widthToDraw < fwidth)
			fwidth = _widthToDraw;
		uint16_t x0 = group->X;

		// send command to lcd to start gram data writing
		_lcd.set_region(group->X, group->Y, group->Width, group->Height);
		_lcd.start_writing_gdata();

		while(_widthToDraw)
		{
			GFrame * frameBuffer = &_frame[_frameIndex];
			frameBuffer->X = x0;
			frameBuffer->Y = group->Y;
			frameBuffer->Width = fwidth;
			frameBuffer->Height = group->Height;
			frameBuffer->SkippedLines = 0;

			// draw base group
			DrawUIControlGElements(frameBuffer, group);

			// draw children
			for(auto item : group->Controls)
			{
				if(item->DoesOverlapRegion(x0, group->Y, fwidth, group->Height))
					// the control inside frame buffer region
					// write data to the frame buffer
					item->Draw();
			}

			// send data to lcd
			_lcd.write_gdata((uint8_t *)frameBuffer->GRam, fwidth * group->Height * sizeof(TColor));

			x0 += fwidth;
			_widthToDraw -= fwidth;
			if(_widthToDraw < fwidth)
				fwidth = _widthToDraw;

			_frameIndex++;
			if(_frameIndex == GFrameNumber)
				_frameIndex = 0;
		}
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template<typename TColor, uint16_t GBufferSize, uint16_t GFrameNumber>
	inline void ControlRenderer<TColor, GBufferSize, GFrameNumber>::Draw(Group * group)
	{
		// save origin frame settings
		GFrame * frameBuffer = &_frame[_frameIndex];
		GFrame origin = *frameBuffer;

		// updata frame according to current group size
		frameBuffer->GRam += group->Y - frameBuffer->Y;
		frameBuffer->Y = group->Y;
		frameBuffer->SkippedLines += frameBuffer->Height - group->Height;
		if(frameBuffer->X < group->X)
		{
			uint16_t dx = group->X - frameBuffer->X;
			frameBuffer->Width -= dx;
			frameBuffer->X = group->X;
			frameBuffer->GRam += frameBuffer->Height * dx;
		}
		uint16_t groupXend = group->X + group->Width;
		uint16_t frameXend = frameBuffer->X + frameBuffer->Width;
		if(groupXend < frameXend)
			frameBuffer->Width -= frameXend - groupXend;
		frameBuffer->Height = group->Height;

		// draw base group
		DrawUIControlGElements(frameBuffer, group);
		// draw children
		for(auto item : group->Controls)
		{
			if(item->DoesOverlapRegion(frameBuffer->X, frameBuffer->Y,
				frameBuffer->Width, frameBuffer->Height))
			{
				// the control inside frame buffer region
				// write data to the frame buffer
				item->Draw();
			}
		}
		// restore origin frame settings
		*frameBuffer = origin;
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	template class ControlRenderer<uint16_t, LCD_BUFFER_SIZE_IN_BYTES/sizeof(uint16_t),
		LCD_BUFFER_NUMBER>;
}