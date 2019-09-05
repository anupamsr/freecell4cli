#ifndef CURSES_H_
#define CURSES_H_

#include <curses.h>

class Curses
{
    public:
        ~Curses();
        static Curses& Instance();
        void           Initialize();
        void           End();
        bool           IsInitialized() const;

    private:
        Curses();
        Curses(const Curses&)            = delete;
        Curses& operator=(const Curses&) = delete;

    private:
        bool m_is_initialized;
};

#endif // ifndef CURSES_H_
