#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pixel_Data { // RGB info for 1 pixel
	unsigned red;
  unsigned green;
  unsigned blue;
}Pixel_Data;

typedef struct PPM_Image_Buffer {
	Pixel_Data* data; // array with pixels
	int rown, coln; // rows and colums of pixels
}PPM_Image_Buffer;


int read_ppm_color_bitmap(const char* filename, PPM_Image_Buffer* buf) {

  /*
  char check2[4];
  fscanf( f,"%s",check2);
  if (strcmp(check2,"255") != NULL)
  {
      perror("Wrong file format\n");
      return -1;
  }

  char check[3];
  fscanf( f,"%s",check);
  else if (strcmp(check,"P3") != NULL)
  {
    perror("Wrong file format\n");
    return -1;
    
  }
  */
  FILE* f = fopen(filename, "r");
  if (f == NULL)
  {
    perror("Could not open file\n");
    return -1;
  }
  //--------------------
  fseek(f, 2, SEEK_CUR);

  fscanf(f, "\n%d %d\n", &buf->rown, &buf->coln);

  fseek(f, 3, SEEK_CUR);
  
  int size = buf->rown * buf->coln;
  buf->data = (Pixel_Data*)malloc(size * sizeof(Pixel_Data));
  for (int i = 0; i < size; i++)
  {
    fscanf(f, "%u", &buf->data[i].red);
    fscanf(f, "%u", &buf->data[i].green);
    fscanf(f, "%u", &buf->data[i].blue);
  }
  fclose(f);
  return 0;
}
int write_ppm_color_bitmap(const char *filename, PPM_Image_Buffer *buf){
  FILE* f = fopen (filename, "w+");
  
  if (f == NULL)
  {
    perror("Could not open file\n");
    return -1;
  }
  //--------------------
  
  fprintf(f, "P3\n%d %d\n255", buf->rown, buf->coln);
  fprintf(f,"\n");

  for ( int i = 0; i < buf->rown * buf->coln; i++)
  {
    fprintf(f, "%u %u %u\n", buf->data[i].red, buf->data[i].green, buf->data[i].blue );
  }
  fclose(f);
  return 0;
}

void filter_color_component(PPM_Image_Buffer* buf, unsigned int rgb_mask){
 
 int pixels = buf->rown * buf->coln;
 for (int i = 0; i < pixels; i++) //change between pixels
 {
    for (int bit = 0; bit < 3; bit++) // change between the 3 bits
    {
      if (!!(rgb_mask & (1 << bit)) == 0 ) // check if current bit is 0
      { 
        // check the position of the 0 and remove the value for the colour
        if (bit == 0) buf -> data[i].red = 0;
        else if (bit == 1)buf -> data[i].green = 0;
        else buf -> data[i].blue = 0;
      }
    }
 }
}

void convert_to_grayscale(PPM_Image_Buffer* buf){
  unsigned grey = 0;
  int size = buf->rown * buf->coln;
  for (int i = 0; i < size; i++) // change between pixels
  { 
    //change the RGB values to grey
    grey = buf->data[i].red * 0.3 + buf->data[i].green * 0.59 + buf->data[i].blue * 0.11;
    buf->data[i].red = grey;
    buf->data[i].green = grey;
    buf->data[i].blue = grey;
  }
}

int main(int argc, char **argv) {// argc = argument count  ;  argv = array with arguments, [0] = name of the exe
  
  PPM_Image_Buffer test;
  PPM_Image_Buffer *buf = &test;

  if (argc < 4 || argc > 5)
  {
    fprintf(stderr, "Invalid arguments!\n");
    return -1;
  }

  // greyscale:
  if (!strcmp(argv[3], "-g"))
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
  /*
  read_ppm_color_bitmap("cat.ppm", buf);
  convert_to_grayscale(buf);
  write_ppm_color_bitmap("cat_grey.ppm", buf);
  */

  free(buf->data);
  return 0;
}
