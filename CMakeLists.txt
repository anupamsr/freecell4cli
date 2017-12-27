cmake_minimum_required(VERSION 2.8)

project(lin_freecell)

find_package(Curses)
include_directories(${CURSES_INCLUDE_DIRS})

add_executable(${PROJECT_NAME}
    "lin_freecell.cpp"
    "lin_freecell.h"
    )

target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARIES})
