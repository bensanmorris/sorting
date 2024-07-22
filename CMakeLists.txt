cmake_minimum_required(VERSION 3.5)

set(PROJECT_NAME sorting)
project(${PROJECT_NAME} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

# testing
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest
  GIT_TAG        main
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  test_sorting
  test_main.cpp
)
target_link_libraries(
  test_sorting
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_sorting)

# benchmarking
set(BENCHMARK_ENABLE_TESTING FALSE)
FetchContent_Declare(googlebenchmark
    GIT_REPOSITORY https://github.com/google/benchmark
    GIT_TAG        main
)
FetchContent_MakeAvailable(googlebenchmark)

add_executable(benchmark_sorting main.cpp sorting.h)
target_link_libraries(benchmark_sorting benchmark::benchmark)
