#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <deque>
#include "Deck.h"
#include "Painter.h"

namespace FreeCell
{
class Board
{
public:
    Board();
    void Place(const Deck& _deck);
    void Paint(const Painter& _painter) const;

private:
    std::vector<std::deque<Card> > mColumns;
    std::vector<std::deque<Card> > mFreecell;
    std::vector<std::deque<Card> > mHomecell;
    friend void Painter::Paint(const Board& _board) const;
};
}
#endif // BOARD_H
