set(AUDIO_CODEC_DRIVER_SRCS
	"${lib_source_files_dir}/audio-codecs/tlv320aic3204-driver.cpp"
	"${lib_source_files_dir}/audio-codecs/tlv320aic3204-input-configs.cpp"
	"${lib_source_files_dir}/audio-codecs/tlv320aic3204-output-configs.cpp"
)

set(AUDIO_CODEC_DRIVER_INCS
	"${lib_source_files_dir}/audio-codecs"
)

if(ESP_PLATFORM)
	list(APPEND AUDIO_CODEC_DRIVER_SRCS "${lib_source_files_dir}/esp32-common/tlv320aic3204-interface.c")
endif()