#include "stdint.h"
#include "attributes.h"
#include "gui_resource_types.h"

#define GUI_USE_PICTUREGDATA

//-------------------------------------------------------
// Picture LUT
//-------------------------------------------------------
static const uint16_t tab64x24enabled_lut[] GUI_RESOURCE_ATTRIBUTES =
{
    0xDEBA,0xDE9A,0xDE99,0xDE58,0xD5F6,0xCD94,0xC532,0xD617,0xC553
};
//-------------------------------------------------------
// Picture file name: tab64x24enabled.bmp, size: 64x24
//-------------------------------------------------------
static const uint8_t data_tab64x24enabled[] GUI_RESOURCE_ATTRIBUTES =
{
    0x60,0x01,0x02,0xF0,0x30,0x01,0x00,0x03,0x04,0x15,0xB6,0x40,0x01,0x03,0x05,0xF6,0x40,0x07,0xF6,0x16,0x20,0x01,0x07,0xF6,
    0x26,0x10,0x01,0x03,0x08,0xF6,0x26,0x20,0x05,0xF6,0x36,0x00,0x01,0x03,0xF6,0x46,0x00,0x02,0x04,0xF6,0x46,0x10,0x05,0xF6,
    0x46,0x10,0x05,0xF6,0x46,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,
    0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,
    0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,
    0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,
    0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,
    0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,0xF6,0x56,0x10,0x05,0xF6,0x46,0x10,0x05,0xF6,0x46,0x00,0x02,0x04,0xF6,0x46,
    0x00,0x01,0x03,0xF6,0x46,0x20,0x05,0xF6,0x36,0x10,0x01,0x03,0x08,0xF6,0x26,0x20,0x01,0x07,0xF6,0x26,0x40,0x07,0xF6,0x16,
    0x40,0x01,0x03,0x05,0xF6,0x50,0x01,0x00,0x03,0x04,0x15,0x08,0xA6,0x70,0x01,0x02,0xE0
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_tab64x24enabled =
{
    tab64x24enabled_lut,
    data_tab64x24enabled
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_tab64x24enabled =
{
    sizeof(tab64x24enabled_lut)/sizeof(uint16_t),
    tab64x24enabled_lut,
    data_tab64x24enabled
};
#endif
#endif
const PictureObject tab64x24enabled =
{
    PICTYPE_COMPRESED_L4,
    64,
    24,
    &gdata_tab64x24enabled
};