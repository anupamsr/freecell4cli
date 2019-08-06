#include "MoveCommand.h"
#include "GameScreen.h"
#include "HelpScreen.h"
#include "StdIn.h"

int main()
{
    FREECELL::Board b;
    LIBCARD::Deck   d;

    d.Shuffle();
    b.Place(d);
    GameScreen g;
    g.Update(b);
    g.Draw();
    HelpScreen h;
    StdIn in;
    while (true)
    {
        std::string input;

        do
        {
            g.ShowPrompt();
            in.GetString(input);
        } while (input.empty());
        if (input[0] == 'q')
        {
            break;
        }
        else if (input[0] == 'h')
        {
            h.Draw();
        }
        else if (input[0] == 'm')
        {
            std::string err_msg;
            bool success = b.Process(input, err_msg);
            if (success)
            {
                g.Update(b);
                g.Draw();
            }
            else
            {
                g.ShowStatus(err_msg);
            }
        }
    }

    g.ShowStatus("Thank you!");
    return 0;
}
