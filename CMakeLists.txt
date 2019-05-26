cmake_minimum_required(VERSION 3.0.2)
project(jbaldwin_project_euler CXX C)

find_library(gmp REQUIRED)
find_library(gmpxx REQUIRED)

add_library(libc
    lib/permutations.h
    lib/prime.h
)
set_target_properties(libc PROPERTIES LINKER_LANGUAGE C)
target_include_directories(libc PUBLIC .)

add_library(libcpp
    lib/Numeric.hpp
    lib/Permutations.hpp
    lib/Prime.hpp
)
set_target_properties(libcpp PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(libcpp PUBLIC .)

add_executable(p001 p001/p1.c)

add_executable(p018 p018/p18.c)

add_executable(p065 p065/p65.c)
target_link_libraries(p065 gmp)

add_executable(p065xx p065/p65.cpp)
target_link_libraries(p065xx gmp gmpxx)

add_executable(p066 p066/p66.c)
target_link_libraries(p066 gmp gmpxx)

add_executable(p067xx p067/p067.cpp)

add_executable(p068xx p068/p068.cpp)
target_link_libraries(p068xx libcpp)

add_executable(p069xx p069/p069.cpp)
target_link_libraries(p069xx libcpp)

add_executable(p070xx p070/p070.cpp)
target_link_libraries(p070xx libcpp)

add_executable(p071xx p071/p071.cpp)
target_link_libraries(p071xx libcpp pthread)

add_executable(p072xx p072/p072.cpp)
target_link_libraries(p072xx libcpp pthread)

add_executable(p073xx p073/p073.cpp)
target_link_libraries(p073xx libcpp pthread)
