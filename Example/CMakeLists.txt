cmake_minimum_required(VERSION 2.8.9)
project(Example CXX)

#======Example=====
#Bin declaration
add_executable(Example
    src/main.cpp
)

#Compilation args
set(CMAKE_CXX_FLAGS "-Wall")


#Include dirs
include_directories(include)
include_directories(../GIF/include)

#Linked libs
find_package (GIF REQUIRED)
target_link_libraries(Example GIF)

#Destination dir
set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})
