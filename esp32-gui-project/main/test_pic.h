#ifndef HEADER_test_pic_DEFINED
#define HEADER_test_pic_DEFINED
#define BASE_ADDRESS 0x90000000U

#include "picture_types.h"

#ifdef __cplusplus
extern "C" {
#endif

extern const PictureDataItem sdr_320x240;

extern const PictureDataItem * const test_picItems[];
extern const PictureCollection test_pic;

#ifdef __cplusplus
}
#endif
#endif