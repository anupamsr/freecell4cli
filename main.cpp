#ifdef BUILD_WITH_CURSES
# include "Curses.h"
#else // ifdef BUILD_WITH_CURSES
# include "StdOut.h"
#endif // ifdef BUILD_WITH_CURSES

#include <stdexcept>
#include "Board.h"
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

#ifdef BUILD_WITH_CURSES
    Curses painter;
#else // ifdef BUILD_WITH_CURSES
    StdOut painter;
#endif // ifdef BUILD_WITH_CURSES
    board.Paint(painter);
    return 0;
}
