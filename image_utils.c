#include <stdlib.h>
#include <stdio.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include "image_utils.h"

Pixel **loadImage(const char *filePath, int *height, int *width) {
  int x,y,n;
  unsigned char *data = stbi_load(filePath, &x, &y, &n, 4); //4 = force RGBA channels
  *height = y;
  *width = x;

  //contiguous allocation:
  Pixel **image = (Pixel **)malloc(sizeof(Pixel *) * y);
  image[0] = (Pixel *)malloc(sizeof(Pixel) * (y * x));
  for(int i=1; i<y; i++) {
    image[i] = (*image + (x * i));
  }

  int rowIndex = 0;
  int colIndex = 0;
  for(int i=0; i<(x * y * 4); i+=4) { //for each row
      image[rowIndex][colIndex].red   = data[i+0];
      image[rowIndex][colIndex].green = data[i+1];
      image[rowIndex][colIndex].blue  = data[i+2];
      colIndex++;
      if(colIndex == x) {
        //go to next row, reset column
        rowIndex++;
        colIndex=0;
      }
  }
  stbi_image_free(data);
  return image;
}

void saveImage(const char *fileName, Pixel **image, int height, int width) {

  // Convert height x width Pixel array to single array with
  // 3 (RGB) channels, ignoring the alpha channel and assume 100% opaque
  unsigned char *data = (unsigned char *) malloc(height * width * 3);
  int x = 0;
  for(int i=0; i<height; i++) {
    for(int j=0; j<width; j++) {
      data[x+0] = image[i][j].red;
      data[x+1] = image[i][j].green;
      data[x+2] = image[i][j].blue;
      x+=3;
    }
  }
  //write
  stbi_write_jpg(fileName, width, height, 3, data, 100);
  free(data);
  return;
}

Pixel ** copyImage(Pixel **image, int height, int width) {
  // this is essentially a deep copy of a 2D array of pixels instead of a 2D array of integers

  if (image == NULL) return NULL;
  if (height < 1 || width < 1) return NULL;

  //allocate memory for the new image
  Pixel **newImage = (Pixel **) malloc(sizeof(Pixel *) * height);
  if (newImage == NULL) {
    printf("Unable to allocate new image.\n");
    return NULL;
  }

  // iterate over each Pixel array in and newImage and create an array of pixels
  for (int i = 0; i<height; i++) {
    newImage[i] = (Pixel *) malloc(sizeof(Pixel) * width);
    if (newImage[i] == NULL) {
      // malloc for this row has failed, free previous rows allcoated and table
      printf("Unable to allocat the %d row in new image (copyImage)\n", i+1);
      for (int j = 0; j<i; j++) {
        free(newImage[j]); // free row
      }
      free(newImage); // free the new image
    } 

    // if malloc for row successful: copy the array of pixels of image[i] to newImage[i]
    for (int k = 0; k<width; k++) {
      newImage[i][k] = image[i][k];
    }
  }

  return newImage;

}

void flipHorizontal(Pixel **image, int height, int width) {

  reverseRows(image, height, width);
}

void flipVertical(Pixel **image, int height, int width) {

  // reverse the array order
  int top = 0;
  int bottom = height - 1;
  while (top < bottom) {
    Pixel *temp = image[top];
    image[top] = image[bottom];
    image[bottom] = temp;
    top++;
    bottom--;
  }

  // reverse the rows
  reverseRows(image, height, width);
}

Pixel ** rotateClockwise(Pixel **image, int height, int width) {
  // first tanspose an array, then reverse the transposed array rows
  // new height and width of transposed array
  int tHeight, tWidth;
  Pixel **transposedImage = transpose(image, height, width, &tHeight, &tWidth);
  reverseRows(transposedImage, tHeight, tWidth);
  return transposedImage;
}

Pixel ** rotateCounterClockwise(Pixel **image, int height, int width) {

}

Pixel **transpose(Pixel **image, int height, int width, int *tHeight, int *tWidth) {

  // no need to check for null pointer or invalid h,w

  // create a new array of opposite dimensions
  Pixel **newImage = (Pixel **) malloc(sizeof(Pixel *) * width);
  if (newImage == NULL) {
    printf("Allocation for new image failed in transpose.\n");
    return NULL;
  }

  // create the rows of length height to change dimensions
  for (int i = 0; i<width; i++) { // using width here will iterate over the number of rows
    newImage[i] = (Pixel *) malloc(sizeof(Pixel) * height); // height here will create (height) number of rows
    // check if allocation failed for a new row
    if (newImage[i] == NULL) {
      // free prev allocated rows from 0 to i (not including i as it was not successfully allocated)
      for (int k = 0; k<i; k++) {
        free(newImage[k]);
      }
      // free the newImage
      free(newImage);
      return NULL;
    }

    // else: row was allocated
  }

  // whole table was allocated if we get to this point

  // iterate over original image using its dimentions (height * width) 
  for (int i = 0; i<height; i++) {
    for (int j = 0; j<width; j++) {
      // set new image at [j][i] to the val at original image [i][j] 
      // which exists due to the new dimensions
      newImage[j][i] = image[i][j];
    }
  }

  // give the calling scope the update tHeight and tWidth variables for using this new image
  *tHeight = width;
  *tWidth = height;
  return newImage;
}

void reverseRows(Pixel **image, int height, int width) {
  int left, right;
  Pixel temp;
  for (int i = 0; i<height; i++) {
    left = 0;
    right = width-1;
    while (left < right) {
      temp = image[i][left];
      image[i][left] = image[i][right];
      image[i][right] = temp;
      left++;
      right--;
    }
  }
}
