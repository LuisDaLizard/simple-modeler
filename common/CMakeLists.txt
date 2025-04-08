cmake_minimum_required(VERSION 3.23)
project(simple-model-common)

file(GLOB_RECURSE COMMON_SRC src/*.c)
set(COMMON_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(COMMON_LIBS simple-model-common)

add_library(simple-model-common STATIC ${COMMON_SRC})
target_include_directories(simple-model-common PRIVATE ${COMMON_INCLUDES})