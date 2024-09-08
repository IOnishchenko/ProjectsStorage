#include "stdint.h"
#include "attributes.h"
#include "gui_resource_types.h"

#define GUI_USE_PICTUREGDATA

//-------------------------------------------------------
// Picture LUT
//-------------------------------------------------------
static const uint16_t background150x18_lut[] GUI_RESOURCE_ATTRIBUTES =
{
    0xDEBA
};
//-------------------------------------------------------
// Picture file name: background150x18.bmp, size: 150x18
//-------------------------------------------------------
static const uint8_t data_background150x18[] GUI_RESOURCE_ATTRIBUTES =
{
    0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0x8B,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_background150x18 =
{
    background150x18_lut,
    data_background150x18
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_background150x18 =
{
    sizeof(background150x18_lut)/sizeof(uint16_t),
    background150x18_lut,
    data_background150x18
};
#endif
#endif
const PictureObject background150x18 =
{
    PICTYPE_COMPRESED_L8,
    150,
    18,
    &gdata_background150x18
};