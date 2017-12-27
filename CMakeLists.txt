cmake_minimum_required(VERSION 2.8)

project(freecell4cli)
add_executable(${PROJECT_NAME}
    "main.cpp"
    "Card.h"
    "Deck.h"
    "Board.h"
    "Card.cpp"
    "Deck.cpp"
    "Board.cpp"
    )
