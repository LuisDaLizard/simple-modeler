cmake_minimum_required(VERSION 3.23)
project(simple-model-app)

file(GLOB_RECURSE APP_SRC src/*.c)

if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")

    add_executable(simple-model-app ${APP_SRC})

elseif(${CMAKE_BUILD_TYPE} STREQUAL "Release")

    add_executable(simple-model-app WIN32 ${APP_SRC})

endif()

target_include_directories(simple-model-app PRIVATE include ../common/include ../graphics/include)
target_link_libraries(simple-model-app simple-model-common simple-model-graphics)