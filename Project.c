#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct Pixel_Data { // info za edin piksel
  unsigned red;
  unsigned green;
  unsigned blue;
}Pixel_Data;

typedef struct PPM_Image_Buffer {
	Pixel_Data* data; // masiv ot pikseli
	int rown, coln; // redove i koloni pikseli
}PPM_Image_Buffer;


int read_ppm_color_bitmap(const char* filename, PPM_Image_Buffer* buf) {

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
  fscanf(f, "\n");

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
  fseek( f,2,SEEK_CUR);

  fprintf(f, "\n%d %d\n", buf->rown, buf->coln);

  fseek( f,3,SEEK_CUR);
  fprintf(f,"\n");

  for ( int i = 0; i < buf->rown * buf->coln; i++)
  {
    fprintf(f, "%u %u %u\n", buf->data[i].red, buf->data[i].green, buf->data[i].blue );
  }
  
  fclose(f);
  return 0;
}

void filter_color_component(PPM_Image_Buffer* buf, unsigned int rgb_mask){
 
 int mask_size = sizeof(rgb_mask)* 8;
 int pixels = buf->rown * buf->coln;
 for (int i = 0; i < pixels; i++) //change between pixels
 {
    for (int bit = 0; bit < 3; bit++) // change between the 3 bits
    {
      if (!!(rgb_mask & (1 << bit)) == 0 ) // check if current bit is 0
      { 
        // check the position of the 0 and remove the value for the colour
        if (bit == 0) buf -> data[i].blue = 0;
        else if (bit == 1)buf -> data[i].green = 0;
        else buf -> data[i].red = 0;
      }
    }
 }
}


int main() {
  PPM_Image_Buffer test;
  PPM_Image_Buffer* buf = &test;
  read_ppm_color_bitmap("image1.txt", buf);
  
  filter_color_component(buf, 5);
  write_ppm_color_bitmap("image1.txt", buf);


  free(buf->data);
  return 0;
}
