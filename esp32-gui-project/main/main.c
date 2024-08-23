#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "configuration.h"

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
extern esp_err_t hw_initialize();
extern esp_err_t vfs_initialize();
extern void gui_thread(void *args);

extern void gpio_task_example(void* arg);
extern QueueHandle_t gpio_evt_queue;

extern void test_thread(void * args);

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void app_main(void)
{
	hw_initialize();

	//Reset the display
	gpio_set_level(LCD_RST, 0);
	vTaskDelay(100 / portTICK_PERIOD_MS);
	gpio_set_level(LCD_RST, 1);
	vTaskDelay(100 / portTICK_PERIOD_MS);

	vfs_initialize();

	xTaskCreate(gui_thread, "guithread", 1024 * 4, (void *)0, 10, NULL);
	xTaskCreate(test_thread, "testthread", 1024 * 4, (void *)0, 10, NULL);
}
