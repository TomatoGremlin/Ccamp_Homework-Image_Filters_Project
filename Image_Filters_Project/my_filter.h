#pragma once
#include <stdio.h>

typedef struct Pixel_Data { // RGB info for 1 pixel
	unsigned red;
  unsigned green;
  unsigned blue;
}Pixel_Data;

typedef struct PPM_Image_Buffer {
	Pixel_Data* data; // array with pixels
	int rown, coln; // rows and colums of pixels
}PPM_Image_Buffer;

int read_ppm_color_bitmap(const char*, PPM_Image_Buffer* );
int write_ppm_color_bitmap(const char *, PPM_Image_Buffer *);

void filter_color_component(PPM_Image_Buffer*, unsigned int);
void convert_to_grayscale(PPM_Image_Buffer*);