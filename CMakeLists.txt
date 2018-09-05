cmake_minimum_required(VERSION 3.12)
project(sdl2pp)

set(CMAKE_CXX_STANDARD 14)

add_executable(sdl2pp main.cpp internal/Window.h internal/define.h)

add_definitions(-DSDL2PP_USE_IMAGE)
