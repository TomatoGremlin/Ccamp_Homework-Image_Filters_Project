#include <stdio.h>
#include "my_filter.h"

int main(int argc, char **argv)
{

  PPM_Image_Buffer test;
  PPM_Image_Buffer *buf = &test;

  if (argc < 4 || argc > 5)
  {
    fprintf(stderr, "Invalid amount of arguments!\n");
    return -1;
  }

  // P3 text -> P6 binary
  if (!strcmp(argv[3], "-b"))
  {
    read_ppm_color_bitmap(argv[1], buf);
    P3_to_P6(argv[2], buf);
  }
  // P6 binary -> P3 text
  else if (!strcmp(argv[3], "-t"))
  {
    P6_to_P3(argv[1], buf);
    write_ppm_color_bitmap(argv[2], buf);
  }

  // greyscale:
  else if (!strcmp(argv[3], "-g"))
  {
    read_ppm_color_bitmap(argv[1], buf);
    convert_to_grayscale(buf);
    write_ppm_color_bitmap(argv[2], buf);
  }
  // colours:
  else if (!strcmp(argv[3], "-f"))
  {
    if (!strcmp(argv[4], "r"))
    {
      //red
       read_ppm_color_bitmap(argv[1], buf);
       filter_color_component(buf, 1);
       write_ppm_color_bitmap(argv[2], buf);
            
    }
    else if (!strcmp(argv[4], "g"))
    {
      //green
       read_ppm_color_bitmap(argv[1], buf);
       filter_color_component(buf, 2);
      write_ppm_color_bitmap(argv[2], buf);
            
    }
    else if (!strcmp(argv[4], "b"))
    {
      //blue
       read_ppm_color_bitmap(argv[1], buf);
       filter_color_component(buf, 4);
       write_ppm_color_bitmap(argv[2], buf);
            
    }
    else if (!strcmp(argv[4], "rg"))
    {
      //red + green
      read_ppm_color_bitmap(argv[1], buf);
      filter_color_component(buf, 3);
      write_ppm_color_bitmap(argv[2], buf);
            
    }
    else if (!strcmp(argv[4], "rb"))
    {
      // red + blue 
      read_ppm_color_bitmap(argv[1], buf);
      filter_color_component(buf, 5);
      write_ppm_color_bitmap(argv[2], buf);
            
    }
   else if (!strcmp(argv[4], "gb"))
   {
      // green + blue
      read_ppm_color_bitmap(argv[1], buf);
      filter_color_component(buf, 6);
      write_ppm_color_bitmap(argv[2], buf);
   }
   else{
    fprintf(stderr, "Invalid arguments for option -f !\n");
    return -1;
   }
  }
  else {
    fprintf(stderr, "Invalid option as argument!\n");
    return -1;
  }

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
