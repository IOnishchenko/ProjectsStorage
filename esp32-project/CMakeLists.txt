# For more information about build system see
# https://docs.espressif.com/projects/esp-idf/en/latest/api-guides/build-system.html
# The following five lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.20)

set(root_dir "./..")
set(lib_source_files_dir "./../..")

include("${root_dir}/command/command.cmake")
include("${root_dir}/common/common.cmake")
include("${root_dir}/esp32-common/esp32-common.cmake")
include("${root_dir}/lcd-drivers/st7789-driver.cmake")
include("${root_dir}/audio-codecs/tlv320aic3204-driver.cmake")
include("${root_dir}/clock-generator/si5351-driver.cmake")
include("${root_dir}/dsp-common/dsp-common.cmake")

set(PROJET_SRCS
	"main.c"
	"instances.cpp"
	"i2c-devices-thread.cpp"
	"audio-data-flow-thread.cpp"
	"gui-thread.cpp"
	"test_pic.c"
	"sdr_320x240_Data.c"
	"${LCD_ST7789_DRIVER_SRCS}"
	"${AUDIO_CODEC_DRIVER_SRCS}"
	"${SI5351_DRIVER_SRCS}"
	"${DSP_COMMON_ALGOTITHMS_SRC}"
)

set(INCLUDE_DIRS
	"."
	"${COMMON_DEF_INCS}"
	"${ESP32_COMMON_INCS}"
	"${COMMAND_INCS}"
	"${ESP32_COMMON_INCS}"
	"${LCD_SSD1306_DRIVER_INCS}"
	"${LCD_ST7789_DRIVER_INCS}"
	"${AUDIO_CODEC_DRIVER_INCS}"
	"${SI5351_DRIVER_INCS}"
	"${DSP_COMMON_ALGOTITHMS_INCS}"
)

list(REMOVE_DUPLICATES INCLUDE_DIRS)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(esp32-project)
