#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "configuration.h"

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
// extern void tlv320aic3204_codec_thread(void * args);
// extern void gui_thread(void * args);
extern esp_err_t hw_initialize();
extern esp_err_t vfs_initialize();
extern void gui_thread(void *args);

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
void app_main(void)
{
	printf("ESP32 Project started!!!\n");
	if(hw_initialize() == ESP_OK)
	{
		//Reset the display
		gpio_set_level(LCD_RST, 0);
		vTaskDelay(100 / portTICK_PERIOD_MS);
		gpio_set_level(LCD_RST, 1);
		vTaskDelay(100 / portTICK_PERIOD_MS);

		vfs_initialize();

		BaseType_t ret1 = xTaskCreate(gui_thread, "guithread", 1024 * 2, (void *)0, 10, NULL);
		printf("gui_thread was created with code %d\n", ret1);
	}
	else
		printf("HW initialization FAILED !!!\n");
}
