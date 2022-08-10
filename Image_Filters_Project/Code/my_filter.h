#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct Pixel_Data
{ // RGB info for 1 pixel
  uint8_t red;
  uint8_t green;
  uint8_t blue;
} Pixel_Data;

typedef struct PPM_Image_Buffer {
	Pixel_Data* data; // array with pixels
	int rown, coln; // rows and colums of pixels
}PPM_Image_Buffer;

int read_ppm_color_bitmap(const char*, PPM_Image_Buffer* );
int write_ppm_color_bitmap(const char *, PPM_Image_Buffer *);

void filter_color_component(PPM_Image_Buffer*, unsigned int);
void convert_to_grayscale(PPM_Image_Buffer*);

int P3_to_P6(const char *, PPM_Image_Buffer *);
int P6_to_P3(const char *, PPM_Image_Buffer *);
