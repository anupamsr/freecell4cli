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
    HelpScreen h;
    StdIn in;
    while (true)
    {
        g.Update(b);
        g.Draw();
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
        if (input[0] == 'h')
        {
            h.Draw();
        }

        std::string err_msg;
        bool success = b.Process(input, err_msg);
        if (!success)
        {
            g.ShowStatus(err_msg);
        }
    }

    g.ShowStatus("Thank you!");
    return 0;
}
