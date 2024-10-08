#include "stdint.h"
#include "attributes.h"
#include "gui_resource_types.h"

#define GUI_USE_PICTUREGDATA

//-------------------------------------------------------
// Picture LUT
//-------------------------------------------------------
static const uint16_t bottomtrack12x200disabled_lut[] GUI_RESOURCE_ATTRIBUTES =
{
    0xDEBA,0x855C,0x9DBB,0xDE9A
};
//-------------------------------------------------------
// Picture file name: bottomtrack12x200disabled.bmp, size: 12x200
//-------------------------------------------------------
static const uint8_t data_bottomtrack12x200disabled[] GUI_RESOURCE_ATTRIBUTES =
{
    0xFF,0x00,0xFF,0x00,0x57,0x00,0xC5,0x01,0x00,0x02,0x00,0x03,0xC6,0x01,0x00,0x02,0xFF,0x01,0xFF,0x01,0x56,0x01,0x00,0x02,
    0xC5,0x01,0x00,0x02,0x00,0x03,0xFF,0x00,0xFF,0x00,0x57,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_bottomtrack12x200disabled =
{
    bottomtrack12x200disabled_lut,
    data_bottomtrack12x200disabled
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_bottomtrack12x200disabled =
{
    sizeof(bottomtrack12x200disabled_lut)/sizeof(uint16_t),
    bottomtrack12x200disabled_lut,
    data_bottomtrack12x200disabled
};
#endif
#endif
const PictureObject bottomtrack12x200disabled =
{
    PICTYPE_COMPRESSED_L8,
    12,
    200,
    &gdata_bottomtrack12x200disabled
};