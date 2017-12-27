#ifndef CARD_H
#define CARD_H

#include "Painter.h"

namespace FreeCell
{
enum eCardSuit {
    NoSuit, Diamond, Clubs, Hearts, Spades,
};

enum eCardRank {
    Jocker, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace,
};

class Card
{
public:
    explicit Card(const eCardSuit& _suit,
                  const eCardRank& _rank);
    eCardSuit GetSuit() const;
    eCardRank GetRank() const;
    bool      IsSimilar(const Card& _card) const;
    bool      HasSimilar(const eCardSuit& _suit,
                         const eCardRank& _rank) const;
    void      Paint(const Painter& _painter) const;

private:
    eCardSuit mSuit;
    eCardRank mRank;
};
}

#endif // CARD_H
