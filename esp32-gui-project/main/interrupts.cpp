#include "configuration.h"
#include "driver/gptimer.h"
#include "freertos/FreeRTOS.h"

QueueHandle_t gpio_evt_queue = NULL;

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
static bool IRAM_ATTR timer_key_scan_cb(gptimer_handle_t timer, const gptimer_alarm_event_data_t *edata, void *user_data)
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
		xQueueSendFromISR(gpio_evt_queue, &gpio_num, NULL);
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
		uint32_t gpio_num = 200U + keyState;
		xQueueSendFromISR(gpio_evt_queue, &gpio_num, NULL);
	}

	return true;
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
extern "C" void timer_initialization()
{
	gptimer_handle_t gptimer = NULL;
	gptimer_config_t timer_config =
	{
		.clk_src = GPTIMER_CLK_SRC_DEFAULT,
		.direction = GPTIMER_COUNT_UP,
		.resolution_hz = 1000000, // 1MHz, 1 tick=1us
	};
	ESP_ERROR_CHECK(gptimer_new_timer(&timer_config, &gptimer));

	gptimer_event_callbacks_t cbs =
	{
		.on_alarm = timer_key_scan_cb,
	};
	ESP_ERROR_CHECK(gptimer_register_event_callbacks(gptimer, &cbs, nullptr));

	ESP_ERROR_CHECK(gptimer_enable(gptimer));

	gptimer_alarm_config_t alarm_config =
	{
		.alarm_count = 5000, // period = 5ms
		.reload_count = 0,
		.flags
		{
			.auto_reload_on_alarm = true,
		}, // enable auto-reload
	};
	ESP_ERROR_CHECK(gptimer_set_alarm_action(gptimer, &alarm_config));
	ESP_ERROR_CHECK(gptimer_start(gptimer));

	gpio_evt_queue = xQueueCreate(10, sizeof(uint32_t));
}

// static uint32_t _encoderA = 0;
// static uint32_t _encoderB = 0;
// static uint32_t _encoderATrig = 0;
// static uint32_t _encoderBTrig = 0;
// static uint32_t _lastCode = 0;

// static uint32_t _started = 0;
// /*-----------------------------------------------------------------//
// //
// //-----------------------------------------------------------------*/
// static void IRAM_ATTR encoder_isr_handler_a(void * arg)
// {
// 	uint32_t gpio_num = (uint32_t)0x01;
// 	xQueueSendFromISR(gpio_evt_queue, &gpio_num, NULL);

// 	// static int startTime = 0;
// 	// TickType_t time = xTaskGetTickCountFromISR();
// 	// int newdata = gpio_get_level(ENC_DATA);
// 	// if((time - startTime) > 20)
// 	// {
// 	// 	startTime = time;
// 	// 	uint32_t gpio_num = (uint32_t)newdata;
// 	// 	xQueueSendFromISR(gpio_evt_queue, &gpio_num, NULL);
// 	// }
// }

// /*-----------------------------------------------------------------//
// //
// //-----------------------------------------------------------------*/
// static void IRAM_ATTR encoder_isr_handler_b(void * arg)
// {
// 	// static int startTime = 0;
// 	// TickType_t time = xTaskGetTickCountFromISR();
// 	// int newdata = gpio_get_level(ENC_DATA);
// 	// if((time - startTime) > 20)
// 	// {
// 	// 	startTime = time;
// 	// 	uint32_t gpio_num = (uint32_t)newdata;
// 	// 	xQueueSendFromISR(gpio_evt_queue, &gpio_num, NULL);
// 	// }
// }

// /*-----------------------------------------------------------------//
// //
// //-----------------------------------------------------------------*/
// static void IRAM_ATTR encoder_key_isr_handler(void * arg)
// {
// 	static int startTime = 0;
// 	TickType_t time = xTaskGetTickCountFromISR();
// 	if((time - startTime) > 20)
// 	{
		
// 		int newdata = gpio_get_level(ENC_BUTTON);
// 		if(!newdata)
// 			gpio_set_intr_type(ENC_BUTTON, GPIO_INTR_POSEDGE);
// 		else
// 			gpio_set_intr_type(ENC_BUTTON, GPIO_INTR_NEGEDGE);

// 		startTime = time;
// 		uint32_t gpio_num = (uint32_t)newdata;
// 		xQueueSendFromISR(gpio_evt_queue, &gpio_num, NULL);
// 	}
// }

// static void IRAM_ATTR gpio_isr_handler(void* arg)
// {
// 	uint32_t gpio_num = (uint32_t) arg;
// 	xQueueSendFromISR(gpio_evt_queue, &gpio_num, NULL);
// }

// /*-----------------------------------------------------------------//
// //
// //-----------------------------------------------------------------*/
// extern "C" void exti_initialization()
// {
// 	//install gpio isr service
// 	gpio_install_isr_service(0);
// 	//hook isr handler for specific gpio pin
// 	gpio_isr_handler_add(ENC_CLK, encoder_isr_handler_a, (void*)ENC_CLK);
// 	//hook isr handler for specific gpio pin
// 	gpio_isr_handler_add(ENC_DATA, encoder_isr_handler_b, (void*)ENC_DATA);
// 	//hook isr handler for specific gpio pin
// 	gpio_isr_handler_add(ENC_BUTTON, encoder_key_isr_handler, (void*)ENC_BUTTON);

// 	gpio_evt_queue = xQueueCreate(10, sizeof(uint32_t));
// }