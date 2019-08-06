#ifndef INPUT_H
#define INPUT_H

#include <string>

class Input
{
    public:
        /**
         * @brief Return a string containing correct command
         * @param _input
         */
        virtual void GetString(std::string& _input) const = 0;
};

#endif // INPUT_H
