add_compile_definitions(USE_ST7789_DRIVER)

set(LCD_ST7789_DRIVER_SRCS
	"${project_dir}/lcd-drivers/st7789.c"
)

set(LCD_ST7789_DRIVER_INCS
	"${project_dir}/lcd-drivers"
)

if(ESP_PLATFORM)
	list(APPEND LCD_ST7789_DRIVER_SRCS "${project_dir}/esp32-common/st7789-interface.c")
endif()