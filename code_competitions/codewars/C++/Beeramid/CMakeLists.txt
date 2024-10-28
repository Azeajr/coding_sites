cmake_minimum_required(VERSION 3.14)
project(Beeramid)

set(CMAKE_CXX_STANDARD 17 )

enable_testing()

add_executable(
  beeramid_test
  beeramid.cc
)

target_link_libraries(
  beeramid_test
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(beeramid_test)