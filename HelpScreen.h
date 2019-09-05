#ifndef HELPSCREEN_H_
#define HELPSCREEN_H_

#include "Output.h"

class HelpScreen : public Output
{
    public:
        HelpScreen();
        ~HelpScreen();
        void Draw() const;

    private:
};

#endif // ifndef HELPSCREEN_H_
