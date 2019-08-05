#ifndef DECK_H_
#define DECK_H_

#include "Card.h"
#include <vector>

namespace LIBCARD
{
struct Deck
{
    Deck()
    {
        AddJocker();
        AddClubs();
        AddHearts();
        AddSpades();
        AddDiamonds();
    }

    void AddCard(const Card& _card)
    {
        m_cards.push_back(_card);
    }

    void AddJocker()
    {
        AddCard(Card(CardSuit::JOCKER, CardRank::JOCKER));
    }

    void AddClubs()
    {
        AddCard(Card(CardSuit::CLUBS, CardRank::ACE));
        AddCard(Card(CardSuit::CLUBS, CardRank::TWO));
        AddCard(Card(CardSuit::CLUBS, CardRank::THREE));
        AddCard(Card(CardSuit::CLUBS, CardRank::FOUR));
        AddCard(Card(CardSuit::CLUBS, CardRank::FIVE));
        AddCard(Card(CardSuit::CLUBS, CardRank::SIX));
        AddCard(Card(CardSuit::CLUBS, CardRank::SEVEN));
        AddCard(Card(CardSuit::CLUBS, CardRank::EIGHT));
        AddCard(Card(CardSuit::CLUBS, CardRank::NINE));
        AddCard(Card(CardSuit::CLUBS, CardRank::TEN));
        AddCard(Card(CardSuit::CLUBS, CardRank::JACK));
        AddCard(Card(CardSuit::CLUBS, CardRank::QUEEN));
        AddCard(Card(CardSuit::CLUBS, CardRank::KING));
    }

    void AddHearts()
    {
        AddCard(Card(CardSuit::HEARTS, CardRank::ACE));
        AddCard(Card(CardSuit::HEARTS, CardRank::TWO));
        AddCard(Card(CardSuit::HEARTS, CardRank::THREE));
        AddCard(Card(CardSuit::HEARTS, CardRank::FOUR));
        AddCard(Card(CardSuit::HEARTS, CardRank::FIVE));
        AddCard(Card(CardSuit::HEARTS, CardRank::SIX));
        AddCard(Card(CardSuit::HEARTS, CardRank::SEVEN));
        AddCard(Card(CardSuit::HEARTS, CardRank::EIGHT));
        AddCard(Card(CardSuit::HEARTS, CardRank::NINE));
        AddCard(Card(CardSuit::HEARTS, CardRank::TEN));
        AddCard(Card(CardSuit::HEARTS, CardRank::JACK));
        AddCard(Card(CardSuit::HEARTS, CardRank::QUEEN));
        AddCard(Card(CardSuit::HEARTS, CardRank::KING));
    }

    void AddSpades()
    {
        AddCard(Card(CardSuit::SPADES, CardRank::ACE));
        AddCard(Card(CardSuit::SPADES, CardRank::TWO));
        AddCard(Card(CardSuit::SPADES, CardRank::THREE));
        AddCard(Card(CardSuit::SPADES, CardRank::FOUR));
        AddCard(Card(CardSuit::SPADES, CardRank::FIVE));
        AddCard(Card(CardSuit::SPADES, CardRank::SIX));
        AddCard(Card(CardSuit::SPADES, CardRank::SEVEN));
        AddCard(Card(CardSuit::SPADES, CardRank::EIGHT));
        AddCard(Card(CardSuit::SPADES, CardRank::NINE));
        AddCard(Card(CardSuit::SPADES, CardRank::TEN));
        AddCard(Card(CardSuit::SPADES, CardRank::JACK));
        AddCard(Card(CardSuit::SPADES, CardRank::QUEEN));
        AddCard(Card(CardSuit::SPADES, CardRank::KING));
    }

    void AddDiamonds()
    {
        AddCard(Card(CardSuit::DIAMONDS, CardRank::ACE));
        AddCard(Card(CardSuit::DIAMONDS, CardRank::TWO));
        AddCard(Card(CardSuit::DIAMONDS, CardRank::THREE));
        AddCard(Card(CardSuit::DIAMONDS, CardRank::FOUR));
        AddCard(Card(CardSuit::DIAMONDS, CardRank::FIVE));
        AddCard(Card(CardSuit::DIAMONDS, CardRank::SIX));
        AddCard(Card(CardSuit::DIAMONDS, CardRank::SEVEN));
        AddCard(Card(CardSuit::DIAMONDS, CardRank::EIGHT));
        AddCard(Card(CardSuit::DIAMONDS, CardRank::NINE));
        AddCard(Card(CardSuit::DIAMONDS, CardRank::TEN));
        AddCard(Card(CardSuit::DIAMONDS, CardRank::JACK));
        AddCard(Card(CardSuit::DIAMONDS, CardRank::QUEEN));
        AddCard(Card(CardSuit::DIAMONDS, CardRank::KING));
    }

    std::vector<Card> m_cards;
};
}

#endif // ifndef DECK_H_
