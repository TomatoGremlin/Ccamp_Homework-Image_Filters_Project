#include "my_filter.h"
#include <stdio.h>

int main() {
  PPM_Image_Buffer test;
  PPM_Image_Buffer* buf = &test;

  // colours:
  /*
  read_ppm_color_bitmap("cat.ppm", buf);
  filter_color_component(buf, 1);
  write_ppm_color_bitmap("cat1.ppm", buf);

  read_ppm_color_bitmap("cat.ppm", buf);
  filter_color_component(buf, 2);
  write_ppm_color_bitmap("cat2.ppm", buf);

  read_ppm_color_bitmap("cat.ppm", buf);
  filter_color_component(buf, 3);
  write_ppm_color_bitmap("cat3.ppm", buf);

  read_ppm_color_bitmap("cat.ppm", buf);
  filter_color_component(buf, 4);
  write_ppm_color_bitmap("cat4.ppm", buf);

  read_ppm_color_bitmap("cat.ppm", buf);
  filter_color_component(buf, 5);
  write_ppm_color_bitmap("cat5.ppm", buf);

  read_ppm_color_bitmap("cat.ppm", buf);
  filter_color_component(buf, 6);
  write_ppm_color_bitmap("cat6.ppm", buf);
  */

  // greyscale:
  /*read_ppm_color_bitmap("cat.ppm", buf);
  convert_to_grayscale(buf);
  write_ppm_color_bitmap("cat_grey.ppm", buf);
  */

  free(buf->data);
  return 0;
}