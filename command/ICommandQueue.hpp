#ifndef COMMON_ICOMMAND_QUEUE_HPP
#define COMMON_ICOMMAND_QUEUE_HPP

#include "stdint.h"

/*--------------------------------------------------------------------------//
// 
//--------------------------------------------------------------------------*/
// Queue to send commands inside a single thread.
class ICommandQueue
{
public:

	// destructor
	virtual ~ICommandQueue() = default;

	// methods
	virtual void * PullFront() = 0;
	virtual void * AllocateItem() = 0;
};

/*--------------------------------------------------------------------------//
// 
//--------------------------------------------------------------------------*/
// Queue to send commands inside a single thread.
template<typename TMessage, uint32_t QLength>
class CommandQueue : public ICommandQueue
{
public:
	// destructor
	~CommandQueue() override = default;

	// methods
	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void * PullFront() override
	{
		if(_freePoolCount != QLength)
		{
			void * itm = _memoryPool[_indexToRead];

			_indexToRead++;
			if(_indexToRead == QLength)
				_indexToRead = 0;

			_freePoolCount++;
			return itm;
		}
		else
			return nullptr;
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void * AllocateItem() override
	{
		if(_freePoolCount)
		{
			void * buffer = _memoryPool[_indexToWrite];

			_indexToWrite++;
			if(_indexToWrite == QLength)
				_indexToWrite = 0;

			_freePoolCount--;
			return buffer;
		}
		else
			return nullptr;
	}

private:
	// fields
	uint8_t _memoryPool[QLength][sizeof(TMessage)];
	uint32_t _indexToWrite = 0;
	uint32_t _indexToRead = 0;
	uint32_t _freePoolCount = QLength;
};

#endif // COMMON_ICOMMAND_QUEUE_HPP