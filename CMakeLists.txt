cmake_minimum_required(VERSION 3.20)

project(cpp_channel)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# set c++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(ENABLE_SHARED "Build shared library" OFF)
option(ENABLE_TESTS "Build tests" ON)
option(ENABLE_EXAMPLES "Build examples" ON)

add_subdirectory(src)

if (ENABLE_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

if (ENABLE_EXAMPLES)
    add_subdirectory(examples)
endif()

