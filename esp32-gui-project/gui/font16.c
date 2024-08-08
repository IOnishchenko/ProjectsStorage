
#include "stdint.h"
#include "attributes.h"
#include "gui_resource_types.h"

#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
//-------------------------------------------------------
// Contains alpha values
//-------------------------------------------------------
const uint8_t font16_lut[] GUI_RESOURCE_ATTRIBUTES =
{
    0x0000,0x0001
};
#endif
//-------------------------------------------------------
// Character: " "/0x20, Width: 8, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x20[] GUI_RESOURCE_ATTRIBUTES =
{
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x20 =
{
    font16_lut,
    data_FontSize16_0x20
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x20 =
{
    2,
    font16_lut,
    data_FontSize16_0x20
};
#endif
#endif
static const PictureObject FontSize16_0x20 =
{
    PICTYPE_BITS,
    8,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x20
#else
    data_FontSize16_0x20
#endif
};
//-------------------------------------------------------
// Character: "!"/0x21, Width: 4, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x21[] GUI_RESOURCE_ATTRIBUTES =
{
    0xFE,0x1B,0xFE,0x1B,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x21 =
{
    font16_lut,
    data_FontSize16_0x21
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x21 =
{
    2,
    font16_lut,
    data_FontSize16_0x21
};
#endif
#endif
static const PictureObject FontSize16_0x21 =
{
    PICTYPE_BITS,
    4,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x21
#else
    data_FontSize16_0x21
#endif
};
//-------------------------------------------------------
// Character: """/0x22, Width: 7, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x22[] GUI_RESOURCE_ATTRIBUTES =
{
    0x1F,0x00,0x1F,0x00,0x00,0x00,0x1F,0x00,0x1F,0x00,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x22 =
{
    font16_lut,
    data_FontSize16_0x22
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x22 =
{
    2,
    font16_lut,
    data_FontSize16_0x22
};
#endif
#endif
static const PictureObject FontSize16_0x22 =
{
    PICTYPE_BITS,
    7,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x22
#else
    data_FontSize16_0x22
#endif
};
//-------------------------------------------------------
// Character: "#"/0x23, Width: 13, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x23[] GUI_RESOURCE_ATTRIBUTES =
{
    0x00,0x03,0x30,0x1B,0xB0,0x07,0x78,0x03,0x36,0x03,0x30,0x03,0x30,0x1B,0xB0,0x07,
    0x78,0x03,0x36,0x03,0x30,0x00,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x23 =
{
    font16_lut,
    data_FontSize16_0x23
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x23 =
{
    2,
    font16_lut,
    data_FontSize16_0x23
};
#endif
#endif
static const PictureObject FontSize16_0x23 =
{
    PICTYPE_BITS,
    13,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x23
#else
    data_FontSize16_0x23
#endif
};
//-------------------------------------------------------
// Character: "$"/0x24, Width: 11, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x24[] GUI_RESOURCE_ATTRIBUTES =
{
    0x70,0x0C,0xF8,0x1C,0x8C,0x10,0x84,0x10,0xFF,0x7F,0x84,0x10,0x84,0x18,0x9C,0x0F,
    0x18,0x07,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x24 =
{
    font16_lut,
    data_FontSize16_0x24
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x24 =
{
    2,
    font16_lut,
    data_FontSize16_0x24
};
#endif
#endif
static const PictureObject FontSize16_0x24 =
{
    PICTYPE_BITS,
    11,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x24
#else
    data_FontSize16_0x24
#endif
};
//-------------------------------------------------------
// Character: "%"/0x25, Width: 20, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x25[] GUI_RESOURCE_ATTRIBUTES =
{
    0x7C,0x00,0xFE,0x00,0x82,0x00,0x82,0x00,0x82,0x00,0xFE,0x00,0x7C,0x18,0x00,0x06,
    0x80,0x01,0x60,0x00,0x18,0x00,0x86,0x0F,0xC0,0x1F,0x40,0x10,0x40,0x10,0x40,0x10,
    0xC0,0x1F,0x80,0x0F,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x25 =
{
    font16_lut,
    data_FontSize16_0x25
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x25 =
{
    2,
    font16_lut,
    data_FontSize16_0x25
};
#endif
#endif
static const PictureObject FontSize16_0x25 =
{
    PICTYPE_BITS,
    20,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x25
#else
    data_FontSize16_0x25
#endif
};
//-------------------------------------------------------
// Character: "&"/0x26, Width: 14, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x26[] GUI_RESOURCE_ATTRIBUTES =
{
    0x00,0x07,0x9C,0x0F,0xFE,0x18,0x62,0x10,0x42,0x10,0xE2,0x10,0xBE,0x11,0x1C,0x0B,
    0x00,0x06,0xE0,0x0F,0xE0,0x18,0x00,0x10,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x26 =
{
    font16_lut,
    data_FontSize16_0x26
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x26 =
{
    2,
    font16_lut,
    data_FontSize16_0x26
};
#endif
#endif
static const PictureObject FontSize16_0x26 =
{
    PICTYPE_BITS,
    14,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x26
#else
    data_FontSize16_0x26
#endif
};
//-------------------------------------------------------
// Character: "'"/0x27, Width: 4, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x27[] GUI_RESOURCE_ATTRIBUTES =
{
    0x1F,0x00,0x1F,0x00,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x27 =
{
    font16_lut,
    data_FontSize16_0x27
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x27 =
{
    2,
    font16_lut,
    data_FontSize16_0x27
};
#endif
#endif
static const PictureObject FontSize16_0x27 =
{
    PICTYPE_BITS,
    4,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x27
#else
    data_FontSize16_0x27
#endif
};
//-------------------------------------------------------
// Character: "("/0x28, Width: 8, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x28[] GUI_RESOURCE_ATTRIBUTES =
{
    0xE0,0x07,0xF8,0x1F,0x1C,0x38,0x06,0x60,0x03,0xC0,0x01,0x80,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x28 =
{
    font16_lut,
    data_FontSize16_0x28
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x28 =
{
    2,
    font16_lut,
    data_FontSize16_0x28
};
#endif
#endif
static const PictureObject FontSize16_0x28 =
{
    PICTYPE_BITS,
    8,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x28
#else
    data_FontSize16_0x28
#endif
};
//-------------------------------------------------------
// Character: ")"/0x29, Width: 8, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x29[] GUI_RESOURCE_ATTRIBUTES =
{
    0x01,0x80,0x03,0xC0,0x06,0x60,0x1C,0x38,0xF8,0x1F,0xE0,0x07,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x29 =
{
    font16_lut,
    data_FontSize16_0x29
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x29 =
{
    2,
    font16_lut,
    data_FontSize16_0x29
};
#endif
#endif
static const PictureObject FontSize16_0x29 =
{
    PICTYPE_BITS,
    8,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x29
#else
    data_FontSize16_0x29
#endif
};
//-------------------------------------------------------
// Character: "*"/0x2A, Width: 9, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x2A[] GUI_RESOURCE_ATTRIBUTES =
{
    0x42,0x00,0x24,0x00,0x18,0x00,0xFF,0x00,0x18,0x00,0x24,0x00,0x42,0x00,0x00,0x00,
    0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x2A =
{
    font16_lut,
    data_FontSize16_0x2A
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x2A =
{
    2,
    font16_lut,
    data_FontSize16_0x2A
};
#endif
#endif
static const PictureObject FontSize16_0x2A =
{
    PICTYPE_BITS,
    9,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x2A
#else
    data_FontSize16_0x2A
#endif
};
//-------------------------------------------------------
// Character: "+"/0x2B, Width: 11, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x2B[] GUI_RESOURCE_ATTRIBUTES =
{
    0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0xF8,0x0F,0x80,0x00,0x80,0x00,0x80,0x00,
    0x80,0x00,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x2B =
{
    font16_lut,
    data_FontSize16_0x2B
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x2B =
{
    2,
    font16_lut,
    data_FontSize16_0x2B
};
#endif
#endif
static const PictureObject FontSize16_0x2B =
{
    PICTYPE_BITS,
    11,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x2B
#else
    data_FontSize16_0x2B
#endif
};
//-------------------------------------------------------
// Character: ","/0x2C, Width: 6, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x2C[] GUI_RESOURCE_ATTRIBUTES =
{
    0x00,0xC0,0x00,0xFC,0x00,0x3C,0x00,0x04,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x2C =
{
    font16_lut,
    data_FontSize16_0x2C
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x2C =
{
    2,
    font16_lut,
    data_FontSize16_0x2C
};
#endif
#endif
static const PictureObject FontSize16_0x2C =
{
    PICTYPE_BITS,
    6,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x2C
#else
    data_FontSize16_0x2C
#endif
};
//-------------------------------------------------------
// Character: "-"/0x2D, Width: 8, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x2D[] GUI_RESOURCE_ATTRIBUTES =
{
    0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x2D =
{
    font16_lut,
    data_FontSize16_0x2D
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x2D =
{
    2,
    font16_lut,
    data_FontSize16_0x2D
};
#endif
#endif
static const PictureObject FontSize16_0x2D =
{
    PICTYPE_BITS,
    8,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x2D
#else
    data_FontSize16_0x2D
#endif
};
//-------------------------------------------------------
// Character: "."/0x2E, Width: 4, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x2E[] GUI_RESOURCE_ATTRIBUTES =
{
    0x00,0x1C,0x00,0x1C,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x2E =
{
    font16_lut,
    data_FontSize16_0x2E
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x2E =
{
    2,
    font16_lut,
    data_FontSize16_0x2E
};
#endif
#endif
static const PictureObject FontSize16_0x2E =
{
    PICTYPE_BITS,
    4,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x2E
#else
    data_FontSize16_0x2E
#endif
};
//-------------------------------------------------------
// Character: "/"/0x2F, Width: 11, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x2F[] GUI_RESOURCE_ATTRIBUTES =
{
    0x00,0xC0,0x00,0xF0,0x00,0x3C,0x00,0x0F,0xC0,0x03,0xF0,0x00,0x3C,0x00,0x0F,0x00,
    0x03,0x00,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x2F =
{
    font16_lut,
    data_FontSize16_0x2F
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x2F =
{
    2,
    font16_lut,
    data_FontSize16_0x2F
};
#endif
#endif
static const PictureObject FontSize16_0x2F =
{
    PICTYPE_BITS,
    11,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x2F
#else
    data_FontSize16_0x2F
#endif
};
//-------------------------------------------------------
// Character: "0"/0x30, Width: 11, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x30[] GUI_RESOURCE_ATTRIBUTES =
{
    0xF8,0x07,0xFC,0x0F,0x06,0x18,0x02,0x10,0x02,0x10,0x02,0x10,0x06,0x18,0xFC,0x0F,
    0xF8,0x07,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x30 =
{
    font16_lut,
    data_FontSize16_0x30
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x30 =
{
    2,
    font16_lut,
    data_FontSize16_0x30
};
#endif
#endif
static const PictureObject FontSize16_0x30 =
{
    PICTYPE_BITS,
    11,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x30
#else
    data_FontSize16_0x30
#endif
};
//-------------------------------------------------------
// Character: "1"/0x31, Width: 8, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x31[] GUI_RESOURCE_ATTRIBUTES =
{
    0x04,0x10,0x04,0x10,0xFE,0x1F,0xFE,0x1F,0x00,0x10,0x00,0x10,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x31 =
{
    font16_lut,
    data_FontSize16_0x31
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x31 =
{
    2,
    font16_lut,
    data_FontSize16_0x31
};
#endif
#endif
static const PictureObject FontSize16_0x31 =
{
    PICTYPE_BITS,
    8,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x31
#else
    data_FontSize16_0x31
#endif
};
//-------------------------------------------------------
// Character: "2"/0x32, Width: 11, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x32[] GUI_RESOURCE_ATTRIBUTES =
{
    0x0C,0x10,0x0E,0x18,0x02,0x1C,0x02,0x16,0x02,0x13,0x82,0x11,0xC6,0x10,0x7C,0x10,
    0x38,0x10,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x32 =
{
    font16_lut,
    data_FontSize16_0x32
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x32 =
{
    2,
    font16_lut,
    data_FontSize16_0x32
};
#endif
#endif
static const PictureObject FontSize16_0x32 =
{
    PICTYPE_BITS,
    11,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x32
#else
    data_FontSize16_0x32
#endif
};
//-------------------------------------------------------
// Character: "3"/0x33, Width: 11, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x33[] GUI_RESOURCE_ATTRIBUTES =
{
    0x0C,0x0C,0x0E,0x1C,0x02,0x10,0x42,0x10,0x42,0x10,0x42,0x10,0xE6,0x18,0xBC,0x0F,
    0x18,0x07,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x33 =
{
    font16_lut,
    data_FontSize16_0x33
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x33 =
{
    2,
    font16_lut,
    data_FontSize16_0x33
};
#endif
#endif
static const PictureObject FontSize16_0x33 =
{
    PICTYPE_BITS,
    11,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x33
#else
    data_FontSize16_0x33
#endif
};
//-------------------------------------------------------
// Character: "4"/0x34, Width: 12, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x34[] GUI_RESOURCE_ATTRIBUTES =
{
    0x80,0x01,0x40,0x01,0x20,0x01,0x10,0x01,0x08,0x01,0x04,0x01,0xFE,0x1F,0xFE,0x1F,
    0x00,0x01,0x00,0x01,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x34 =
{
    font16_lut,
    data_FontSize16_0x34
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x34 =
{
    2,
    font16_lut,
    data_FontSize16_0x34
};
#endif
#endif
static const PictureObject FontSize16_0x34 =
{
    PICTYPE_BITS,
    12,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x34
#else
    data_FontSize16_0x34
#endif
};
//-------------------------------------------------------
// Character: "5"/0x35, Width: 11, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x35[] GUI_RESOURCE_ATTRIBUTES =
{
    0x00,0x0C,0x3E,0x1C,0x3E,0x10,0x22,0x10,0x22,0x10,0x22,0x10,0x62,0x18,0xC2,0x0F,
    0x82,0x07,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x35 =
{
    font16_lut,
    data_FontSize16_0x35
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x35 =
{
    2,
    font16_lut,
    data_FontSize16_0x35
};
#endif
#endif
static const PictureObject FontSize16_0x35 =
{
    PICTYPE_BITS,
    11,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x35
#else
    data_FontSize16_0x35
#endif
};
//-------------------------------------------------------
// Character: "6"/0x36, Width: 11, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x36[] GUI_RESOURCE_ATTRIBUTES =
{
    0xE0,0x07,0xF8,0x0F,0x5C,0x18,0x24,0x10,0x26,0x10,0x22,0x10,0x62,0x18,0xC2,0x0F,
    0x80,0x07,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x36 =
{
    font16_lut,
    data_FontSize16_0x36
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x36 =
{
    2,
    font16_lut,
    data_FontSize16_0x36
};
#endif
#endif
static const PictureObject FontSize16_0x36 =
{
    PICTYPE_BITS,
    11,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x36
#else
    data_FontSize16_0x36
#endif
};
//-------------------------------------------------------
// Character: "7"/0x37, Width: 11, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x37[] GUI_RESOURCE_ATTRIBUTES =
{
    0x02,0x00,0x02,0x00,0x02,0x18,0x02,0x1E,0x82,0x07,0xE2,0x01,0x7A,0x00,0x1E,0x00,
    0x06,0x00,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x37 =
{
    font16_lut,
    data_FontSize16_0x37
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x37 =
{
    2,
    font16_lut,
    data_FontSize16_0x37
};
#endif
#endif
static const PictureObject FontSize16_0x37 =
{
    PICTYPE_BITS,
    11,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x37
#else
    data_FontSize16_0x37
#endif
};
//-------------------------------------------------------
// Character: "8"/0x38, Width: 11, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x38[] GUI_RESOURCE_ATTRIBUTES =
{
    0x18,0x07,0xBC,0x0F,0xE6,0x18,0x42,0x10,0x42,0x10,0x42,0x10,0xE6,0x18,0xBC,0x0F,
    0x18,0x07,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x38 =
{
    font16_lut,
    data_FontSize16_0x38
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x38 =
{
    2,
    font16_lut,
    data_FontSize16_0x38
};
#endif
#endif
static const PictureObject FontSize16_0x38 =
{
    PICTYPE_BITS,
    11,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x38
#else
    data_FontSize16_0x38
#endif
};
//-------------------------------------------------------
// Character: "9"/0x39, Width: 11, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x39[] GUI_RESOURCE_ATTRIBUTES =
{
    0x78,0x00,0xFC,0x10,0x86,0x11,0x02,0x11,0x02,0x19,0x02,0x09,0x86,0x0C,0xFC,0x07,
    0xF8,0x03,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x39 =
{
    font16_lut,
    data_FontSize16_0x39
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x39 =
{
    2,
    font16_lut,
    data_FontSize16_0x39
};
#endif
#endif
static const PictureObject FontSize16_0x39 =
{
    PICTYPE_BITS,
    11,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x39
#else
    data_FontSize16_0x39
#endif
};
//-------------------------------------------------------
// Character: ":"/0x3A, Width: 4, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x3A[] GUI_RESOURCE_ATTRIBUTES =
{
    0x70,0x1C,0x70,0x1C,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x3A =
{
    font16_lut,
    data_FontSize16_0x3A
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x3A =
{
    2,
    font16_lut,
    data_FontSize16_0x3A
};
#endif
#endif
static const PictureObject FontSize16_0x3A =
{
    PICTYPE_BITS,
    4,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x3A
#else
    data_FontSize16_0x3A
#endif
};
//-------------------------------------------------------
// Character: ";"/0x3B, Width: 6, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x3B[] GUI_RESOURCE_ATTRIBUTES =
{
    0x00,0xC0,0x70,0xFC,0x70,0x3C,0x00,0x04,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x3B =
{
    font16_lut,
    data_FontSize16_0x3B
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x3B =
{
    2,
    font16_lut,
    data_FontSize16_0x3B
};
#endif
#endif
static const PictureObject FontSize16_0x3B =
{
    PICTYPE_BITS,
    6,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x3B
#else
    data_FontSize16_0x3B
#endif
};
//-------------------------------------------------------
// Character: "<"/0x3C, Width: 11, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x3C[] GUI_RESOURCE_ATTRIBUTES =
{
    0x80,0x01,0x80,0x01,0x40,0x02,0x40,0x02,0x20,0x04,0x20,0x04,0x10,0x08,0x10,0x08,
    0x08,0x10,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x3C =
{
    font16_lut,
    data_FontSize16_0x3C
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x3C =
{
    2,
    font16_lut,
    data_FontSize16_0x3C
};
#endif
#endif
static const PictureObject FontSize16_0x3C =
{
    PICTYPE_BITS,
    11,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x3C
#else
    data_FontSize16_0x3C
#endif
};
//-------------------------------------------------------
// Character: "="/0x3D, Width: 11, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x3D[] GUI_RESOURCE_ATTRIBUTES =
{
    0x20,0x02,0x20,0x02,0x20,0x02,0x20,0x02,0x20,0x02,0x20,0x02,0x20,0x02,0x20,0x02,
    0x20,0x02,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x3D =
{
    font16_lut,
    data_FontSize16_0x3D
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x3D =
{
    2,
    font16_lut,
    data_FontSize16_0x3D
};
#endif
#endif
static const PictureObject FontSize16_0x3D =
{
    PICTYPE_BITS,
    11,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x3D
#else
    data_FontSize16_0x3D
#endif
};
//-------------------------------------------------------
// Character: ">"/0x3E, Width: 11, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x3E[] GUI_RESOURCE_ATTRIBUTES =
{
    0x08,0x10,0x10,0x08,0x10,0x08,0x20,0x04,0x20,0x04,0x40,0x02,0x40,0x02,0x80,0x01,
    0x80,0x01,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x3E =
{
    font16_lut,
    data_FontSize16_0x3E
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x3E =
{
    2,
    font16_lut,
    data_FontSize16_0x3E
};
#endif
#endif
static const PictureObject FontSize16_0x3E =
{
    PICTYPE_BITS,
    11,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x3E
#else
    data_FontSize16_0x3E
#endif
};
//-------------------------------------------------------
// Character: "?"/0x3F, Width: 10, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x3F[] GUI_RESOURCE_ATTRIBUTES =
{
    0x0C,0x00,0x0E,0x00,0x02,0x00,0x02,0x1B,0x82,0x1B,0xC6,0x00,0x7C,0x00,0x38,0x00,
    0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x3F =
{
    font16_lut,
    data_FontSize16_0x3F
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x3F =
{
    2,
    font16_lut,
    data_FontSize16_0x3F
};
#endif
#endif
static const PictureObject FontSize16_0x3F =
{
    PICTYPE_BITS,
    10,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x3F
#else
    data_FontSize16_0x3F
#endif
};
//-------------------------------------------------------
// Character: "@"/0x40, Width: 15, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x40[] GUI_RESOURCE_ATTRIBUTES =
{
    0xE0,0x07,0x18,0x18,0x04,0x20,0xC4,0x27,0xE2,0x4F,0x32,0x48,0x12,0x48,0x12,0x44,
    0xF2,0x4F,0xF4,0x4F,0x04,0x08,0x18,0x08,0xE0,0x07,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x40 =
{
    font16_lut,
    data_FontSize16_0x40
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x40 =
{
    2,
    font16_lut,
    data_FontSize16_0x40
};
#endif
#endif
static const PictureObject FontSize16_0x40 =
{
    PICTYPE_BITS,
    15,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x40
#else
    data_FontSize16_0x40
#endif
};
//-------------------------------------------------------
// Character: "A"/0x41, Width: 12, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x41[] GUI_RESOURCE_ATTRIBUTES =
{
    0x00,0x1C,0x80,0x1F,0xE0,0x03,0x78,0x02,0x1E,0x02,0x1E,0x02,0x78,0x02,0xE0,0x03,
    0x80,0x1F,0x00,0x1C,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x41 =
{
    font16_lut,
    data_FontSize16_0x41
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x41 =
{
    2,
    font16_lut,
    data_FontSize16_0x41
};
#endif
#endif
static const PictureObject FontSize16_0x41 =
{
    PICTYPE_BITS,
    12,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x41
#else
    data_FontSize16_0x41
#endif
};
//-------------------------------------------------------
// Character: "B"/0x42, Width: 12, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x42[] GUI_RESOURCE_ATTRIBUTES =
{
    0xFE,0x1F,0xFE,0x1F,0x42,0x10,0x42,0x10,0x42,0x10,0x42,0x10,0x46,0x10,0xFC,0x18,
    0x98,0x0F,0x00,0x07,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x42 =
{
    font16_lut,
    data_FontSize16_0x42
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x42 =
{
    2,
    font16_lut,
    data_FontSize16_0x42
};
#endif
#endif
static const PictureObject FontSize16_0x42 =
{
    PICTYPE_BITS,
    12,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x42
#else
    data_FontSize16_0x42
#endif
};
//-------------------------------------------------------
// Character: "C"/0x43, Width: 12, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x43[] GUI_RESOURCE_ATTRIBUTES =
{
    0xF0,0x03,0xFC,0x0F,0x0C,0x0C,0x06,0x18,0x02,0x10,0x02,0x10,0x02,0x10,0x02,0x10,
    0x0E,0x1C,0x0C,0x0C,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x43 =
{
    font16_lut,
    data_FontSize16_0x43
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x43 =
{
    2,
    font16_lut,
    data_FontSize16_0x43
};
#endif
#endif
static const PictureObject FontSize16_0x43 =
{
    PICTYPE_BITS,
    12,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x43
#else
    data_FontSize16_0x43
#endif
};
//-------------------------------------------------------
// Character: "D"/0x44, Width: 13, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x44[] GUI_RESOURCE_ATTRIBUTES =
{
    0xFE,0x1F,0xFE,0x1F,0x02,0x10,0x02,0x10,0x02,0x10,0x02,0x10,0x02,0x10,0x06,0x18,
    0x0C,0x0C,0xFC,0x0F,0xF0,0x03,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x44 =
{
    font16_lut,
    data_FontSize16_0x44
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x44 =
{
    2,
    font16_lut,
    data_FontSize16_0x44
};
#endif
#endif
static const PictureObject FontSize16_0x44 =
{
    PICTYPE_BITS,
    13,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x44
#else
    data_FontSize16_0x44
#endif
};
//-------------------------------------------------------
// Character: "E"/0x45, Width: 11, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x45[] GUI_RESOURCE_ATTRIBUTES =
{
    0xFE,0x1F,0xFE,0x1F,0x42,0x10,0x42,0x10,0x42,0x10,0x42,0x10,0x42,0x10,0x42,0x10,
    0x02,0x10,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x45 =
{
    font16_lut,
    data_FontSize16_0x45
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x45 =
{
    2,
    font16_lut,
    data_FontSize16_0x45
};
#endif
#endif
static const PictureObject FontSize16_0x45 =
{
    PICTYPE_BITS,
    11,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x45
#else
    data_FontSize16_0x45
#endif
};
//-------------------------------------------------------
// Character: "F"/0x46, Width: 10, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x46[] GUI_RESOURCE_ATTRIBUTES =
{
    0xFE,0x1F,0xFE,0x1F,0x42,0x00,0x42,0x00,0x42,0x00,0x42,0x00,0x42,0x00,0x42,0x00,
    0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x46 =
{
    font16_lut,
    data_FontSize16_0x46
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x46 =
{
    2,
    font16_lut,
    data_FontSize16_0x46
};
#endif
#endif
static const PictureObject FontSize16_0x46 =
{
    PICTYPE_BITS,
    10,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x46
#else
    data_FontSize16_0x46
#endif
};
//-------------------------------------------------------
// Character: "G"/0x47, Width: 13, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x47[] GUI_RESOURCE_ATTRIBUTES =
{
    0xF0,0x03,0xFC,0x0F,0x0C,0x0C,0x06,0x18,0x02,0x10,0x02,0x10,0x82,0x10,0x82,0x10,
    0x82,0x10,0x8E,0x1F,0x8C,0x0F,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x47 =
{
    font16_lut,
    data_FontSize16_0x47
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x47 =
{
    2,
    font16_lut,
    data_FontSize16_0x47
};
#endif
#endif
static const PictureObject FontSize16_0x47 =
{
    PICTYPE_BITS,
    13,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x47
#else
    data_FontSize16_0x47
#endif
};
//-------------------------------------------------------
// Character: "H"/0x48, Width: 13, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x48[] GUI_RESOURCE_ATTRIBUTES =
{
    0xFE,0x1F,0xFE,0x1F,0x40,0x00,0x40,0x00,0x40,0x00,0x40,0x00,0x40,0x00,0x40,0x00,
    0x40,0x00,0xFE,0x1F,0xFE,0x1F,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x48 =
{
    font16_lut,
    data_FontSize16_0x48
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x48 =
{
    2,
    font16_lut,
    data_FontSize16_0x48
};
#endif
#endif
static const PictureObject FontSize16_0x48 =
{
    PICTYPE_BITS,
    13,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x48
#else
    data_FontSize16_0x48
#endif
};
//-------------------------------------------------------
// Character: "I"/0x49, Width: 8, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x49[] GUI_RESOURCE_ATTRIBUTES =
{
    0x02,0x10,0x02,0x10,0xFE,0x1F,0xFE,0x1F,0x02,0x10,0x02,0x10,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x49 =
{
    font16_lut,
    data_FontSize16_0x49
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x49 =
{
    2,
    font16_lut,
    data_FontSize16_0x49
};
#endif
#endif
static const PictureObject FontSize16_0x49 =
{
    PICTYPE_BITS,
    8,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x49
#else
    data_FontSize16_0x49
#endif
};
//-------------------------------------------------------
// Character: "J"/0x4A, Width: 9, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x4A[] GUI_RESOURCE_ATTRIBUTES =
{
    0x00,0x10,0x00,0x10,0x02,0x10,0x02,0x10,0x02,0x18,0xFE,0x0F,0xFE,0x07,0x00,0x00,
    0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x4A =
{
    font16_lut,
    data_FontSize16_0x4A
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x4A =
{
    2,
    font16_lut,
    data_FontSize16_0x4A
};
#endif
#endif
static const PictureObject FontSize16_0x4A =
{
    PICTYPE_BITS,
    9,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x4A
#else
    data_FontSize16_0x4A
#endif
};
//-------------------------------------------------------
// Character: "K"/0x4B, Width: 12, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x4B[] GUI_RESOURCE_ATTRIBUTES =
{
    0xFE,0x1F,0xFE,0x1F,0x80,0x01,0xC0,0x00,0xE0,0x01,0x30,0x03,0x18,0x06,0x0C,0x0C,
    0x06,0x18,0x02,0x10,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x4B =
{
    font16_lut,
    data_FontSize16_0x4B
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x4B =
{
    2,
    font16_lut,
    data_FontSize16_0x4B
};
#endif
#endif
static const PictureObject FontSize16_0x4B =
{
    PICTYPE_BITS,
    12,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x4B
#else
    data_FontSize16_0x4B
#endif
};
//-------------------------------------------------------
// Character: "L"/0x4C, Width: 10, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x4C[] GUI_RESOURCE_ATTRIBUTES =
{
    0xFE,0x1F,0xFE,0x1F,0x00,0x10,0x00,0x10,0x00,0x10,0x00,0x10,0x00,0x10,0x00,0x10,
    0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x4C =
{
    font16_lut,
    data_FontSize16_0x4C
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x4C =
{
    2,
    font16_lut,
    data_FontSize16_0x4C
};
#endif
#endif
static const PictureObject FontSize16_0x4C =
{
    PICTYPE_BITS,
    10,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x4C
#else
    data_FontSize16_0x4C
#endif
};
//-------------------------------------------------------
// Character: "M"/0x4D, Width: 15, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x4D[] GUI_RESOURCE_ATTRIBUTES =
{
    0xFE,0x1F,0x0E,0x00,0x3C,0x00,0xF0,0x00,0xC0,0x03,0x00,0x0F,0x00,0x0E,0x80,0x03,
    0xE0,0x00,0x38,0x00,0x0E,0x00,0xFE,0x1F,0xFE,0x1F,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x4D =
{
    font16_lut,
    data_FontSize16_0x4D
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x4D =
{
    2,
    font16_lut,
    data_FontSize16_0x4D
};
#endif
#endif
static const PictureObject FontSize16_0x4D =
{
    PICTYPE_BITS,
    15,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x4D
#else
    data_FontSize16_0x4D
#endif
};
//-------------------------------------------------------
// Character: "N"/0x4E, Width: 13, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x4E[] GUI_RESOURCE_ATTRIBUTES =
{
    0xFE,0x1F,0x06,0x00,0x0E,0x00,0x18,0x00,0x70,0x00,0xE0,0x00,0x80,0x03,0x00,0x07,
    0x00,0x1C,0x00,0x18,0xFE,0x1F,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x4E =
{
    font16_lut,
    data_FontSize16_0x4E
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x4E =
{
    2,
    font16_lut,
    data_FontSize16_0x4E
};
#endif
#endif
static const PictureObject FontSize16_0x4E =
{
    PICTYPE_BITS,
    13,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x4E
#else
    data_FontSize16_0x4E
#endif
};
//-------------------------------------------------------
// Character: "O"/0x4F, Width: 14, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x4F[] GUI_RESOURCE_ATTRIBUTES =
{
    0xF0,0x03,0xFC,0x0F,0x0C,0x0C,0x06,0x18,0x02,0x10,0x02,0x10,0x02,0x10,0x02,0x10,
    0x06,0x18,0x0C,0x0C,0xFC,0x0F,0xF0,0x03,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x4F =
{
    font16_lut,
    data_FontSize16_0x4F
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x4F =
{
    2,
    font16_lut,
    data_FontSize16_0x4F
};
#endif
#endif
static const PictureObject FontSize16_0x4F =
{
    PICTYPE_BITS,
    14,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x4F
#else
    data_FontSize16_0x4F
#endif
};
//-------------------------------------------------------
// Character: "P"/0x50, Width: 12, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x50[] GUI_RESOURCE_ATTRIBUTES =
{
    0xFE,0x1F,0xFE,0x1F,0x02,0x01,0x02,0x01,0x02,0x01,0x02,0x01,0x02,0x01,0x86,0x01,
    0xFC,0x00,0x78,0x00,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x50 =
{
    font16_lut,
    data_FontSize16_0x50
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x50 =
{
    2,
    font16_lut,
    data_FontSize16_0x50
};
#endif
#endif
static const PictureObject FontSize16_0x50 =
{
    PICTYPE_BITS,
    12,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x50
#else
    data_FontSize16_0x50
#endif
};
//-------------------------------------------------------
// Character: "Q"/0x51, Width: 14, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x51[] GUI_RESOURCE_ATTRIBUTES =
{
    0xF0,0x03,0xFC,0x0F,0x0C,0x0C,0x06,0x18,0x02,0x10,0x02,0x10,0x02,0x70,0x02,0xF0,
    0x06,0xD8,0x0C,0x8C,0xFC,0x8F,0xF0,0x83,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x51 =
{
    font16_lut,
    data_FontSize16_0x51
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x51 =
{
    2,
    font16_lut,
    data_FontSize16_0x51
};
#endif
#endif
static const PictureObject FontSize16_0x51 =
{
    PICTYPE_BITS,
    14,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x51
#else
    data_FontSize16_0x51
#endif
};
//-------------------------------------------------------
// Character: "R"/0x52, Width: 13, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x52[] GUI_RESOURCE_ATTRIBUTES =
{
    0xFE,0x1F,0xFE,0x1F,0x82,0x00,0x82,0x00,0x82,0x00,0x82,0x01,0x82,0x03,0xC6,0x06,
    0x7C,0x0C,0x38,0x18,0x00,0x10,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x52 =
{
    font16_lut,
    data_FontSize16_0x52
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x52 =
{
    2,
    font16_lut,
    data_FontSize16_0x52
};
#endif
#endif
static const PictureObject FontSize16_0x52 =
{
    PICTYPE_BITS,
    13,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x52
#else
    data_FontSize16_0x52
#endif
};
//-------------------------------------------------------
// Character: "S"/0x53, Width: 11, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x53[] GUI_RESOURCE_ATTRIBUTES =
{
    0x38,0x0C,0x7C,0x1C,0x66,0x10,0xC2,0x10,0xC2,0x10,0xC2,0x10,0x82,0x19,0x8E,0x0F,
    0x0C,0x07,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x53 =
{
    font16_lut,
    data_FontSize16_0x53
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x53 =
{
    2,
    font16_lut,
    data_FontSize16_0x53
};
#endif
#endif
static const PictureObject FontSize16_0x53 =
{
    PICTYPE_BITS,
    11,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x53
#else
    data_FontSize16_0x53
#endif
};
//-------------------------------------------------------
// Character: "T"/0x54, Width: 12, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x54[] GUI_RESOURCE_ATTRIBUTES =
{
    0x02,0x00,0x02,0x00,0x02,0x00,0x02,0x00,0xFE,0x1F,0xFE,0x1F,0x02,0x00,0x02,0x00,
    0x02,0x00,0x02,0x00,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x54 =
{
    font16_lut,
    data_FontSize16_0x54
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x54 =
{
    2,
    font16_lut,
    data_FontSize16_0x54
};
#endif
#endif
static const PictureObject FontSize16_0x54 =
{
    PICTYPE_BITS,
    12,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x54
#else
    data_FontSize16_0x54
#endif
};
//-------------------------------------------------------
// Character: "U"/0x55, Width: 13, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x55[] GUI_RESOURCE_ATTRIBUTES =
{
    0xFE,0x07,0xFE,0x0F,0x00,0x18,0x00,0x10,0x00,0x10,0x00,0x10,0x00,0x10,0x00,0x10,
    0x00,0x18,0xFE,0x0F,0xFE,0x07,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x55 =
{
    font16_lut,
    data_FontSize16_0x55
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x55 =
{
    2,
    font16_lut,
    data_FontSize16_0x55
};
#endif
#endif
static const PictureObject FontSize16_0x55 =
{
    PICTYPE_BITS,
    13,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x55
#else
    data_FontSize16_0x55
#endif
};
//-------------------------------------------------------
// Character: "V"/0x56, Width: 12, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x56[] GUI_RESOURCE_ATTRIBUTES =
{
    0x0E,0x00,0x3E,0x00,0xF0,0x01,0xC0,0x07,0x00,0x1E,0x00,0x1E,0xC0,0x07,0xF0,0x01,
    0x3E,0x00,0x0E,0x00,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x56 =
{
    font16_lut,
    data_FontSize16_0x56
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x56 =
{
    2,
    font16_lut,
    data_FontSize16_0x56
};
#endif
#endif
static const PictureObject FontSize16_0x56 =
{
    PICTYPE_BITS,
    12,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x56
#else
    data_FontSize16_0x56
#endif
};
//-------------------------------------------------------
// Character: "W"/0x57, Width: 18, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x57[] GUI_RESOURCE_ATTRIBUTES =
{
    0x0E,0x00,0x7E,0x00,0xF0,0x03,0x80,0x1F,0x00,0x1E,0xC0,0x07,0xF0,0x00,0x1E,0x00,
    0x1E,0x00,0xF0,0x00,0xC0,0x07,0x00,0x1E,0x80,0x1F,0xF0,0x03,0x7E,0x00,0x0E,0x00,
    0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x57 =
{
    font16_lut,
    data_FontSize16_0x57
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x57 =
{
    2,
    font16_lut,
    data_FontSize16_0x57
};
#endif
#endif
static const PictureObject FontSize16_0x57 =
{
    PICTYPE_BITS,
    18,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x57
#else
    data_FontSize16_0x57
#endif
};
//-------------------------------------------------------
// Character: "X"/0x58, Width: 12, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x58[] GUI_RESOURCE_ATTRIBUTES =
{
    0x06,0x18,0x0E,0x1C,0x38,0x07,0xF0,0x03,0xC0,0x00,0xC0,0x00,0xF0,0x03,0x38,0x07,
    0x0E,0x1C,0x06,0x18,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x58 =
{
    font16_lut,
    data_FontSize16_0x58
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x58 =
{
    2,
    font16_lut,
    data_FontSize16_0x58
};
#endif
#endif
static const PictureObject FontSize16_0x58 =
{
    PICTYPE_BITS,
    12,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x58
#else
    data_FontSize16_0x58
#endif
};
//-------------------------------------------------------
// Character: "Y"/0x59, Width: 12, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x59[] GUI_RESOURCE_ATTRIBUTES =
{
    0x06,0x00,0x1E,0x00,0x78,0x00,0xE0,0x00,0x80,0x1F,0x80,0x1F,0xE0,0x00,0x78,0x00,
    0x1E,0x00,0x06,0x00,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x59 =
{
    font16_lut,
    data_FontSize16_0x59
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x59 =
{
    2,
    font16_lut,
    data_FontSize16_0x59
};
#endif
#endif
static const PictureObject FontSize16_0x59 =
{
    PICTYPE_BITS,
    12,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x59
#else
    data_FontSize16_0x59
#endif
};
//-------------------------------------------------------
// Character: "Z"/0x5A, Width: 11, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x5A[] GUI_RESOURCE_ATTRIBUTES =
{
    0x02,0x18,0x02,0x1C,0x02,0x17,0x82,0x13,0xC2,0x10,0x72,0x10,0x3A,0x10,0x0E,0x10,
    0x06,0x10,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x5A =
{
    font16_lut,
    data_FontSize16_0x5A
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x5A =
{
    2,
    font16_lut,
    data_FontSize16_0x5A
};
#endif
#endif
static const PictureObject FontSize16_0x5A =
{
    PICTYPE_BITS,
    11,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x5A
#else
    data_FontSize16_0x5A
#endif
};
//-------------------------------------------------------
// Character: "["/0x5B, Width: 7, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x5B[] GUI_RESOURCE_ATTRIBUTES =
{
    0xFF,0xFF,0xFF,0xFF,0x01,0x80,0x01,0x80,0x01,0x80,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x5B =
{
    font16_lut,
    data_FontSize16_0x5B
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x5B =
{
    2,
    font16_lut,
    data_FontSize16_0x5B
};
#endif
#endif
static const PictureObject FontSize16_0x5B =
{
    PICTYPE_BITS,
    7,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x5B
#else
    data_FontSize16_0x5B
#endif
};
//-------------------------------------------------------
// Character: "\"/0x5C, Width: 11, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x5C[] GUI_RESOURCE_ATTRIBUTES =
{
    0x03,0x00,0x0F,0x00,0x3C,0x00,0xF0,0x00,0xC0,0x03,0x00,0x0F,0x00,0x3C,0x00,0xF0,
    0x00,0xC0,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x5C =
{
    font16_lut,
    data_FontSize16_0x5C
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x5C =
{
    2,
    font16_lut,
    data_FontSize16_0x5C
};
#endif
#endif
static const PictureObject FontSize16_0x5C =
{
    PICTYPE_BITS,
    11,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x5C
#else
    data_FontSize16_0x5C
#endif
};
//-------------------------------------------------------
// Character: "]"/0x5D, Width: 7, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x5D[] GUI_RESOURCE_ATTRIBUTES =
{
    0x01,0x80,0x01,0x80,0x01,0x80,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x5D =
{
    font16_lut,
    data_FontSize16_0x5D
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x5D =
{
    2,
    font16_lut,
    data_FontSize16_0x5D
};
#endif
#endif
static const PictureObject FontSize16_0x5D =
{
    PICTYPE_BITS,
    7,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x5D
#else
    data_FontSize16_0x5D
#endif
};
//-------------------------------------------------------
// Character: "^"/0x5E, Width: 13, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x5E[] GUI_RESOURCE_ATTRIBUTES =
{
    0x40,0x00,0x60,0x00,0x30,0x00,0x18,0x00,0x0C,0x00,0x06,0x00,0x0C,0x00,0x18,0x00,
    0x30,0x00,0x60,0x00,0x40,0x00,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x5E =
{
    font16_lut,
    data_FontSize16_0x5E
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x5E =
{
    2,
    font16_lut,
    data_FontSize16_0x5E
};
#endif
#endif
static const PictureObject FontSize16_0x5E =
{
    PICTYPE_BITS,
    13,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x5E
#else
    data_FontSize16_0x5E
#endif
};
//-------------------------------------------------------
// Character: "_"/0x5F, Width: 13, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x5F[] GUI_RESOURCE_ATTRIBUTES =
{
    0x00,0x40,0x00,0x40,0x00,0x40,0x00,0x40,0x00,0x40,0x00,0x40,0x00,0x40,0x00,0x40,
    0x00,0x40,0x00,0x40,0x00,0x40,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x5F =
{
    font16_lut,
    data_FontSize16_0x5F
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x5F =
{
    2,
    font16_lut,
    data_FontSize16_0x5F
};
#endif
#endif
static const PictureObject FontSize16_0x5F =
{
    PICTYPE_BITS,
    13,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x5F
#else
    data_FontSize16_0x5F
#endif
};
//-------------------------------------------------------
// Character: "`"/0x60, Width: 5, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x60[] GUI_RESOURCE_ATTRIBUTES =
{
    0x02,0x00,0x06,0x00,0x04,0x00,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x60 =
{
    font16_lut,
    data_FontSize16_0x60
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x60 =
{
    2,
    font16_lut,
    data_FontSize16_0x60
};
#endif
#endif
static const PictureObject FontSize16_0x60 =
{
    PICTYPE_BITS,
    5,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x60
#else
    data_FontSize16_0x60
#endif
};
//-------------------------------------------------------
// Character: "a"/0x61, Width: 11, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x61[] GUI_RESOURCE_ATTRIBUTES =
{
    0x00,0x0E,0x20,0x1F,0x30,0x11,0x90,0x10,0x90,0x10,0x90,0x10,0xB0,0x08,0xE0,0x1F,
    0xC0,0x1F,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x61 =
{
    font16_lut,
    data_FontSize16_0x61
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x61 =
{
    2,
    font16_lut,
    data_FontSize16_0x61
};
#endif
#endif
static const PictureObject FontSize16_0x61 =
{
    PICTYPE_BITS,
    11,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x61
#else
    data_FontSize16_0x61
#endif
};
//-------------------------------------------------------
// Character: "b"/0x62, Width: 11, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x62[] GUI_RESOURCE_ATTRIBUTES =
{
    0xFF,0x1F,0xFF,0x1F,0x20,0x08,0x10,0x10,0x10,0x10,0x10,0x10,0x30,0x18,0xE0,0x0F,
    0xC0,0x07,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x62 =
{
    font16_lut,
    data_FontSize16_0x62
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x62 =
{
    2,
    font16_lut,
    data_FontSize16_0x62
};
#endif
#endif
static const PictureObject FontSize16_0x62 =
{
    PICTYPE_BITS,
    11,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x62
#else
    data_FontSize16_0x62
#endif
};
//-------------------------------------------------------
// Character: "c"/0x63, Width: 10, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x63[] GUI_RESOURCE_ATTRIBUTES =
{
    0xC0,0x07,0xE0,0x0F,0x30,0x18,0x10,0x10,0x10,0x10,0x10,0x10,0x30,0x18,0x20,0x08,
    0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x63 =
{
    font16_lut,
    data_FontSize16_0x63
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x63 =
{
    2,
    font16_lut,
    data_FontSize16_0x63
};
#endif
#endif
static const PictureObject FontSize16_0x63 =
{
    PICTYPE_BITS,
    10,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x63
#else
    data_FontSize16_0x63
#endif
};
//-------------------------------------------------------
// Character: "d"/0x64, Width: 11, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x64[] GUI_RESOURCE_ATTRIBUTES =
{
    0xC0,0x07,0xE0,0x0F,0x30,0x18,0x10,0x10,0x10,0x10,0x10,0x10,0x20,0x08,0xFF,0x1F,
    0xFF,0x1F,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x64 =
{
    font16_lut,
    data_FontSize16_0x64
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x64 =
{
    2,
    font16_lut,
    data_FontSize16_0x64
};
#endif
#endif
static const PictureObject FontSize16_0x64 =
{
    PICTYPE_BITS,
    11,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x64
#else
    data_FontSize16_0x64
#endif
};
//-------------------------------------------------------
// Character: "e"/0x65, Width: 11, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x65[] GUI_RESOURCE_ATTRIBUTES =
{
    0xC0,0x07,0xE0,0x0F,0xB0,0x18,0x90,0x10,0x90,0x10,0x90,0x10,0xB0,0x10,0xE0,0x18,
    0xC0,0x08,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x65 =
{
    font16_lut,
    data_FontSize16_0x65
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x65 =
{
    2,
    font16_lut,
    data_FontSize16_0x65
};
#endif
#endif
static const PictureObject FontSize16_0x65 =
{
    PICTYPE_BITS,
    11,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x65
#else
    data_FontSize16_0x65
#endif
};
//-------------------------------------------------------
// Character: "f"/0x66, Width: 8, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x66[] GUI_RESOURCE_ATTRIBUTES =
{
    0x10,0x00,0xFE,0x1F,0xFF,0x1F,0x11,0x00,0x11,0x00,0x01,0x00,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x66 =
{
    font16_lut,
    data_FontSize16_0x66
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x66 =
{
    2,
    font16_lut,
    data_FontSize16_0x66
};
#endif
#endif
static const PictureObject FontSize16_0x66 =
{
    PICTYPE_BITS,
    8,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x66
#else
    data_FontSize16_0x66
#endif
};
//-------------------------------------------------------
// Character: "g"/0x67, Width: 11, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x67[] GUI_RESOURCE_ATTRIBUTES =
{
    0xC0,0x07,0xE0,0x4F,0x30,0xD8,0x10,0x90,0x10,0x90,0x10,0x90,0x20,0xC8,0xF0,0x7F,
    0xF0,0x3F,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x67 =
{
    font16_lut,
    data_FontSize16_0x67
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x67 =
{
    2,
    font16_lut,
    data_FontSize16_0x67
};
#endif
#endif
static const PictureObject FontSize16_0x67 =
{
    PICTYPE_BITS,
    11,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x67
#else
    data_FontSize16_0x67
#endif
};
//-------------------------------------------------------
// Character: "h"/0x68, Width: 11, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x68[] GUI_RESOURCE_ATTRIBUTES =
{
    0xFF,0x1F,0xFF,0x1F,0x20,0x00,0x10,0x00,0x10,0x00,0x10,0x00,0x30,0x00,0xE0,0x1F,
    0xC0,0x1F,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x68 =
{
    font16_lut,
    data_FontSize16_0x68
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x68 =
{
    2,
    font16_lut,
    data_FontSize16_0x68
};
#endif
#endif
static const PictureObject FontSize16_0x68 =
{
    PICTYPE_BITS,
    11,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x68
#else
    data_FontSize16_0x68
#endif
};
//-------------------------------------------------------
// Character: "i"/0x69, Width: 4, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x69[] GUI_RESOURCE_ATTRIBUTES =
{
    0xF3,0x1F,0xF3,0x1F,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x69 =
{
    font16_lut,
    data_FontSize16_0x69
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x69 =
{
    2,
    font16_lut,
    data_FontSize16_0x69
};
#endif
#endif
static const PictureObject FontSize16_0x69 =
{
    PICTYPE_BITS,
    4,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x69
#else
    data_FontSize16_0x69
#endif
};
//-------------------------------------------------------
// Character: "j"/0x6A, Width: 7, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x6A[] GUI_RESOURCE_ATTRIBUTES =
{
    0x00,0x80,0x10,0x80,0x10,0x80,0xF3,0xFF,0xF3,0x7F,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x6A =
{
    font16_lut,
    data_FontSize16_0x6A
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x6A =
{
    2,
    font16_lut,
    data_FontSize16_0x6A
};
#endif
#endif
static const PictureObject FontSize16_0x6A =
{
    PICTYPE_BITS,
    7,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x6A
#else
    data_FontSize16_0x6A
#endif
};
//-------------------------------------------------------
// Character: "k"/0x6B, Width: 11, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x6B[] GUI_RESOURCE_ATTRIBUTES =
{
    0xFF,0x1F,0xFF,0x1F,0x00,0x03,0x80,0x01,0xC0,0x03,0x60,0x06,0x30,0x0C,0x10,0x18,
    0x00,0x10,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x6B =
{
    font16_lut,
    data_FontSize16_0x6B
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x6B =
{
    2,
    font16_lut,
    data_FontSize16_0x6B
};
#endif
#endif
static const PictureObject FontSize16_0x6B =
{
    PICTYPE_BITS,
    11,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x6B
#else
    data_FontSize16_0x6B
#endif
};
//-------------------------------------------------------
// Character: "l"/0x6C, Width: 4, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x6C[] GUI_RESOURCE_ATTRIBUTES =
{
    0xFF,0x1F,0xFF,0x1F,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x6C =
{
    font16_lut,
    data_FontSize16_0x6C
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x6C =
{
    2,
    font16_lut,
    data_FontSize16_0x6C
};
#endif
#endif
static const PictureObject FontSize16_0x6C =
{
    PICTYPE_BITS,
    4,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x6C
#else
    data_FontSize16_0x6C
#endif
};
//-------------------------------------------------------
// Character: "m"/0x6D, Width: 16, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x6D[] GUI_RESOURCE_ATTRIBUTES =
{
    0xF0,0x1F,0xF0,0x1F,0x20,0x00,0x10,0x00,0x10,0x00,0x10,0x00,0xF0,0x1F,0xE0,0x1F,
    0x20,0x00,0x10,0x00,0x10,0x00,0x10,0x00,0xF0,0x1F,0xE0,0x1F,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x6D =
{
    font16_lut,
    data_FontSize16_0x6D
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x6D =
{
    2,
    font16_lut,
    data_FontSize16_0x6D
};
#endif
#endif
static const PictureObject FontSize16_0x6D =
{
    PICTYPE_BITS,
    16,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x6D
#else
    data_FontSize16_0x6D
#endif
};
//-------------------------------------------------------
// Character: "n"/0x6E, Width: 11, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x6E[] GUI_RESOURCE_ATTRIBUTES =
{
    0xF0,0x1F,0xF0,0x1F,0x20,0x00,0x10,0x00,0x10,0x00,0x10,0x00,0x30,0x00,0xE0,0x1F,
    0xC0,0x1F,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x6E =
{
    font16_lut,
    data_FontSize16_0x6E
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x6E =
{
    2,
    font16_lut,
    data_FontSize16_0x6E
};
#endif
#endif
static const PictureObject FontSize16_0x6E =
{
    PICTYPE_BITS,
    11,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x6E
#else
    data_FontSize16_0x6E
#endif
};
//-------------------------------------------------------
// Character: "o"/0x6F, Width: 11, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x6F[] GUI_RESOURCE_ATTRIBUTES =
{
    0xC0,0x07,0xE0,0x0F,0x30,0x18,0x10,0x10,0x10,0x10,0x10,0x10,0x30,0x18,0xE0,0x0F,
    0xC0,0x07,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x6F =
{
    font16_lut,
    data_FontSize16_0x6F
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x6F =
{
    2,
    font16_lut,
    data_FontSize16_0x6F
};
#endif
#endif
static const PictureObject FontSize16_0x6F =
{
    PICTYPE_BITS,
    11,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x6F
#else
    data_FontSize16_0x6F
#endif
};
//-------------------------------------------------------
// Character: "p"/0x70, Width: 11, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x70[] GUI_RESOURCE_ATTRIBUTES =
{
    0xF0,0xFF,0xF0,0xFF,0x20,0x08,0x10,0x10,0x10,0x10,0x10,0x10,0x30,0x18,0xE0,0x0F,
    0xC0,0x07,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x70 =
{
    font16_lut,
    data_FontSize16_0x70
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x70 =
{
    2,
    font16_lut,
    data_FontSize16_0x70
};
#endif
#endif
static const PictureObject FontSize16_0x70 =
{
    PICTYPE_BITS,
    11,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x70
#else
    data_FontSize16_0x70
#endif
};
//-------------------------------------------------------
// Character: "q"/0x71, Width: 11, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x71[] GUI_RESOURCE_ATTRIBUTES =
{
    0xC0,0x07,0xE0,0x0F,0x30,0x18,0x10,0x10,0x10,0x10,0x10,0x10,0x20,0x08,0xF0,0xFF,
    0xF0,0xFF,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x71 =
{
    font16_lut,
    data_FontSize16_0x71
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x71 =
{
    2,
    font16_lut,
    data_FontSize16_0x71
};
#endif
#endif
static const PictureObject FontSize16_0x71 =
{
    PICTYPE_BITS,
    11,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x71
#else
    data_FontSize16_0x71
#endif
};
//-------------------------------------------------------
// Character: "r"/0x72, Width: 9, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x72[] GUI_RESOURCE_ATTRIBUTES =
{
    0xF0,0x1F,0xF0,0x1F,0x40,0x00,0x20,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x00,0x00,
    0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x72 =
{
    font16_lut,
    data_FontSize16_0x72
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x72 =
{
    2,
    font16_lut,
    data_FontSize16_0x72
};
#endif
#endif
static const PictureObject FontSize16_0x72 =
{
    PICTYPE_BITS,
    9,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x72
#else
    data_FontSize16_0x72
#endif
};
//-------------------------------------------------------
// Character: "s"/0x73, Width: 9, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x73[] GUI_RESOURCE_ATTRIBUTES =
{
    0xE0,0x08,0xF0,0x19,0x90,0x11,0x90,0x13,0x10,0x13,0x30,0x1F,0x20,0x0E,0x00,0x00,
    0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x73 =
{
    font16_lut,
    data_FontSize16_0x73
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x73 =
{
    2,
    font16_lut,
    data_FontSize16_0x73
};
#endif
#endif
static const PictureObject FontSize16_0x73 =
{
    PICTYPE_BITS,
    9,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x73
#else
    data_FontSize16_0x73
#endif
};
//-------------------------------------------------------
// Character: "t"/0x74, Width: 8, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x74[] GUI_RESOURCE_ATTRIBUTES =
{
    0x10,0x00,0xFC,0x0F,0xFC,0x1F,0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x74 =
{
    font16_lut,
    data_FontSize16_0x74
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x74 =
{
    2,
    font16_lut,
    data_FontSize16_0x74
};
#endif
#endif
static const PictureObject FontSize16_0x74 =
{
    PICTYPE_BITS,
    8,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x74
#else
    data_FontSize16_0x74
#endif
};
//-------------------------------------------------------
// Character: "u"/0x75, Width: 11, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x75[] GUI_RESOURCE_ATTRIBUTES =
{
    0xF0,0x07,0xF0,0x0F,0x00,0x18,0x00,0x10,0x00,0x10,0x00,0x10,0x00,0x08,0xF0,0x1F,
    0xF0,0x1F,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x75 =
{
    font16_lut,
    data_FontSize16_0x75
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x75 =
{
    2,
    font16_lut,
    data_FontSize16_0x75
};
#endif
#endif
static const PictureObject FontSize16_0x75 =
{
    PICTYPE_BITS,
    11,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x75
#else
    data_FontSize16_0x75
#endif
};
//-------------------------------------------------------
// Character: "v"/0x76, Width: 12, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x76[] GUI_RESOURCE_ATTRIBUTES =
{
    0x30,0x00,0xF0,0x00,0xC0,0x03,0x00,0x0F,0x00,0x1C,0x00,0x1C,0x00,0x0F,0xC0,0x03,
    0xF0,0x00,0x30,0x00,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x76 =
{
    font16_lut,
    data_FontSize16_0x76
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x76 =
{
    2,
    font16_lut,
    data_FontSize16_0x76
};
#endif
#endif
static const PictureObject FontSize16_0x76 =
{
    PICTYPE_BITS,
    12,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x76
#else
    data_FontSize16_0x76
#endif
};
//-------------------------------------------------------
// Character: "w"/0x77, Width: 16, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x77[] GUI_RESOURCE_ATTRIBUTES =
{
    0x30,0x00,0xF0,0x01,0xC0,0x07,0x00,0x1E,0x00,0x1E,0x80,0x07,0xF0,0x00,0xF0,0x00,
    0x80,0x07,0x00,0x1E,0x00,0x1E,0xC0,0x07,0xF0,0x01,0x30,0x00,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x77 =
{
    font16_lut,
    data_FontSize16_0x77
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x77 =
{
    2,
    font16_lut,
    data_FontSize16_0x77
};
#endif
#endif
static const PictureObject FontSize16_0x77 =
{
    PICTYPE_BITS,
    16,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x77
#else
    data_FontSize16_0x77
#endif
};
//-------------------------------------------------------
// Character: "x"/0x78, Width: 11, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x78[] GUI_RESOURCE_ATTRIBUTES =
{
    0x10,0x10,0x70,0x1C,0xE0,0x0E,0x80,0x03,0x00,0x01,0x80,0x03,0xE0,0x0E,0x70,0x1C,
    0x10,0x10,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x78 =
{
    font16_lut,
    data_FontSize16_0x78
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x78 =
{
    2,
    font16_lut,
    data_FontSize16_0x78
};
#endif
#endif
static const PictureObject FontSize16_0x78 =
{
    PICTYPE_BITS,
    11,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x78
#else
    data_FontSize16_0x78
#endif
};
//-------------------------------------------------------
// Character: "y"/0x79, Width: 12, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x79[] GUI_RESOURCE_ATTRIBUTES =
{
    0x30,0x00,0xF0,0x00,0xC0,0x03,0x00,0xCF,0x00,0xFC,0x00,0x3C,0x00,0x0F,0xC0,0x03,
    0xF0,0x00,0x30,0x00,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x79 =
{
    font16_lut,
    data_FontSize16_0x79
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x79 =
{
    2,
    font16_lut,
    data_FontSize16_0x79
};
#endif
#endif
static const PictureObject FontSize16_0x79 =
{
    PICTYPE_BITS,
    12,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x79
#else
    data_FontSize16_0x79
#endif
};
//-------------------------------------------------------
// Character: "z"/0x7A, Width: 10, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x7A[] GUI_RESOURCE_ATTRIBUTES =
{
    0x10,0x18,0x10,0x1C,0x10,0x16,0x10,0x13,0x90,0x11,0xD0,0x10,0x70,0x10,0x30,0x10,
    0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x7A =
{
    font16_lut,
    data_FontSize16_0x7A
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x7A =
{
    2,
    font16_lut,
    data_FontSize16_0x7A
};
#endif
#endif
static const PictureObject FontSize16_0x7A =
{
    PICTYPE_BITS,
    10,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x7A
#else
    data_FontSize16_0x7A
#endif
};
//-------------------------------------------------------
// Character: "{"/0x7B, Width: 10, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x7B[] GUI_RESOURCE_ATTRIBUTES =
{
    0x80,0x00,0x80,0x00,0xC0,0x01,0x7E,0x7F,0x3F,0xFE,0x01,0x80,0x01,0x80,0x01,0x80,
    0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x7B =
{
    font16_lut,
    data_FontSize16_0x7B
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x7B =
{
    2,
    font16_lut,
    data_FontSize16_0x7B
};
#endif
#endif
static const PictureObject FontSize16_0x7B =
{
    PICTYPE_BITS,
    10,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x7B
#else
    data_FontSize16_0x7B
#endif
};
//-------------------------------------------------------
// Character: "|"/0x7C, Width: 4, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x7C[] GUI_RESOURCE_ATTRIBUTES =
{
    0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x7C =
{
    font16_lut,
    data_FontSize16_0x7C
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x7C =
{
    2,
    font16_lut,
    data_FontSize16_0x7C
};
#endif
#endif
static const PictureObject FontSize16_0x7C =
{
    PICTYPE_BITS,
    4,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x7C
#else
    data_FontSize16_0x7C
#endif
};
//-------------------------------------------------------
// Character: "}"/0x7D, Width: 10, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x7D[] GUI_RESOURCE_ATTRIBUTES =
{
    0x01,0x80,0x01,0x80,0x01,0x80,0x3F,0xFE,0x7E,0x7F,0xC0,0x01,0x80,0x00,0x80,0x00,
    0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x7D =
{
    font16_lut,
    data_FontSize16_0x7D
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x7D =
{
    2,
    font16_lut,
    data_FontSize16_0x7D
};
#endif
#endif
static const PictureObject FontSize16_0x7D =
{
    PICTYPE_BITS,
    10,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x7D
#else
    data_FontSize16_0x7D
#endif
};
//-------------------------------------------------------
// Character: "~"/0x7E, Width: 13, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x7E[] GUI_RESOURCE_ATTRIBUTES =
{
    0x80,0x03,0x40,0x00,0x20,0x00,0x20,0x00,0x40,0x00,0x80,0x00,0x00,0x01,0x00,0x02,
    0x00,0x02,0x00,0x01,0xE0,0x00,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x7E =
{
    font16_lut,
    data_FontSize16_0x7E
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x7E =
{
    2,
    font16_lut,
    data_FontSize16_0x7E
};
#endif
#endif
static const PictureObject FontSize16_0x7E =
{
    PICTYPE_BITS,
    13,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x7E
#else
    data_FontSize16_0x7E
#endif
};
//-------------------------------------------------------
// Character: ""/0x7F, Width: 17, Height: 16
//-------------------------------------------------------
static const uint8_t data_FontSize16_0x7F[] GUI_RESOURCE_ATTRIBUTES =
{
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize16_0x7F =
{
    font16_lut,
    data_FontSize16_0x7F
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize16_0x7F =
{
    2,
    font16_lut,
    data_FontSize16_0x7F
};
#endif
#endif
static const PictureObject FontSize16_0x7F =
{
    PICTYPE_BITS,
    17,
    16,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize16_0x7F
#else
    data_FontSize16_0x7F
#endif
};
//-------------------------------------------------------
//
//-------------------------------------------------------
const PictureObject * const font16[] =
{
    &FontSize16_0x20,
    &FontSize16_0x21,
    &FontSize16_0x22,
    &FontSize16_0x23,
    &FontSize16_0x24,
    &FontSize16_0x25,
    &FontSize16_0x26,
    &FontSize16_0x27,
    &FontSize16_0x28,
    &FontSize16_0x29,
    &FontSize16_0x2A,
    &FontSize16_0x2B,
    &FontSize16_0x2C,
    &FontSize16_0x2D,
    &FontSize16_0x2E,
    &FontSize16_0x2F,
    &FontSize16_0x30,
    &FontSize16_0x31,
    &FontSize16_0x32,
    &FontSize16_0x33,
    &FontSize16_0x34,
    &FontSize16_0x35,
    &FontSize16_0x36,
    &FontSize16_0x37,
    &FontSize16_0x38,
    &FontSize16_0x39,
    &FontSize16_0x3A,
    &FontSize16_0x3B,
    &FontSize16_0x3C,
    &FontSize16_0x3D,
    &FontSize16_0x3E,
    &FontSize16_0x3F,
    &FontSize16_0x40,
    &FontSize16_0x41,
    &FontSize16_0x42,
    &FontSize16_0x43,
    &FontSize16_0x44,
    &FontSize16_0x45,
    &FontSize16_0x46,
    &FontSize16_0x47,
    &FontSize16_0x48,
    &FontSize16_0x49,
    &FontSize16_0x4A,
    &FontSize16_0x4B,
    &FontSize16_0x4C,
    &FontSize16_0x4D,
    &FontSize16_0x4E,
    &FontSize16_0x4F,
    &FontSize16_0x50,
    &FontSize16_0x51,
    &FontSize16_0x52,
    &FontSize16_0x53,
    &FontSize16_0x54,
    &FontSize16_0x55,
    &FontSize16_0x56,
    &FontSize16_0x57,
    &FontSize16_0x58,
    &FontSize16_0x59,
    &FontSize16_0x5A,
    &FontSize16_0x5B,
    &FontSize16_0x5C,
    &FontSize16_0x5D,
    &FontSize16_0x5E,
    &FontSize16_0x5F,
    &FontSize16_0x60,
    &FontSize16_0x61,
    &FontSize16_0x62,
    &FontSize16_0x63,
    &FontSize16_0x64,
    &FontSize16_0x65,
    &FontSize16_0x66,
    &FontSize16_0x67,
    &FontSize16_0x68,
    &FontSize16_0x69,
    &FontSize16_0x6A,
    &FontSize16_0x6B,
    &FontSize16_0x6C,
    &FontSize16_0x6D,
    &FontSize16_0x6E,
    &FontSize16_0x6F,
    &FontSize16_0x70,
    &FontSize16_0x71,
    &FontSize16_0x72,
    &FontSize16_0x73,
    &FontSize16_0x74,
    &FontSize16_0x75,
    &FontSize16_0x76,
    &FontSize16_0x77,
    &FontSize16_0x78,
    &FontSize16_0x79,
    &FontSize16_0x7A,
    &FontSize16_0x7B,
    &FontSize16_0x7C,
    &FontSize16_0x7D,
    &FontSize16_0x7E,
    &FontSize16_0x7F,
    
};

