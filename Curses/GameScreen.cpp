#include "../GameScreen.h"
#include "../Helper.h"
#include "Curses.h"

static void PrintCard(const LIBCARD::Card& _card);
GameScreen::GameScreen()
    : m_display()
{
    Curses::Instance().Initialize();

    //    bkgd(COLOR_PAIR(1));
}

GameScreen::~GameScreen()
{
    Curses::Instance().End();
}

void GameScreen::Update(const FREECELL::Board& _board)
{
    _board.Update(m_display);
}

void GameScreen::Draw() const
{
    attrset(COLOR_PAIR(1));
    for (size_t j = 0; j < 7; ++j)
    {
        PrintCard(m_display[j][0]);
        attron(COLOR_PAIR(1));
        addstr("  ");
    }

    PrintCard(m_display[7][0]);
    attron(COLOR_PAIR(4));
    addstr("\n\r");
    for (size_t j = 0; j < 7; ++j)
    {
        addstr("---  ");
    }

    addstr("---\n\r");
    for (size_t i = 1; i < m_display[0].size(); ++i)
    {
        for (size_t j = 0; j < 7; ++j)
        {
            PrintCard(m_display[j][i]);
            attron(COLOR_PAIR(1));
            addstr("  ");
        }

        PrintCard(m_display[7][i]);
        attron(COLOR_PAIR(1));
        addstr("\n\r");
    }

    attroff(COLOR_PAIR(1));
    refresh();
}

void GameScreen::ShowStatus(const std::string& _status)
{
    addstr("\n\r");
    if (!_status.empty())
    {
        attron(A_BOLD);
        addstr("STATUS: ");
        attroff(A_BOLD);
        addstr(_status.c_str());
        addstr("\n\r");
        refresh();
    }
}

void GameScreen::ShowPrompt()
{
    attron(COLOR_PAIR(4) | A_BOLD);
    addstr("\n\r>>");
    attroff(COLOR_PAIR(4) | A_BOLD);
    addstr(" ");
    refresh();
}

void PrintCard(const LIBCARD::Card& _card)
{
    auto suit       = _card.GetSuit();
    auto color      = FREECELL::GetColor(suit);
    auto color_pair = int(1);

    switch (color) {
    case FREECELL::CardColor::RED:
        color_pair = 2;
        break;

    case FREECELL::CardColor::BLACK:
        color_pair = 3;
        break;

    default:
        break;
    }

    attron(COLOR_PAIR(color_pair));
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

    addstr(output.c_str());
    attroff(COLOR_PAIR(color_pair));
}
