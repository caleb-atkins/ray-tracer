/*
obj.h - defines OBJ_T that holds sphere information
*/

#include "vec.h"
#include "sphere.h"

#ifndef OBJ_H
#define OBJ_H

// struct to hold sphere data, color data, and next sphere to render
typedef struct OBJ_T {
  SPHERE_T sphere;
  COLOR_T color;
  struct OBJ_T * next;
} OBJ_T;

#endif
