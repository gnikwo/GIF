cmake_minimum_required(VERSION 2.8.9)
project(GIF CXX)


#========GIF========
#Lib declaration
add_library(GIF SHARED
    src/GIF.cpp
    src/Window.cpp
    src/Shader.cpp
    src/Element.cpp
    src/MutexInterface.cpp
    src/MutexUnix.cpp
    src/ThreadInterface.cpp
    src/ThreadUnix.cpp
    src/Button.cpp
)

#Compilation args
set(CMAKE_CXX_FLAGS "-Wall -Wextra -O3 -g3 -std=c++11")

#Include dirs
include_directories(include)
include_directories(../deps/glfw/include)
include_directories(../deps/glm)

#Destination dir
set(LIBRARY_OUTPUT_PATH lib)
