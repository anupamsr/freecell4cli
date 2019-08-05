#include "PlayArea.h"

namespace LIBCARD
{
PlayArea::PlayArea() {}

PlayArea::~PlayArea() {}

void PlayArea::Add(Deck& _deck)
{
    size_t column = 0;

    while (_deck.m_cards.size() > 0)
    {
        m_cards[column].insert(m_cards[column].end(), std::make_move_iterator(_deck.m_cards.begin()), std::make_move_iterator(_deck.m_cards.begin() + 1));
        ++column;
        column %= PLAY_AREA_SIZE;
    }

    _deck.m_cards.clear();
}
}
