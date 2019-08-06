#include "Board.h"
#include "Deck.h"
#include "MoveCommand.h"

namespace FREECELL
{
Board::Board()
    : m_is_updatable(true) {}

void Board::Update(std::vector<std::vector<LIBCARD::Card> >& _display) const
{
    if (!m_is_updatable)
    {
        return;
    }

    _display.clear();
    for (size_t i = 0; i < 4; ++i)
    {
        std::vector<LIBCARD::Card> v;
        if (m_freecell.Size(i) > 0)
        {
            size_t last_pos = m_freecell.Size(i) - 1;
            v.push_back(m_freecell.Get(i, last_pos));
        }
        else
        {
            v.push_back(LIBCARD::Card(LIBCARD::CardSuit::NOTHING, LIBCARD::CardRank::NOTHING));
        }

        _display.push_back(v);
    }
    for (size_t i = 4; i < 8; ++i)
    {
        std::vector<LIBCARD::Card> v;
        if (m_homecell.Size(i - 4) > 0)
        {
            size_t last_pos = m_homecell.Size(i - 4) - 1;
            v.push_back(m_homecell.Get(i - 4, last_pos));
        }
        else
        {
            v.push_back(LIBCARD::Card(LIBCARD::CardSuit::NOTHING, LIBCARD::CardRank::NOTHING));
        }

        _display.push_back(v);
    }

    size_t max_size = 0;
    for (size_t i = 0; i < 8; ++i)
    {
        if (m_playarea.Size(i) > max_size)
        {
            max_size = m_playarea.Size(i);
        }
        for (size_t j = 0; j < m_playarea.Size(i); ++j)
        {
            _display[i].push_back(m_playarea.Get(i, j));
        }
    }
    for (size_t i = 0; i < 8; ++i)
    {
        for (size_t j = m_playarea.Size(i); j < max_size; ++j)
        {
            _display[i].push_back(LIBCARD::Card(LIBCARD::CardSuit::NOTHING, LIBCARD::CardRank::NOTHING));
        }
    }
}

void Board::Place(LIBCARD::Deck& _deck)
{
    m_playarea.Add(_deck);
}

bool Board::Process(const std::string& _input, std::string& _err_msg)
{
    MoveCommand<PlayArea, PlayArea> m(m_playarea, 1, 1, m_playarea, 2, 2);

    if (m.Execute())
    {
        m_is_updatable = true;
    }
    else
    {
        _err_msg = "Error moving";
        return false;
    }

    return true;
}
}
