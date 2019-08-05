#ifndef BOARD_H_
#define BOARD_H_

#include "Freecell.h"
#include "Homecell.h"
#include "PlayArea.h"

namespace FREECELL
{
class Board
{
    public:
        Board();
        void Place(LIBCARD::Deck& _deck);

    private:
        Freecell m_freecell;
        Homecell m_homecell;
        PlayArea m_playarea;
};
}

#endif // ifndef BOARD_H_
