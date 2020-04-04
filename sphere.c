/******************************************************************************************************
=======================================================================================================
sphere.c - provides intersect_sphere function to detect ray tracer intersection with sphere in 3D space
=======================================================================================================
******************************************************************************************************/

#include "math.h"
#include "sphere.h"

/**
  * @desc calculates and assigns *t = distance from camera to sphere intersection given current tracing ray
  *
  * @param RAY_T ray - current ray tracing projection to target pixel
  * @param SPHERE_T sphere - sphere object under consideration
  * @param double *t - becomes calculated distance from camera to sphere intersection
  * @param VEC_T *int_pt - pointer to intersection point of current view ray with closest sphere object
  * @param VEC_T *normal - pointer to normalized ray for vector calculations
  *
  * @return 1 if intersection is detected, 0 otherwise
**/
int intersect_sphere(RAY_T ray, SPHERE_T sphere, double *t, VEC_T *int_pt, VEC_T *normal) {
  VEC_T direction = ray.direction;
  VEC_T origin = ray.origin;

  VEC_T center = sphere.center;
  double radius = sphere.radius;

  // compute linear discriminant
  double b = 2 * ((direction.x * (origin.x - center.x)) + (direction.y * (origin.y - center.y)) + (direction.z * (origin.z - center.z)));
  double c = pow((origin.x - center.x), 2) + pow((origin.y - center.y), 2) + pow((origin.z - center.z), 2) - pow(sphere.radius, 2);
  double discriminant = (b * b) - (4 * c);

  // if negative discriminant, then no intersection
  if (discriminant < 0) {return 0;}

  // compute quadratic formula
  double length_plus = ((-b) + sqrt(discriminant)) / 2;
  double length_minus = ((-b) - sqrt(discriminant)) / 2;

  // determine length for t, distance to intersection!

  // if both distances are negative, no intersection
  if (length_plus <= 0 && length_minus <= 0) {return 0;}

  // if length_minus is the only positive one, or they are both positive and length_minus < length_plus
  // *t = length_minus
  else if ((length_plus <= 0 && length_minus > 0) || ((length_plus > 0 && length_minus > 0) && (length_plus > length_minus))){
    *t = length_minus;
  }

  // if length_plus is the only positive one, or they are both positive and length_plus < length_minus
  // *t = length_plus
  else if ((length_plus > 0 && length_minus <= 0) || ((length_plus > 0 && length_minus > 0) && (length_plus < length_minus))){
    *t = length_plus;
  }

  int_pt -> x = origin.x + (direction.x * (*t));
  int_pt -> y = origin.y + (direction.y * (*t));
  int_pt -> z = origin.z + (direction.z * (*t));

  normal -> x = (int_pt -> x - center.x) / radius;
  normal -> y = (int_pt -> y - center.y) / radius;
  normal -> z = (int_pt -> z - center.z) / radius;
  return 1;

}
