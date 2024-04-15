cmake_minimum_required(VERSION 3.15)

project(cSnake VERSION 1.0)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_C_EXTENSIONS ON)

configure_file(cSnakeConfig.h.in cSnakeConfig.h)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")

find_package( Curses REQUIRED )
include_directories( ${CURSES_INCLUDE_DIRS} )

add_executable(cSnake src/main.c src/ui.c)

target_link_libraries( cSnake ${CURSES_LIBRARIES} )

target_include_directories(cSnake PUBLIC 
                                "${PROJECT_BINARY_DIR}"
                                "${PROJECT_SOURCE_DIR}/headers"
                                )
