set(project_dir "./../..")
include("${project_dir}/esp32-common/esp32-common.cmake")
include("${project_dir}/lcd-drivers/ssd1306-driver.cmake")

set(PROJET_SRCS
	"main.c"
	"${ESP32_COMMON_SRCS}"
	"${LCD_DRIVER_SRCS}"
)

set(INCLUDE_DIRS
	"."
	"${ESP32_COMMON_INCS}"
	"${LCD_DRIVER_INCS}"
)

idf_component_register(
	SRCS "${PROJET_SRCS}" 
    INCLUDE_DIRS "${INCLUDE_DIRS}"
)
