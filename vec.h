/*
vec.h - vec.c header file
-> VEC_T vector structure, vector dot product normalization functions
*/

#ifndef VEC_H
#define VEC_H

// vector structure for 3D calculations
typedef struct VEC_T {
  double x, y, z;
} VEC_T;

double dot(VEC_T v1, VEC_T v2);
VEC_T normalize(VEC_T v);

#endif
