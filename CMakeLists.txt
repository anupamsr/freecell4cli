cmake_minimum_required(VERSION 2.8)

project(freecell4cli)

find_package(Curses)
include_directories(${CURSES_INCLUDE_DIRS})

add_executable(${PROJECT_NAME}
    "main.cpp"
    "Board.h"
    "Board.cpp"
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
    )

add_subdirectory("LibCard")

target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARIES} "Card")

if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -Werror -Weffc++)
endif()
