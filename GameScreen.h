#ifndef GAMESCREEN_H_
#define GAMESCREEN_H_

#include "Output.h"
#include "Board.h"
#include <vector>
#include <iostream>

class GameScreen : public Output
{
    private:
        static std::string GetOutputStr(const LIBCARD::Card& _card);

    public:
        GameScreen()
            : m_display() {}

        void Update(const FREECELL::Board& _board);
        void Draw() const;
        void ShowStatus(const std::string& _status);
        void ShowPrompt();

    private:
        std::vector<std::vector<LIBCARD::Card> > m_display;
};

#endif // ifndef GAMESCREEN_H_
