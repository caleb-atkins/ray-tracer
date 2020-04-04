/**********************************************
===============================================
vec.c - provides vector structure and functions
===============================================
**********************************************/

#include "math.h"
#include "vec.h"

/**
  * @desc computes and returns normalized vector v
  *
  * @param VEC_T v - vector to be normalized
  *
  * @return VEC_T normalized_v - VEC_T v normalized
**/
VEC_T normalize(VEC_T v) {
  VEC_T normalized_v;
  double vector_length = sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));

  normalized_v.x = v.x / vector_length;
  normalized_v.y = v.y / vector_length;
  normalized_v.z = v.z / vector_length;

  return normalized_v;
}

/**
  * @desc computes and returns dot product of vectors v1 and v2
  *
  * @param VEC_T v1 - first vector for input
  * @param VEC_T v2 - second vector for input
  *
  * @return dot product of VEC_T v1 and VEC_T v2
**/
double dot(VEC_T v1, VEC_T v2) {return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);}
