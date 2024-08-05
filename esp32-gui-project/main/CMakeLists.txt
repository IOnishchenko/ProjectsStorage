idf_component_register(
	SRCS "configuration.c" "main.c" "${PROJET_SRCS}"
	INCLUDE_DIRS "${INCLUDE_DIRS}"
	REQUIRES sdmmc fatfs
	PRIV_REQUIRES esp_driver_i2c esp_driver_spi)
