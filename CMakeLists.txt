cmake_minimum_required(VERSION 2.8)

project(LibCard)
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
    )
