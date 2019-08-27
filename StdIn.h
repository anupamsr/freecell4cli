#ifndef STDIN_H
#define STDIN_H

#include "Input.h"
#include <iostream>
#include <cctype>
#include <algorithm>

class StdIn : public Input
{
    public:
        StdIn() {}

        virtual ~StdIn() {}

        virtual void GetString(std::string& _input) const
        {
            std::cin >> _input;
            auto to_lower = [](const auto c) {
                                return std::tolower(c);
                            };
            std::transform(_input.begin(), _input.end(), _input.begin(), to_lower);
        }

    private:
};

#endif // ifndef STDIN_H
