#include "GameScreen.h"

void GameScreen::Update(const FREECELL::Board& _board)
{
    _board.Update(m_display);
}

void GameScreen::Draw() const
{
    for (size_t i = 0; i < m_display[0].size(); ++i)
    {
        for (size_t j = 0; j < 8; ++j)
        {
            std::cout << GetOutputStr(m_display[j][i]);
            std::cout << ", ";
        }

        std::cout << std::endl;
    }
}

void GameScreen::ShowStatus(const std::string& _status)
{
    if (!_status.empty())
    {
        std::cerr << "STATUS: " << _status << std::endl;
    }
}

void GameScreen::ShowPrompt()
{
    std::cout << ">> ";
}

std::string GameScreen::GetOutputStr(const LIBCARD::Card& _card)
{
    auto rank = _card.GetRank();

    std::string output;

    switch (rank) {
    case LIBCARD::CardRank::TWO:
        output += " 2";
        break;

    case LIBCARD::CardRank::THREE:
        output += " 3";
        break;

    case LIBCARD::CardRank::FOUR:
        output += " 4";
        break;

    case LIBCARD::CardRank::FIVE:
        output += " 5";
        break;

    case LIBCARD::CardRank::SIX:
        output += " 6";
        break;

    case LIBCARD::CardRank::SEVEN:
        output += " 7";
        break;

    case LIBCARD::CardRank::EIGHT:
        output += " 8";
        break;

    case LIBCARD::CardRank::NINE:
        output += " 9";
        break;

    case LIBCARD::CardRank::TEN:
        output += "10";
        break;

    case LIBCARD::CardRank::JACK:
        output += " J";
        break;

    case LIBCARD::CardRank::QUEEN:
        output += " Q";
        break;

    case LIBCARD::CardRank::KING:
        output += " K";
        break;

    case LIBCARD::CardRank::ACE:
        output += " A";
        break;

    case LIBCARD::CardRank::JOCKER:
        output += ":)";
        break;

    case LIBCARD::CardRank::NOTHING:
        output += "  ";
    }

    auto suit = _card.GetSuit();

    switch (suit) {
    case LIBCARD::CardSuit::DIAMONDS:
        output += "D";
        break;

    case LIBCARD::CardSuit::CLUBS:
        output += "C";
        break;

    case LIBCARD::CardSuit::HEARTS:
        output += "H";
        break;

    case LIBCARD::CardSuit::SPADES:
        output += "S";
        break;

    case LIBCARD::CardSuit::JOCKER:
        output += "j";
        break;

    case LIBCARD::CardSuit::NOTHING:
        output += " ";
    }

    return output;
}
