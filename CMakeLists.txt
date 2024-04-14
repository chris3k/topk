cmake_minimum_required(VERSION 3.14)

project(topk)
set(CMAKE_CXX_STANDARD 20)


include(FetchContent)

# include: benchmark
FetchContent_Declare(
  benchmark
  GIT_REPOSITORY https://github.com/google/benchmark.git
  GIT_TAG        d6ce1452872abcd7e5a772f757708a2ad0eee71c
  FIND_PACKAGE_ARGS NAMES benchmark
)
set(BENCHMARK_ENABLE_TESTING OFF)
FetchContent_MakeAvailable(benchmark)

# include: fmt
FetchContent_Declare(
  fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG        aa52eb765dec0eb67fab4b035a4a05b82346c8f5
  FIND_PACKAGE_ARGS NAMES fmt
)
FetchContent_MakeAvailable(fmt)


add_executable(topk main.cpp)
target_link_libraries(topk fmt::fmt)

add_executable(bench bench.cpp)
target_link_libraries(bench benchmark::benchmark)
