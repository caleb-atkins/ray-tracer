/*********************************************
==============================================
sphere.h - sphere.c header file
- SPHERE_T struct
- intersect_sphere() prototype
==============================================
*********************************************/

#ifndef SPHERE_H
#define SPHERE_H

#include "vec.h"
#include "rt.h"

// holds positional center and radius information for sphere
typedef struct SPHERE_T {
  VEC_T center;
  double radius;
} SPHERE_T;

// calculates and assigns *t = distance from camera to sphere intersection given current tracing ray
int intersect_sphere (RAY_T ray, SPHERE_T sphere, double *t, VEC_T *int_pt, VEC_T *normal);

#endif
