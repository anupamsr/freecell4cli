#include "Board.h"
#include "Deck.h"

namespace LIBCARD
{
Board::Board()
{
    Deck deck;

    m_playarea.Add(deck);
}
}
