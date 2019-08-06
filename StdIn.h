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

            std::transform(_input.begin(), _input.end(), _input.begin(), [](unsigned char c) {
            return std::tolower(c);
        });
        }

    private:
};

#endif // ifndef STDIN_H
