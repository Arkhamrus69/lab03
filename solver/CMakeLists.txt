cmake_minimum_required(VERSION 3.10)
project(solver VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(solver main.cpp)
target_link_libraries(solver PRIVATE formatter_ex solver_lib)
