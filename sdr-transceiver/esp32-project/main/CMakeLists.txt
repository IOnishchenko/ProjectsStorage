idf_component_register(
	SRCS "main.c" "configuration.c" "interrupts.cpp" "${PROJET_SRCS}"
	INCLUDE_DIRS "${INCLUDE_DIRS}"
	REQUIRES sdmmc fatfs
	PRIV_REQUIRES esp_driver_i2c esp_driver_spi esp_driver_gpio esp_driver_gptimer)
