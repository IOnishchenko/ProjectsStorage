#include "stdint.h"
#include "attributes.h"
#include "gui_resource_types.h"

#define GUI_USE_PICTUREGDATA

//-------------------------------------------------------
// Picture LUT
//-------------------------------------------------------
static const uint16_t toptrack12x200enabled_lut[] GUI_RESOURCE_ATTRIBUTES =
{
    0xDEBA,0xDE99,0xCD94,0xC532,0xDE79
};
//-------------------------------------------------------
// Picture file name: toptrack12x200enabled.bmp, size: 12x200
//-------------------------------------------------------
static const uint8_t data_toptrack12x200enabled[] GUI_RESOURCE_ATTRIBUTES =
{
    0xFF,0x00,0xFF,0x00,0x57,0x00,0x00,0x01,0x00,0x02,0xC5,0x03,0x00,0x02,0xFF,0x03,0xFF,0x03,0x56,0x03,0x00,0x02,0xC6,0x03,
    0x00,0x01,0x00,0x02,0xC5,0x03,0x01,0x00,0x00,0x04,0xFF,0x00,0xFF,0x00,0x54,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_toptrack12x200enabled =
{
    toptrack12x200enabled_lut,
    data_toptrack12x200enabled
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_toptrack12x200enabled =
{
    sizeof(toptrack12x200enabled_lut)/sizeof(uint16_t),
    toptrack12x200enabled_lut,
    data_toptrack12x200enabled
};
#endif
#endif
const PictureObject toptrack12x200enabled =
{
    PICTYPE_COMPRESSED_L8,
    12,
    200,
    &gdata_toptrack12x200enabled
};