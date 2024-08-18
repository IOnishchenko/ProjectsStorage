#include "stdint.h"
#include "attributes.h"
#include "gui_resource_types.h"

#define GUI_USE_PICTUREGDATA

//-------------------------------------------------------
// Picture LUT
//-------------------------------------------------------
static const uint16_t button64x24normal_lut[] GUI_RESOURCE_ATTRIBUTES =
{
    0xDEBA,0xDE99,0xDE9A,0xDE79,0xCDB5,0xCD94,0xC532,0xD617,0xC553
};
//-------------------------------------------------------
// Picture file name: button64x24normal.bmp, size: 64x24
//-------------------------------------------------------
static const uint8_t data_button64x24normal[] GUI_RESOURCE_ATTRIBUTES =
{
    0x00,0x10,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x01,0x00,0x00,0x32,0x54,0x66,0x66,0x66,0x66,0x66,0x66,0x45,0x23,0x00,
    0x20,0x67,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x78,0x02,0x31,0x68,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x86,0x13,
    0x42,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x24,0x50,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x05,
    0x60,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x06,0x60,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x06,
    0x60,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x06,0x60,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x06,
    0x60,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x06,0x60,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x06,
    0x60,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x06,0x60,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x06,
    0x60,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x06,0x60,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x06,
    0x60,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x06,0x60,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x06,
    0x60,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x06,0x60,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x06,
    0x60,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x06,0x60,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x06,
    0x60,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x06,0x60,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x06,
    0x60,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x06,0x60,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x06,
    0x60,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x06,0x60,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x06,
    0x60,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x06,0x60,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x06,
    0x60,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x06,0x60,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x06,
    0x60,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x06,0x60,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x06,
    0x60,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x06,0x60,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x06,
    0x60,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x06,0x60,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x06,
    0x60,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x06,0x60,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x06,
    0x60,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x06,0x60,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x06,
    0x60,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x06,0x60,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x06,
    0x60,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x06,0x60,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x06,
    0x60,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x06,0x60,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x06,
    0x60,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x06,0x60,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x06,
    0x60,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x06,0x60,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x06,
    0x60,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x06,0x60,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x06,
    0x60,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x06,0x60,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x06,
    0x60,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x06,0x60,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x08,
    0x50,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x05,0x42,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x24,
    0x31,0x68,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x86,0x13,0x20,0x87,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x78,0x02,
    0x00,0x32,0x54,0x68,0x66,0x66,0x66,0x66,0x66,0x45,0x23,0x00,0x00,0x10,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x01,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_button64x24normal =
{
    button64x24normal_lut,
    data_button64x24normal
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_button64x24normal =
{
    sizeof(button64x24normal_lut)/sizeof(uint16_t),
    button64x24normal_lut,
    data_button64x24normal
};
#endif
#endif
const PictureObject button64x24normal =
{
    PICTYPE_L4,
    64,
    24,
    &gdata_button64x24normal
};