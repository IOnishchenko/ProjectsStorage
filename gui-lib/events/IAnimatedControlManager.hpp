#ifndef GUI_EVENTS_IANIMATED_CONTROL_MANAGER_HPP
#define GUI_EVENTS_IANIMATED_CONTROL_MANAGER_HPP

#include "IAnimatedControl.hpp"
#include "ISubscribersManager.hpp"
#include "CommandDispatcher.hpp"
#include "Command.hpp"

namespace gui
{
	class IAnimatedControlManager : private ISubscribersManager<IAnimatedControl>
	{
	public:
		// constructor
		IAnimatedControlManager();

		// destructor
		virtual ~IAnimatedControlManager() = default;

		// methods
		void RegisterAnimation(IAnimatedControl * animation);
		void UnregisterAnimation(IAnimatedControl * animation);
		void AnimateControls(uint32_t duration);

	protected:
		// command
		Command<IAnimatedControlManager, IAnimatedControl *> _removeAnimationCmd;

		// methods
		virtual CommandDispatcher & GetCommandDispatcher() = 0;
		virtual void StartAnimation() = 0;
		virtual void StopAnimation() = 0;
		void RemoveAnimation(IAnimatedControl * animation);
	};
}

#endif // GUI_EVENTS_IANIMATED_CONTROL_MANAGER_HPP