# cmake version require
cmake_minimum_required(VERSION 3.0.0)

# assign cpp standard
set(CMAKE_CXX_COMPILER "c++")
# set(CMAKE_C_COMPILER "c++")
set(CMAKE_CXX_FLAGS "-std=c++11")
# set(CMAKE_C_FLAGS "-std=c++11")

# set project name and version
project(gtestTest VERSION 0.1.0)

# add include and src path
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

# file to compile
add_executable(${PROJECT_NAME} src/main.cpp)

# add cpp as lib
add_library(libTest src/test.cpp)

# for gtest, included in tests sub-folder
enable_testing()
add_subdirectory(tests)