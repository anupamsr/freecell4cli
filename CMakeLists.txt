cmake_minimum_required(VERSION 2.8)

project(freecell4cli CXX)
set(CMAKE_CXX_STANDARD 14)

set(BUILD_WITH_CURSES TRUE)

add_subdirectory("LibCard")

list(APPEND Sources
    "main.cpp"
    "Board.h"
    "Board.cpp"
    "Homecell.h"
    "Freecell.h"
    "PlayArea.h"
    "PlayArea.cpp"
    "Constants.h"
    "Command.h"
    "Command.cpp"
    "MoveCommand.h"
    "GameScreen.h"
    "Input.h"
    "Input.cpp"
    "Prompt.h"
    "Output.h"
    "Output.cpp"
    "HelpScreen.h"
    "ValidMoveCommand.h"
    "Helper.h"
    "Helper.cpp"
    )

if(BUILD_WITH_CURSES)
    list(APPEND Sources
        "Curses/HelpScreen.cpp"
        "Curses/GameScreen.cpp"
        "Curses/Prompt.cpp"
        "Curses/Curses.h"
        "Curses/Curses.cpp"
        )
    add_definitions(-DBUILD_WITH_CURSES=${BUILD_WITH_CURSES})
    find_package(Curses)
    include_directories(${CURSES_INCLUDE_DIRS})
    add_executable(${PROJECT_NAME} ${Sources})
    target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARIES})
else()
    list(APPEND Sources
        "Std/HelpScreen.cpp"
        "Std/GameScreen.cpp"
        "Std/Prompt.cpp"
        )
    add_executable(${PROJECT_NAME} ${Sources})
endif()

target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARIES} "Card")

if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -Werror -Weffc++)
endif()
