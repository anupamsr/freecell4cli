#ifndef MOVECOMMAND_H_
#define MOVECOMMAND_H_

#include "Command.h"
#include "LibCard/Card.h"
#include <cstddef>

namespace FREECELL
{
template<typename From, typename To>
class MoveCommand : public Command
{
    public:
        MoveCommand(From& _from, const size_t& _from_pos_1, const size_t& _from_pos_2, To& _to, const size_t& _to_pos_1, const size_t& _to_pos_2)
            : m_from(_from),
            m_from_pos_1(_from_pos_1),
            m_from_pos_2(_from_pos_2),
            m_to(_to),
            m_to_pos_1(_to_pos_1),
            m_to_pos_2(_to_pos_2)
        {}

        bool Execute()
        {
            auto card = m_from.Get(m_from_pos_1, m_from_pos_2);

            if (card.GetSuit() == LIBCARD::CardSuit::NOTHING && card.GetRank() == LIBCARD::CardRank::NOTHING)
            {
                return false;
            }

            m_to.Insert(card, m_to_pos_1, m_to_pos_2);
            m_from.Remove(m_from_pos_1, m_from_pos_2);
            return true;
        }

    private:
        From& m_from;
        size_t m_from_pos_1;
        size_t m_from_pos_2;
        To& m_to;
        size_t m_to_pos_1;
        size_t m_to_pos_2;
};
}

#endif // ifndef MOVECOMMAND_H_
