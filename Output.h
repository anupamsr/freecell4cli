#ifndef OUTPUT_H
#define OUTPUT_H

class Output
{
    public:
        /**
         * @brief Draw the content on screen
         * @param _input
         */
        virtual void Draw() const = 0;
        virtual ~Output()
        {}
};

#endif // ifndef OUTPUT_H
