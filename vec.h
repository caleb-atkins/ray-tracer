/*********************************
==================================
vec.h - vec.c header file
- VEC_T vector struct
- dot() and normalize() prototypes
==================================
*********************************/

#ifndef VEC_H
#define VEC_H

// vector structure for 3D calculations
typedef struct VEC_T {
  double x, y, z;
} VEC_T;

// computes and returns normalized vector v
double dot(VEC_T v1, VEC_T v2);

// computes and returns dot product of vectors v1 and v2
VEC_T normalize(VEC_T v);

#endif
