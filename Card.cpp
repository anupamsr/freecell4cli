#include "Card.h"

namespace LIBCARD
{
Card::Card(const CardSuit& _suit, const CardRank& _rank)
    : m_suit(_suit),
    m_rank(_rank) {}

Card::~Card() {}

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
}
