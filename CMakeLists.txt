cmake_minimum_required(VERSION 2.8.9)
project(GIF_all)

set(CMAKE_MODULE_PATH cmake/Modules)

#========DEPS=======
#GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(deps/glfw)

#GLFW

#add_subdirectory(deps/glm)

#GLEW
add_subdirectory(GIF)
add_subdirectory(Example)

