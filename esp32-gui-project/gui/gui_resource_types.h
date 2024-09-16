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
    PICTYPE_A8,
    PICTYPE_L4,
    PICTYPE_L8,
    PICTYPE_AL44,
    PICTYPE_COMPRESED_A4,
    PICTYPE_COMPRESED_L4,
    PICTYPE_COMPRESED_L8,
} PictureCodingType;

typedef struct
{
    const void * lut;
    const uint8_t * data;
} PictureGData;

typedef struct
{
    const void * alpha_lut;
    const void * color_lut;
    const uint8_t * data;
} AL44PictureGData;

typedef struct
{
    const uint16_t lut_size;
    const void * lut;
    const uint8_t * data;
} PictureGDataExt;

typedef struct
{
    const uint16_t alpha_lut_size;
    const void * alpha_lut;
    const uint16_t color_lut_size;
    const void * color_lut;
    const uint8_t * data;
} AL44PictureGDataExt;

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
