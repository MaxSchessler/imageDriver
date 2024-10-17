/**
 * This is a main test driver program that allows you
 * to test your functions on an actual image visually
 * in an ad-hoc manner.
 */
#include <stdlib.h>
#include <stdio.h>

#include "image_utils.h"

int main(int argc, char **argv) {

  int height, width;
  char *inputFileName = NULL;
  char *outputFileName = NULL;
  int mode = 0;
  if(argc != 4) {
    fprintf(stderr, "Usage: inputFileName outputFileName mode\n");
    fprintf(stderr, "  mode: 1  = Flip Horizontal\n");
    fprintf(stderr, "        2  = Flip Vertical\n");
    fprintf(stderr, "        3  = Rotate Clockwise\n");
    exit(1);
  } else {
    inputFileName = argv[1];
    outputFileName = argv[2];
    mode = atoi(argv[3]);
  }
  Pixel **image = loadImage(inputFileName, &height, &width);
  if(mode == 1) {
    flipHorizontal(image, height, width);
    saveImage(outputFileName, image, height, width);
  } else if(mode == 2) {
    flipVertical(image, height, width);
    saveImage(outputFileName, image, height, width);
  } else if(mode == 3) {
    Pixel ** rotated = rotateClockwise(image, height, width);
    saveImage(outputFileName, rotated, width, height);
  } else {
    fprintf(stderr, "ERROR: invalid mode %d\n", mode);
    exit(1);
  }

  return 0;
}
