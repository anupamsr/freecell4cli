#include "MoveCommand.h"
#include "GameScreen.h"
#include "HelpScreen.h"
#include "StdIn.h"
#include <random>
#include <functional>

template<class T = std::mt19937, std::size_t N = T::state_size>
auto ProperlySeededRandomEngine()->typename std::enable_if<!!N, T>::type
{
    typename T::result_type random_data[N];
    std::random_device source;
    std::generate(std::begin(random_data), std::end(random_data), std::ref(source));
    std::seed_seq seeds(std::begin(random_data), std::end(random_data));
    T seededEngine(seeds);
    return seededEngine;
}

int main()
{
    LIBCARD::Deck d;
    auto jocker = LIBCARD::Card(LIBCARD::CardSuit::JOCKER, LIBCARD::CardRank::JOCKER);

    d.RemoveCard(jocker);
    auto rng = ProperlySeededRandomEngine();
    d.Shuffle(rng);
    FREECELL::Board b;
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
        if (input[0] == 'q' || input[0] == 'e')
        {
            break;
        }
        else if (input[0] == 'h')
        {
            h.Draw();
        }
        else if (input[0] == 'n')
        {
            b.Clear();
            d.Recreate();
            d.RemoveCard(jocker);
            d.Shuffle(rng);
            b.Place(d);
            g.Update(b);
            g.Draw();
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
        else
        {
            g.ShowStatus("Unknown command");
        }
    }

    g.ShowStatus("Thank you!");
    return 0;
}
