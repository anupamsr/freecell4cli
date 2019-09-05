#include "../Prompt.h"
#include <iostream>

Prompt::Prompt()
{}

Prompt::~Prompt()
{}

void Prompt::GetString(std::string& _input) const
{
    std::cin >> _input;
    auto to_lower = [](const auto c) {
                        return std::tolower(c);
                    };

    std::transform(_input.begin(), _input.end(), _input.begin(), to_lower);
}
