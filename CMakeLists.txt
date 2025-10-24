cmake_minimum_required(VERSION 3.14)
project(lab3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ---- GoogleTest ----
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.15.2
  TLS_VERIFY     false
)
FetchContent_MakeAvailable(googletest)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)


add_library(lab3_lib
    src/figure.cpp
    src/rhomb.cpp
    src/trapezoid.cpp
    src/rectangle.cpp
    src/array.cpp
)
target_include_directories(lab3_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)


add_executable(lab3 main.cpp)
target_link_libraries(lab3 PRIVATE lab3_lib)


enable_testing()

add_executable(tests test/tests_l3.cpp)
target_link_libraries(tests PRIVATE
    lab3_lib
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests)
