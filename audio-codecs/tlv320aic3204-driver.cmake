set(AUDIO_CODEC_DRIVER_SRCS
	"${project_dir}/audio-codecs/tlv320aic3204-driver.cpp"
	"${project_dir}/audio-codecs/tlv320aic3204-input-configs.cpp"
	"${project_dir}/audio-codecs/tlv320aic3204-output-configs.cpp"
)

set(AUDIO_CODEC_DRIVER_INCS
	"${project_dir}/audio-codecs"
)

if(ESP_PLATFORM)
	list(APPEND AUDIO_CODEC_DRIVER_SRCS "${project_dir}/esp32-common/tlv320aic3204-interface.c")
endif()