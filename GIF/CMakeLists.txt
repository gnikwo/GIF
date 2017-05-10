cmake_minimum_required(VERSION 2.8.9)
project(GIF CXX)

#========DEPS=======
#GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(deps/glfw)


#========GIF========
#Lib declaration
add_library(GIF SHARED
    src/Window.cpp
    src/Element.cpp
    src/MutexInterface.cpp
    src/MutexUnix.cpp
    src/ThreadInterface.cpp
    src/ThreadUnix.cpp
)

#Compilation args
set(CMAKE_CXX_FLAGS "-Wall")


#Include dirs
include_directories(include)
include_directories(deps/glfw/include)

#Linked libs
find_package(glfw3 3.2 REQUIRED)
target_link_libraries(GIF glfw ${GLFW_LIBRARIES})

#Destination dir
set(LIBRARY_OUTPUT_PATH lib)

