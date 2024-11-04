#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

//  return a dynamically allocated array
//  assign the length of this array to *z
//  memory will be freed by the test suite

int *array_diff(const int *arr1, size_t n1, const int *arr2, size_t n2,
                size_t *z) {
  int *arr = (int *)malloc(n1 * sizeof(int));

  int i = 0;
  int j = 0;
  int k = 0;
  bool i_already_exists;

  for (i = 0; i < n1; i++) {
    i_already_exists = false;
    for (j = 0; j < n2; j++) {
      if (arr1[i] == arr2[j]) {
        i_already_exists = true;
        break;
      }
    }
    if (!i_already_exists) {
      arr[k] = arr1[i];
      k++;
    }
  }

  *z = k;
  return arr;
}