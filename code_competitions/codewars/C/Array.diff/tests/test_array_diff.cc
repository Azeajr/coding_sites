#include "array_diff.h"
#include <gtest/gtest.h>

TEST(ArrayDiffTest, Test0) {
  const int arr1[2] = {1, 2};
  const int arr2[1] = {1};
  const int expected[1] = {2};

  size_t n;
  int *result = array_diff(arr1, 2, arr2, 1, &n);
  ASSERT_EQ(n, 1);
  for (size_t i = 0; i < n; ++i) {
    ASSERT_EQ(result[i], expected[i]);
  }
  free(result); // Since array_diff is supposed to allocate memory
}

TEST(ArrayDiffTest, Test1) {
  const int arr1[3] = {1, 2, 2};
  const int arr2[1] = {1};
  const int expected[2] = {2, 2};

  size_t n;
  int *result = array_diff(arr1, 3, arr2, 1, &n);
  ASSERT_EQ(n, 2);
  for (size_t i = 0; i < n; ++i) {
    ASSERT_EQ(result[i], expected[i]);
  }
  free(result); // Since array_diff is supposed to allocate memory
}

TEST(ArrayDiffTest, Test2) {
  const int arr1[3] = {1, 2, 2};
  const int arr2[1] = {2};
  const int expected[1] = {1};

  size_t n;
  int *result = array_diff(arr1, 3, arr2, 1, &n);
  ASSERT_EQ(n, 1);
  for (size_t i = 0; i < n; ++i) {
    ASSERT_EQ(result[i], expected[i]);
  }
  free(result); // Since array_diff is supposed to allocate memory
}

TEST(ArrayDiffTest, Test3) {
  const int arr1[3] = {1, 2, 3};
  const int arr2[2] = {1, 2};
  const int expected[1] = {3};

  size_t n;
  int *result = array_diff(arr1, 3, arr2, 2, &n);
  ASSERT_EQ(n, 1);
  for (size_t i = 0; i < n; ++i) {
    ASSERT_EQ(result[i], expected[i]);
  }
  free(result); // Since array_diff is supposed to allocate memory
}

TEST(ArrayDiffTest, Test4) {
  const int arr1[3] = {1, 2, 2};
  const int arr2[0] = {};
  const int expected[3] = {1, 2, 2};

  size_t n;
  int *result = array_diff(arr1, 3, arr2, 0, &n);
  ASSERT_EQ(n, 3);
  for (size_t i = 0; i < n; ++i) {
    ASSERT_EQ(result[i], expected[i]);
  }
  free(result); // Since array_diff is supposed to allocate memory
}

TEST(ArrayDiffTest, Test5) {
  const int arr1[0] = {};
  const int arr2[2] = {1, 2};
  const int expected[0] = {};

  size_t n;
  int *result = array_diff(arr1, 0, arr2, 2, &n);
  ASSERT_EQ(n, 0);
  for (size_t i = 0; i < n; ++i) {
    ASSERT_EQ(result[i], expected[i]);
  }
  free(result); // Since array_diff is supposed to allocate memory
}

TEST(ArrayDiffTest, Test6) {
  const int arr1[5] = {1, 2, 3, 4, 5};
  const int arr2[3] = {1, 3, 4};
  const int expected[2] = {2, 5};

  size_t n;
  int *result = array_diff(arr1, 5, arr2, 3, &n);
  ASSERT_EQ(n, 2);
  for (size_t i = 0; i < n; ++i) {
    ASSERT_EQ(result[i], expected[i]);
  }
  free(result); // Since array_diff is supposed to allocate memory
}

// TEST(ArrayDiffTest, Test1) {
//     int a[] = {1, 2, 3, 4, 5};
//     int b[] = {1, 3, 5};
//     size_t n;
//     int* result = array_diff(a, 5, b, 3, &n);
//     ASSERT_EQ(n, 2);
//     ASSERT_EQ(result[0], 2);
//     ASSERT_EQ(result[1], 4);
//     free(result);  // Since array_diff is supposed to allocate memory
// }
