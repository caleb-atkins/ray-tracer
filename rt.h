/*
rt.h - rt.c header file
-> ray type and color type structures
*/

#ifndef RT_H
#define RT_H

#include "vec.h"

// ray type holds point origin and direction of ray
typedef struct RAY_T {
  VEC_T origin;
  VEC_T direction;
} RAY_T;

// color type holds RGB values
typedef struct COLOR_T {
  double R, G, B;
} COLOR_T;

#endif
