#include "../HelpScreen.h"
#include "Curses.h"

HelpScreen::HelpScreen()
{
    Curses::Instance().Initialize();
}

HelpScreen::~HelpScreen()
{
    Curses::Instance().End();
}

void HelpScreen::Draw() const
{
    addstr("\t[u]\t\tundo last move(NOT IMPLEMENTED)\n\r");
    addstr("\t[h]\t\thelp\n\r");
    addstr("\t[m]\t\tmove card from column #[1,2,3,4,5,6,7,8] or\n\r");
    addstr("\t\t\t[f]ree cell #[1,2,3,4] to column #[1,2,3,4,5,6,7,8] or\n\r");
    addstr("\t\t\t[f]ree cell #[1,2,3,4] or [h]ome cell\n\r");
    addstr("\t[e]\t\texit\n\r");
    addstr("\t[c]\t\tcheck deck for win and valid moves\n\r" "\t[ESC]\t\tCancel command\n\r");
}
