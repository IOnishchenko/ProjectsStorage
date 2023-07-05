set(project_dir "./../..")
include("${project_dir}/esp32-common/esp32-common.cmake")
include("${project_dir}/lcd-drivers/ssd1306-driver.cmake")
include("${project_dir}/gui-128x64/gui-128x64.cmake")
include("${project_dir}/gui-resources/gui-resources.cmake")
include("${project_dir}/audio-codecs/audio-codecs.cmake")
include("${project_dir}/command/command.cmake")

set(PROJET_SRCS
	"main.c"
	"instances.cpp"
	"audio-codec-thread.cpp"
	"audio-data-flow-thread.cpp"
	"${ESP32_COMMON_SRCS}"
	"${LCD_DRIVER_SRCS}"
	"${GUI_128x64_SRCS}"
	"${GUI_RESOURCES_SRCS}"
	"${AUDIO_CODEC_DRIVER_SRCS}"
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
)

idf_component_register(
	SRCS "${PROJET_SRCS}" 
    INCLUDE_DIRS "${INCLUDE_DIRS}"
)
