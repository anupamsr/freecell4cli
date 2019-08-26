#include "Deck.h"

namespace LIBCARD
{
Deck::Deck()
    : m_cards()
{
    Recreate();
}

void Deck::Recreate()
{
    m_cards.clear();
    AddCard(Card(CardSuit::JOCKER, CardRank::JOCKER));
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

void Deck::AddCard(const Card& _card)
{
    m_cards.push_back(_card);
}

bool Deck::RemoveCard(const Card& _card)
{
    for (auto it = m_cards.begin(); it != m_cards.end(); ++it)
    {
        if (it->GetRank() == _card.GetRank() && it->GetSuit() == _card.GetSuit())
        {
            m_cards.erase(it);
            return true;
        }
    }

    return false;
}
}
