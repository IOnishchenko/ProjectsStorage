#include "stdint.h"
#include "attributes.h"
#include "gui_resource_types.h"

#define GUI_USE_PICTUREGDATA

//-------------------------------------------------------
// Picture LUT
//-------------------------------------------------------
static const uint16_t button64x24focused_lut[] GUI_RESOURCE_ATTRIBUTES =
{
    0xDEBA,0xC63A,0x549D,0x0B9F,0x037F,0xB61B,0x1B9E,0x7C97,0x94B6,0xC532,0x4C1A,0xB513
};
//-------------------------------------------------------
// Picture file name: button64x24focused.bmp, size: 64x24
//-------------------------------------------------------
static const uint8_t data_button64x24focused[] GUI_RESOURCE_ATTRIBUTES =
{
    0x10,0x01,0x02,0x03,0xD4,0x03,0x02,0x01,0x20,0x05,0x03,0x06,0x07,0x08,0xB9,0x08,0x07,0x06,0x03,0x05,0x00,0x01,0x03,0x0A,
    0xF9,0x09,0x0B,0x0A,0x03,0x01,0x02,0x06,0x0B,0xF9,0x19,0x0B,0x06,0x02,0x03,0x07,0xF9,0x39,0x07,0x03,0x04,0x08,0xF9,0x39,
    0x08,0x14,0xF9,0x59,0x14,0xF9,0x59,0x14,0xF9,0x59,0x14,0xF9,0x59,0x14,0xF9,0x59,0x14,0xF9,0x59,0x14,0xF9,0x59,0x14,0xF9,
    0x59,0x14,0xF9,0x59,0x14,0xF9,0x59,0x14,0xF9,0x59,0x14,0xF9,0x59,0x14,0xF9,0x59,0x14,0xF9,0x59,0x14,0xF9,0x59,0x14,0xF9,
    0x59,0x14,0xF9,0x59,0x14,0xF9,0x59,0x14,0xF9,0x59,0x14,0xF9,0x59,0x14,0xF9,0x59,0x14,0xF9,0x59,0x14,0xF9,0x59,0x14,0xF9,
    0x59,0x14,0xF9,0x59,0x14,0xF9,0x59,0x14,0xF9,0x59,0x14,0xF9,0x59,0x14,0xF9,0x59,0x14,0xF9,0x59,0x14,0xF9,0x59,0x14,0xF9,
    0x59,0x14,0xF9,0x59,0x14,0xF9,0x59,0x14,0xF9,0x59,0x14,0xF9,0x59,0x14,0xF9,0x59,0x14,0xF9,0x59,0x14,0xF9,0x59,0x14,0xF9,
    0x59,0x14,0xF9,0x59,0x14,0xF9,0x59,0x14,0xF9,0x59,0x14,0xF9,0x59,0x14,0xF9,0x59,0x14,0xF9,0x59,0x14,0xF9,0x59,0x14,0xF9,
    0x59,0x14,0xF9,0x59,0x14,0xF9,0x59,0x14,0xF9,0x59,0x14,0xF9,0x49,0x0B,0x14,0x08,0xF9,0x39,0x08,0x04,0x03,0x07,0xF9,0x39,
    0x07,0x03,0x02,0x06,0x0B,0xF9,0x19,0x0B,0x06,0x02,0x01,0x03,0x0A,0x0B,0xF9,0x0B,0x0A,0x03,0x01,0x00,0x05,0x03,0x06,0x07,
    0x08,0x0B,0xA9,0x08,0x07,0x06,0x03,0x05,0x20,0x01,0x02,0x03,0xD4,0x03,0x02,0x01,0x10
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_button64x24focused =
{
    button64x24focused_lut,
    data_button64x24focused
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_button64x24focused =
{
    sizeof(button64x24focused_lut)/sizeof(uint16_t),
    button64x24focused_lut,
    data_button64x24focused
};
#endif
#endif
const PictureObject button64x24focused =
{
    PICTYPE_COMPRESSED_L4,
    64,
    24,
    &gdata_button64x24focused
};