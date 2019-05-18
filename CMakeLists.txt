cmake_minimum_required(VERSION 3.0.2)
project(jbaldwin_project_euler CXX C)

find_library(gmp REQUIRED)
find_library(gmpxx REQUIRED)

add_executable(p001 p001/p1.c)

add_executable(p018 p018/p18.c)

add_executable(p065 p065/p65.c)
target_link_libraries(p065 gmp)

add_executable(p065xx p065/p65.cpp)
target_link_libraries(p065xx gmp gmpxx)

add_executable(p066 p066/p66.c)
target_link_libraries(p066 gmp gmpxx)

add_executable(p067xx p067/p067.cpp)
