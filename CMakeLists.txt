cmake_minimum_required (VERSION 3.1)
project (freecell4cli CXX)

set(CMAKE_CXX_STANDARD 14)
add_definitions(-Wall -Wextra -pedantic -Weffc++ -Wno-deprecated-declarations)

add_executable(${PROJECT_NAME}
    "main.cpp"
    "Card.h"
    "Deck.h"
    "Board.h"
    "Painter.h"
    "Console.h"
    "Card.cpp"
    "Deck.cpp"
    "Board.cpp"
    "Console.cpp"
    )
