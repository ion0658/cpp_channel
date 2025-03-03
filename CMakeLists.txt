cmake_minimum_required(VERSION 3.20)

project(cpp_channel)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_RPATH_USE_ORIGIN ON)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")

# set c++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

option(ENABLE_SHARED "Build shared library" OFF)
option(ENABLE_HEADER_ONLY "Build header only library" OFF)

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

