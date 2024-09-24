add_compile_definitions(USE_SH1106_DRIVER)

set(LCD_SH1106_DRIVER_SRCS
	"${lib_source_files_dir}/lcd-drivers/sh1106.c"
)

set(LCD_SH1106_DRIVER_INCS
	"${lib_source_files_dir}/lcd-drivers"
)

if(ESP_PLATFORM)
	list(APPEND LCD_SH1106_DRIVER_SRCS "${lib_source_files_dir}/esp32-common/sh1106-interface.c")
endif()