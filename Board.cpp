#include "Board.h"

namespace FreeCell
{
Board::Board() : mColumns(), mFreecell(), mHomecell()
{
    for (size_t i = 0; i < 8; ++i)
    {
        mColumns.push_back(std::queue<Card>());
    }
    for (size_t i = 0; i < 4; ++i)
    {
        mFreecell.push_back(std::queue<Card>());
    }
    for (size_t i = 0; i < 4; ++i)
    {
        mHomecell.push_back(std::queue<Card>());
    }
}
}
