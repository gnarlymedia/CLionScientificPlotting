cmake_minimum_required(VERSION 3.6)
project(my_project)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES source.c)

add_executable(my_project ${SOURCE_FILES})

find_library(M_LIB m X11)
find_library(CPGPLOT_LIB cpgplot pgplot png z)
target_link_libraries(my_project ${M_LIB})
target_link_libraries(my_project ${CPGPLOT_LIB})