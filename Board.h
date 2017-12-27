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
    void                           Place(const Deck& _deck);
    void                           Paint(const Painter& _painter) const;
    std::vector<std::deque<Card> > GetColumns() const;
    std::vector<std::deque<Card> > GetFreecell() const;
    std::vector<std::deque<Card> > GetHomecell() const;

private:
    std::vector<std::deque<Card> > mColumns;
    std::vector<std::deque<Card> > mFreecell;
    std::vector<std::deque<Card> > mHomecell;
};
}
#endif // BOARD_H
