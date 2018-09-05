cmake_minimum_required(VERSION 3.12)
project(sdl2pp)

set(CMAKE_CXX_STANDARD 14)

add_library(sdl2pp STATIC src/Renderer.cpp src/Texture.cpp src/Surface.cpp src/Init.cpp src/InitImage.cpp src/Window.cpp include/Size.h include/EventDispatcher.cpp include/EventDispatcher.h)

target_include_directories(sdl2pp PRIVATE include)
target_include_directories(sdl2pp PRIVATE src)

add_definitions(-DSDL2PP_USE_IMAGE)
