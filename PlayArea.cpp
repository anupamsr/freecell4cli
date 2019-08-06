#include "PlayArea.h"

namespace FREECELL
{
PlayArea::PlayArea() {}

PlayArea::~PlayArea() {}

void PlayArea::Add(LIBCARD::Deck& _deck)
{
    size_t column = 0;

    while (_deck.m_cards.size() > 0)
    {
        if (_deck.m_cards.begin()->GetSuit() != LIBCARD::CardSuit::JOCKER && _deck.m_cards.begin()->GetRank() != LIBCARD::CardRank::JOCKER)
        {
            m_cards[column].insert(m_cards[column].end(), std::make_move_iterator(_deck.m_cards.begin()), std::make_move_iterator(_deck.m_cards.begin() + 1));
            ++column;
            column %= PLAY_AREA_SIZE;
        }

        _deck.m_cards.erase(_deck.m_cards.begin(), _deck.m_cards.begin() + 1);
    }
}
}
