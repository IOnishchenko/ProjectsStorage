#include "stdint.h"
#include "attributes.h"
#include "gui_resource_types.h"

#define GUI_USE_PICTUREGDATA

//-------------------------------------------------------
// Picture LUT
//-------------------------------------------------------
static const uint16_t checkbox36x18checked_dis_lut[] GUI_RESOURCE_ATTRIBUTES =
{
    0xDEBA,0xDE99,0xDE9A,0xD637,0xD5D6,0xCDD5,0xD638,0xCD94,0xD5F6,0x9D16,0x7CB8,0x84D8
};
//-------------------------------------------------------
// Picture file name: checkbox36x18checked_dis.bmp, size: 36x18
//-------------------------------------------------------
static const uint8_t data_checkbox36x18checked_dis[] GUI_RESOURCE_ATTRIBUTES =
{
    0x05,0x00,0x00,0x01,0x03,0x00,0x00,0x01,0x09,0x00,0x01,0x02,0x00,0x03,0x00,0x04,0x01,0x05,0x00,0x04,0x00,0x03,0x01,0x02,
    0x05,0x00,0x00,0x02,0x00,0x00,0x00,0x06,0x07,0x07,0x00,0x06,0x00,0x00,0x00,0x02,0x04,0x00,0x00,0x08,0x09,0x07,0x00,0x08,
    0x03,0x00,0x00,0x02,0x00,0x06,0x0B,0x07,0x00,0x06,0x00,0x02,0x01,0x00,0x00,0x02,0x0D,0x07,0x00,0x02,0x00,0x00,0x00,0x01,
    0x00,0x03,0x0D,0x07,0x00,0x03,0x00,0x01,0x00,0x00,0x00,0x04,0x0D,0x07,0x00,0x04,0x01,0x00,0x00,0x05,0x0D,0x07,0x00,0x05,
    0x01,0x00,0x0F,0x07,0x01,0x00,0x0F,0x07,0x01,0x00,0x0F,0x07,0x01,0x00,0x0F,0x07,0x01,0x00,0x0F,0x07,0x01,0x00,0x0F,0x07,
    0x01,0x00,0x0F,0x07,0x01,0x00,0x0F,0x07,0x01,0x00,0x0F,0x07,0x01,0x00,0x0F,0x07,0x01,0x00,0x0F,0x07,0x01,0x00,0x0F,0x07,
    0x01,0x00,0x04,0x07,0x00,0x09,0x03,0x0A,0x00,0x09,0x04,0x07,0x01,0x00,0x03,0x07,0x00,0x0B,0x05,0x0A,0x00,0x0B,0x03,0x07,
    0x01,0x00,0x02,0x07,0x00,0x09,0x07,0x0A,0x00,0x09,0x02,0x07,0x01,0x00,0x02,0x07,0x09,0x0A,0x02,0x07,0x01,0x00,0x02,0x07,
    0x09,0x0A,0x02,0x07,0x01,0x00,0x02,0x07,0x09,0x0A,0x02,0x07,0x01,0x00,0x00,0x05,0x01,0x07,0x09,0x0A,0x01,0x07,0x00,0x05,
    0x01,0x00,0x00,0x04,0x01,0x07,0x00,0x09,0x07,0x0A,0x00,0x09,0x01,0x07,0x00,0x04,0x00,0x00,0x00,0x01,0x00,0x03,0x02,0x07,
    0x00,0x0B,0x05,0x0A,0x00,0x0B,0x02,0x07,0x00,0x03,0x00,0x01,0x00,0x00,0x00,0x02,0x03,0x07,0x00,0x09,0x03,0x0A,0x00,0x09,
    0x03,0x07,0x00,0x02,0x01,0x00,0x00,0x02,0x00,0x06,0x0B,0x07,0x00,0x06,0x00,0x02,0x03,0x00,0x00,0x08,0x09,0x07,0x00,0x08,
    0x04,0x00,0x00,0x02,0x00,0x00,0x00,0x06,0x07,0x07,0x00,0x06,0x00,0x00,0x00,0x02,0x05,0x00,0x01,0x02,0x00,0x03,0x00,0x04,
    0x01,0x05,0x00,0x04,0x00,0x03,0x01,0x02,0x09,0x00,0x00,0x01,0x03,0x00,0x00,0x01,0x05,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_checkbox36x18checked_dis =
{
    checkbox36x18checked_dis_lut,
    data_checkbox36x18checked_dis
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_checkbox36x18checked_dis =
{
    sizeof(checkbox36x18checked_dis_lut)/sizeof(uint16_t),
    checkbox36x18checked_dis_lut,
    data_checkbox36x18checked_dis
};
#endif
#endif
const PictureObject checkbox36x18checked_dis =
{
    PICTYPE_COMPRESED_L8,
    36,
    18,
    &gdata_checkbox36x18checked_dis
};