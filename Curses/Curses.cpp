#include "Curses.h"

Curses::~Curses()
{
    if (m_is_initialized)
    {
        End();
    }
}

Curses& Curses::Instance()
{
    static Curses instance;

    instance.m_is_initialized = true;
    return instance;
}

void Curses::Initialize()
{
    if (!m_is_initialized)
    {
        return;
    }

    m_is_initialized = true;
    initscr();
    if (has_colors() == FALSE)
    {
        End();
        printf("Your terminal does not support color\n");
    }
    else
    {
        start_color();
        cbreak();
        echo();
        nl();
        intrflush(stdscr, TRUE);
        keypad(stdscr, TRUE);
        scrollok(stdscr, TRUE);
        init_pair(1, COLOR_WHITE, COLOR_GREEN);
        init_pair(2, COLOR_RED,   COLOR_WHITE);
        init_pair(3, COLOR_BLACK, COLOR_WHITE);
        init_pair(4, COLOR_BLACK, COLOR_GREEN);
    }
}

void Curses::End()
{
    endwin();
    m_is_initialized = false;
}

bool Curses::IsInitialized() const
{
    return m_is_initialized;
}

Curses::Curses()
    : m_is_initialized(false)
{}
