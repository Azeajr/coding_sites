#include <stdlib.h>

//  return a dynamically allocated array
//  assign the length of this array to *z
//  memory will be freed by the test suite

int *array_diff(const int *arr1, size_t n1, const int *arr2, size_t n2,
                size_t *z) {
  // Allocate memory for the result array
  int *arr = (int *)malloc(n1 * sizeof(int));

  // Initialize indices and flag
  *z = 0;
  unsigned element_found;

  // Iterate through each element of arr1
  for (int i = 0; i < n1; i++) {
    element_found = 0;
    // Check if the current element of arr1 exists in arr2
    for (int j = 0; j < n2; j++) {
      if (arr1[i] == arr2[j]) {
        element_found = 1;
        break;
      }
    }
    // If the element does not exist in arr2, add it to the result array
    if (!element_found) {
      arr[*z] = arr1[i];
      (*z)++;
    }
  }

  return arr;
}