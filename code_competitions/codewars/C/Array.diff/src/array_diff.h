#ifndef ARRAY_DIFF_H
#define ARRAY_DIFF_H

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

int *array_diff(const int *arr1, size_t n1, const int *arr2, size_t n2, size_t *z);

#ifdef __cplusplus
}
#endif

#endif // ARRAY_DIFF_H
