#ifndef CONSOLE_H
#define CONSOLE_H

#include "Painter.h"

class Console : public Painter
{
public:
    Console();
    void Paint(const FreeCell::Board& _card) const;
    void Paint(const FreeCell::Card& _board) const;
};

#endif // CONSOLE_H
