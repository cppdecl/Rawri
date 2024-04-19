cmake_minimum_required(VERSION 3.19)

project(rawri)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 11)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_definitions(-D__CMAKE_ROOT_DIRECTORY__="${CMAKE_CURRENT_SOURCE_DIR}/..")

add_library(${PROJECT_NAME} 
    Rawri.cc
)

target_include_directories(${PROJECT_NAME} INTERFACE .)