#include "stdint.h"
#include "attributes.h"
#include "gui_resource_types.h"

#define GUI_USE_PICTUREGDATA

//-------------------------------------------------------
// Picture LUT
//-------------------------------------------------------
static const uint16_t hpointer12x12disabled_lut[] GUI_RESOURCE_ATTRIBUTES =
{
    0xDEBA,0xDE99,0xC5F8,0xD617,0xD638
};
//-------------------------------------------------------
// Picture file name: hpointer12x12disabled.bmp, size: 12x12
//-------------------------------------------------------
static const uint8_t data_hpointer12x12disabled[] GUI_RESOURCE_ATTRIBUTES =
{
    0x10,0x01,0x02,0x33,0x02,0x01,0x20,0x01,0x73,0x01,0x00,0x01,0x93,0x01,0x04,0x93,0x04,0xF3,0xF3,0xF3,0x04,0x93,0x04,0x01,
    0x93,0x01,0x00,0x01,0x73,0x01,0x20,0x01,0x53,0x01,0x10
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_hpointer12x12disabled =
{
    hpointer12x12disabled_lut,
    data_hpointer12x12disabled
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_hpointer12x12disabled =
{
    sizeof(hpointer12x12disabled_lut)/sizeof(uint16_t),
    hpointer12x12disabled_lut,
    data_hpointer12x12disabled
};
#endif
#endif
const PictureObject hpointer12x12disabled =
{
    PICTYPE_COMPRESED_L4,
    12,
    12,
    &gdata_hpointer12x12disabled
};