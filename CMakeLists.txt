cmake_minimum_required(VERSION 2.8.9)
project(GIF_all)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/modules/")

if(WIN32)

    #SET(CMAKE_CXX_COMPILER "C:/MinGW/bin/g++.exe")

endif()

#========DEPS=======
#GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(deps/glfw)

#GLM
add_subdirectory(deps/glm)

#SOIL
add_subdirectory(deps/soil)

#GIF
add_subdirectory(GIF)
add_subdirectory(Example)

