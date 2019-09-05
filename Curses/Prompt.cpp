#include "../Prompt.h"
#include "Curses.h"

Prompt::Prompt()
{
    Curses::Instance().Initialize();
}

Prompt::~Prompt()
{
    Curses::Instance().End();
}

void Prompt::GetString(std::string& _input) const
{
    attron(COLOR_PAIR(0));
    char input[80];
    getstr(input);
    addstr("\n\r");
    _input = input;
    auto to_lower = [](const auto c) {
                        return std::tolower(c);
                    };
    std::transform(_input.begin(), _input.end(), _input.begin(), to_lower);
    attroff(COLOR_PAIR(0));
}
