cmake_minimum_required(VERSION 2.8)

project(Card)

add_library(${PROJECT_NAME} SHARED
    "Card.h"
    "Card.cpp"
    "CardCollection.h"
    "Deck.h"
    "Deck.cpp"
    )

if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -Werror -Weffc++)
endif()
