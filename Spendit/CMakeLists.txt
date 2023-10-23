cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(spendit)

file(GLOB_RECURSE SRC_FILES src/*.cpp)
add_executable(spendit ${SRC_FILES})
target_include_directories(spendit PUBLIC include/)