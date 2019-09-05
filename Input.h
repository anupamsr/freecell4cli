#ifndef INPUT_H_
#define INPUT_H_

#include <string>

class Input
{
    public:
        /**
         * @brief Return a string containing correct command
         * @param _input
         */
        virtual void GetString(std::string& _input) const = 0;
        virtual ~Input();
};

#endif // ifndef INPUT_H_
