cmake_minimum_required(VERSION 3.15)

project(CONTAINERS LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


add_executable(containers
    main.cpp
    ../libs/array.hpp
    ../libs/stack.hpp
    ../libs/vector.hpp)