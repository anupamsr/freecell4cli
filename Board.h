#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <queue>
#include "Card.h"

namespace FreeCell
{
class Board
{
public:
    Board();
private:
    std::vector<std::queue<Card>> mColumns;
    std::vector<std::queue<Card>> mFreecell;
    std::vector<std::queue<Card>> mHomecell;
};
}
#endif // BOARD_H
