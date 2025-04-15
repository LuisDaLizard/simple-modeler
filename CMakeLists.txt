cmake_minimum_required(VERSION 3.23)
project(simple-model C)

set(CMAKE_C_STANDARD 99)
set(THIRD_PARTY ${CMAKE_CURRENT_SOURCE_DIR}/third_party)

add_subdirectory(third_party)
add_subdirectory(common)
add_subdirectory(graphics)
add_subdirectory(app)