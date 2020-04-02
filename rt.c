/*

Caleb Atkins
CSCI 304

Ray-tracing program
Input: text file containing sphere information OR manual text input via command line interface
Output: .ppm image file of spheres

*/

#include "rt.h"
#include "vec.h"
#include "obj.h"
#include "sphere.h"
#include "light.h"

#include "stdlib.h"
#include "stdio.h"
#include "math.h"

// reads spheres from stdin; creates linked list using dynamic memory
void read_objs(OBJ_T **list) {

  // initialize sphere variables and list
  double x, y, z, radius, r, g, b;
  *list = NULL;

  // read in sphere information from text file
  while (scanf("%lf %lf %lf %lf %lf %lf %lf", &x, &y, &z, &radius, &r, &g, &b) == 7) {
    // clear memory space for new sphere object
    OBJ_T *new_sphere = (OBJ_T *) malloc(sizeof(OBJ_T));

    new_sphere -> sphere.center.x = x;
    new_sphere -> sphere.center.y = y;
    new_sphere -> sphere.center.z = z;
    new_sphere -> sphere.radius = radius;
    new_sphere -> color.R = r;
    new_sphere -> color.G = g;
    new_sphere -> color.B = b;

    // point to next sphere
    new_sphere -> next = *list;

    // points to head sphere in linked list
    *list = new_sphere;
  }
}

// send ray caster to interpet color for display
COLOR_T trace(RAY_T ray, OBJ_T *list, LIGHT_T light) {

  // accept the shortest distance to see which sphere is in the front
  double distance;
  double min_distance = 1000.0;

  // min_color = color before illuminate()
  COLOR_T min_color, black, color;

  OBJ_T *pointer;
  OBJ_T *closest_obj = NULL;
  VEC_T int_pt, normal, closest_int_pt, closest_normal;

  black.R = 0.0;
  black.G = 0.0;
  black.B = 0.0;

  // for each sphere in the list, check if ray intersects with sphere
  for (pointer = list; pointer != NULL; pointer = pointer -> next) {
    distance = min_distance + 1.0;

    // look for ray intersection
    int sphere_located = intersect_sphere(ray, pointer->sphere, &distance, &int_pt, &normal);

    // set shortest distance
    if (sphere_located == 1 && distance < min_distance) {
      min_distance = distance;
      closest_int_pt = int_pt;
      closest_normal = normal;
      closest_obj = pointer;

      // set initial color before calling illuminate()
      min_color = pointer -> color;
    }
  }

  // apply lighting if there is a sphere found, otherwise apply black background
  if (closest_obj != NULL) {return illuminate(ray, light, list, min_color, closest_int_pt, closest_normal);}
  else {return black;}
}

/*
read in spheres from either piped-in text file or manual user input into a dynamic memory linked list
-> free up memory at end of program
*/
int main() {
  int x_pixel, y_pixel;

  // initialize linked list
  OBJ_T *list;

  // read in sphere values from standard input
  read_objs(&list);

  // Initilization of type of PPM file used, 1000x1000 pixel space with RGB values of max 255
  printf("P6\n");
  printf("1000 1000\n");
  printf("255\n");

  // traverse 1000x1000 pixel frame, pixel by pixel, ray tracing onto image space and applying colors/shades to spheres
  // note: min_color in trace() refers to color before applying lighting, max_color refers to the max value allowed for sphere color input
  double z = 1;
  for (y_pixel = 0; y_pixel < 1000; y_pixel++) {
    for (x_pixel = 0; x_pixel < 1000; x_pixel++) {

      // account for positional offsets required by PPM image file format
      double x = -0.5 + (x_pixel / 1000.0);
      double y = 0.5 - (y_pixel / 1000.0);

      // calculate current ray
      VEC_T target_location;
      target_location.x = x;
      target_location.y = y;
      target_location.z = z;
      target_location = normalize(target_location);

      // ray originates at camera viewpoint, extends to target_location
      RAY_T ray;
      VEC_T zero_vector;
      zero_vector.x = 0;
      zero_vector.y = 0;
      zero_vector.z = 0;
      ray.origin = zero_vector;
      ray.direction = target_location;

      // set lighting origin to the upper right area
      LIGHT_T light;
      light.loc.x = 5;
      light.loc.y = 10;
      light.loc.z = 0;

      // maximum RGB input values for color calculation
      COLOR_T max_color;
      max_color.B = 1;
      max_color.G = 1;
      max_color.R = 1;

      // ray tracing! calculate color for given pixel
      COLOR_T color = trace(ray, list, light);

      // apply max_color limit to RGB values
      if (color.R > max_color.R) {color.R = 1;}
      if (color.G > max_color.G) {color.G = 1;}
      if (color.B > max_color.B) {color.B = 1;}

      // calculate color for PPM
      unsigned char r = color.R * 255;
      unsigned char g = color.G * 255;
      unsigned char b = color.B * 255;

      // send pixel's determined color to PPM file
      printf("%c%c%c", r, g, b);
    }
  }

  // after writing to PPM file, clear memory used for linked list
  OBJ_T *head;
  while (list != NULL) {
    head = list;
    list = list -> next;
    free(head);
  }

  // Done!
  return 0;
}
