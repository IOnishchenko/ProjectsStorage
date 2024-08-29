#include "stdint.h"
#include "attributes.h"
#include "gui_resource_types.h"

#define GUI_USE_PICTUREGDATA

//-------------------------------------------------------
// Picture LUT
//-------------------------------------------------------
static const uint16_t tab64x24pressed_lut[] GUI_RESOURCE_ATTRIBUTES =
{
    0xDEBA,0xDE99,0xD617,0xC532,0xB48E,0xABCB,0xCD94,0xABEC
};
//-------------------------------------------------------
// Picture file name: tab64x24pressed.bmp, size: 64x24
//-------------------------------------------------------
static const uint8_t data_tab64x24pressed[] GUI_RESOURCE_ATTRIBUTES =
{
    0x60,0x11,0xF0,0x30,0x01,0x00,0x02,0x03,0x14,0xB5,0x40,0x01,0x02,0x04,0xF5,0x40,0x06,0xF5,0x15,0x20,0x01,0x06,0xF5,0x25,
    0x10,0x01,0x02,0x07,0xF5,0x25,0x20,0x04,0xF5,0x35,0x00,0x01,0x02,0xF5,0x45,0x00,0x01,0x03,0xF5,0x45,0x10,0x04,0xF5,0x45,
    0x10,0x04,0xF5,0x45,0x10,0xF5,0x55,0x10,0xF5,0x55,0x10,0xF5,0x55,0x10,0xF5,0x55,0x10,0xF5,0x55,0x10,0xF5,0x55,0x10,0xF5,
    0x55,0x10,0xF5,0x55,0x10,0xF5,0x55,0x10,0xF5,0x55,0x10,0xF5,0x55,0x10,0xF5,0x55,0x10,0xF5,0x55,0x10,0xF5,0x55,0x10,0xF5,
    0x55,0x10,0xF5,0x55,0x10,0xF5,0x55,0x10,0xF5,0x55,0x10,0xF5,0x55,0x10,0xF5,0x55,0x10,0xF5,0x55,0x10,0xF5,0x55,0x10,0xF5,
    0x55,0x10,0xF5,0x55,0x10,0xF5,0x55,0x10,0xF5,0x55,0x10,0xF5,0x55,0x10,0xF5,0x55,0x10,0xF5,0x55,0x10,0xF5,0x55,0x10,0xF5,
    0x55,0x10,0xF5,0x55,0x10,0xF5,0x55,0x10,0xF5,0x55,0x10,0xF5,0x55,0x10,0xF5,0x55,0x10,0xF5,0x55,0x10,0xF5,0x55,0x10,0xF5,
    0x55,0x10,0xF5,0x55,0x10,0xF5,0x55,0x10,0xF5,0x55,0x10,0x04,0xF5,0x45,0x10,0x04,0xF5,0x45,0x00,0x01,0x03,0xF5,0x45,0x00,
    0x01,0x02,0xF5,0x45,0x20,0x04,0xF5,0x35,0x10,0x01,0x02,0x07,0xF5,0x25,0x20,0x01,0x06,0xF5,0x25,0x40,0x06,0xF5,0x15,0x40,
    0x01,0x02,0x04,0xF5,0x50,0x01,0x00,0x02,0x03,0x14,0x07,0xA5,0x70,0x11,0xE0
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_tab64x24pressed =
{
    tab64x24pressed_lut,
    data_tab64x24pressed
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_tab64x24pressed =
{
    sizeof(tab64x24pressed_lut)/sizeof(uint16_t),
    tab64x24pressed_lut,
    data_tab64x24pressed
};
#endif
#endif
const PictureObject tab64x24pressed =
{
    PICTYPE_COMPRESED_L4,
    64,
    24,
    &gdata_tab64x24pressed
};