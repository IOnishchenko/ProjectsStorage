#ifndef PICTERE_STRUCTURES_DEFINED
#define PICTERE_STRUCTURES_DEFINED

#include "stdint.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
    uint16_t width;
    uint16_t height;
    const uint32_t * data;
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
