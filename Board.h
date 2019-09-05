#ifndef BOARD_H_
#define BOARD_H_

#include "Freecell.h"
#include "Homecell.h"
#include "PlayArea.h"
#include <string>

namespace FREECELL
{
class Board
{
    public:
        Board();
        void Update(std::vector<std::vector<LIBCARD::Card> >& _display) const;
        void Place(LIBCARD::Deck& _deck);
        bool Process(const std::string& _input,
                     std::string      & _err_msg);
        bool AutoCheck(std::string& _err_msg);
        void Clear();

    private:
        Freecell m_freecell;
        Homecell m_homecell;
        PlayArea m_playarea;
        bool m_is_updatable;
};
}

#endif // ifndef BOARD_H_
