#include "../HelpScreen.h"
#include <iostream>

HelpScreen::HelpScreen()
{}

HelpScreen::~HelpScreen()
{}

void HelpScreen::Draw() const
{
    std::cout << "\t[u]\t\tundo last move(NOT IMPLEMENTED)" << std::endl << "\t[h]\t\thelp" << std::endl << "\t[m]\t\tmove card from column #[1,2,3,4,5,6,7,8] or" << std::endl <<
    "\t\t\t[f]ree cell #[1,2,3,4] to column #[1,2,3,4,5,6,7,8] or" << std::endl << "\t\t\t[f]ree cell #[1,2,3,4] or [h]ome cell" << std::endl << "\t[e]\t\texit" << std::endl <<
    "\t[c]\t\tcheck deck for win and valid moves" << std::endl << "\t[ESC]\t\tCancel command\r\n" << std::endl;
}
