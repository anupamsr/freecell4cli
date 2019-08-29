cmake_minimum_required(VERSION 2.8)

project(LibCard)

find_package(Curses)
include_directories(${CURSES_INCLUDE_DIRS})

add_executable(${PROJECT_NAME}
    "main.cpp"
    "Card.h"
    "Card.cpp"
    "CardCollection.h"
    "Board.h"
    "Board.cpp"
    "Deck.h"
    "Homecell.h"
    "Freecell.h"
    "PlayArea.h"
    "PlayArea.cpp"
    "Constants.h"
    "Command.h"
    "MoveCommand.h"
    "GameScreen.h"
    "Input.h"
    "StdIn.h"
    "Output.h"
    "HelpScreen.h"
    "GameScreen.cpp"
    "ValidMoveCommand.h"
    "Deck.cpp"
    )

target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARIES})

if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -Werror -Weffc++)
endif()
