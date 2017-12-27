#include "Card.h"

namespace FreeCell
{
Card::Card(const eCardSuit& _suit, const eCardRank& _rank)
    : mSuit(_suit),
    mRank(_rank) {}

eCardSuit Card::GetSuit() const
{
    return mSuit;
}

eCardRank Card::GetRank() const
{
    return mRank;
}

bool Card::IsSimilar(const Card& _card) const
{
    return HasSimilar(_card.GetSuit(), _card.GetRank());
}

bool Card::HasSimilar(const eCardSuit& _suit, const eCardRank& _rank) const
{
    return mSuit == _suit && mRank == _rank;
}

void Card::Paint(const Painter& _painter) const
{
    _painter.Paint(*this);
}
}
