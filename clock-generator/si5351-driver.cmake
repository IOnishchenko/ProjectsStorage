
set(SI5351_DRIVER_SRCS
	"${lib_source_files_dir}/clock-generator/si5351.cpp"
)

set(SI5351_DRIVER_INCS
	"${lib_source_files_dir}/clock-generator"
)

if(ESP_PLATFORM)
	list(APPEND SI5351_DRIVER_SRCS "${lib_source_files_dir}/esp32-common/si5351-interface.c")
endif()