#include "freertos/FreeRTOS.h"
#include "freertos/timers.h"
#include "GUIThread.hpp"
#include "stdint.h"

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
extern gui::GUIThread UIThread;

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
static void AnimationTimerCallback(TimerHandle_t xTimer);

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
constexpr uint32_t ANIMATION_TIMER_TICK = 10;

static TimerHandle_t _handler;

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void CreateAnimationTimer()
{
	_handler = xTimerCreate("ATimer", ANIMATION_TIMER_TICK, pdTRUE, 0,
		AnimationTimerCallback);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void StartAnimationTimer()
{
	xTimerStart(_handler, ANIMATION_TIMER_TICK);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void StopAnimationTimer()
{
	xTimerStop(_handler, ANIMATION_TIMER_TICK);
}

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
static void AnimationTimerCallback(TimerHandle_t xTimer)
{
	UIThread.HandleAnimationTimerTickAsync.TryExecute(ANIMATION_TIMER_TICK);
}