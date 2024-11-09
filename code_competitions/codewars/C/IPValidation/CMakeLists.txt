cmake_minimum_required(VERSION 3.14)
project(IPValidation)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

include(FetchContent)

if(POLICY CMP0074)
    cmake_policy(SET CMP0074 NEW)
endif()

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

add_library(is_valid_ip src/is_valid_ip.c)

add_executable(test_is_valid_ip tests/test_is_valid_ip.cc)
target_link_libraries(test_is_valid_ip gtest_main is_valid_ip)

enable_testing()
include(GoogleTest)
gtest_discover_tests(test_is_valid_ip)
