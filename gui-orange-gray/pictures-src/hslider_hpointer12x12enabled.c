#include "stdint.h"
#include "attributes.h"
#include "gui_resource_types.h"

#define GUI_USE_PICTUREGDATA

//-------------------------------------------------------
// Picture LUT
//-------------------------------------------------------
static const uint16_t hpointer12x12enabled_lut[] GUI_RESOURCE_ATTRIBUTES =
{
    0xDEBA,0xDE79,0xB555,0xC533,0xC532,0xDE58,0xCDB5,0xCD74
};
//-------------------------------------------------------
// Picture file name: hpointer12x12enabled.bmp, size: 12x12
//-------------------------------------------------------
static const uint8_t data_hpointer12x12enabled[] GUI_RESOURCE_ATTRIBUTES =
{
    0x10,0x01,0x02,0x03,0x14,0x03,0x02,0x01,0x20,0x05,0x03,0x54,0x03,0x05,0x00,0x01,0x03,0x74,0x03,0x01,0x06,0x94,0x06,0x03,
    0x94,0x03,0xF4,0x74,0x03,0x94,0x03,0x06,0x94,0x06,0x01,0x03,0x74,0x03,0x01,0x00,0x05,0x03,0x54,0x03,0x05,0x20,0x01,0x07,
    0x03,0x14,0x03,0x07,0x01,0x10
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_hpointer12x12enabled =
{
    hpointer12x12enabled_lut,
    data_hpointer12x12enabled
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_hpointer12x12enabled =
{
    sizeof(hpointer12x12enabled_lut)/sizeof(uint16_t),
    hpointer12x12enabled_lut,
    data_hpointer12x12enabled
};
#endif
#endif
const PictureObject hpointer12x12enabled =
{
    PICTYPE_COMPRESSED_L4,
    12,
    12,
    &gdata_hpointer12x12enabled
};