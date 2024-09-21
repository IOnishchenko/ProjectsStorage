#ifndef PICTERE_STRUCTURES_DEFINED_H
#define PICTERE_STRUCTURES_DEFINED_H

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
    PICTYPE_COMPRESSED_A4,
    PICTYPE_COMPRESSED_L4,
    PICTYPE_COMPRESSED_L8,
} PictureCodingType;

typedef struct
{
    const void * lut;
    const uint8_t * data;
} PictureGData;

typedef struct
{
    const uint8_t lut_size;
    const void * lut;
    const uint8_t * data;
} PictureGDataExt;

typedef struct
{
    PictureCodingType coding;
    uint16_t width;
    uint16_t height;
    const void * gdata;
} PictureObject;

#ifdef __cplusplus
}
#endif
#endif
