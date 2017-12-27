#ifndef CURSES_H
#define CURSES_H

#include "Painter.h"

class Curses : public Painter
{
public:
    Curses();
    void Paint(const FreeCell::Board& _card) const;
    void Paint(const FreeCell::Card& _board) const;
};

#endif // CURSES_H
