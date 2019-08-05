#ifndef CARDCOLLECTION_H_
#define CARDCOLLECTION_H_

#include "Card.h"
#include <vector>
#include <algorithm>

namespace LIBCARD
{
template<int size>
class CardCollection
{
    public:
        CardCollection()
            : m_cards(size, std::vector<Card>()) {}

        ~CardCollection() {}

        Card Get(const int& _from_pos_1, const int& _from_pos_2) const
        {
            return m_cards[_from_pos_1][_from_pos_2];
        }

        void Insert(const Card& _card, const int& _to_pos_1, const int& _to_pos_2)
        {
            m_cards[_to_pos_1].insert(m_cards[_to_pos_1].begin() + _to_pos_2, _card);
        }

        void Remove(const int& _from_pos_1, const int& _from_pos_2)
        {
            m_cards[_from_pos_1].erase(m_cards[_from_pos_1].begin() + _from_pos_2);
        }

    protected:
        std::vector<std::vector<Card> > m_cards;
};
}

#endif // ifndef CARDCOLLECTION_H_
