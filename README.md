# ray-tracer
Ray-tracing program (C) - displays colored spheres in PPM image with fixed lighting via ray tracing image rendering
- Input: sphere positions, sizes, and colors from standard input (either piped text file or manual user input)
- Output: prints colored 3D representation of spheres under a light source on black background


Compile with $ gcc rt.c vec.c sphere.c light.c -o rt


Usage:

(1) Text file input -> run with $ ./rt < [filename].txt > img.ppm

-> pipe in text file containing list of spheres' information (text file format: {sphere_center_x_coordinate} {sphere_center_y_coordinate} {sphere_center_z_coordinate}
{sphere_radius} {sphere_color_R_value} {sphere_color_G_value} {sphere_color_B_value} - repeated for each sphere, look at spheres.txt for reference)

(2) Manual user input -> run with <./rt > img.ppm>

-> input 7 separate lines of decimal values at a time for a single sphere ({sphere_center_x_coordinate} {sphere_center_y_coordinate} {sphere_center_z_coordinate} {sphere_radius} {sphere_color_R_value} {sphere_color_G_value} {sphere_color_B_value})

-> submit values with Enter, repeat for each sphere. When finished, input a / (foward-slash) and hit Enter

Open img.ppm for results, enjoy!
