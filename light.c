/*
light.c - provides lighting for 3D representation after computing ambient, diffuse, and specular lighting
*/

#include "math.h"
#include "light.h"
#include "vec.h"

/*
computes ambient, diffuse, and specular lighting
returns final color
*/
COLOR_T illuminate (RAY_T ray, LIGHT_T light, OBJ_T *list, COLOR_T surface_color, VEC_T int_pt, VEC_T normal){
  //copy surface_color to return
  COLOR_T finished_color = surface_color;

  VEC_T light_vector, spec;
  double light_vector_normalized;

  // compute normalized light rays based on lighting origin point and intersection points
  light_vector.x = (light.loc.x - int_pt.x);
  light_vector.y = (light.loc.y - int_pt.y);
  light_vector.z = (light.loc.z - int_pt.z);
  light_vector_normalized = dot(normalize(light_vector), normal);

  //ambient lighting
  finished_color.R = 0.2 * surface_color.R;
  finished_color.G = 0.2 * surface_color.G;
  finished_color.B = 0.2 * surface_color.B;

  // compute lighting if required
  if (light_vector_normalized > 0)
  {
    //diffuse lighting
    finished_color.R += light_vector_normalized * surface_color.R;
    finished_color.G += light_vector_normalized * surface_color.G;
    finished_color.B += light_vector_normalized * surface_color.B;

    //specular lighting
    spec.x += light_vector.x - (normal.x * 2 * light_vector_normalized);
    spec.y += light_vector.y - (normal.y * 2 * light_vector_normalized);
    spec.z += light_vector.z - (normal.z * 2 * light_vector_normalized);

    VEC_T r_normalized = normalize(spec);

    if (dot(r_normalized, ray.direction) < 0) {
      finished_color.R += pow(dot(r_normalized, ray.direction), 200);
      finished_color.G += pow(dot(r_normalized, ray.direction), 200);
      finished_color.B += pow(dot(r_normalized, ray.direction), 200);
    }
  }

  return finished_color;

}
