/**
 * This is a starter test driver program that may use
 * to test your array functions.
 */
#include <stdlib.h>
#include <stdio.h>

#include "array_utils.h"

/**
 * Prints the given array to the standard output
 */
void printArray(const int *arr, int size);

int main(int argc, char **argv) {

  int n = 7;
  int testArray[] = {8, 6, 7, 5, 3, 0, 9};

  if(!contains(testArray, n, 5)) {
    printf("contains failed!\n");
  }

  if(contains(testArray, n, 42)) {
    printf("contains failed!\n");
  }

  // print the test array
  printArray(testArray, n);

  int *temp = paddedCopy(testArray, n, n - 3);
  printf("Temp Array: ");
  printArray(temp, n-3);
  free(temp);

  temp = paddedCopy(testArray, n, n + 3);
  printf("Temp Array: ");
  printArray(temp, n+3);
  free(temp);

  printf("Array Before: ");
  printArray(testArray, n);
  reverse(testArray, n);
  printf("Array After: ");
  printArray(testArray, n);

  temp = reverseCopy(testArray, n);
  printf("Original: ");
  printArray(testArray, n);
  printf("Copy:     ");
  printArray(temp, n);
  free(temp);

  return 0;

}

void printArray(const int *arr, int size) {
  printf("[");
  for(int i=0; i<size-1; i++) {
    printf("%d, ", arr[i]);
  }
  printf("%d]\n ", arr[size-1]);
}
