cmake_minimum_required(VERSION 2.8.9)
project(Example CXX)

#======Example=====
#Bin declaration
add_executable(Example
    src/main.cpp
)

#Compilation args
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wno-unused-parameter -O3 -g3 -std=c++11")


#Include dirs
include_directories(include)
include_directories(../GIF/include)

#Linked libs
find_package(GIF REQUIRED)
find_package(glfw3 3.2 REQUIRED)

target_link_libraries(Example GIF)
target_link_libraries(Example glfw ${GLFW_LIBRARIES})
target_link_libraries(Example GLEW)
target_link_libraries(Example glm)
target_link_libraries(Example soil)

#Destination dir
set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})
