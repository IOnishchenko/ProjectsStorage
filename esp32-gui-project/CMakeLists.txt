# For more information about build system see
# https://docs.espressif.com/projects/esp-idf/en/latest/api-guides/build-system.html
# The following five lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.20)

set(root_dir "./..")
set(project_dir "./../..")

# add_compile_definitions(GUI_TOUCH_SCREEN_ENABLED)
add_compile_definitions(GUI_FOCUSABLE_CONTROLS_ENABLE)

include("${root_dir}/command/command.cmake")
include("${root_dir}/common/common.cmake")
include("${root_dir}/esp32-common/esp32-common.cmake")
include("${root_dir}/lcd-drivers/st7789-driver.cmake")
include("${root_dir}/lcd-drivers/sh1106-driver.cmake")
include("${root_dir}/gui-lib/gui-lib.cmake")
include("${root_dir}/gui-resources/gui-resources.cmake")

set(PROJET_SRCS
	"main.c"
	"${ESP32_COMMON_SRCS}"
	"${LCD_ST7789_DRIVER_SRCS}"
	"${LCD_SH1106_DRIVER_SRCS}"
	"${GUI_LIB_SRCS}"
	"../gui/gui-thread.cpp"
	"../gui/sdr_dumy_picture_sdr_320x240_V2.c"
	"../gui/MainScreen.cpp"
)

set(INCLUDE_DIRS
	"."
	"${COMMON_DEF_INCS}"
	"${COMMAND_INCS}"
	"${ESP32_COMMON_INCS}"
	"${LCD_ST7789_DRIVER_INCS}"
	"${LCD_SH1106_DRIVER_INCS}"
	"${GUI_LIB_DIRS}"
	"${GUI_RESOURCES_INCS}"
	"../gui/"
)

list(REMOVE_DUPLICATES INCLUDE_DIRS)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(esp32-gui-project)
