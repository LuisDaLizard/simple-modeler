cmake_minimum_required(VERSION 3.23)
project(simple-model-app)

file(GLOB_RECURSE APP_SRC src/*.c)

add_executable(simple-model-app ${APP_SRC})
target_include_directories(simple-model-app PRIVATE include ../common/include ../graphics/include)
target_link_libraries(simple-model-app simple-model-common simple-model-graphics)