#ifndef GUI_CONTROL_RENDERER_HPP
#define GUI_CONTROL_RENDERER_HPP

#include "IUIControlRenderer.hpp"
#include "IGElementDecoder.hpp"
#include "lcd-driver.h"

namespace gui
{
	template<typename TColor, uint16_t GBufferSize, uint16_t GFrameNumber>
	class ControlRenderer : public IUIControlRenderer
	{
		struct GFrame
		{
			uint16_t X;
			uint16_t Y;
			uint16_t Width;
			uint16_t Height;
			TColor GRam[GBufferSize];
		};

		enum class State
		{
			Ready,
			Busy
		};

	public:
		// constructor
		ControlRenderer(IGElementDecoder & decoder, lcd_driver & lcd);

		// destructor
		~ControlRenderer() override = default;

		// IUIControlRenderer methods/
		void DrawUIControl(IUIControl * control) override;
		void DrawGroup(Group * group) override;

	private:
		// fields
		lcd_driver & _lcd;
		GFrame _frame[GFrameNumber];
		uint16_t _frameIndex = 0;
		uint16_t _widthToDraw = 0;
		IGElementDecoder & _decoder;
		State _state = State::Ready;

		// methods
		void DrawUIControlGElements(GFrame * frame, IUIControl * control);
		void InitializeAndDraw(IUIControl * control);
		void Draw(IUIControl * control);
		void InitializeAndDraw(Group * control);
		void Draw(Group * control);
	};
}

#endif // GUI_CONTROL_RENDERER_HPP