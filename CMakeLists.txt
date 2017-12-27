cmake_minimum_required (VERSION 3.1)
project (freecell4cli CXX)

set(CMAKE_CXX_STANDARD 14)
add_definitions(-Wall -Wextra -pedantic -Weffc++ -Wno-deprecated-declarations)

set(BUILD_WITH_CURSES FALSE)

list(APPEND Sources
    "main.cpp"
    "Card.h"
    "Deck.h"
    "Board.h"
    "Painter.h"
    "Card.cpp"
    "Deck.cpp"
    "Board.cpp"
    )

if(BUILD_WITH_CURSES)
    list(APPEND Sources
        "Curses.h"
        "Curses.cpp"
        )
    add_definitions(-DBUILD_WITH_CURSES=${BUILD_WITH_CURSES})
    find_package(Curses)
    include_directories(${CURSES_INCLUDE_DIRS})
    add_executable(${PROJECT_NAME} ${Sources})
    target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARIES})
else()
    list(APPEND Sources
        "StdOut.h"
        "StdOut.cpp"
        )
    add_executable(${PROJECT_NAME} ${Sources})
endif()
