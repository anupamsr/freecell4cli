#include "Board.h"
#include "LibCard/Deck.h"
#include "ValidMoveCommand.h"

namespace FREECELL
{
Board::Board()
    : m_freecell(),
    m_homecell(),
    m_playarea(),
    m_is_updatable(true)
{}

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

bool Board::AutoCheck(std::string& _err_msg)
{
    std::string err_msg;
    bool no_possible_move = false;
    bool has_moved        = false;

    while (!no_possible_move)
    {
        no_possible_move = true;
        std::string moves[PLAY_AREA_SIZE] = { "m1h", "m2h", "m3h", "m4h", "m5h", "m6h", "m7h", "m8h" };
        for (auto const& move : moves)
        {
            auto success = Process(move, err_msg);
            if (success)
            {
                has_moved        = true;
                no_possible_move = false;
            }
        }
    }
    if (has_moved)
    {
        m_is_updatable = true;
    }
    else
    {
        _err_msg       = "Nothing to move";
        m_is_updatable = false;
    }

    return has_moved;
}

bool Board::Process(const std::string& _input, std::string& _err_msg)
{
    // From
    if (_input.size() > 2)
    {
        if (_input[1] == '1' || _input[1] == '2' || _input[1] == '3' || _input[1] == '4' || _input[1] == '5' || _input[1] == '6' || _input[1] == '7' || _input[1] == '8')
        {
            // playarea position
            auto first = static_cast<size_t>(_input[1] - '0');
            // to
            if (_input.size() == 4 && _input[2] == 'f')
            {
                // freecell
                if (_input[3] == '1' || _input[3] == '2' || _input[3] == '3' || _input[3] == '4')
                {
                    // position
                    auto second = static_cast<size_t>(_input[3] - '0');
                    ValidMoveCommand<PlayArea, Freecell> m(m_playarea, first, m_freecell, second);
                    if (m.Execute())
                    {
                        m_is_updatable = true;
                    }
                    else
                    {
                        _err_msg = "Could not move";
                        return false;
                    }
                }
                else
                {
                    _err_msg = "Incorrect freecell position";
                    return false;
                }
            }
            else if (_input[2] == '1' || _input[2] == '2' || _input[2] == '3' || _input[2] == '4' || _input[2] == '5' || _input[2] == '6' || _input[2] == '7' || _input[2] == '8')
            {
                // playarea position
                auto second = static_cast<size_t>(_input[2] - '0');
                ValidMoveCommand<PlayArea, PlayArea> m(m_playarea, first, m_playarea, second);
                if (m.Execute())
                {
                    m_is_updatable = true;
                }
                else
                {
                    _err_msg = "Could not move";
                    return false;
                }
            }
            else if (_input[2] == 'h')
            {
                // homecell
                ValidMoveCommand<PlayArea, Homecell> m(m_playarea, first, m_homecell);
                if (m.Execute())
                {
                    m_is_updatable = true;
                }
                else
                {
                    _err_msg = "Could not move";
                    return false;
                }
            }
            else
            {
                _err_msg = "Incorrect target";
                return false;
            }
        }
        else if (_input[1] == 'f')
        {
            // freecell
            if (_input[2] == '1' || _input[2] == '2' || _input[2] == '3' || _input[2] == '4')
            {
                // position
                auto first = static_cast<size_t>(_input[2] - '0');
                // to
                if (_input.size() == 4 &&
                    (_input[3] == '1' || _input[3] == '2' || _input[3] == '3' || _input[3] == '4' || _input[3] == '5' || _input[3] == '6' || _input[3] == '7' || _input[3] == '8'))
                {
                    // playarea position
                    auto second = static_cast<size_t>(_input[3] - '0');
                    ValidMoveCommand<Freecell, PlayArea> m(m_freecell, first, m_playarea, second);
                    if (m.Execute())
                    {
                        m_is_updatable = true;
                    }
                    else
                    {
                        _err_msg = "Could not move";
                        return false;
                    }
                }
                else if (_input.size() == 5 && _input[3] == 'f')
                {
                    // freecell
                    if (_input[4] == '1' || _input[4] == '2' || _input[4] == '3' || _input[4] == '4')
                    {
                        // position
                        auto second = static_cast<size_t>(_input[3] - '0');
                        ValidMoveCommand<Freecell, Freecell> m(m_freecell, first, m_freecell, second);
                        if (m.Execute())
                        {
                            m_is_updatable = true;
                        }
                        else
                        {
                            _err_msg = "Could not move";
                            return false;
                        }
                    }
                }
                else if (_input.size() == 4 && _input[3] == 'h')
                {
                    // homecell
                    ValidMoveCommand<Freecell, Homecell> m(m_freecell, first, m_homecell);
                    if (m.Execute())
                    {
                        m_is_updatable = true;
                    }
                    else
                    {
                        _err_msg = "Could not move";
                        return false;
                    }
                }
                else
                {
                    _err_msg = "Incorrect target";
                    return false;
                }
            }
            else
            {
                _err_msg = "Incorrect freecell position";
                return false;
            }
        }
        else
        {
            _err_msg = "Incorrect source";
            return false;
        }
    }
    else
    {
        _err_msg = "Incomplete command";
        return false;
    }

    return true;
}

void Board::Clear()
{
    m_freecell.Clear();
    m_homecell.Clear();
    m_playarea.Clear();
    m_is_updatable = true;
}
}
