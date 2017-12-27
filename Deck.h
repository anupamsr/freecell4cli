#ifndef DECK_H
#define DECK_H

#include <vector>
#include "Card.h"

namespace FreeCell {
class Deck
{
public:
    Deck();
    void Shuffle();
private:
    std::vector<Card> mDeck;
};
}
#endif // DECK_H
