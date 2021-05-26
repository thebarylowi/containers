cmake_minimum_required(VERSION 3.16)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link runTests with what we want to test and the GTest and pthread library
add_executable(functions_test 
    main.cpp
    array_test.cpp)
target_link_libraries(functions_test ${GTEST_LIBRARIES} pthread)