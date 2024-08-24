#include "stdint.h"
#include "attributes.h"
#include "gui_resource_types.h"

#define GUI_USE_PICTUREGDATA

//-------------------------------------------------------
// Picture LUT
//-------------------------------------------------------
static const uint16_t hpointer12x12selected_lut[] GUI_RESOURCE_ATTRIBUTES =
{
    0xDEBA,0xC63A,0x341E,0x037F,0xB61B,0x4C7D,0x445D
};
//-------------------------------------------------------
// Picture file name: hpointer12x12selected.bmp, size: 12x12
//-------------------------------------------------------
static const uint8_t data_hpointer12x12selected[] GUI_RESOURCE_ATTRIBUTES =
{
    0x10,0x01,0x02,0x33,0x02,0x01,0x20,0x04,0x73,0x04,0x00,0x01,0x93,0x01,0x05,0x93,0x05,0xF3,0xF3,0xF3,0x05,0x93,0x05,0x01,
    0x93,0x01,0x00,0x04,0x73,0x04,0x20,0x01,0x06,0x33,0x06,0x01,0x10
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_hpointer12x12selected =
{
    hpointer12x12selected_lut,
    data_hpointer12x12selected
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_hpointer12x12selected =
{
    sizeof(hpointer12x12selected_lut)/sizeof(uint16_t),
    hpointer12x12selected_lut,
    data_hpointer12x12selected
};
#endif
#endif
const PictureObject hpointer12x12selected =
{
    PICTYPE_COMPRESED_L4,
    12,
    12,
    &gdata_hpointer12x12selected
};