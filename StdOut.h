#ifndef STDOUT_H
#define STDOUT_H

#include "Painter.h"

class StdOut : public Painter
{
public:
    StdOut();
    void Paint(const FreeCell::Board& _card) const;
    void Paint(const FreeCell::Card& _board) const;
};

#endif // STDOUT_H
