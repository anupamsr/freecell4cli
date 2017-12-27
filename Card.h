#ifndef CARD_H
#define CARD_H

namespace FreeCell
{
enum eCardSuit
{
    NoSuit,
    Diamond,
    Clubs,
    Hearts,
    Spades,
};

enum eCardRank
{
    Jocker,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace,
};

class Card
{
public:
    explicit Card(const eCardSuit & _suit, const eCardRank & _rank);
private:
    eCardSuit mSuit;
    eCardRank mRank;
};
}

#endif // CARD_H
