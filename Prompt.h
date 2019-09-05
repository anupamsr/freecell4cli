#ifndef PROMPT_H_

#include "Input.h"
#include <algorithm>

class Prompt : public Input
{
    public:
        Prompt();
        virtual ~Prompt();
        virtual void GetString(std::string& _input) const;

    private:
};

#endif // ifndef PROMPT_H_
