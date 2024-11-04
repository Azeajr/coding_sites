cmake_minimum_required(VERSION 3.14)  # FetchContent is available in CMake 3.11+, but 3.14+ is recommended
project(ArrayDiff)

# Set C standard as the project is C based
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Include FetchContent module
include(FetchContent)

# Set policy CMP0135 to NEW to use the timestamp of extraction
if(POLICY CMP0135)
  cmake_policy(SET CMP0135 NEW)
endif()

# Declare the GoogleTest content
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/b514bdc898e2951020cbdca1304b75f5950d1f59.zip
)

# Force the shared CRT on MSVC
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Make the fetched content available
FetchContent_MakeAvailable(googletest)

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

# Add the source directory to build the library
add_library(array_diff src/array_diff.c)

# Add the test executable
add_executable(array_diff_test tests/test_array_diff.cc)
target_link_libraries(array_diff_test array_diff gtest gtest_main)

# Enable testing and add tests
enable_testing()
include(GoogleTest)
gtest_discover_tests(array_diff_test)
