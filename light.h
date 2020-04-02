/*
light.h - light.c header file
-> LIGHT_T with loc field, illuminate() function prototype
*/

#ifndef LIGHT_H
#define LIGHT_H

#include "vec.h"
#include "rt.h"
#include "obj.h"

// light type stores location of light shining onto scene
typedef struct LIGHT_T {
  VEC_T loc;
} LIGHT_T;

COLOR_T illuminate (RAY_T ray, LIGHT_T light, OBJ_T *list, COLOR_T surface_color, VEC_T int_pt, VEC_T normal);

#endif
