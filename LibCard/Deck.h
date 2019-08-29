#ifndef DECK_H_
#define DECK_H_

#include "Card.h"
#include <vector>
#include <algorithm>

namespace LIBCARD
{
const auto JOCKER_CARD = LIBCARD::Card(LIBCARD::CardSuit::JOCKER, LIBCARD::CardRank::JOCKER);
struct Deck
{
    Deck();
    void AddCard(const Card& _card);
    bool RemoveCard(const Card& _card);
    void Recreate();
    template<typename T>
    void Shuffle(T& t)
    {
        std::shuffle(m_cards.begin(), m_cards.end(), t);
    }

    std::vector<Card> m_cards;
};
}

#endif // ifndef DECK_H_
