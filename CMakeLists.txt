cmake_minimum_required(VERSION 3.9)
project(matrixcalc C)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(src)
add_subdirectory(tests)

add_executable(matrixcalc main.c)
add_executable(matrixcalc_test test.c)

target_link_libraries(matrixcalc src)
target_link_libraries(matrixcalc_test src tests)
