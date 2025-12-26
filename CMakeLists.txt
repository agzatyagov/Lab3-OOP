cmake_minimum_required(VERSION 3.20)
project(Labo3oop LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(labo3oop_lib
        src/point.cpp
        src/figure.cpp
        src/rectangle.cpp
        src/trapezoid.cpp
        src/rhombus.cpp
        src/array.cpp
)

target_include_directories(labo3oop_lib PUBLIC include)

add_executable(Labo3oop main.cpp)
target_link_libraries(Labo3oop PRIVATE labo3oop_lib)

# google tests
include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(Labo3oopTests tests/tests.cpp)
target_link_libraries(Labo3oopTests PRIVATE labo3oop_lib GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(Labo3oopTests)
