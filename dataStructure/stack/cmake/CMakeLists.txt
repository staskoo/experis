cmake_minimum_required(VERSION 3.10.0)

#project name
project (CStack)

add_definitions(-Dcl -DEHsc -DW4 -DFe -D_DEBUG -DMDd -Dtest_1 -DWIN32 -D_CONSOLE)

set(CMAKE_BUILD_TYPE Debug)

add_executable(output ../CStackTest.cpp)