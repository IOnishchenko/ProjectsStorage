if()
	add_compile_definitions(USE_SSD1306_DRIVER)

	set(LCD_SSD1306_DRIVER_SRCS
		"${lib_source_files_dir}/lcd-drivers/ssd1306.c"
	)

	set(LCD_SSD1306_DRIVER_INCS
		"${lib_source_files_dir}/lcd-drivers"
	)

	if(ESP_PLATFORM)
		list(APPEND LCD_ST7789_DRIVER_SRCS "${lib_source_files_dir}/esp32-common/ssd1306-interface.c")
	endif()