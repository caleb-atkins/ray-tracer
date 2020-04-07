# ray-tracer
Ray-tracing program (C) - displays colored spheres in PPM image with fixed lighting via ray tracing image rendering
- Input: sphere positions, sizes, and colors from standard input (either piped text file or manual user input)
- Output: prints colored 3D representation of spheres under a light source on black background


Compile with $ gcc rt.c vec.c sphere.c light.c -o rt


Usage: -> run with $ ./rt < [filename].txt > img.ppm

- pipe in text file containing list of spheres' information (text file format: {sphere_center_x_coordinate} {sphere_center_y_coordinate} {sphere_center_z_coordinate}
{sphere_radius} {sphere_color_R_value} {sphere_color_G_value} {sphere_color_B_value} - repeated for each sphere, look at spheres.txt for reference)
- for best results, restrict input values for x and y coordinates to [-5.0, 5.0], z coordinates to between [5.0, 20.0], sphere radii between [0.1, 5.0], and RGB values must be between [0.0, 1.0] for proporionate mapping to RBG values 0-255

Open img.ppm for results, enjoy!
