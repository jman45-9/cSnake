cmake_minimum_required(VERSION 3.15)

project(cSnake VERSION 1.0)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_C_EXTENSIONS ON)

configure_file(cSnakeConfig.h.in cSnakeConfig.h)

add_executable(cSnake src/main.c)

target_include_directories(cSnake PUBLIC 
                                "${PROJECT_BINARY_DIR}"
                                "${PROJECT_SOURCE_DIR}/headers"
                                )
