#include <iostream>

#include "Board.h"
#include "MoveCommand.h"

int main()
{
    using namespace FREECELL;
    LIBCARD::Deck d;
    d.Shuffle();
    Board b;
    b.Place(d);
    PlayArea p;
    MoveCommand<8, 8> m(p, 1, 1, p, 2, 2);
    return 0;
}
