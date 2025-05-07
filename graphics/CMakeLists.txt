cmake_minimum_required(VERSION 3.23)
project(simple-model-graphics C)

file(GLOB_RECURSE GRAPHICS_SRC src/*.c)

set(GRAPHICS_INCLUDE
        include/
        ../common/include
        ${THIRD_PARTY}/glfw/include
        ${THIRD_PARTY}/glad/include
        ${THIRD_PARTY}/nuklear)

set(GRAPHICS_LIBRARIES
        simple-model-common
        glfw
        glad )

if(APPLE)
    set(GRAPHICS_LIBRARIES ${GRAPHICS_LIBRARIES}
            "-framework OpenGL"
            "-framework Cocoa"
            "-framework IOKit")
elseif(WIN32)
    set(GRAPHICS_LIBRARIES ${GRAPHICS_LIBRARIES} opengl32.lib)
endif()

add_library(simple-model-graphics STATIC ${GRAPHICS_SRC})
target_include_directories(simple-model-graphics PRIVATE ${GRAPHICS_INCLUDE})
target_link_libraries(simple-model-graphics ${GRAPHICS_LIBRARIES})