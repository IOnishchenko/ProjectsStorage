
#include "stdint.h"
#include "attributes.h"
#include "gui_resource_types.h"

#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
//-------------------------------------------------------
// Contains alpha values
//-------------------------------------------------------
const uint8_t font12_lut[] GUI_RESOURCE_ATTRIBUTES =
{
    0x0000,0x0001
};
#endif
//-------------------------------------------------------
// Character: " "/0x20, Width: 5, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x20[] GUI_RESOURCE_ATTRIBUTES =
{
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x20 =
{
    font12_lut,
    data_FontSize12_0x20
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x20 =
{
    2,
    font12_lut,
    data_FontSize12_0x20
};
#endif
#endif
static const PictureObject FontSize12_0x20 =
{
    PICTYPE_BITS,
    5,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x20
#else
    data_FontSize12_0x20
#endif
};
//-------------------------------------------------------
// Character: "!"/0x21, Width: 2, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x21[] GUI_RESOURCE_ATTRIBUTES =
{
    0xFE,0x02,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x21 =
{
    font12_lut,
    data_FontSize12_0x21
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x21 =
{
    2,
    font12_lut,
    data_FontSize12_0x21
};
#endif
#endif
static const PictureObject FontSize12_0x21 =
{
    PICTYPE_BITS,
    2,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x21
#else
    data_FontSize12_0x21
#endif
};
//-------------------------------------------------------
// Character: """/0x22, Width: 5, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x22[] GUI_RESOURCE_ATTRIBUTES =
{
    0x07,0x00,0x00,0x00,0x70,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x22 =
{
    font12_lut,
    data_FontSize12_0x22
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x22 =
{
    2,
    font12_lut,
    data_FontSize12_0x22
};
#endif
#endif
static const PictureObject FontSize12_0x22 =
{
    PICTYPE_BITS,
    5,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x22
#else
    data_FontSize12_0x22
#endif
};
//-------------------------------------------------------
// Character: "#"/0x23, Width: 9, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x23[] GUI_RESOURCE_ATTRIBUTES =
{
    0x80,0x00,0x39,0xF8,0x60,0x09,0x90,0x83,0x0F,0x96,0x00,0x01,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x23 =
{
    font12_lut,
    data_FontSize12_0x23
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x23 =
{
    2,
    font12_lut,
    data_FontSize12_0x23
};
#endif
#endif
static const PictureObject FontSize12_0x23 =
{
    PICTYPE_BITS,
    9,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x23
#else
    data_FontSize12_0x23
#endif
};
//-------------------------------------------------------
// Character: "$"/0x24, Width: 7, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x24[] GUI_RESOURCE_ATTRIBUTES =
{
    0x18,0x42,0x22,0xFF,0x4F,0x24,0x44,0x42,0x18,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x24 =
{
    font12_lut,
    data_FontSize12_0x24
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x24 =
{
    2,
    font12_lut,
    data_FontSize12_0x24
};
#endif
#endif
static const PictureObject FontSize12_0x24 =
{
    PICTYPE_BITS,
    7,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x24
#else
    data_FontSize12_0x24
#endif
};
//-------------------------------------------------------
// Character: "%"/0x25, Width: 12, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x25[] GUI_RESOURCE_ATTRIBUTES =
{
    0x1C,0x20,0x02,0x22,0xC0,0x21,0x80,0x01,0x07,0x0C,0x20,0x1C,0x20,0x02,0x22,0xC0,
    0x01,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x25 =
{
    font12_lut,
    data_FontSize12_0x25
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x25 =
{
    2,
    font12_lut,
    data_FontSize12_0x25
};
#endif
#endif
static const PictureObject FontSize12_0x25 =
{
    PICTYPE_BITS,
    12,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x25
#else
    data_FontSize12_0x25
#endif
};
//-------------------------------------------------------
// Character: "&"/0x26, Width: 9, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x26[] GUI_RESOURCE_ATTRIBUTES =
{
    0xDC,0x21,0x22,0x22,0x22,0x22,0x5C,0x02,0x18,0x60,0x01,0x20,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x26 =
{
    font12_lut,
    data_FontSize12_0x26
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x26 =
{
    2,
    font12_lut,
    data_FontSize12_0x26
};
#endif
#endif
static const PictureObject FontSize12_0x26 =
{
    PICTYPE_BITS,
    9,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x26
#else
    data_FontSize12_0x26
#endif
};
//-------------------------------------------------------
// Character: "'"/0x27, Width: 2, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x27[] GUI_RESOURCE_ATTRIBUTES =
{
    0x07,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x27 =
{
    font12_lut,
    data_FontSize12_0x27
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x27 =
{
    2,
    font12_lut,
    data_FontSize12_0x27
};
#endif
#endif
static const PictureObject FontSize12_0x27 =
{
    PICTYPE_BITS,
    2,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x27
#else
    data_FontSize12_0x27
#endif
};
//-------------------------------------------------------
// Character: "("/0x28, Width: 4, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x28[] GUI_RESOURCE_ATTRIBUTES =
{
    0xF8,0x61,0x60,0x01,0x08,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x28 =
{
    font12_lut,
    data_FontSize12_0x28
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x28 =
{
    2,
    font12_lut,
    data_FontSize12_0x28
};
#endif
#endif
static const PictureObject FontSize12_0x28 =
{
    PICTYPE_BITS,
    4,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x28
#else
    data_FontSize12_0x28
#endif
};
//-------------------------------------------------------
// Character: ")"/0x29, Width: 4, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x29[] GUI_RESOURCE_ATTRIBUTES =
{
    0x01,0x68,0x60,0xF8,0x01,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x29 =
{
    font12_lut,
    data_FontSize12_0x29
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x29 =
{
    2,
    font12_lut,
    data_FontSize12_0x29
};
#endif
#endif
static const PictureObject FontSize12_0x29 =
{
    PICTYPE_BITS,
    4,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x29
#else
    data_FontSize12_0x29
#endif
};
//-------------------------------------------------------
// Character: "*"/0x2A, Width: 6, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x2A[] GUI_RESOURCE_ATTRIBUTES =
{
    0x0A,0x40,0x00,0x1F,0x40,0x00,0x0A,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x2A =
{
    font12_lut,
    data_FontSize12_0x2A
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x2A =
{
    2,
    font12_lut,
    data_FontSize12_0x2A
};
#endif
#endif
static const PictureObject FontSize12_0x2A =
{
    PICTYPE_BITS,
    6,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x2A
#else
    data_FontSize12_0x2A
#endif
};
//-------------------------------------------------------
// Character: "+"/0x2B, Width: 8, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x2B[] GUI_RESOURCE_ATTRIBUTES =
{
    0x40,0x00,0x04,0x40,0x80,0x3F,0x40,0x00,0x04,0x40,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x2B =
{
    font12_lut,
    data_FontSize12_0x2B
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x2B =
{
    2,
    font12_lut,
    data_FontSize12_0x2B
};
#endif
#endif
static const PictureObject FontSize12_0x2B =
{
    PICTYPE_BITS,
    8,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x2B
#else
    data_FontSize12_0x2B
#endif
};
//-------------------------------------------------------
// Character: ","/0x2C, Width: 3, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x2C[] GUI_RESOURCE_ATTRIBUTES =
{
    0x00,0x08,0x70,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x2C =
{
    font12_lut,
    data_FontSize12_0x2C
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x2C =
{
    2,
    font12_lut,
    data_FontSize12_0x2C
};
#endif
#endif
static const PictureObject FontSize12_0x2C =
{
    PICTYPE_BITS,
    3,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x2C
#else
    data_FontSize12_0x2C
#endif
};
//-------------------------------------------------------
// Character: "-"/0x2D, Width: 5, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x2D[] GUI_RESOURCE_ATTRIBUTES =
{
    0x40,0x00,0x04,0x40,0x00,0x04,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x2D =
{
    font12_lut,
    data_FontSize12_0x2D
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x2D =
{
    2,
    font12_lut,
    data_FontSize12_0x2D
};
#endif
#endif
static const PictureObject FontSize12_0x2D =
{
    PICTYPE_BITS,
    5,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x2D
#else
    data_FontSize12_0x2D
#endif
};
//-------------------------------------------------------
// Character: "."/0x2E, Width: 2, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x2E[] GUI_RESOURCE_ATTRIBUTES =
{
    0x00,0x03,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x2E =
{
    font12_lut,
    data_FontSize12_0x2E
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x2E =
{
    2,
    font12_lut,
    data_FontSize12_0x2E
};
#endif
#endif
static const PictureObject FontSize12_0x2E =
{
    PICTYPE_BITS,
    2,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x2E
#else
    data_FontSize12_0x2E
#endif
};
//-------------------------------------------------------
// Character: "/"/0x2F, Width: 6, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x2F[] GUI_RESOURCE_ATTRIBUTES =
{
    0x00,0x08,0x70,0xE0,0xC0,0x01,0x03,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x2F =
{
    font12_lut,
    data_FontSize12_0x2F
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x2F =
{
    2,
    font12_lut,
    data_FontSize12_0x2F
};
#endif
#endif
static const PictureObject FontSize12_0x2F =
{
    PICTYPE_BITS,
    6,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x2F
#else
    data_FontSize12_0x2F
#endif
};
//-------------------------------------------------------
// Character: "0"/0x30, Width: 7, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x30[] GUI_RESOURCE_ATTRIBUTES =
{
    0xFC,0x21,0x20,0x02,0x22,0x20,0x02,0xC2,0x1F,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x30 =
{
    font12_lut,
    data_FontSize12_0x30
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x30 =
{
    2,
    font12_lut,
    data_FontSize12_0x30
};
#endif
#endif
static const PictureObject FontSize12_0x30 =
{
    PICTYPE_BITS,
    7,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x30
#else
    data_FontSize12_0x30
#endif
};
//-------------------------------------------------------
// Character: "1"/0x31, Width: 6, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x31[] GUI_RESOURCE_ATTRIBUTES =
{
    0x04,0x42,0x20,0xFE,0x03,0x20,0x00,0x02,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x31 =
{
    font12_lut,
    data_FontSize12_0x31
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x31 =
{
    2,
    font12_lut,
    data_FontSize12_0x31
};
#endif
#endif
static const PictureObject FontSize12_0x31 =
{
    PICTYPE_BITS,
    6,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x31
#else
    data_FontSize12_0x31
#endif
};
//-------------------------------------------------------
// Character: "2"/0x32, Width: 7, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x32[] GUI_RESOURCE_ATTRIBUTES =
{
    0x0C,0x23,0x28,0x42,0x22,0x24,0x22,0xC2,0x21,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x32 =
{
    font12_lut,
    data_FontSize12_0x32
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x32 =
{
    2,
    font12_lut,
    data_FontSize12_0x32
};
#endif
#endif
static const PictureObject FontSize12_0x32 =
{
    PICTYPE_BITS,
    7,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x32
#else
    data_FontSize12_0x32
#endif
};
//-------------------------------------------------------
// Character: "3"/0x33, Width: 7, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x33[] GUI_RESOURCE_ATTRIBUTES =
{
    0x04,0x21,0x20,0x22,0x22,0x22,0x22,0xC2,0x1D,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x33 =
{
    font12_lut,
    data_FontSize12_0x33
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x33 =
{
    2,
    font12_lut,
    data_FontSize12_0x33
};
#endif
#endif
static const PictureObject FontSize12_0x33 =
{
    PICTYPE_BITS,
    7,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x33
#else
    data_FontSize12_0x33
#endif
};
//-------------------------------------------------------
// Character: "4"/0x34, Width: 8, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x34[] GUI_RESOURCE_ATTRIBUTES =
{
    0x60,0x00,0x05,0x48,0x40,0x04,0xFE,0x03,0x04,0x40,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x34 =
{
    font12_lut,
    data_FontSize12_0x34
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x34 =
{
    2,
    font12_lut,
    data_FontSize12_0x34
};
#endif
#endif
static const PictureObject FontSize12_0x34 =
{
    PICTYPE_BITS,
    8,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x34
#else
    data_FontSize12_0x34
#endif
};
//-------------------------------------------------------
// Character: "5"/0x35, Width: 7, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x35[] GUI_RESOURCE_ATTRIBUTES =
{
    0x1E,0x21,0x21,0x12,0x22,0x21,0x12,0x22,0x1E,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x35 =
{
    font12_lut,
    data_FontSize12_0x35
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x35 =
{
    2,
    font12_lut,
    data_FontSize12_0x35
};
#endif
#endif
static const PictureObject FontSize12_0x35 =
{
    PICTYPE_BITS,
    7,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x35
#else
    data_FontSize12_0x35
#endif
};
//-------------------------------------------------------
// Character: "6"/0x36, Width: 7, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x36[] GUI_RESOURCE_ATTRIBUTES =
{
    0xF8,0x41,0x21,0x12,0x22,0x21,0x12,0x02,0x1E,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x36 =
{
    font12_lut,
    data_FontSize12_0x36
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x36 =
{
    2,
    font12_lut,
    data_FontSize12_0x36
};
#endif
#endif
static const PictureObject FontSize12_0x36 =
{
    PICTYPE_BITS,
    7,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x36
#else
    data_FontSize12_0x36
#endif
};
//-------------------------------------------------------
// Character: "7"/0x37, Width: 7, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x37[] GUI_RESOURCE_ATTRIBUTES =
{
    0x02,0x20,0x20,0x82,0x21,0x06,0x1A,0x60,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x37 =
{
    font12_lut,
    data_FontSize12_0x37
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x37 =
{
    2,
    font12_lut,
    data_FontSize12_0x37
};
#endif
#endif
static const PictureObject FontSize12_0x37 =
{
    PICTYPE_BITS,
    7,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x37
#else
    data_FontSize12_0x37
#endif
};
//-------------------------------------------------------
// Character: "8"/0x38, Width: 7, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x38[] GUI_RESOURCE_ATTRIBUTES =
{
    0xDC,0x21,0x22,0x22,0x22,0x22,0x22,0xC2,0x1D,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x38 =
{
    font12_lut,
    data_FontSize12_0x38
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x38 =
{
    2,
    font12_lut,
    data_FontSize12_0x38
};
#endif
#endif
static const PictureObject FontSize12_0x38 =
{
    PICTYPE_BITS,
    7,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x38
#else
    data_FontSize12_0x38
#endif
};
//-------------------------------------------------------
// Character: "9"/0x39, Width: 7, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x39[] GUI_RESOURCE_ATTRIBUTES =
{
    0x3C,0x20,0x24,0x42,0x22,0x24,0x42,0xC1,0x0F,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x39 =
{
    font12_lut,
    data_FontSize12_0x39
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x39 =
{
    2,
    font12_lut,
    data_FontSize12_0x39
};
#endif
#endif
static const PictureObject FontSize12_0x39 =
{
    PICTYPE_BITS,
    7,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x39
#else
    data_FontSize12_0x39
#endif
};
//-------------------------------------------------------
// Character: ":"/0x3A, Width: 2, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x3A[] GUI_RESOURCE_ATTRIBUTES =
{
    0x18,0x03,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x3A =
{
    font12_lut,
    data_FontSize12_0x3A
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x3A =
{
    2,
    font12_lut,
    data_FontSize12_0x3A
};
#endif
#endif
static const PictureObject FontSize12_0x3A =
{
    PICTYPE_BITS,
    2,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x3A
#else
    data_FontSize12_0x3A
#endif
};
//-------------------------------------------------------
// Character: ";"/0x3B, Width: 3, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x3B[] GUI_RESOURCE_ATTRIBUTES =
{
    0x00,0x88,0x71,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x3B =
{
    font12_lut,
    data_FontSize12_0x3B
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x3B =
{
    2,
    font12_lut,
    data_FontSize12_0x3B
};
#endif
#endif
static const PictureObject FontSize12_0x3B =
{
    PICTYPE_BITS,
    3,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x3B
#else
    data_FontSize12_0x3B
#endif
};
//-------------------------------------------------------
// Character: "<"/0x3C, Width: 8, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x3C[] GUI_RESOURCE_ATTRIBUTES =
{
    0x40,0x00,0x0A,0xA0,0x00,0x11,0x10,0x81,0x20,0x08,0x02,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x3C =
{
    font12_lut,
    data_FontSize12_0x3C
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x3C =
{
    2,
    font12_lut,
    data_FontSize12_0x3C
};
#endif
#endif
static const PictureObject FontSize12_0x3C =
{
    PICTYPE_BITS,
    8,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x3C
#else
    data_FontSize12_0x3C
#endif
};
//-------------------------------------------------------
// Character: "="/0x3D, Width: 8, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x3D[] GUI_RESOURCE_ATTRIBUTES =
{
    0x50,0x00,0x05,0x50,0x00,0x05,0x50,0x00,0x05,0x50,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x3D =
{
    font12_lut,
    data_FontSize12_0x3D
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x3D =
{
    2,
    font12_lut,
    data_FontSize12_0x3D
};
#endif
#endif
static const PictureObject FontSize12_0x3D =
{
    PICTYPE_BITS,
    8,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x3D
#else
    data_FontSize12_0x3D
#endif
};
//-------------------------------------------------------
// Character: ">"/0x3E, Width: 8, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x3E[] GUI_RESOURCE_ATTRIBUTES =
{
    0x08,0x82,0x20,0x10,0x01,0x11,0xA0,0x00,0x0A,0x40,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x3E =
{
    font12_lut,
    data_FontSize12_0x3E
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x3E =
{
    2,
    font12_lut,
    data_FontSize12_0x3E
};
#endif
#endif
static const PictureObject FontSize12_0x3E =
{
    PICTYPE_BITS,
    8,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x3E
#else
    data_FontSize12_0x3E
#endif
};
//-------------------------------------------------------
// Character: "?"/0x3F, Width: 6, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x3F[] GUI_RESOURCE_ATTRIBUTES =
{
    0x04,0x20,0x00,0xC2,0x22,0x02,0x1C,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x3F =
{
    font12_lut,
    data_FontSize12_0x3F
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x3F =
{
    2,
    font12_lut,
    data_FontSize12_0x3F
};
#endif
#endif
static const PictureObject FontSize12_0x3F =
{
    PICTYPE_BITS,
    6,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x3F
#else
    data_FontSize12_0x3F
#endif
};
//-------------------------------------------------------
// Character: "@"/0x40, Width: 11, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x40[] GUI_RESOURCE_ATTRIBUTES =
{
    0xF0,0xC0,0x30,0x04,0x22,0x4F,0x0A,0xA5,0x50,0xFA,0x45,0x10,0x0C,0x01,0x0F,0x00,
    0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x40 =
{
    font12_lut,
    data_FontSize12_0x40
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x40 =
{
    2,
    font12_lut,
    data_FontSize12_0x40
};
#endif
#endif
static const PictureObject FontSize12_0x40 =
{
    PICTYPE_BITS,
    11,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x40
#else
    data_FontSize12_0x40
#endif
};
//-------------------------------------------------------
// Character: "A"/0x41, Width: 9, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x41[] GUI_RESOURCE_ATTRIBUTES =
{
    0x00,0x03,0x0E,0x98,0x60,0x08,0x86,0x80,0x09,0xE0,0x00,0x30,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x41 =
{
    font12_lut,
    data_FontSize12_0x41
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x41 =
{
    2,
    font12_lut,
    data_FontSize12_0x41
};
#endif
#endif
static const PictureObject FontSize12_0x41 =
{
    PICTYPE_BITS,
    9,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x41
#else
    data_FontSize12_0x41
#endif
};
//-------------------------------------------------------
// Character: "B"/0x42, Width: 7, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x42[] GUI_RESOURCE_ATTRIBUTES =
{
    0xFE,0x23,0x22,0x22,0x22,0x22,0x3C,0x02,0x1C,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x42 =
{
    font12_lut,
    data_FontSize12_0x42
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x42 =
{
    2,
    font12_lut,
    data_FontSize12_0x42
};
#endif
#endif
static const PictureObject FontSize12_0x42 =
{
    PICTYPE_BITS,
    7,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x42
#else
    data_FontSize12_0x42
#endif
};
//-------------------------------------------------------
// Character: "C"/0x43, Width: 8, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x43[] GUI_RESOURCE_ATTRIBUTES =
{
    0xF8,0x40,0x10,0x02,0x22,0x20,0x02,0x22,0x20,0x04,0x01,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x43 =
{
    font12_lut,
    data_FontSize12_0x43
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x43 =
{
    2,
    font12_lut,
    data_FontSize12_0x43
};
#endif
#endif
static const PictureObject FontSize12_0x43 =
{
    PICTYPE_BITS,
    8,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x43
#else
    data_FontSize12_0x43
#endif
};
//-------------------------------------------------------
// Character: "D"/0x44, Width: 8, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x44[] GUI_RESOURCE_ATTRIBUTES =
{
    0xFE,0x23,0x20,0x02,0x22,0x20,0x02,0x42,0x10,0xF8,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x44 =
{
    font12_lut,
    data_FontSize12_0x44
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x44 =
{
    2,
    font12_lut,
    data_FontSize12_0x44
};
#endif
#endif
static const PictureObject FontSize12_0x44 =
{
    PICTYPE_BITS,
    8,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x44
#else
    data_FontSize12_0x44
#endif
};
//-------------------------------------------------------
// Character: "E"/0x45, Width: 7, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x45[] GUI_RESOURCE_ATTRIBUTES =
{
    0xFE,0x23,0x22,0x22,0x22,0x22,0x22,0x22,0x22,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x45 =
{
    font12_lut,
    data_FontSize12_0x45
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x45 =
{
    2,
    font12_lut,
    data_FontSize12_0x45
};
#endif
#endif
static const PictureObject FontSize12_0x45 =
{
    PICTYPE_BITS,
    7,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x45
#else
    data_FontSize12_0x45
#endif
};
//-------------------------------------------------------
// Character: "F"/0x46, Width: 7, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x46[] GUI_RESOURCE_ATTRIBUTES =
{
    0xFE,0x23,0x02,0x22,0x20,0x02,0x22,0x20,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x46 =
{
    font12_lut,
    data_FontSize12_0x46
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x46 =
{
    2,
    font12_lut,
    data_FontSize12_0x46
};
#endif
#endif
static const PictureObject FontSize12_0x46 =
{
    PICTYPE_BITS,
    7,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x46
#else
    data_FontSize12_0x46
#endif
};
//-------------------------------------------------------
// Character: "G"/0x47, Width: 8, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x47[] GUI_RESOURCE_ATTRIBUTES =
{
    0xF8,0x40,0x10,0x02,0x22,0x20,0x22,0x22,0x22,0xE4,0x01,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x47 =
{
    font12_lut,
    data_FontSize12_0x47
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x47 =
{
    2,
    font12_lut,
    data_FontSize12_0x47
};
#endif
#endif
static const PictureObject FontSize12_0x47 =
{
    PICTYPE_BITS,
    8,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x47
#else
    data_FontSize12_0x47
#endif
};
//-------------------------------------------------------
// Character: "H"/0x48, Width: 8, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x48[] GUI_RESOURCE_ATTRIBUTES =
{
    0xFE,0x03,0x02,0x20,0x00,0x02,0x20,0x00,0x02,0xFE,0x03,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x48 =
{
    font12_lut,
    data_FontSize12_0x48
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x48 =
{
    2,
    font12_lut,
    data_FontSize12_0x48
};
#endif
#endif
static const PictureObject FontSize12_0x48 =
{
    PICTYPE_BITS,
    8,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x48
#else
    data_FontSize12_0x48
#endif
};
//-------------------------------------------------------
// Character: "I"/0x49, Width: 4, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x49[] GUI_RESOURCE_ATTRIBUTES =
{
    0x02,0xE2,0x3F,0x02,0x02,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x49 =
{
    font12_lut,
    data_FontSize12_0x49
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x49 =
{
    2,
    font12_lut,
    data_FontSize12_0x49
};
#endif
#endif
static const PictureObject FontSize12_0x49 =
{
    PICTYPE_BITS,
    4,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x49
#else
    data_FontSize12_0x49
#endif
};
//-------------------------------------------------------
// Character: "J"/0x4A, Width: 5, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x4A[] GUI_RESOURCE_ATTRIBUTES =
{
    0x00,0x22,0x20,0x02,0xE2,0x1F,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x4A =
{
    font12_lut,
    data_FontSize12_0x4A
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x4A =
{
    2,
    font12_lut,
    data_FontSize12_0x4A
};
#endif
#endif
static const PictureObject FontSize12_0x4A =
{
    PICTYPE_BITS,
    5,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x4A
#else
    data_FontSize12_0x4A
#endif
};
//-------------------------------------------------------
// Character: "K"/0x4B, Width: 7, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x4B[] GUI_RESOURCE_ATTRIBUTES =
{
    0xFE,0x03,0x02,0x50,0x80,0x08,0x04,0x21,0x20,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x4B =
{
    font12_lut,
    data_FontSize12_0x4B
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x4B =
{
    2,
    font12_lut,
    data_FontSize12_0x4B
};
#endif
#endif
static const PictureObject FontSize12_0x4B =
{
    PICTYPE_BITS,
    7,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x4B
#else
    data_FontSize12_0x4B
#endif
};
//-------------------------------------------------------
// Character: "L"/0x4C, Width: 7, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x4C[] GUI_RESOURCE_ATTRIBUTES =
{
    0xFE,0x03,0x20,0x00,0x02,0x20,0x00,0x02,0x20,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x4C =
{
    font12_lut,
    data_FontSize12_0x4C
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x4C =
{
    2,
    font12_lut,
    data_FontSize12_0x4C
};
#endif
#endif
static const PictureObject FontSize12_0x4C =
{
    PICTYPE_BITS,
    7,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x4C
#else
    data_FontSize12_0x4C
#endif
};
//-------------------------------------------------------
// Character: "M"/0x4D, Width: 9, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x4D[] GUI_RESOURCE_ATTRIBUTES =
{
    0xFE,0x63,0x00,0x38,0x00,0x0C,0xC0,0x80,0x03,0x06,0xE0,0x3F,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x4D =
{
    font12_lut,
    data_FontSize12_0x4D
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x4D =
{
    2,
    font12_lut,
    data_FontSize12_0x4D
};
#endif
#endif
static const PictureObject FontSize12_0x4D =
{
    PICTYPE_BITS,
    9,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x4D
#else
    data_FontSize12_0x4D
#endif
};
//-------------------------------------------------------
// Character: "N"/0x4E, Width: 8, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x4E[] GUI_RESOURCE_ATTRIBUTES =
{
    0xFE,0x63,0x00,0x18,0x00,0x02,0xC0,0x00,0x30,0xFE,0x03,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x4E =
{
    font12_lut,
    data_FontSize12_0x4E
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x4E =
{
    2,
    font12_lut,
    data_FontSize12_0x4E
};
#endif
#endif
static const PictureObject FontSize12_0x4E =
{
    PICTYPE_BITS,
    8,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x4E
#else
    data_FontSize12_0x4E
#endif
};
//-------------------------------------------------------
// Character: "O"/0x4F, Width: 9, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x4F[] GUI_RESOURCE_ATTRIBUTES =
{
    0xF8,0x40,0x10,0x02,0x22,0x20,0x02,0x22,0x20,0x04,0x81,0x0F,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x4F =
{
    font12_lut,
    data_FontSize12_0x4F
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x4F =
{
    2,
    font12_lut,
    data_FontSize12_0x4F
};
#endif
#endif
static const PictureObject FontSize12_0x4F =
{
    PICTYPE_BITS,
    9,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x4F
#else
    data_FontSize12_0x4F
#endif
};
//-------------------------------------------------------
// Character: "P"/0x50, Width: 7, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x50[] GUI_RESOURCE_ATTRIBUTES =
{
    0xFE,0x23,0x04,0x42,0x20,0x04,0x42,0xC0,0x03,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x50 =
{
    font12_lut,
    data_FontSize12_0x50
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x50 =
{
    2,
    font12_lut,
    data_FontSize12_0x50
};
#endif
#endif
static const PictureObject FontSize12_0x50 =
{
    PICTYPE_BITS,
    7,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x50
#else
    data_FontSize12_0x50
#endif
};
//-------------------------------------------------------
// Character: "Q"/0x51, Width: 9, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x51[] GUI_RESOURCE_ATTRIBUTES =
{
    0xF8,0x40,0x10,0x02,0x22,0x20,0x02,0x22,0x60,0x04,0x89,0x8F,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x51 =
{
    font12_lut,
    data_FontSize12_0x51
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x51 =
{
    2,
    font12_lut,
    data_FontSize12_0x51
};
#endif
#endif
static const PictureObject FontSize12_0x51 =
{
    PICTYPE_BITS,
    9,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x51
#else
    data_FontSize12_0x51
#endif
};
//-------------------------------------------------------
// Character: "R"/0x52, Width: 8, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x52[] GUI_RESOURCE_ATTRIBUTES =
{
    0xFE,0x23,0x02,0x22,0x20,0x06,0xA2,0xC0,0x11,0x00,0x02,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x52 =
{
    font12_lut,
    data_FontSize12_0x52
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x52 =
{
    2,
    font12_lut,
    data_FontSize12_0x52
};
#endif
#endif
static const PictureObject FontSize12_0x52 =
{
    PICTYPE_BITS,
    8,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x52
#else
    data_FontSize12_0x52
#endif
};
//-------------------------------------------------------
// Character: "S"/0x53, Width: 7, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x53[] GUI_RESOURCE_ATTRIBUTES =
{
    0x1C,0x21,0x22,0x22,0x22,0x22,0x22,0x42,0x1C,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x53 =
{
    font12_lut,
    data_FontSize12_0x53
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x53 =
{
    2,
    font12_lut,
    data_FontSize12_0x53
};
#endif
#endif
static const PictureObject FontSize12_0x53 =
{
    PICTYPE_BITS,
    7,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x53
#else
    data_FontSize12_0x53
#endif
};
//-------------------------------------------------------
// Character: "T"/0x54, Width: 8, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x54[] GUI_RESOURCE_ATTRIBUTES =
{
    0x02,0x20,0x00,0x02,0xE0,0x3F,0x02,0x20,0x00,0x02,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x54 =
{
    font12_lut,
    data_FontSize12_0x54
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x54 =
{
    2,
    font12_lut,
    data_FontSize12_0x54
};
#endif
#endif
static const PictureObject FontSize12_0x54 =
{
    PICTYPE_BITS,
    8,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x54
#else
    data_FontSize12_0x54
#endif
};
//-------------------------------------------------------
// Character: "U"/0x55, Width: 8, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x55[] GUI_RESOURCE_ATTRIBUTES =
{
    0xFE,0x00,0x10,0x00,0x02,0x20,0x00,0x02,0x10,0xFE,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x55 =
{
    font12_lut,
    data_FontSize12_0x55
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x55 =
{
    2,
    font12_lut,
    data_FontSize12_0x55
};
#endif
#endif
static const PictureObject FontSize12_0x55 =
{
    PICTYPE_BITS,
    8,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x55
#else
    data_FontSize12_0x55
#endif
};
//-------------------------------------------------------
// Character: "V"/0x56, Width: 9, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x56[] GUI_RESOURCE_ATTRIBUTES =
{
    0x06,0x80,0x03,0xC0,0x00,0x30,0x00,0x03,0x0C,0x38,0x60,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x56 =
{
    font12_lut,
    data_FontSize12_0x56
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x56 =
{
    2,
    font12_lut,
    data_FontSize12_0x56
};
#endif
#endif
static const PictureObject FontSize12_0x56 =
{
    PICTYPE_BITS,
    9,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x56
#else
    data_FontSize12_0x56
#endif
};
//-------------------------------------------------------
// Character: "W"/0x57, Width: 12, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x57[] GUI_RESOURCE_ATTRIBUTES =
{
    0x1E,0x00,0x0E,0x00,0x03,0x0C,0x38,0x60,0x00,0x38,0x00,0x0C,0x00,0x03,0x0E,0x1E,
    0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x57 =
{
    font12_lut,
    data_FontSize12_0x57
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x57 =
{
    2,
    font12_lut,
    data_FontSize12_0x57
};
#endif
#endif
static const PictureObject FontSize12_0x57 =
{
    PICTYPE_BITS,
    12,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x57
#else
    data_FontSize12_0x57
#endif
};
//-------------------------------------------------------
// Character: "X"/0x58, Width: 7, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x58[] GUI_RESOURCE_ATTRIBUTES =
{
    0x06,0x83,0x08,0x70,0x00,0x07,0x88,0x60,0x30,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x58 =
{
    font12_lut,
    data_FontSize12_0x58
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x58 =
{
    2,
    font12_lut,
    data_FontSize12_0x58
};
#endif
#endif
static const PictureObject FontSize12_0x58 =
{
    PICTYPE_BITS,
    7,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x58
#else
    data_FontSize12_0x58
#endif
};
//-------------------------------------------------------
// Character: "Y"/0x59, Width: 8, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x59[] GUI_RESOURCE_ATTRIBUTES =
{
    0x02,0xC0,0x00,0x10,0x00,0x3E,0x10,0xC0,0x00,0x02,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x59 =
{
    font12_lut,
    data_FontSize12_0x59
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x59 =
{
    2,
    font12_lut,
    data_FontSize12_0x59
};
#endif
#endif
static const PictureObject FontSize12_0x59 =
{
    PICTYPE_BITS,
    8,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x59
#else
    data_FontSize12_0x59
#endif
};
//-------------------------------------------------------
// Character: "Z"/0x5A, Width: 7, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x5A[] GUI_RESOURCE_ATTRIBUTES =
{
    0x02,0x23,0x28,0x62,0x22,0x21,0x0A,0x62,0x20,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x5A =
{
    font12_lut,
    data_FontSize12_0x5A
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x5A =
{
    2,
    font12_lut,
    data_FontSize12_0x5A
};
#endif
#endif
static const PictureObject FontSize12_0x5A =
{
    PICTYPE_BITS,
    7,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x5A
#else
    data_FontSize12_0x5A
#endif
};
//-------------------------------------------------------
// Character: "["/0x5B, Width: 4, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x5B[] GUI_RESOURCE_ATTRIBUTES =
{
    0xFF,0x1F,0x80,0x01,0x08,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x5B =
{
    font12_lut,
    data_FontSize12_0x5B
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x5B =
{
    2,
    font12_lut,
    data_FontSize12_0x5B
};
#endif
#endif
static const PictureObject FontSize12_0x5B =
{
    PICTYPE_BITS,
    4,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x5B
#else
    data_FontSize12_0x5B
#endif
};
//-------------------------------------------------------
// Character: "\"/0x5C, Width: 6, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x5C[] GUI_RESOURCE_ATTRIBUTES =
{
    0x03,0xC0,0x01,0x60,0x00,0x38,0x00,0x0C,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x5C =
{
    font12_lut,
    data_FontSize12_0x5C
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x5C =
{
    2,
    font12_lut,
    data_FontSize12_0x5C
};
#endif
#endif
static const PictureObject FontSize12_0x5C =
{
    PICTYPE_BITS,
    6,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x5C
#else
    data_FontSize12_0x5C
#endif
};
//-------------------------------------------------------
// Character: "]"/0x5D, Width: 4, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x5D[] GUI_RESOURCE_ATTRIBUTES =
{
    0x01,0x18,0x80,0xFF,0x0F,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x5D =
{
    font12_lut,
    data_FontSize12_0x5D
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x5D =
{
    2,
    font12_lut,
    data_FontSize12_0x5D
};
#endif
#endif
static const PictureObject FontSize12_0x5D =
{
    PICTYPE_BITS,
    4,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x5D
#else
    data_FontSize12_0x5D
#endif
};
//-------------------------------------------------------
// Character: "^"/0x5E, Width: 9, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x5E[] GUI_RESOURCE_ATTRIBUTES =
{
    0x10,0x80,0x00,0x04,0x20,0x00,0x02,0x40,0x00,0x08,0x00,0x01,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x5E =
{
    font12_lut,
    data_FontSize12_0x5E
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x5E =
{
    2,
    font12_lut,
    data_FontSize12_0x5E
};
#endif
#endif
static const PictureObject FontSize12_0x5E =
{
    PICTYPE_BITS,
    9,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x5E
#else
    data_FontSize12_0x5E
#endif
};
//-------------------------------------------------------
// Character: "_"/0x5F, Width: 9, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x5F[] GUI_RESOURCE_ATTRIBUTES =
{
    0x00,0x08,0x80,0x00,0x08,0x80,0x00,0x08,0x80,0x00,0x08,0x80,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x5F =
{
    font12_lut,
    data_FontSize12_0x5F
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x5F =
{
    2,
    font12_lut,
    data_FontSize12_0x5F
};
#endif
#endif
static const PictureObject FontSize12_0x5F =
{
    PICTYPE_BITS,
    9,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x5F
#else
    data_FontSize12_0x5F
#endif
};
//-------------------------------------------------------
// Character: "`"/0x60, Width: 3, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x60[] GUI_RESOURCE_ATTRIBUTES =
{
    0x01,0x20,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x60 =
{
    font12_lut,
    data_FontSize12_0x60
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x60 =
{
    2,
    font12_lut,
    data_FontSize12_0x60
};
#endif
#endif
static const PictureObject FontSize12_0x60 =
{
    PICTYPE_BITS,
    3,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x60
#else
    data_FontSize12_0x60
#endif
};
//-------------------------------------------------------
// Character: "a"/0x61, Width: 7, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x61[] GUI_RESOURCE_ATTRIBUTES =
{
    0x80,0x81,0x24,0x48,0x82,0x24,0x48,0x02,0x3F,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x61 =
{
    font12_lut,
    data_FontSize12_0x61
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x61 =
{
    2,
    font12_lut,
    data_FontSize12_0x61
};
#endif
#endif
static const PictureObject FontSize12_0x61 =
{
    PICTYPE_BITS,
    7,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x61
#else
    data_FontSize12_0x61
#endif
};
//-------------------------------------------------------
// Character: "b"/0x62, Width: 7, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x62[] GUI_RESOURCE_ATTRIBUTES =
{
    0xFF,0x03,0x21,0x08,0x82,0x20,0x08,0x02,0x1F,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x62 =
{
    font12_lut,
    data_FontSize12_0x62
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x62 =
{
    2,
    font12_lut,
    data_FontSize12_0x62
};
#endif
#endif
static const PictureObject FontSize12_0x62 =
{
    PICTYPE_BITS,
    7,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x62
#else
    data_FontSize12_0x62
#endif
};
//-------------------------------------------------------
// Character: "c"/0x63, Width: 6, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x63[] GUI_RESOURCE_ATTRIBUTES =
{
    0xF0,0x81,0x20,0x08,0x82,0x20,0x10,0x01,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x63 =
{
    font12_lut,
    data_FontSize12_0x63
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x63 =
{
    2,
    font12_lut,
    data_FontSize12_0x63
};
#endif
#endif
static const PictureObject FontSize12_0x63 =
{
    PICTYPE_BITS,
    6,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x63
#else
    data_FontSize12_0x63
#endif
};
//-------------------------------------------------------
// Character: "d"/0x64, Width: 7, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x64[] GUI_RESOURCE_ATTRIBUTES =
{
    0xF0,0x81,0x20,0x08,0x82,0x20,0x08,0xF1,0x3F,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x64 =
{
    font12_lut,
    data_FontSize12_0x64
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x64 =
{
    2,
    font12_lut,
    data_FontSize12_0x64
};
#endif
#endif
static const PictureObject FontSize12_0x64 =
{
    PICTYPE_BITS,
    7,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x64
#else
    data_FontSize12_0x64
#endif
};
//-------------------------------------------------------
// Character: "e"/0x65, Width: 7, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x65[] GUI_RESOURCE_ATTRIBUTES =
{
    0xF0,0x81,0x24,0x48,0x82,0x24,0x48,0x02,0x17,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x65 =
{
    font12_lut,
    data_FontSize12_0x65
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x65 =
{
    2,
    font12_lut,
    data_FontSize12_0x65
};
#endif
#endif
static const PictureObject FontSize12_0x65 =
{
    PICTYPE_BITS,
    7,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x65
#else
    data_FontSize12_0x65
#endif
};
//-------------------------------------------------------
// Character: "f"/0x66, Width: 5, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x66[] GUI_RESOURCE_ATTRIBUTES =
{
    0x08,0xE0,0x3F,0x09,0x90,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x66 =
{
    font12_lut,
    data_FontSize12_0x66
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x66 =
{
    2,
    font12_lut,
    data_FontSize12_0x66
};
#endif
#endif
static const PictureObject FontSize12_0x66 =
{
    PICTYPE_BITS,
    5,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x66
#else
    data_FontSize12_0x66
#endif
};
//-------------------------------------------------------
// Character: "g"/0x67, Width: 7, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x67[] GUI_RESOURCE_ATTRIBUTES =
{
    0xF0,0x81,0xA0,0x08,0x8A,0xA0,0x08,0x89,0x7F,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x67 =
{
    font12_lut,
    data_FontSize12_0x67
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x67 =
{
    2,
    font12_lut,
    data_FontSize12_0x67
};
#endif
#endif
static const PictureObject FontSize12_0x67 =
{
    PICTYPE_BITS,
    7,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x67
#else
    data_FontSize12_0x67
#endif
};
//-------------------------------------------------------
// Character: "h"/0x68, Width: 7, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x68[] GUI_RESOURCE_ATTRIBUTES =
{
    0xFF,0x03,0x01,0x08,0x80,0x00,0x08,0x00,0x3F,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x68 =
{
    font12_lut,
    data_FontSize12_0x68
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x68 =
{
    2,
    font12_lut,
    data_FontSize12_0x68
};
#endif
#endif
static const PictureObject FontSize12_0x68 =
{
    PICTYPE_BITS,
    7,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x68
#else
    data_FontSize12_0x68
#endif
};
//-------------------------------------------------------
// Character: "i"/0x69, Width: 2, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x69[] GUI_RESOURCE_ATTRIBUTES =
{
    0xF9,0x03,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x69 =
{
    font12_lut,
    data_FontSize12_0x69
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x69 =
{
    2,
    font12_lut,
    data_FontSize12_0x69
};
#endif
#endif
static const PictureObject FontSize12_0x69 =
{
    PICTYPE_BITS,
    2,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x69
#else
    data_FontSize12_0x69
#endif
};
//-------------------------------------------------------
// Character: "j"/0x6A, Width: 4, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x6A[] GUI_RESOURCE_ATTRIBUTES =
{
    0x00,0x88,0x80,0xF9,0x07,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x6A =
{
    font12_lut,
    data_FontSize12_0x6A
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x6A =
{
    2,
    font12_lut,
    data_FontSize12_0x6A
};
#endif
#endif
static const PictureObject FontSize12_0x6A =
{
    PICTYPE_BITS,
    4,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x6A
#else
    data_FontSize12_0x6A
#endif
};
//-------------------------------------------------------
// Character: "k"/0x6B, Width: 6, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x6B[] GUI_RESOURCE_ATTRIBUTES =
{
    0xFF,0x03,0x04,0xA0,0x00,0x11,0x08,0x02,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x6B =
{
    font12_lut,
    data_FontSize12_0x6B
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x6B =
{
    2,
    font12_lut,
    data_FontSize12_0x6B
};
#endif
#endif
static const PictureObject FontSize12_0x6B =
{
    PICTYPE_BITS,
    6,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x6B
#else
    data_FontSize12_0x6B
#endif
};
//-------------------------------------------------------
// Character: "l"/0x6C, Width: 2, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x6C[] GUI_RESOURCE_ATTRIBUTES =
{
    0xFF,0x03,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x6C =
{
    font12_lut,
    data_FontSize12_0x6C
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x6C =
{
    2,
    font12_lut,
    data_FontSize12_0x6C
};
#endif
#endif
static const PictureObject FontSize12_0x6C =
{
    PICTYPE_BITS,
    2,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x6C
#else
    data_FontSize12_0x6C
#endif
};
//-------------------------------------------------------
// Character: "m"/0x6D, Width: 10, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x6D[] GUI_RESOURCE_ATTRIBUTES =
{
    0xF8,0x83,0x00,0x08,0x80,0x00,0xF0,0x83,0x00,0x08,0x80,0x00,0xF0,0x03,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x6D =
{
    font12_lut,
    data_FontSize12_0x6D
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x6D =
{
    2,
    font12_lut,
    data_FontSize12_0x6D
};
#endif
#endif
static const PictureObject FontSize12_0x6D =
{
    PICTYPE_BITS,
    10,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x6D
#else
    data_FontSize12_0x6D
#endif
};
//-------------------------------------------------------
// Character: "n"/0x6E, Width: 7, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x6E[] GUI_RESOURCE_ATTRIBUTES =
{
    0xF8,0x03,0x01,0x08,0x80,0x00,0x08,0x00,0x3F,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x6E =
{
    font12_lut,
    data_FontSize12_0x6E
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x6E =
{
    2,
    font12_lut,
    data_FontSize12_0x6E
};
#endif
#endif
static const PictureObject FontSize12_0x6E =
{
    PICTYPE_BITS,
    7,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x6E
#else
    data_FontSize12_0x6E
#endif
};
//-------------------------------------------------------
// Character: "o"/0x6F, Width: 7, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x6F[] GUI_RESOURCE_ATTRIBUTES =
{
    0xF0,0x81,0x20,0x08,0x82,0x20,0x08,0x02,0x1F,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x6F =
{
    font12_lut,
    data_FontSize12_0x6F
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x6F =
{
    2,
    font12_lut,
    data_FontSize12_0x6F
};
#endif
#endif
static const PictureObject FontSize12_0x6F =
{
    PICTYPE_BITS,
    7,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x6F
#else
    data_FontSize12_0x6F
#endif
};
//-------------------------------------------------------
// Character: "p"/0x70, Width: 7, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x70[] GUI_RESOURCE_ATTRIBUTES =
{
    0xF8,0x0F,0x21,0x08,0x82,0x20,0x08,0x02,0x1F,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x70 =
{
    font12_lut,
    data_FontSize12_0x70
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x70 =
{
    2,
    font12_lut,
    data_FontSize12_0x70
};
#endif
#endif
static const PictureObject FontSize12_0x70 =
{
    PICTYPE_BITS,
    7,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x70
#else
    data_FontSize12_0x70
#endif
};
//-------------------------------------------------------
// Character: "q"/0x71, Width: 7, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x71[] GUI_RESOURCE_ATTRIBUTES =
{
    0xF0,0x81,0x20,0x08,0x82,0x20,0x08,0x81,0xFF,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x71 =
{
    font12_lut,
    data_FontSize12_0x71
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x71 =
{
    2,
    font12_lut,
    data_FontSize12_0x71
};
#endif
#endif
static const PictureObject FontSize12_0x71 =
{
    PICTYPE_BITS,
    7,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x71
#else
    data_FontSize12_0x71
#endif
};
//-------------------------------------------------------
// Character: "r"/0x72, Width: 5, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x72[] GUI_RESOURCE_ATTRIBUTES =
{
    0xF8,0x03,0x01,0x08,0x80,0x00,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x72 =
{
    font12_lut,
    data_FontSize12_0x72
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x72 =
{
    2,
    font12_lut,
    data_FontSize12_0x72
};
#endif
#endif
static const PictureObject FontSize12_0x72 =
{
    PICTYPE_BITS,
    5,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x72
#else
    data_FontSize12_0x72
#endif
};
//-------------------------------------------------------
// Character: "s"/0x73, Width: 6, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x73[] GUI_RESOURCE_ATTRIBUTES =
{
    0x30,0x82,0x24,0x48,0x82,0x24,0x88,0x01,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x73 =
{
    font12_lut,
    data_FontSize12_0x73
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x73 =
{
    2,
    font12_lut,
    data_FontSize12_0x73
};
#endif
#endif
static const PictureObject FontSize12_0x73 =
{
    PICTYPE_BITS,
    6,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x73
#else
    data_FontSize12_0x73
#endif
};
//-------------------------------------------------------
// Character: "t"/0x74, Width: 6, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x74[] GUI_RESOURCE_ATTRIBUTES =
{
    0x08,0xE0,0x1F,0x08,0x82,0x20,0x08,0x02,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x74 =
{
    font12_lut,
    data_FontSize12_0x74
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x74 =
{
    2,
    font12_lut,
    data_FontSize12_0x74
};
#endif
#endif
static const PictureObject FontSize12_0x74 =
{
    PICTYPE_BITS,
    6,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x74
#else
    data_FontSize12_0x74
#endif
};
//-------------------------------------------------------
// Character: "u"/0x75, Width: 7, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x75[] GUI_RESOURCE_ATTRIBUTES =
{
    0xF8,0x01,0x20,0x00,0x02,0x20,0x00,0x81,0x3F,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x75 =
{
    font12_lut,
    data_FontSize12_0x75
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x75 =
{
    2,
    font12_lut,
    data_FontSize12_0x75
};
#endif
#endif
static const PictureObject FontSize12_0x75 =
{
    PICTYPE_BITS,
    7,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x75
#else
    data_FontSize12_0x75
#endif
};
//-------------------------------------------------------
// Character: "v"/0x76, Width: 6, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x76[] GUI_RESOURCE_ATTRIBUTES =
{
    0x18,0x00,0x0E,0x00,0x03,0x0E,0x18,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x76 =
{
    font12_lut,
    data_FontSize12_0x76
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x76 =
{
    2,
    font12_lut,
    data_FontSize12_0x76
};
#endif
#endif
static const PictureObject FontSize12_0x76 =
{
    PICTYPE_BITS,
    6,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x76
#else
    data_FontSize12_0x76
#endif
};
//-------------------------------------------------------
// Character: "w"/0x77, Width: 10, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x77[] GUI_RESOURCE_ATTRIBUTES =
{
    0x18,0x00,0x0E,0x00,0x03,0x0E,0x18,0x00,0x0E,0x00,0x03,0x0E,0x18,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x77 =
{
    font12_lut,
    data_FontSize12_0x77
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x77 =
{
    2,
    font12_lut,
    data_FontSize12_0x77
};
#endif
#endif
static const PictureObject FontSize12_0x77 =
{
    PICTYPE_BITS,
    10,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x77
#else
    data_FontSize12_0x77
#endif
};
//-------------------------------------------------------
// Character: "x"/0x78, Width: 6, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x78[] GUI_RESOURCE_ATTRIBUTES =
{
    0x18,0x03,0x0A,0x40,0x00,0x0A,0x18,0x03,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x78 =
{
    font12_lut,
    data_FontSize12_0x78
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x78 =
{
    2,
    font12_lut,
    data_FontSize12_0x78
};
#endif
#endif
static const PictureObject FontSize12_0x78 =
{
    PICTYPE_BITS,
    6,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x78
#else
    data_FontSize12_0x78
#endif
};
//-------------------------------------------------------
// Character: "y"/0x79, Width: 6, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x79[] GUI_RESOURCE_ATTRIBUTES =
{
    0x18,0x00,0x8E,0x00,0x07,0x0E,0x18,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x79 =
{
    font12_lut,
    data_FontSize12_0x79
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x79 =
{
    2,
    font12_lut,
    data_FontSize12_0x79
};
#endif
#endif
static const PictureObject FontSize12_0x79 =
{
    PICTYPE_BITS,
    6,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x79
#else
    data_FontSize12_0x79
#endif
};
//-------------------------------------------------------
// Character: "z"/0x7A, Width: 6, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x7A[] GUI_RESOURCE_ATTRIBUTES =
{
    0x08,0x83,0x28,0x48,0x82,0x22,0x18,0x02,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x7A =
{
    font12_lut,
    data_FontSize12_0x7A
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x7A =
{
    2,
    font12_lut,
    data_FontSize12_0x7A
};
#endif
#endif
static const PictureObject FontSize12_0x7A =
{
    PICTYPE_BITS,
    6,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x7A
#else
    data_FontSize12_0x7A
#endif
};
//-------------------------------------------------------
// Character: "{"/0x7B, Width: 6, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x7B[] GUI_RESOURCE_ATTRIBUTES =
{
    0x20,0x00,0x02,0xDE,0x17,0x80,0x01,0x08,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x7B =
{
    font12_lut,
    data_FontSize12_0x7B
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x7B =
{
    2,
    font12_lut,
    data_FontSize12_0x7B
};
#endif
#endif
static const PictureObject FontSize12_0x7B =
{
    PICTYPE_BITS,
    6,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x7B
#else
    data_FontSize12_0x7B
#endif
};
//-------------------------------------------------------
// Character: "|"/0x7C, Width: 2, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x7C[] GUI_RESOURCE_ATTRIBUTES =
{
    0xFF,0x0F,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x7C =
{
    font12_lut,
    data_FontSize12_0x7C
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x7C =
{
    2,
    font12_lut,
    data_FontSize12_0x7C
};
#endif
#endif
static const PictureObject FontSize12_0x7C =
{
    PICTYPE_BITS,
    2,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x7C
#else
    data_FontSize12_0x7C
#endif
};
//-------------------------------------------------------
// Character: "}"/0x7D, Width: 6, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x7D[] GUI_RESOURCE_ATTRIBUTES =
{
    0x01,0x18,0x80,0xDE,0x07,0x02,0x20,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x7D =
{
    font12_lut,
    data_FontSize12_0x7D
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x7D =
{
    2,
    font12_lut,
    data_FontSize12_0x7D
};
#endif
#endif
static const PictureObject FontSize12_0x7D =
{
    PICTYPE_BITS,
    6,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x7D
#else
    data_FontSize12_0x7D
#endif
};
//-------------------------------------------------------
// Character: "~"/0x7E, Width: 9, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x7E[] GUI_RESOURCE_ATTRIBUTES =
{
    0xC0,0x00,0x02,0x20,0x00,0x04,0x40,0x00,0x08,0x80,0x00,0x06,0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x7E =
{
    font12_lut,
    data_FontSize12_0x7E
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x7E =
{
    2,
    font12_lut,
    data_FontSize12_0x7E
};
#endif
#endif
static const PictureObject FontSize12_0x7E =
{
    PICTYPE_BITS,
    9,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x7E
#else
    data_FontSize12_0x7E
#endif
};
//-------------------------------------------------------
// Character: ""/0x7F, Width: 12, Height: 12
//-------------------------------------------------------
static const uint8_t data_FontSize12_0x7F[] GUI_RESOURCE_ATTRIBUTES =
{
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00
};
#ifdef GUI_USE_PICTUREGDATA
static const PictureGData gdata_FontSize12_0x7F =
{
    font12_lut,
    data_FontSize12_0x7F
};
#else
#ifdef GUI_USE_PICTUREGDATAEXT
static const PictureGDataExt gdata_FontSize12_0x7F =
{
    2,
    font12_lut,
    data_FontSize12_0x7F
};
#endif
#endif
static const PictureObject FontSize12_0x7F =
{
    PICTYPE_BITS,
    12,
    12,
#if defined(GUI_USE_PICTUREGDATA) || defined(GUI_USE_PICTUREGDATAEXT)
    &gdata_FontSize12_0x7F
#else
    data_FontSize12_0x7F
#endif
};
//-------------------------------------------------------
//
//-------------------------------------------------------
const PictureObject * const font12[] =
{
    &FontSize12_0x20,
    &FontSize12_0x21,
    &FontSize12_0x22,
    &FontSize12_0x23,
    &FontSize12_0x24,
    &FontSize12_0x25,
    &FontSize12_0x26,
    &FontSize12_0x27,
    &FontSize12_0x28,
    &FontSize12_0x29,
    &FontSize12_0x2A,
    &FontSize12_0x2B,
    &FontSize12_0x2C,
    &FontSize12_0x2D,
    &FontSize12_0x2E,
    &FontSize12_0x2F,
    &FontSize12_0x30,
    &FontSize12_0x31,
    &FontSize12_0x32,
    &FontSize12_0x33,
    &FontSize12_0x34,
    &FontSize12_0x35,
    &FontSize12_0x36,
    &FontSize12_0x37,
    &FontSize12_0x38,
    &FontSize12_0x39,
    &FontSize12_0x3A,
    &FontSize12_0x3B,
    &FontSize12_0x3C,
    &FontSize12_0x3D,
    &FontSize12_0x3E,
    &FontSize12_0x3F,
    &FontSize12_0x40,
    &FontSize12_0x41,
    &FontSize12_0x42,
    &FontSize12_0x43,
    &FontSize12_0x44,
    &FontSize12_0x45,
    &FontSize12_0x46,
    &FontSize12_0x47,
    &FontSize12_0x48,
    &FontSize12_0x49,
    &FontSize12_0x4A,
    &FontSize12_0x4B,
    &FontSize12_0x4C,
    &FontSize12_0x4D,
    &FontSize12_0x4E,
    &FontSize12_0x4F,
    &FontSize12_0x50,
    &FontSize12_0x51,
    &FontSize12_0x52,
    &FontSize12_0x53,
    &FontSize12_0x54,
    &FontSize12_0x55,
    &FontSize12_0x56,
    &FontSize12_0x57,
    &FontSize12_0x58,
    &FontSize12_0x59,
    &FontSize12_0x5A,
    &FontSize12_0x5B,
    &FontSize12_0x5C,
    &FontSize12_0x5D,
    &FontSize12_0x5E,
    &FontSize12_0x5F,
    &FontSize12_0x60,
    &FontSize12_0x61,
    &FontSize12_0x62,
    &FontSize12_0x63,
    &FontSize12_0x64,
    &FontSize12_0x65,
    &FontSize12_0x66,
    &FontSize12_0x67,
    &FontSize12_0x68,
    &FontSize12_0x69,
    &FontSize12_0x6A,
    &FontSize12_0x6B,
    &FontSize12_0x6C,
    &FontSize12_0x6D,
    &FontSize12_0x6E,
    &FontSize12_0x6F,
    &FontSize12_0x70,
    &FontSize12_0x71,
    &FontSize12_0x72,
    &FontSize12_0x73,
    &FontSize12_0x74,
    &FontSize12_0x75,
    &FontSize12_0x76,
    &FontSize12_0x77,
    &FontSize12_0x78,
    &FontSize12_0x79,
    &FontSize12_0x7A,
    &FontSize12_0x7B,
    &FontSize12_0x7C,
    &FontSize12_0x7D,
    &FontSize12_0x7E,
    &FontSize12_0x7F,
    
};

