#ifndef GUI_IMODAL_WINDOW_HPP
#define GUI_IMODAL_WINDOW_HPP

#include "Group.hpp"
#include "IUIContext.hpp"
#include "IFocusManager.hpp"
#include "IEncoderEventManager.hpp"
#include "IEncoderEventHandler.hpp"
#include "IKeyboardEventManager.hpp"
#include "IKeyboardEventHandler.hpp"

namespace gui
{
	class IModalWindow : public Group,
		public IEncoderEventManager,
		public IEncoderEventHandler,
		public IKeyboardEventManager,
		public IKeyboardEventHandler
	{
	public:
		// constructors
		IModalWindow(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
			IGElement * gelement);

		IModalWindow(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
			const std::initializer_list<IUIControl *> & controls, IGElement * gelement);

		// destructor
		~IModalWindow() override;

		// IEncoderEventHandler methods
		void OnEncoderMoved(EncoderEvent & event) override;

		// IKeyboardEventHandler methods
		void OnKeyPress(KeyEvent & event) override;
		void OnKeyRelease(KeyEvent & event) override;
		void OnKeyLongPress(KeyEvent & event) override;

	protected:
		// field
		IUIContext _modalWindowContext;
	
	private:
		// fields
		const IUIContext & _mainContext;
		IFocusManager _focusManager;
	};
}

#endif // GUI_IMODAL_WINDOW_HPP