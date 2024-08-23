#include "configuration.h"
#include "driver/gptimer.h"
#include "freertos/FreeRTOS.h"
#include "GUIThread.hpp"

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
extern gui::GUIThread UIThread;

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
extern "C" bool IRAM_ATTR timer_key_scan_cb(gptimer_handle_t timer, const gptimer_alarm_event_data_t *edata, void *user_data)
{
	static uint32_t _KEY0 = 0;
	static uint32_t _KEY1 = 0;
	static uint32_t _KEY2 = 0;
	static uint32_t _currentKeyState = 0;

	_KEY0 = _KEY1;
	_KEY1 = _KEY2;
	_KEY2 = gpio_get_level(ENC_BUTTON);
	uint32_t keyState = (_KEY0 & _KEY1) | (_KEY1 & _KEY2) | (_KEY0 & _KEY2);

	if(_currentKeyState != keyState)
	{
		_currentKeyState = keyState;
		gui::KeyEvent event =
		{
			.Code = gui::KeyCode::ENCODER_KEY,
			.Type = (keyState) ? gui::KeyEventType::Released : gui::KeyEventType::Pressed,
		};
		if(_currentKeyState)
			UIThread.HandleKeyboardEventAsync.TryExecute(event);
		else
			UIThread.HandleKeyboardEventAsync.TryExecute(event);
	}

	return true;
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
constexpr uint32_t ENCODER_TIMEOUT = 2;
constexpr uint32_t ENCODER_TIME_THRESHOULD = 100;

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
extern "C" void IRAM_ATTR external_gpio_interrup_cb(void * param)
{
	/*
		_________              ________________                _______________
		a/b      |____________|                |______________|
		_______________                 _______________                  _______
		b/a            |_______________|               |________________|
		|ab      |01   |00    |10      |11     |01     |00    |10       |11
		|ab      |10   |00    |01      |11     |10     |00    |01       |11
	*/
	static uint32_t prevTimeStamp = 0;
	static uint32_t state = 0b11;
	uint32_t pins = (gpio_get_level(ENC_A) << 1) | gpio_get_level(ENC_B);

	switch(state)
	{
		case 0b11:
			if((pins == 0b01) || (pins == 0b10))
				state = pins;
			break;
		case 0b10:
			if(pins == 0b00)
				state <<= 2;
			else if(pins == 0b01)
				state = pins;
			break;
		case 0b01:
			if(pins == 0b00)
				state <<= 2;
			else if(pins == 0b10)
				state = pins;
			break;
		case 0b01'00:
			if(pins == 0b10)
			{
				state <<= 2;
				state |= pins;
			}
			break;
		case 0b10'00:
			if(pins == 0b01)
			{
				state <<= 2;
				state |= pins;
			}
			break;
		case 0b01'00'10:
			if(pins == 0b11)
			{
				uint32_t time = xTaskGetTickCount();
				state = pins;
				gui::EncoderEvent event =
				{
					.Id = gui::EncoderId::MAIN_ENCODER,
					.Direction = gui::EncoderDirection::ENC_DECREASE,
					.Duration = time - prevTimeStamp,
				};
				UIThread.HandleEncoderEventAsync.TryExecute(event);
				prevTimeStamp = time;
			}
			break;
		case 0b10'00'01:
			if(pins == 0b11)
			{
				uint32_t time = xTaskGetTickCount();
				state = pins;
				gui::EncoderEvent event =
				{
					.Id = gui::EncoderId::MAIN_ENCODER,
					.Direction = gui::EncoderDirection::ENC_INCREASE,
					.Duration = time - prevTimeStamp,
				};
				UIThread.HandleEncoderEventAsync.TryExecute(event);
				prevTimeStamp = time;
			}
			break;
		default:
			if(pins == 0b11)
				state = pins;
	}
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
extern "C" void test_thread(void * args)
{
	while(true)
	{
		vTaskDelay(100);
		//uint32_t time = xTaskGetTickCount();
		//UIThread.OnTimerTikedAsync(time);
	}
}