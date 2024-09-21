#include "stdint.h"
#include "attributes.h"
#include "gui_resource_types.h"

#define GUI_USE_PICTUREGDATA

//-------------------------------------------------------
// Picture LUT
//-------------------------------------------------------
static const uint16_t button64x24enabled_lut[] GUI_RESOURCE_ATTRIBUTES =
{
    0xDEBA,0xDE99,0xDE9A,0xDE79,0xCDB5,0xCD94,0xC532,0xD617,0xC553
};
//-------------------------------------------------------
// Picture file name: button64x24enabled.bmp, size: 64x24
//-------------------------------------------------------
static const uint8_t data_button64x24enabled[] GUI_RESOURCE_ATTRIBUTES =
{
    0x20,0x01,0x02,0xD0,0x02,0x01,0x40,0x02,0x03,0x04,0x05,0xB6,0x05,0x04,0x03,0x02,0x20,0x02,0x07,0xF6,0x06,0x08,0x07,0x02,
    0x00,0x01,0x03,0x08,0xF6,0x16,0x08,0x03,0x01,0x02,0x04,0xF6,0x36,0x04,0x02,0x00,0x05,0xF6,0x36,0x05,0x10,0xF6,0x56,0x10,
    0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,
    0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,
    0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,
    0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,
    0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,
    0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,
    0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x46,0x08,0x10,0x05,0xF6,0x36,0x05,0x00,0x02,0x04,0xF6,0x36,0x04,0x02,0x01,0x03,0x08,
    0xF6,0x16,0x08,0x03,0x01,0x00,0x02,0x07,0x08,0xF6,0x08,0x07,0x02,0x20,0x02,0x03,0x04,0x05,0x08,0xA6,0x05,0x04,0x03,0x02,
    0x40,0x01,0x02,0xD0,0x02,0x01,0x20
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_button64x24enabled =
{
    button64x24enabled_lut,
    data_button64x24enabled
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_button64x24enabled =
{
    sizeof(button64x24enabled_lut)/sizeof(uint16_t),
    button64x24enabled_lut,
    data_button64x24enabled
};
#endif
#endif
const PictureObject button64x24enabled =
{
    PICTYPE_COMPRESSED_L4,
    64,
    24,
    &gdata_button64x24enabled
};