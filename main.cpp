#include <stdexcept>
#include "Board.h"
#include "Console.h"

using namespace FreeCell;
Deck GetFreecellDeck()
{
    Deck deck;

    try
    {
        while (true)
        {
            deck.Remove(eCardSuit::NoSuit, eCardRank::Jocker);
        }
    }
    catch (const std::logic_error& _ex)
    {}
    return deck;
}

int main()
{
    using namespace FreeCell;
    Board board;
    Deck  deck = GetFreecellDeck();
    deck.Shuffle();
    board.Place(deck);
    Console console;
    board.Paint(console);
    return 0;
}
