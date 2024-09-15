#include "IAnimatedControlManager.hpp"

namespace gui
{
	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	IAnimatedControlManager::IAnimatedControlManager()
		:
		_removeAnimationCmd(this, &IAnimatedControlManager::RemoveAnimation)
	{
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	void IAnimatedControlManager::RegisterAnimation(IAnimatedControl * animation)
	{
		if(!HasSubscribers())
			StartAnimation();
		Subscribe(animation);
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	void IAnimatedControlManager::UnregisterAnimation(IAnimatedControl * animation)
	{
		GetCommandDispatcher().PushToQueue(_removeAnimationCmd, animation);
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	void IAnimatedControlManager::AnimateControls(uint32_t duration)
	{
		for(auto itm : _subscribers)
		{
			itm->Animate();
		}
	}

	/*----------------------------------------------------------------//
	//
	//----------------------------------------------------------------*/
	void IAnimatedControlManager::RemoveAnimation(IAnimatedControl * animation)
	{
		Unsubscribe(animation);
		if(!HasSubscribers())
			StopAnimation();
	}
}