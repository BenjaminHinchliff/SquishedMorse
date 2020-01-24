# CMakeList.txt : CMake project for SquishedMorse, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("SquishedMorse")

add_subdirectory(src)
add_subdirectory(tst)

configure_file(enable1.txt ${CMAKE_CURRENT_BINARY_DIR}/enable1.txt COPYONLY)