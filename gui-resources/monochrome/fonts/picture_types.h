#ifndef PICTERE_STRUCTURES_DEFINED
#define PICTERE_STRUCTURES_DEFINED

#include "stdint.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
    PICTYPE_BITS,
    PICTYPE_A4,
    PICTYPE_L4,
    PICTYPE_L8,
    PICTYPE_A4L4,     // not implemented
    PICTYPE_RGB565, // not implemented
    PICTYPE_RGB888, // not implemented
} PictureCodingType;

typedef struct
{
    uint16_t width;
    uint16_t height;
    PictureCodingType coding;
    const uint8_t * data;
} PictureDataItem;

typedef struct
{
    uint32_t  count;
    const uint32_t * colors;
} Palette;

typedef struct
{
    const Palette * const palettes;
    const PictureDataItem * const * const items;
} PictureCollection;

#ifdef __cplusplus
}
#endif
#endif
