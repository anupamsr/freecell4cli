#ifndef BOARD_H_
#define BOARD_H_

#include "Freecell.h"
#include "Homecell.h"
#include "PlayArea.h"

namespace LIBCARD
{
class Board
{
    public:
        Board();

    private:
        Freecell m_freecell;
        Homecell m_homecell;
        PlayArea m_playarea;
};
}

#endif // ifndef BOARD_H_
