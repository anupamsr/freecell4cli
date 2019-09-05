#include "Helper.h"

FREECELL::CardColor FREECELL::GetColor(const LIBCARD::CardSuit& _suit)
{
    switch (_suit) {
    case LIBCARD::CardSuit::CLUBS:
    case LIBCARD::CardSuit::SPADES:
        return CardColor::BLACK;

    case LIBCARD::CardSuit::HEARTS:
    case LIBCARD::CardSuit::DIAMONDS:
        return CardColor::RED;

    default:
        return CardColor::NOTHING;
    }
}
