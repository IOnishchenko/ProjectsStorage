#include "stdint.h"
#include "attributes.h"
#include "gui_resource_types.h"

#define GUI_USE_PICTUREGDATA

//-------------------------------------------------------
// Picture LUT
//-------------------------------------------------------
static const uint16_t checkbox36x18checked_press_lut[] GUI_RESOURCE_ATTRIBUTES =
{
    0xDEBA,0xDE99,0xD5F7,0xC574,0xC532,0xD637,0xC553,0xCDD6,0xD658,0xD617,0xCDB5,0xD5F6,0xDE58
};
//-------------------------------------------------------
// Picture file name: checkbox36x18checked_press.bmp, size: 36x18
//-------------------------------------------------------
static const uint8_t data_checkbox36x18checked_press[] GUI_RESOURCE_ATTRIBUTES =
{
    0x03,0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x03,0x04,0x00,0x03,0x00,0x02,0x00,0x01,0x06,0x00,0x00,0x05,0x01,0x06,0x00,0x07,
    0x00,0x05,0x01,0x08,0x00,0x05,0x00,0x07,0x01,0x06,0x00,0x05,0x04,0x00,0x00,0x09,0x00,0x04,0x00,0x0A,0x00,0x01,0x05,0x00,
    0x00,0x01,0x00,0x0A,0x00,0x04,0x00,0x09,0x02,0x00,0x00,0x05,0x00,0x04,0x00,0x09,0x09,0x00,0x00,0x09,0x00,0x04,0x00,0x05,
    0x00,0x00,0x00,0x01,0x00,0x06,0x00,0x0A,0x0B,0x00,0x00,0x0A,0x00,0x06,0x00,0x01,0x00,0x02,0x00,0x06,0x00,0x01,0x0B,0x00,
    0x00,0x01,0x00,0x06,0x00,0x02,0x00,0x03,0x00,0x07,0x0D,0x00,0x00,0x07,0x00,0x03,0x00,0x04,0x00,0x05,0x0D,0x00,0x00,0x05,
    0x01,0x04,0x00,0x08,0x0D,0x00,0x00,0x08,0x01,0x04,0x0F,0x00,0x01,0x04,0x0F,0x00,0x01,0x04,0x0F,0x00,0x01,0x04,0x0F,0x00,
    0x01,0x04,0x0F,0x00,0x01,0x04,0x0F,0x00,0x01,0x04,0x0F,0x00,0x01,0x04,0x0F,0x00,0x01,0x04,0x0F,0x00,0x01,0x04,0x0F,0x00,
    0x01,0x04,0x0F,0x00,0x01,0x04,0x06,0x00,0x01,0x01,0x06,0x00,0x01,0x04,0x04,0x00,0x00,0x0B,0x00,0x06,0x01,0x04,0x00,0x06,
    0x00,0x0B,0x04,0x00,0x01,0x04,0x03,0x00,0x00,0x03,0x00,0x06,0x00,0x0B,0x01,0x08,0x00,0x0B,0x00,0x06,0x00,0x03,0x03,0x00,
    0x01,0x04,0x02,0x00,0x00,0x0B,0x00,0x06,0x00,0x0C,0x03,0x00,0x00,0x0C,0x00,0x06,0x00,0x0B,0x02,0x00,0x01,0x04,0x02,0x00,
    0x00,0x06,0x00,0x0B,0x05,0x00,0x00,0x0B,0x00,0x06,0x02,0x00,0x01,0x04,0x02,0x00,0x00,0x04,0x00,0x08,0x05,0x00,0x00,0x08,
    0x00,0x04,0x02,0x00,0x01,0x04,0x02,0x00,0x00,0x04,0x00,0x08,0x05,0x00,0x00,0x08,0x00,0x04,0x01,0x00,0x00,0x01,0x01,0x04,
    0x00,0x08,0x01,0x00,0x00,0x06,0x00,0x0B,0x05,0x00,0x00,0x0B,0x00,0x06,0x01,0x00,0x00,0x08,0x01,0x04,0x00,0x05,0x01,0x00,
    0x00,0x0B,0x00,0x06,0x00,0x0C,0x03,0x00,0x00,0x0C,0x00,0x06,0x00,0x0B,0x01,0x00,0x00,0x05,0x00,0x04,0x00,0x03,0x00,0x07,
    0x02,0x00,0x00,0x03,0x00,0x06,0x00,0x0B,0x01,0x08,0x00,0x0B,0x00,0x06,0x00,0x03,0x02,0x00,0x00,0x07,0x00,0x03,0x00,0x02,
    0x00,0x06,0x00,0x01,0x02,0x00,0x00,0x0B,0x00,0x06,0x01,0x04,0x00,0x06,0x00,0x0B,0x02,0x00,0x00,0x01,0x00,0x06,0x00,0x02,
    0x00,0x01,0x00,0x06,0x00,0x0A,0x0B,0x00,0x00,0x0A,0x00,0x06,0x00,0x01,0x00,0x00,0x00,0x05,0x00,0x04,0x00,0x09,0x09,0x00,
    0x00,0x09,0x00,0x04,0x00,0x05,0x02,0x00,0x00,0x09,0x00,0x04,0x00,0x0A,0x00,0x01,0x05,0x00,0x00,0x01,0x00,0x0A,0x00,0x04,
    0x00,0x09,0x04,0x00,0x00,0x05,0x01,0x06,0x00,0x07,0x00,0x05,0x01,0x08,0x00,0x05,0x00,0x07,0x01,0x06,0x00,0x05,0x06,0x00,
    0x00,0x01,0x00,0x02,0x00,0x03,0x03,0x04,0x00,0x03,0x00,0x02,0x00,0x01,0x03,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_checkbox36x18checked_press =
{
    checkbox36x18checked_press_lut,
    data_checkbox36x18checked_press
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_checkbox36x18checked_press =
{
    sizeof(checkbox36x18checked_press_lut)/sizeof(uint16_t),
    checkbox36x18checked_press_lut,
    data_checkbox36x18checked_press
};
#endif
#endif
const PictureObject checkbox36x18checked_press =
{
    PICTYPE_COMPRESED_L8,
    36,
    18,
    &gdata_checkbox36x18checked_press
};