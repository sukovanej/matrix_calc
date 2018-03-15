cmake_minimum_required(VERSION 3.9)
project(matrix-calc C)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(src)
add_subdirectory(tests)

add_executable(matrix-calc main.c)
add_executable(matrixcalc_test test.c)

target_link_libraries(matrix-calc src)
target_link_libraries(matrixcalc_test src tests)
