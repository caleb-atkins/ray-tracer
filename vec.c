/*
vec.c - provide vector structure and functions
*/

#include "math.h"
#include "vec.h"

// computes and returns normalized vector v
VEC_T normalize(VEC_T v) {
  VEC_T normalized_v;
  double vector_length = sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));

  normalized_v.x = v.x / vector_length;
  normalized_v.y = v.y / vector_length;
  normalized_v.z = v.z / vector_length;

  return normalized_v;
}

// computes and returns dot product of vectors v1 and v2
double dot(VEC_T v1, VEC_T v2) {return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);}
