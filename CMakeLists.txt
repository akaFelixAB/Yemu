cmake_minimum_required(VERSION 3.16)
project(Yemu LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Recommend g++
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    message(STATUS "Using GNU compiler: ${CMAKE_CXX_COMPILER}")
else()
    message(WARNING "Recommended compiler is g++.")
endif()

# Enable Ninja generator if available
if (CMAKE_GENERATOR STREQUAL "Ninja")
    message(STATUS "Ninja build system detected.")
endif()

# Main executable
add_executable(Yemu src/main.cpp src/MinCPU.cpp)

# Optional: Enable testing
option(YEMU_ENABLE_TESTS "Enable unit tests" ON) # Turn off with -DYEMU_ENABLE_TESTS=OFF
if(YEMU_ENABLE_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
