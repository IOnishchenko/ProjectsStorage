#ifndef SSD1306_H
#define SSD1306_H
#ifdef __cplusplus
extern "C" {
#endif
/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
#define SSD1306_I2C_ADDRESS			0x3c
//#define SSD1306_I2C_ADDRESS		0x3d
#define SSD1306_I2C_ADDR_TO_READ	((SSD1306_I2C_ADDRESS << 1) | 1)
#define SSD1306_I2C_ADDR_TO_WRITE	((SSD1306_I2C_ADDRESS << 1) | 0)

#define SSD1306_I2C_LAST_CMD_BYTE	(0 << 6)
#define SSD1306_I2C_CMD_BYTE		((1 << 7) | SSD1306_I2C_LAST_CMD_BYTE)

#define SSD1306_I2C_LAST_GDATA_BYTE	(1 << 6)
#define SSD1306_I2C_GDATA_BYTE		((1 << 7) | SSD1306_I2C_LAST_GDATA_BYTE)

#define SSD1306_GDATA_BUFFER_SIZE	128

// Fundamental Command Table
#define SSD1306_SET_CONTRAST_CMD	0x81
#define SSD1306_SET_CONTRAST_VAL	0x7f	// 0 - 255

#define SSD1306_DISPLAY_RAM_ON_CMD	0xa4 
#define SSD1306_DISPLAY_RAM_OFF_CMD	0xa5

#define SSD1306_SET_NORM_DISPLAY_CMD	0xa6
#define SSD1306_SET_INVERS_DISPLAY_CMD	0xa7

#define SSD1306_SET_DISPLAY_OFF_CMD	0xae
#define SSD1306_SET_DISPLAY_ON_CMD	0xaf

// Scrolling Command Table
// ---/--/--/---

// Addressing Setting Command Table
#define SSD1306_MEM_ADDR_MODE_CMD	0x20
#define SSD1306_MEM_ADDR_MODE_VAL	0x01	// Vertical addressing mode

#define SSD1306_COLUMN_ADDR_CMD		0x21
#define SSD1306_COLUMN_ADDR_VAL0	0		// Start column  
#define SSD1306_COLUMN_ADDR_VAL1	127		// end column

#define SSD1306_PAGE_ADDR_CMD		0x22
#define SSD1306_PAGE_ADDR_VAL0		0		// Start page  
#define SSD1306_PAGE_ADDR_VAL1		7		// end page

// Hardware Configuration
#define SSD1306_SET_SEG_REMAP_CMD	0xa0	// column address 0 to seg0
//#define SSD1306_SET_SEG_REMAP_CMD	0xa1	// column address 0 to seg127

#define SSD1306_SET_MUX_RATIO_CMD	0xa8
#define SSD1306_SET_MUX_RATIO_VAL	63

#define SSD1306_SET_SCAN_DIR_CMD	0xc0	// normal mode (RESET) Scan from COM0 to COM[N –1]. Where N is the Multiplex ratio.
//#define SSD1306_SET_SCAN_DIR_CMD	0xc8	// remapped mode. Scan from COM[N-1] to COM0. Where N is the Multiplex ratio.

#define SSD1306_SET_OFFSET_CMD		0xd3	// Set vertical shift by COM from 0d~63d
#define SSD1306_SET_OFFSET_VAL		0

#define SSD1306_SET_CON_PINS_CMD	0xda
#define SSD1306_SET_CON_PINS_VAL	0x12	// default value
/* SSD1306_SET_CON_PINS_VAL 
A[4]=0b, Sequential COM pin configuration
A[4]=1b(RESET), Alternative COM pin
configuration
A[5]=0b(RESET), Disable COM Left/Right
remap
A[5]=1b, Enable COM Left/Right remap
*/

#define SSD1306_SET_CLOCK_CMD		0xd5
#define SSD1306_SET_CLOCK_VAL		((0) | (0x08 << 4)) // default value
/* SSD1306_SET_CLOCK_VAL
A[3:0] : Define the divide ratio (D) of the
display clocks (DCLK):
Divide ratio= A[3:0] + 1, RESET is
0000b (divide ratio = 1)
A[7:4] : Set the Oscillator Frequency, FOSC.
Oscillator Frequency increases with
the value of A[7:4] and vice versa.
RESET is 1000b
Range:0000b~1111b
*/

// Charge Pump Command Table
#define SSD1306_CHARGE_PUMP_CMD	0x8d
#define SSD1306_CHARGE_PUMP_VAL	0x14

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
#ifdef __cplusplus
}
#endif
#endif // SSD1306_H