#ifndef GUI_SCREEN_HPP
#define GUI_SCREEN_HPP

#include <memory>
#include "Group.hpp"

namespace gui
{
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	class Screen : public Group
	{
	public:
		// constructor
		Screen(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
			Group * subGroup, const std::initializer_list<IUIControl *> & statisContent,
			IGElement * gelement);

		Screen(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const IUIContext & context,
			Group * subGroup, IUIControl * statisContent, IGElement * gelement);

		// destructor
		~Screen() override = default;

	protected:
		// methods
		void SetSubGroup(Group *);
		void ReplaceSubGroup(Group * screen);

		template<typename TScreen>
		void ReplaceGroup(std::unique_ptr<IUIControl> & screenOwner)
		{
			// // need to wait because ui control that is being drawing can be destructed
			// // and it will cause unexpected issue
			// IUIContext::Renderer->WaitWhileBusy();

			// screenOwner->OnDeinitialize();
			// screenOwner.reset(new TScreen);

			// _activeControl = screenOwner.get();
			// _activeControl->OnInitialize(0);
			// ReplaceDynamicUIControl(_activeControl);
			// _activeControl->Draw();

			// // need to wait the drawing has finished before animation starts
			// IUIContext::Renderer->WaitWhileBusy();
		}

		template<typename TScreen, typename... Args>
		void ReplaceGroup(std::unique_ptr<IUIContext> & screenOwner, Args... args)
		{
			// // need to wait because ui control that is being drawing can be destructed
			// // and it will cause unexpected issue
			// IUIContext::Renderer->WaitWhileBusy();

			// screenOwner->OnDeinitialize();
			// screenOwner.reset(new TScreen(args...));

			// _activeControl = screenOwner.get();
			// _activeControl->OnInitialize(0);
			// ReplaceDynamicUIControl(_activeControl);
			// _activeControl->Draw();

			// // need to wait the drawing has finished before animation starts
			// IUIContext::Renderer->WaitWhileBusy();
		}
	};
}

#endif // SCREEN_H