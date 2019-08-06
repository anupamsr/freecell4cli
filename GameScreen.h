#ifndef GAMESCREEN_H_
#define GAMESCREEN_H_

#include "Output.h"
#include "Board.h"
#include <vector>
#include <iostream>

class GameScreen : public Output
{
    public:
        GameScreen() {}

        void Update(const FREECELL::Board& _board)
        {
            _board.Update(m_display);
        }

        void Draw() const
        {
            for (size_t i = 0; i < m_display[0].size(); ++i)
            {
                for (size_t j = 0; j < 8; ++j)
                {
                    LIBCARD::CardSuit suit = m_display[j][i].GetSuit();
                    LIBCARD::CardRank rank = m_display[j][i].GetRank();
                    if (suit == LIBCARD::CardSuit::NOTHING)
                    {
                        std::cout << " ";
                    }
                    else
                    {
                        std::cout << static_cast<int>(suit);
                    }

                    std::cout << " ";
                    if (rank == LIBCARD::CardRank::NOTHING)
                    {
                        std::cout << " ";
                    }
                    else
                    {
                        std::cout << static_cast<int>(rank);
                    }

                    std::cout << ", ";
                }

                std::cout << std::endl;
            }
        }

        void ShowStatus(const std::string& _status)
        {
            if (!_status.empty())
            {
                std::cerr << "STATUS: " << _status << std::endl;
            }
        }

        void ShowPrompt()
        {
            std::cout << ">> ";
        }

    private:
        std::vector<std::vector<LIBCARD::Card> > m_display;
};

#endif // ifndef GAMESCREEN_H_
