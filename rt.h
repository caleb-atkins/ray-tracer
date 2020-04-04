/**************************
===========================
rt.h - rt.c header file
- RAY_T and COLOR_T structs
===========================
**************************/

#ifndef RT_H
#define RT_H

#include "vec.h"

// holds origin point and direction of a particular ray
typedef struct RAY_T {
  VEC_T origin;
  VEC_T direction;
} RAY_T;

// holds RGB values of a particular object
typedef struct COLOR_T {
  double R, G, B;
} COLOR_T;

#endif
