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
    virtual ~Painter() {}

    virtual void Paint(const FreeCell::Board& _card) const = 0;
    virtual void Paint(const FreeCell::Card& _board) const = 0;
};

#endif // PAINTER_H
