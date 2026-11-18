cmake_minimum_required(VERSION 3.25)

project(
    matching-engine
    VERSION 1.0.0
    DESCRIPTION "a simulated matching engine by Brandon Do"
    LANGUAGES CXX
)

enable_testing()

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(engine_warnings INTERFACE)
target_compile_options(engine_warnings INTERFACE -Wall -Wextra -Wpedantic -Wconversion -Wsign-conversion -Wshadow)

add_subdirectory(src/)
add_subdirectory(apps/)

add_subdirectory(tests/)