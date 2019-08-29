#ifndef HELPSCREEN_H_
#define HELPSCREEN_H_

#include "Output.h"
#include <iostream>

class HelpScreen : public Output
{
    public:
        HelpScreen() {}

        void Draw() const
        {
            std::cout << "\t[u]\t\tundo last move(NOT IMPLEMENTED)" << std::endl << "\t[h]\t\thelp" << std::endl << "\t[m]\t\tmove card from column #[1,2,3,4,5,6,7,8] or" << std::endl <<
        "\t\t\t[h]ome cell #[1,2,3,4] to column #[1,2,3,4,5,6,7,8] or" << std::endl << "\t\t\t[h]ome cell #[1,2,3,4] or [f]ree cell" << std::endl << "\t[e]\t\texit" << std::endl <<
        "\t[c]\t\tcheck deck for win and valid moves" << std::endl << "\t[ESC]\t\tCancel command\r\n" << std::endl;
        }

    private:
};

#endif // ifndef HELPSCREEN_H_
