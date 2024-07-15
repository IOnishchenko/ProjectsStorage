
set(SI5351_DRIVER_SRCS
	"${project_dir}/clock-generator/si5351.cpp"
)

set(SI5351_DRIVER_INCS
	"${project_dir}/clock-generator"
)

if(ESP_PLATFORM)
	list(APPEND SI5351_DRIVER_SRCS "${project_dir}/esp32-common/si5351-interface.c")
endif()