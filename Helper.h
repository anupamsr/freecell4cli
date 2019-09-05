#ifndef HELPER_H_
#define HELPER_H_

#include "LibCard/Card.h"

namespace FREECELL
{
enum class CardColor {
    NOTHING, RED, BLACK
};

CardColor GetColor(const LIBCARD::CardSuit& _suit);
}

#endif // ifndef HELPER_H_
