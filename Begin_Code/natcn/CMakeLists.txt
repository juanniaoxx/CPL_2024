cmake_minimum_required(VERSION 3.26)
project(natcn)

set(CMAKE_CXX_STANDARD 17)

add_executable(natcn main.c src/natcn.c)

target_include_directories(natcn PUBLIC include)