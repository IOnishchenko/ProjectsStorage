#ifndef GUI_ISUBSCRIBER_MANAGER_HPP
#define GUI_ISUBSCRIBER_MANAGER_HPP

#include <forward_list>

namespace gui
{
	template<typename TSubscriber>
	class ISubscriberManager
	{
	public:

		// destructor
		virtual ~ISubscriberManager() = default;

		// methods
		void Subscribe(TSubscriber * subscriber)
		{
			_subscribers.push_front(subscriber);
		}

		void Unsubscribe(TSubscriber * subscriber)
		{
			_subscribers.remove(subscriber);
		}
		
		bool HasSubscribers()
		{
			return !_subscribers.empty();
		}
	protected:
		// fields
		std::forward_list<TSubscriber *> _subscribers;
	};
}

#endif // GUI_ISUBSCRIBER_MANAGER_HPP