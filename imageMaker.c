/**
 * This is a utility program that demonstrates how to make
 * some "pallet" images for testing and debugging.
 *
 * For example, the 2x3testImage.jpg allows you to easily test
 * your functions using a debugger on a small image.
 */
#include <stdlib.h>
#include <stdio.h>

#include "image_utils.h"

int main(int argc, char **argv) {

  int y = 2, x = 3;
  char *outputFileName = "2x3testImage.jpg";

  //contiguous allocation:
  Pixel **image = (Pixel **)malloc(sizeof(Pixel *) * y);
  image[0] = (Pixel *)malloc(sizeof(Pixel) * (y * x));
  for(int i=1; i<y; i++) {
    image[i] = (*image + (x * i));
  }

  Pixel p1 = {255,0,0};
  image[0][0] = p1;
  Pixel p2 = {0,255,0};
  image[0][1] = p2;
  Pixel p3 = {0,0,255};
  image[0][2] = p3;
  Pixel p4 = {255,255,0};
  image[1][0] = p4;
  Pixel p5 = {0,255,255};
  image[1][1] = p5;
  Pixel p6 = {255,0,255};
  image[1][2] = p6;
  saveImage(outputFileName, image, y, x);

  y = 256;
  x = 256;

  //contiguous allocation:
  image = (Pixel **)malloc(sizeof(Pixel *) * y);
  image[0] = (Pixel *)malloc(sizeof(Pixel) * (y * x));
  for(int i=1; i<y; i++) {
    image[i] = (*image + (x * i));
  }

  for(int i=0; i<256; i++) {
    for(int j=0; j<256; j++) {
      Pixel p = {0, i, j};
      image[i][j] = p;
    }
  }

  saveImage("pallet.jpg", image, y, x);

  return 0;
}
