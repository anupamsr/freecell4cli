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

        Card Get(const size_t& _from_pos_1, const size_t& _from_pos_2) const
        {
            try
            {
                return m_cards.at(_from_pos_1).at(_from_pos_2);
            }
            catch (...)
            {
                return Card(CardSuit::NOTHING, CardRank::NOTHING);
            }
        }

        void Insert(const Card& _card, const size_t& _to_pos_1, const size_t& _to_pos_2)
        {
            m_cards[_to_pos_1].insert(m_cards[_to_pos_1].begin() + _to_pos_2, _card);
        }

        void Remove(const size_t& _from_pos_1, const size_t& _from_pos_2)
        {
            m_cards[_from_pos_1].erase(m_cards[_from_pos_1].begin() + _from_pos_2);
        }

        auto Size(const size_t& _from_pos_1) const
        {
            return m_cards[_from_pos_1].size();
        }

        void Clear()
        {
            m_cards = std::vector<std::vector<Card> >(size, std::vector<Card>());
        }

    protected:
        std::vector<std::vector<Card> > m_cards;
};
}

#endif // ifndef CARDCOLLECTION_H_
