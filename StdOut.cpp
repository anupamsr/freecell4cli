#include "StdOut.h"
#include "Board.h"
#include <iostream>

// template<typename T> T Max(T v)
// {
//    return v;
// }
// template<typename T, typename ... Args> T Max(T first, Args ... args)
// {
//    return std::max(first, Max(args ...));
// }
StdOut::StdOut() {}

void StdOut::Paint(const FreeCell::Board& _board) const
{
    std::cout << "Free cells:" << std::endl;
    for (size_t i = 0; i < 4; ++i)
    {
        if (_board.GetFreecell()[i].size() > 0)
        {
            Paint(_board.GetFreecell()[i].front());
        }
        else
        {
            std::cout << "   ";
        }

        std::cout << " ";
    }

    std::cout << std::endl;
    std::cout << "Home cells:" << std::endl;
    for (size_t i = 0; i < 4; ++i)
    {
        if (_board.GetHomecell()[i].size() > 0)
        {
            Paint(_board.GetHomecell()[i].front());
        }
        else
        {
            std::cout << "   ";
        }

        std::cout << " ";
    }

    std::cout << std::endl;
    std::cout << "Board:" << std::endl;

    // size_t max_length =
    //     Max(_board.mColumns[0].size(),
    //         _board.mColumns[1].size(),
    //         _board.mColumns[2].size(),
    //         _board.mColumns[3].size(),
    //         _board.mColumns[4].size(),
    //         _board.mColumns[5].size(),
    //         _board.mColumns[6].size(),
    //         _board.mColumns[7].size());
    //     std::max(_board.mColumns[0].size(),
    //         std::max(_board.mColumns[1].size(),
    //             std::max(_board.mColumns[2].size(),
    //                 std::max(_board.mColumns[3].size(),
    //                       std::max(_board.mColumns[4].size(),
    //                             std::max(_board.mColumns[5].size(),
    //                                   std::max(_board.mColumns[6].size(), _board.mColumns[7].size())))))));
    auto columns = _board.GetColumns();
    auto it0     = columns[0].cbegin();
    auto it1     = columns[1].cbegin();
    auto it2     = columns[2].cbegin();
    auto it3     = columns[3].cbegin();
    auto it4     = columns[4].cbegin();
    auto it5     = columns[5].cbegin();
    auto it6     = columns[6].cbegin();
    auto it7     = columns[7].cbegin();
    for (size_t i = 0;
         i < 8 &&
         (it0 != columns[0].cend() || it1 != columns[1].cend() || it2 != columns[2].cend() || it3 != columns[3].cend() ||
          it4 != columns[4].cend() || it5 != columns[5].cend() || it6 != columns[6].cend() || it7 != columns[7].cend()); ++i)
    {
        if (it0 != columns[0].cend())
        {
            Paint(*it0);
            ++it0;
        }
        else
        {
            std::cout << "   ";
        }

        std::cout << " ";
        if (it1 != columns[1].cend())
        {
            Paint(*it1);
            ++it1;
        }
        else
        {
            std::cout << "   ";
        }

        std::cout << " ";
        if (it2 != columns[2].cend())
        {
            Paint(*it2);
            ++it2;
        }
        else
        {
            std::cout << "   ";
        }

        std::cout << " ";
        if (it3 != columns[3].cend())
        {
            Paint(*it3);
            ++it3;
        }
        else
        {
            std::cout << "   ";
        }

        std::cout << " ";
        if (it4 != columns[4].cend())
        {
            Paint(*it4);
            ++it4;
        }
        else
        {
            std::cout << "   ";
        }

        std::cout << " ";
        if (it5 != columns[5].cend())
        {
            Paint(*it5);
            ++it5;
        }
        else
        {
            std::cout << "   ";
        }

        std::cout << " ";
        if (it6 != columns[6].cend())
        {
            Paint(*it6);
            ++it6;
        }
        else
        {
            std::cout << "   ";
        }

        std::cout << " ";
        if (it7 != columns[7].cend())
        {
            Paint(*it7);
            ++it7;
        }
        else
        {
            std::cout << "   ";
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;
}

void StdOut::Paint(const FreeCell::Card& _card) const
{
    auto rank = _card.GetRank();

    switch (rank) {
    case FreeCell::eCardRank::Two:
        std::cout << " 2";
        break;

    case FreeCell::eCardRank::Three:
        std::cout << " 3";
        break;

    case FreeCell::eCardRank::Four:
        std::cout << " 4";
        break;

    case FreeCell::eCardRank::Five:
        std::cout << " 5";
        break;

    case FreeCell::eCardRank::Six:
        std::cout << " 6";
        break;

    case FreeCell::eCardRank::Seven:
        std::cout << " 7";
        break;

    case FreeCell::eCardRank::Eight:
        std::cout << " 8";
        break;

    case FreeCell::eCardRank::Nine:
        std::cout << " 9";
        break;

    case FreeCell::eCardRank::Ten:
        std::cout << "10";
        break;

    case FreeCell::eCardRank::Jack:
        std::cout << " J";
        break;

    case FreeCell::eCardRank::Queen:
        std::cout << " Q";
        break;

    case FreeCell::eCardRank::King:
        std::cout << " K";
        break;

    case FreeCell::eCardRank::Ace:
        std::cout << " A";
        break;

    case FreeCell::eCardRank::Jocker:
        std::cout << "jo";
        break;
    }

    auto suit = _card.GetSuit();

    switch (suit) {
    case FreeCell::eCardSuit::Diamond:
        std::cout << "D";
        break;

    case FreeCell::eCardSuit::Clubs:
        std::cout << "C";
        break;

    case FreeCell::eCardSuit::Hearts:
        std::cout << "H";
        break;

    case FreeCell::eCardSuit::Spades:
        std::cout << "S";
        break;

    case FreeCell::eCardSuit::NoSuit:
        std::cout << "k";
        break;
    }
}
