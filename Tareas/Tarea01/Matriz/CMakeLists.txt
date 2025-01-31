cmake_minimum_required(VERSION 3.13)  # CMake version check
project(Tarea01Matriz)               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

# Add main.cpp file of the project root directory as a source file
set(SOURCE_FILES Sources/main.cpp Sources/Matriz.cpp)
set(HEADER_FILES Headers/Matriz.hpp)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(Tarea01Matriz ${SOURCE_FILES})
