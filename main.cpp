#include "MoveCommand.h"
#include "Screen.h"
#include "StdIn.h"

int main()
{
    FREECELL::Board b;
    LIBCARD::Deck   d;

    d.Shuffle();
    b.Place(d);
    Screen s;
    StdIn  in;
    while (true)
    {
        s.Update(b);
        s.Draw();
        std::string input;

        do
        {
            s.ShowPrompt();
            in.GetString(input);
        } while (input.empty());
        if (input[0] == 'q')
        {
            break;
        }

        std::string err_msg;
        bool success = b.Process(input, err_msg);
        if (!success)
        {
            s.ShowStatus(err_msg);
        }
    }

    s.ShowStatus("Thank you!");
    return 0;
}
