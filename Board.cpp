#include "Board.h"
#include <cstddef> // size_t
namespace FreeCell
{
Board::Board()
    : mColumns(),
    mFreecell(),
    mHomecell()
{
    for (size_t i = 0; i < 8; ++i)
    {
        mColumns.push_back(std::deque<Card>());
    }
    for (size_t i = 0; i < 4; ++i)
    {
        mFreecell.push_back(std::deque<Card>());
    }
    for (size_t i = 0; i < 4; ++i)
    {
        mHomecell.push_back(std::deque<Card>());
    }
}

void Board::Place(const Deck& _deck)
{
    for (size_t i = 0; i < _deck.Size(); ++i)
    {
        mColumns[i % 8].push_front(_deck.GetCard(i));
    }
}

void Board::Paint(const Painter& _painter) const
{
    _painter.Paint(*this);
}

std::vector<std::deque<Card> > Board::GetColumns() const
{
    return mColumns;
}

std::vector<std::deque<Card> > Board::GetFreecell() const
{
    return mFreecell;
}

std::vector<std::deque<Card> > Board::GetHomecell() const
{
    return mHomecell;
}
}
