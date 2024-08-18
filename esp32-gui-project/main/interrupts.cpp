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
static uint32_t _A0 = 0;
static uint32_t _A1 = 0;
static uint32_t _A2 = 0;
static uint32_t _oldA = 0;
static uint32_t _currentA = 0;
static uint32_t _lockA = 0;

static uint32_t _B0 = 0;
static uint32_t _B1 = 0;
static uint32_t _B2 = 0;

static uint32_t _KEY0 = 0;
static uint32_t _KEY1 = 0;
static uint32_t _KEY2 = 0;
static uint32_t _currentKeyState = 0;

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
extern "C" bool IRAM_ATTR timer_key_scan_cb(gptimer_handle_t timer, const gptimer_alarm_event_data_t *edata, void *user_data)
{
	_A0 = _A1;
	_A1 = _A2;
	_A2 = gpio_get_level(ENC_CLK);

	_oldA = _currentA;
	_currentA = (_A0 & _A1) | (_A1 & _A2) | (_A0 & _A2);

	_B0 = _B1;
	_B1 = _B2;
	_B2 = gpio_get_level(ENC_DATA);

	if((!_lockA) && _oldA && (!_currentA))
	{
		uint32_t gpio_num = (_B0 & _B1) | (_B1 & _B2) | (_B0 & _B2);
		gui::EncoderEvent event =
		{
			.Id = gui::EncoderId::MAIN_ENCODER,
			.Direction = gpio_num ? gui::EncoderDirection::ENC_INCREASE :
				gui::EncoderDirection::ENC_DECREASE,
		};
		UIThread.HandleEncoderEventAsync.TryExecute(event);
		_lockA = true;
	}

	if(_lockA && (!_oldA) && _currentA)
	{
		_lockA = false;
	}

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
extern "C" void test_thread(void * args)
{
	while(true)
	{
		vTaskDelay(100);
		//uint32_t time = xTaskGetTickCount();
		//UIThread.OnTimerTikedAsync(time);
	}
}