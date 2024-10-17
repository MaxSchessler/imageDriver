/**
 * Author Max Schessler
 * Date: 10/15/2024
 * 
 * This file contians the method signatures for array utilities.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>



/**
 * Checks if an array contains a specific element.
 *
 * @param arr A pointer to the array of integers.
 * @param size The number of elements in the array.
 * @param x The integer value to search for in the array.
 * @return 1 if the array contains the element, 0 otherwise.
 */
int contains(const int *arr, int size, int x);


/**
 * Checks if a given value exists within a specified subarray.
 *
 * @param arr Pointer to the array of integers.
 * @param size The total size of the array.
 * @param x The value to search for within the subarray.
 * @param i The starting index of the subarray (inclusive).
 * @param j The ending index of the subarray (inclusive).
 * @return 1 if the value is found within the subarray, 0 otherwise.
 */
int containsWithin(const int *arr, int size, int x, int i, int j);


/**
 * Creates a new array that is a padded copy of the given array.
 *
 * @param arr The original array to be copied.
 * @param oldSize The size of the original array.
 * @param newSize The size of the new array to be created.
 * @return A pointer to the new array, which contains the elements of the original array
 *         followed by zeros if the new size is larger than the old size.
 */
int * paddedCopy(const int *arr, int oldSize, int newSize);


/**
 * Reverses the elements of the given array in place.
 *
 * @param arr A pointer to the array to be reversed.
 * @param size The number of elements in the array.
 */
void reverse(int *arr, int size);

/**
 * Creates a new array that is a reversed copy of the given array.
 *
 * @param arr A pointer to the array to be copied and reversed.
 * @param size The number of elements in the array.
 * @return A pointer to the newly created array that contains the elements of the original array in reverse order.
 */
int * reverseCopy(const int *arr, int size);

