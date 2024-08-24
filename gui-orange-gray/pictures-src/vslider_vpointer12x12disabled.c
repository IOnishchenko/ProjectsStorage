#include "stdint.h"
#include "attributes.h"
#include "gui_resource_types.h"

#define GUI_USE_PICTUREGDATA

//-------------------------------------------------------
// Picture LUT
//-------------------------------------------------------
static const uint16_t vpointer12x12disabled_lut[] GUI_RESOURCE_ATTRIBUTES =
{
    0xDEBA,0xDE99,0xD638,0xD617,0xC5F8
};
//-------------------------------------------------------
// Picture file name: vpointer12x12disabled.bmp, size: 12x12
//-------------------------------------------------------
static const uint8_t data_vpointer12x12disabled[] GUI_RESOURCE_ATTRIBUTES =
{
    0x01,0x00,0x00,0x01,0x00,0x02,0x03,0x03,0x00,0x02,0x00,0x01,0x02,0x00,0x00,0x01,0x07,0x03,0x00,0x01,0x00,0x00,0x00,0x01,
    0x09,0x03,0x00,0x01,0x0A,0x03,0x00,0x04,0x3A,0x03,0x00,0x04,0x00,0x01,0x09,0x03,0x00,0x01,0x00,0x00,0x00,0x01,0x07,0x03,
    0x00,0x01,0x02,0x00,0x00,0x01,0x00,0x02,0x03,0x03,0x00,0x02,0x00,0x01,0x01,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_vpointer12x12disabled =
{
    vpointer12x12disabled_lut,
    data_vpointer12x12disabled
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_vpointer12x12disabled =
{
    sizeof(vpointer12x12disabled_lut)/sizeof(uint16_t),
    vpointer12x12disabled_lut,
    data_vpointer12x12disabled
};
#endif
#endif
const PictureObject vpointer12x12disabled =
{
    PICTYPE_COMPRESED_L8,
    12,
    12,
    &gdata_vpointer12x12disabled
};