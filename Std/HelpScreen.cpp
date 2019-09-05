#include "../HelpScreen.h"
#include <iostream>

HelpScreen::HelpScreen()
{}

HelpScreen::~HelpScreen()
{}

void HelpScreen::Draw() const
{
    std::cout << "\t[u]\t\tundo last move(NOT IMPLEMENTED)" << std::endl;
    std::cout << "\t[h]\t\thelp" << std::endl;
    std::cout << "\t[s]\t\tshow board (again)\n\r" << std::endl;
    std::cout << "\t[m]\t\tmove card from column #[1,2,3,4,5,6,7,8] or" << std::endl;
    std::cout << "\t\t\t[f]ree cell #[1,2,3,4] to column #[1,2,3,4,5,6,7,8] or" << std::endl;
    std::cout << "\t\t\t[f]ree cell #[1,2,3,4] or [h]ome cell" << std::endl;
    std::cout << "\t[e]\t\texit" << std::endl;
    std::cout << "\t[c]\t\tcheck deck for win and valid moves" << std::endl;
}
