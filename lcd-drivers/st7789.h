#ifndef ST7789_H
#define ST7789_H
#ifdef __cplusplus
extern "C" {
#endif

/*
 Max SPI speed is 15 MHz. see the Datasheet
*/
/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
#define ST7789_SLEEP_IN_CMD			0x10u
#define ST7789_SLEEP_OUT_CMD		0x11u

#define ST7789_DISPLAY_OFF_CMD		0x28u
#define ST7789_DISPLAY_ON_CMD		0x29u

#define ST7789_COLUMN_ADDRESS_CMD	0x2au // has 4 parameter bytes
#define ST7789_ROW_ADDRESS_CMD		0x2bu // has 4 parameter bytes

#define ST7789_START_WRITE_MEMORY_CMD		0x2cu // gdata after this command
#define ST7789_START_READ_MEMORY_CMD		0x2eu

#define ST7789_MEMORY_ACCESS_CMD			0x36u // has 1 parameter byte

#define ST7789_INTERFACE_PIXEL_FORMAT_CMD	0x3au // has 1 parameter byte

#define ST7789_CONTINUE_WRITE_MEMORY_CMD	0x3cu
#define ST7789_CONTINUE_READ_MEMORY_CMD		0x3eu


/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
#ifdef __cplusplus
}
#endif
#endif // ST7789_H