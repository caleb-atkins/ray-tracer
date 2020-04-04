/********************************************************
=========================================================
obj.h - defines OBJ_T linked list struct for holding sphere data
=========================================================
********************************************************/

#include "vec.h"
#include "sphere.h"

#ifndef OBJ_H
#define OBJ_H

// linked list to hold sphere data, color data, and next sphere to render
typedef struct OBJ_T {
  SPHERE_T sphere;
  COLOR_T color;
  struct OBJ_T * next;
} OBJ_T;

#endif
