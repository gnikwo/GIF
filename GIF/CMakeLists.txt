cmake_minimum_required(VERSION 2.8.9)
project(GIF CXX)

#========GIF========

if(WIN32)
    set(OS_dependant_sources src/MutexWindows.cpp src/ThreadWindows.cpp)
else()
    set(OS_dependant_sources src/MutexUnix.cpp src/ThreadUnix.cpp)
endif()

#Lib declaration
add_library(GIF SHARED
    src/GIF.cpp
    src/Window.cpp
    src/Shader.cpp
    src/Texture.cpp
    src/Element.cpp
    src/MutexInterface.cpp
    src/ThreadInterface.cpp
    ${OS_dependant_sources}
    src/Button.cpp
    src/Box.cpp
	src/Library.cpp
	src/Controller.cpp
)

#Compilation args
set(CMAKE_CXX_FLAGS "-Wall -Wextra -O3 -g3 -std=c++11")

#Include dirs
include_directories(include)
include_directories(../deps/glfw/include)
include_directories(../deps/glew/include)
include_directories(../deps/glm)
include_directories(../deps/soil/src)

#Destination dir
set(LIBRARY_OUTPUT_PATH lib)

