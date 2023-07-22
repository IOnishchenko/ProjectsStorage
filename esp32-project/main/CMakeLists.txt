set(project_dir "./../..")

include("${project_dir}/command/command.cmake")
include("${project_dir}/esp32-common/esp32-common.cmake")
include("${project_dir}/lcd-drivers/st7789-driver.cmake")
include("${project_dir}/audio-codecs/tlv320aic3204-driver.cmake")
include("${project_dir}/clock-generator/si5351-driver.cmake")

set(PROJET_SRCS
	"main.c"
	"instances.cpp"
	"i2c-devices-thread.cpp"
	"audio-data-flow-thread.cpp"
	"${ESP32_COMMON_SRCS}"
	"${LCD_DRIVER_SRCS}"
	"${AUDIO_CODEC_DRIVER_SRCS}"
	"${SI5351_DRIVER_SRCS}"
)

set(INCLUDE_DIRS
	"."
	"${project_dir}/common"
	"${ESP32_COMMON_INCS}"
	"${LCD_DRIVER_INCS}"
	"${GUI_128x64_INCS}"
	"${GUI_RESOURCES_INCS}"
	"${AUDIO_CODEC_DRIVER_INCS}"
	"${COMMAND_INCS}"
	"${SI5351_DRIVER_INCS}"
)

idf_component_register(
	SRCS "${PROJET_SRCS}" 
    INCLUDE_DIRS "${INCLUDE_DIRS}"
)
