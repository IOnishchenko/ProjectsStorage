idf_component_register(
	SRCS "configuration.c" "main.c" "${PROJET_SRCS}"
	INCLUDE_DIRS "${INCLUDE_DIRS}"
	REQUIRES sdmmc fatfs)
