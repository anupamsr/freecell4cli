#ifndef OUTPUT_H_
#define OUTPUT_H_

class Output
{
    public:
        /**
         * @brief Draw the content on screen
         * @param _input
         */
        virtual void Draw() const = 0;
        virtual ~Output();
};

#endif // ifndef OUTPUT_H_
