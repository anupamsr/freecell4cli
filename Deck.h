#ifndef DECK_H
#define DECK_H

#include <cstddef> // size_t
#include <vector>
#include "Card.h"

namespace FreeCell
{
class Deck
{
public:
    Deck();
    size_t Size() const;
    void   Add(const Card& _card);
    void   Add(const Deck& _deck);
    Card   Remove(const eCardSuit& _suit,
                  const eCardRank& _rank);
    void   Shuffle();
    Card   GetCard(const size_t _position) const;

private:
    std::vector<Card> mDeck;
};
}
#endif // DECK_H
