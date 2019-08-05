#ifndef CARDCOLLECTION_H_
#define CARDCOLLECTION_H_

#include "Card.h"
#include <vector>

namespace LIBCARD
{
template<int size>
class CardCollection
{
    public:
        CardCollection()
            : m_cards(size, std::vector<Card>()) {}

        ~CardCollection() {}

    protected:
        std::vector<std::vector<Card> > m_cards;
};
}

#endif // ifndef CARDCOLLECTION_H_
