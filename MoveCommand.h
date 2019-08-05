#ifndef MOVECOMMAND_H_
#define MOVECOMMAND_H_

#include "Command.h"
#include "CardCollection.h"

namespace FREECELL
{
template<int FromSize, int ToSize>
class MoveCommand : public Command
{
    typedef LIBCARD::CardCollection<FromSize> From;
    typedef LIBCARD::CardCollection<ToSize>   To;

    public:
        MoveCommand(const From& _from, const int& _from_pos_1, const int& _from_pos_2, const To& _to, const int& _to_pos_1, const int& _to_pos_2)
            : m_from(_from),
            m_from_pos_1(_from_pos_1),
            m_from_pos_2(_from_pos_2),
            m_to(_to),
            m_to_pos_1(_to_pos_1),
            m_to_pos_2(_to_pos_2) {}

        bool Execute()
        {
            auto card = m_from.Get(m_from_pos_1, m_from_pos_2);

            m_to.Insert(card, m_to_pos_1, m_to_pos_2);
            m_from.Remove(m_from_pos_1, m_from_pos_2);
            return true;
        }

    private:
        From m_from;
        int m_from_pos_1;
        int m_from_pos_2;
        To m_to;
        int m_to_pos_1;
        int m_to_pos_2;
};
}

#endif // ifndef MOVECOMMAND_H_
