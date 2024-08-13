#ifndef FREERTOS_COMMAND_QUEUE_HPP
#define FREERTOS_COMMAND_QUEUE_HPP

#include "stdint.h"
#include "AsyncCallQueue.hpp"
#include "AsyncCommand.hpp"
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#include "freertos/semphr.h"
#include "freertos/task.h"

/*--------------------------------------------------------------------------//
// 
//--------------------------------------------------------------------------*/
template<typename TMessage, uint32_t QLength>
class CommandQueue :  public AsyncCallQueue
{
public:
	// constructor
	CommandQueue()
		:_indexToWrite{0}
	{
		_spinlock = portMUX_INITIALIZER_UNLOCKED;
		_queueHandle = xQueueCreateStatic(QLength, sizeof(TMessage),
			_queueMessageBuffer, &_queueBuffer);
		_semaphoreHandle = xSemaphoreCreateCountingStatic(QLength, QLength, &_semaphoreBuffer);
	}

	// destructor
	~CommandQueue() override
	{
		vQueueDelete(_queueHandle);
		// TODO - 
		/*Delete a semaphore. This function must be used with care.
		For example, do not delete a mutex type semaphore if the mutex is held by a task.*/
		vSemaphoreDelete(_semaphoreHandle);
	}

	// methods
	/*--------------------------------------------------------------------------//
	// blocks the thread if there is not free memory
	//--------------------------------------------------------------------------*/
	void * MemoryAllocate() override
	{
		// thread blocks if there are not free memory
		xSemaphoreTake(_semaphoreHandle, portMAX_DELAY);

		// critical section
#if defined(ESP_PLATFORM)
		taskENTER_CRITICAL(&_spinlock);
#else
		taskENTER_CRITICAL();
#endif // ESP_PLATFORM
		void * res = static_cast<void *>(&_memoryPool[_indexToWrite]);
		_indexToWrite++;
		if(_indexToWrite == QLength)
			_indexToWrite = 0;
#if defined(ESP_PLATFORM)
		taskEXIT_CRITICAL(&_spinlock);
#else
		taskEXIT_CRITICAL();
#endif // ESP_PLATFORM

		return res;
	}

	/*--------------------------------------------------------------------------//
	// non blocking
	//--------------------------------------------------------------------------*/
	void * TryMemoryAllocate() override
	{
		BaseType_t xTaskWokenByReceive = pdTRUE;
		if(xSemaphoreTakeFromISR(_semaphoreHandle, &xTaskWokenByReceive) == pdTRUE)
		{
			// critical section
#if defined(ESP_PLATFORM)
			taskENTER_CRITICAL_ISR(&_spinlock);
#else
			taskENTER_CRITICAL_FROM_ISR();
#endif // ESP_PLATFORM
			void * res = static_cast<void *>(&_memoryPool[_indexToWrite]);
			_indexToWrite++;
			if(_indexToWrite == QLength)
				_indexToWrite = 0;
#if defined(ESP_PLATFORM)
			taskEXIT_CRITICAL_ISR(&_spinlock);
#else
			taskEXIT_CRITICAL_FROM_ISR();
#endif // ESP_PLATFORM

			return res;
		}
		else
			return nullptr;
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void MemoryFree(void * memory) override
	{
		xSemaphoreGive(_semaphoreHandle);
	}

	/*--------------------------------------------------------------------------//
	// block the thread
	//--------------------------------------------------------------------------*/
	void PushToQueue(void * item) override
	{
		xQueueSend(_queueHandle, &item, portMAX_DELAY);
	}

	/*--------------------------------------------------------------------------//
	// non blocking
	//--------------------------------------------------------------------------*/
	bool TryPushToQueue(void * item) override
	{
		return (xQueueSendFromISR(_queueHandle, &item, nullptr) == pdTRUE);
	}

	/*--------------------------------------------------------------------------//
	// 
	//--------------------------------------------------------------------------*/
	void * PullFromQueue() override
	{
		void * result;
		xQueueReceive(_queueHandle, &result, portMAX_DELAY);
		return result;
	}

private:
	// fields
	StaticQueue_t _queueBuffer;
	uint8_t _queueMessageBuffer[QLength * sizeof(void *)];
	QueueHandle_t _queueHandle;
	StaticSemaphore_t _semaphoreBuffer;
	SemaphoreHandle_t _semaphoreHandle;

	portMUX_TYPE _spinlock;
	TMessage _memoryPool[QLength];
	uint32_t _indexToWrite;
	uint32_t _indexToRead;
};

#endif // FREERTOS_COMMAND_QUEUE_HPP