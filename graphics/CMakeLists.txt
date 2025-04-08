cmake_minimum_required(VERSION 3.23)
project(simple-model-graphics C)

file(GLOB_RECURSE GRAPHICS_SRC src/*.c)

add_library(simple-model-graphics STATIC ${GRAPHICS_SRC})
target_include_directories(simple-model-graphics PRIVATE include ../common/include ${THIRD_PARTY}/glfw/include)
target_link_libraries(simple-model-graphics simple-model-common glfw)