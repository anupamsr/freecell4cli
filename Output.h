#ifndef OUTPUT_H
#define OUTPUT_H

#include <string>

class Output
{
    public:
        /**
         * @brief Draw the content on screen
         * @param _input
         */
        virtual void Draw() const = 0;
};

#endif // ifndef OUTPUT_H
