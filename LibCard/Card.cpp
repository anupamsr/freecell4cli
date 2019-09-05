#include "Card.h"

namespace LIBCARD
{
Card::Card(const CardSuit& _suit, const CardRank& _rank)
    : m_suit(_suit),
    m_rank(_rank)
{}

Card::~Card()
{}

CardSuit Card::GetSuit() const
{
    return m_suit;
}

CardRank Card::GetRank() const
{
    return m_rank;
}

void Card::SetSuit(const CardSuit& _suit)
{
    m_suit = _suit;
}

void Card::SetRank(const CardRank& _rank)
{
    m_rank = _rank;
}

bool Card::operator==(const Card& _card)
{
    return m_suit == _card.m_suit && m_rank == _card.m_rank;
}

bool Card::operator!=(const Card& _card)
{
    return !(this == &_card);
}
}
