#include "Deck.h"

namespace FreeCell {
Deck::Deck() : mDeck()
{
    mDeck.push_back(Card(eCardSuit::NoSuit, eCardRank::Jocker));

    mDeck.push_back(Card(eCardSuit::Diamond, eCardRank::Two));
    mDeck.push_back(Card(eCardSuit::Diamond, eCardRank::Three));
    mDeck.push_back(Card(eCardSuit::Diamond, eCardRank::Four));
    mDeck.push_back(Card(eCardSuit::Diamond, eCardRank::Five));
    mDeck.push_back(Card(eCardSuit::Diamond, eCardRank::Six));
    mDeck.push_back(Card(eCardSuit::Diamond, eCardRank::Seven));
    mDeck.push_back(Card(eCardSuit::Diamond, eCardRank::Eight));
    mDeck.push_back(Card(eCardSuit::Diamond, eCardRank::Nine));
    mDeck.push_back(Card(eCardSuit::Diamond, eCardRank::Ten));
    mDeck.push_back(Card(eCardSuit::Diamond, eCardRank::Jack));
    mDeck.push_back(Card(eCardSuit::Diamond, eCardRank::Queen));
    mDeck.push_back(Card(eCardSuit::Diamond, eCardRank::King));
    mDeck.push_back(Card(eCardSuit::Diamond, eCardRank::Ace));

    mDeck.push_back(Card(eCardSuit::Clubs, eCardRank::Two));
    mDeck.push_back(Card(eCardSuit::Clubs, eCardRank::Three));
    mDeck.push_back(Card(eCardSuit::Clubs, eCardRank::Four));
    mDeck.push_back(Card(eCardSuit::Clubs, eCardRank::Five));
    mDeck.push_back(Card(eCardSuit::Clubs, eCardRank::Six));
    mDeck.push_back(Card(eCardSuit::Clubs, eCardRank::Seven));
    mDeck.push_back(Card(eCardSuit::Clubs, eCardRank::Eight));
    mDeck.push_back(Card(eCardSuit::Clubs, eCardRank::Nine));
    mDeck.push_back(Card(eCardSuit::Clubs, eCardRank::Ten));
    mDeck.push_back(Card(eCardSuit::Clubs, eCardRank::Jack));
    mDeck.push_back(Card(eCardSuit::Clubs, eCardRank::Queen));
    mDeck.push_back(Card(eCardSuit::Clubs, eCardRank::King));
    mDeck.push_back(Card(eCardSuit::Clubs, eCardRank::Ace));

    mDeck.push_back(Card(eCardSuit::Hearts, eCardRank::Two));
    mDeck.push_back(Card(eCardSuit::Hearts, eCardRank::Three));
    mDeck.push_back(Card(eCardSuit::Hearts, eCardRank::Four));
    mDeck.push_back(Card(eCardSuit::Hearts, eCardRank::Five));
    mDeck.push_back(Card(eCardSuit::Hearts, eCardRank::Six));
    mDeck.push_back(Card(eCardSuit::Hearts, eCardRank::Seven));
    mDeck.push_back(Card(eCardSuit::Hearts, eCardRank::Eight));
    mDeck.push_back(Card(eCardSuit::Hearts, eCardRank::Nine));
    mDeck.push_back(Card(eCardSuit::Hearts, eCardRank::Ten));
    mDeck.push_back(Card(eCardSuit::Hearts, eCardRank::Jack));
    mDeck.push_back(Card(eCardSuit::Hearts, eCardRank::Queen));
    mDeck.push_back(Card(eCardSuit::Hearts, eCardRank::King));
    mDeck.push_back(Card(eCardSuit::Hearts, eCardRank::Ace));

    mDeck.push_back(Card(eCardSuit::Spades, eCardRank::Two));
    mDeck.push_back(Card(eCardSuit::Spades, eCardRank::Three));
    mDeck.push_back(Card(eCardSuit::Spades, eCardRank::Four));
    mDeck.push_back(Card(eCardSuit::Spades, eCardRank::Five));
    mDeck.push_back(Card(eCardSuit::Spades, eCardRank::Six));
    mDeck.push_back(Card(eCardSuit::Spades, eCardRank::Seven));
    mDeck.push_back(Card(eCardSuit::Spades, eCardRank::Eight));
    mDeck.push_back(Card(eCardSuit::Spades, eCardRank::Nine));
    mDeck.push_back(Card(eCardSuit::Spades, eCardRank::Ten));
    mDeck.push_back(Card(eCardSuit::Spades, eCardRank::Jack));
    mDeck.push_back(Card(eCardSuit::Spades, eCardRank::Queen));
    mDeck.push_back(Card(eCardSuit::Spades, eCardRank::King));
    mDeck.push_back(Card(eCardSuit::Spades, eCardRank::Ace));
}

void Deck::Shuffle()
{

}
}
