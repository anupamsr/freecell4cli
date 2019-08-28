#ifndef VALIDMOVECOMMAND_H_
#define VALIDMOVECOMMAND_H_

#include "MoveCommand.h"
#include "Homecell.h"

namespace FREECELL
{
enum class CardColor {
    NOTHING, RED, BLACK
};

CardColor GetColor(const LIBCARD::CardSuit& _suit)
{
    switch (_suit) {
    case LIBCARD::CardSuit::CLUBS:
    case LIBCARD::CardSuit::SPADES:
        return CardColor::BLACK;

    case LIBCARD::CardSuit::HEARTS:
    case LIBCARD::CardSuit::DIAMONDS:
        return CardColor::RED;

    default:
        return CardColor::NOTHING;
    }
}

template<typename From, typename To>
class ValidMoveCommand : public Command
{
public:
    ValidMoveCommand(From& _from, const size_t& _from_pos, To& _to, const size_t& _to_pos)
        : m_from(_from),
        m_from_pos(_from_pos),
        m_to(_to),
        m_to_pos(_to_pos)
    {}

    bool Execute()
    {
        auto m_from_pos_1 = m_from_pos - 1;

        if (m_from.Size(m_from_pos_1) == 0)
        {
            return false;
        }

        auto m_from_pos_2 = m_from.Size(m_from_pos_1) - 1;
        auto from_card    = m_from.Get(m_from_pos_1, m_from_pos_2);
        auto from_color   = GetColor(from_card.GetSuit());
        auto m_to_pos_1   = m_to_pos - 1;
        auto m_to_pos_2   = size_t(0);
        if (m_to.Size(m_to_pos_1) != 0)
        {
            m_to_pos_2 = m_to.Size(m_to_pos_1) - 1;
            auto to_card  = m_to.Get(m_to_pos_1, m_to_pos_2);
            auto to_color = GetColor(to_card.GetSuit());
            if (from_color == to_color)
            {
                return false;
            }

            ++m_to_pos_2;
        }

        return MoveCommand<From, To>(m_from, m_from_pos_1, m_from_pos_2, m_to, m_to_pos_1, m_to_pos_2).Execute();
    }

private:
    From& m_from;
    size_t m_from_pos;
    To& m_to;
    size_t m_to_pos;
};

template<typename From>
class ValidMoveCommand<From, Homecell> : public Command
{
public:
    ValidMoveCommand(From& _from, const size_t& _from_pos, Homecell& _to)
        : m_from(_from),
        m_from_pos(_from_pos),
        m_to(_to)
    {}

    bool Execute()
    {
        auto m_from_pos_1 = m_from_pos - 1;

        if (m_from.Size(m_from_pos_1) == 0)
        {
            return false;
        }

        auto m_from_pos_2 = m_from.Size(m_from_pos_1) - 1;
        auto from_card    = m_from.Get(m_from_pos_1, m_from_pos_2);
        auto m_to_pos_1   = size_t(0);

        switch (from_card.GetSuit()) {
        case LIBCARD::CardSuit::CLUBS:
            m_to_pos_1 = 0;
            break;

        case LIBCARD::CardSuit::HEARTS:
            m_to_pos_1 = 1;
            break;

        case LIBCARD::CardSuit::SPADES:
            m_to_pos_1 = 2;
            break;

        case LIBCARD::CardSuit::DIAMONDS:
            m_to_pos_1 = 3;
            break;

        default:
            return false;
        }

        auto m_to_pos_2 = m_to.Size(m_to_pos_1);
        return MoveCommand<From, Homecell>(m_from, m_from_pos_1, m_from_pos_2, m_to, m_to_pos_1, m_to_pos_2).Execute();
    }

private:
    From& m_from;
    size_t m_from_pos;
    Homecell& m_to;
};
}

#endif // ifndef VALIDMOVECOMMAND_H_
