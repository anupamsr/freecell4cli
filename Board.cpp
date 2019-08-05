#include "Board.h"
#include "Deck.h"

namespace FREECELL
{
Board::Board() {}

void Board::Place(LIBCARD::Deck& _deck)
{
    m_playarea.Add(_deck);
}
}
