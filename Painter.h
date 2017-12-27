#ifndef PAINTER_H
#define PAINTER_H

namespace FreeCell
{
class Board;
class Card;
}
class Painter
{
public:
    Painter();
    void Paint(const FreeCell::Board& _card) const;
    void Paint(const FreeCell::Card& _board) const;
};

#endif // PAINTER_H
