/**
 * Author Max Schessler
 * Date: 10/15/2024
 * 
 * This file contains method definitions for array utils.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "array_utils.h"

int contains(const int *arr, int size, int x) {
    if (arr == NULL) return false;
    if (size < 1) return false;


    for (int i = 0; i<size; i++) {
        if (arr[i] == x) return true;
    }

    return false;
}

int containsWithin(const int *arr, int size, int x, int i, int j) {
    if (arr == NULL) return false;
    if (size < 1) return false;
    if (i < 0 || j >= size || i > j) return false;
    
    for (int k = i; k <= j; k++) {
        if (arr[k] == x) return true;
    }

    return false;
}

int * paddedCopy(const int *arr, int oldSize, int newSize) {
    if (arr == NULL) return false;
    if (oldSize < 1 || newSize < 1) return NULL;

    int *new = (int *) malloc(sizeof(int) * newSize);
    
    // iterate over 0 -> newSize, if i exists in the range of (0, oldSize) add 
    // arr[i] to the list, else insert 0 
    for (int i = 0; i<newSize; i++) {
        if (i < oldSize) {
            new[i] = arr[i];
        } else {
            new[i] = 0;
        }
    }


    return new;
}

void reverse(int *arr, int size) {

    if (arr == NULL || size < 1) {
        printf("Invalid inputs for reverse.\n");
        return;
    }

    // edit the array in place
    // use a left and right pointer to swap the first and last elements
    int left = 0; 
    int right = size-1;
    int temp;

    // while left < right (as left == right is the the very middle element)
    while (left < right) {
        // swap
        temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        // update left and right
        left ++;
        right --;
    }
}

int * reverseCopy(const int *arr, int size) {
    if (arr == NULL || size < 1) {
        printf("Invalid inputs for reverse.\n");
        return NULL;
    }

    // create new array, copy integers over
    int *newArr = (int *) malloc(sizeof(int) * size);
    for (int i = 0; i<size; i++){
        newArr[i] = arr[i];
    }

    // create left and right pointers
    int left = 0; 
    int right = size-1;
    int temp;

    // while left < right (as left == right is the the very middle element)
    while (left < right) {
        // swap
        temp = newArr[left];
        newArr[left] = newArr[right];
        newArr[right] = temp;

        // update left and right
        left ++;
        right --;
    }

    return newArr;
}