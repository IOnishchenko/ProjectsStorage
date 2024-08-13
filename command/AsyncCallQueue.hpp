#ifndef ASYNC_CALL_QUEUE_HPP
#define ASYNC_CALL_QUEUE_HPP

class AsyncCallQueue
{
public:
	// destructor
	virtual ~AsyncCallQueue() = default;

	// methods
	// blocks the thread if there is not free memory
	virtual void * MemoryAllocate() = 0;
	// non blocking
	virtual void * TryMemoryAllocate() = 0;
	virtual void MemoryFree(void * memory) = 0;
	// block the thread
	virtual void PushToQueue(void * item) = 0;
	// non blocking
	virtual bool TryPushToQueue(void * item) = 0;
	virtual void * PullFromQueue() = 0;
};

#endif // ASYNC_CALL_QUEUE_HPP