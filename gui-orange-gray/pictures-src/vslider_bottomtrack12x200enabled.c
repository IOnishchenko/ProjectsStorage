#include "stdint.h"
#include "attributes.h"
#include "gui_resource_types.h"

#define GUI_USE_PICTUREGDATA

//-------------------------------------------------------
// Picture LUT
//-------------------------------------------------------
static const uint16_t bottomtrack12x200enabled_lut[] GUI_RESOURCE_ATTRIBUTES =
{
    0xDEBA,0x037F,0x343E,0xD67A
};
//-------------------------------------------------------
// Picture file name: bottomtrack12x200enabled.bmp, size: 12x200
//-------------------------------------------------------
static const uint8_t data_bottomtrack12x200enabled[] GUI_RESOURCE_ATTRIBUTES =
{
    0xFF,0x00,0xFF,0x00,0x57,0x00,0xC5,0x01,0x00,0x02,0x00,0x03,0xC6,0x01,0x00,0x02,0xFF,0x01,0xFF,0x01,0x56,0x01,0x00,0x02,
    0xC5,0x01,0x00,0x02,0x00,0x03,0xFF,0x00,0xFF,0x00,0x57,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_bottomtrack12x200enabled =
{
    bottomtrack12x200enabled_lut,
    data_bottomtrack12x200enabled
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_bottomtrack12x200enabled =
{
    sizeof(bottomtrack12x200enabled_lut)/sizeof(uint16_t),
    bottomtrack12x200enabled_lut,
    data_bottomtrack12x200enabled
};
#endif
#endif
const PictureObject bottomtrack12x200enabled =
{
    PICTYPE_COMPRESED_L8,
    12,
    200,
    &gdata_bottomtrack12x200enabled
};