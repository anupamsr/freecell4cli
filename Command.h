#ifndef COMMAND_H_
#define COMMAND_H_

namespace FREECELL
{
class Command
{
    public:
        virtual bool Execute() = 0;
        virtual ~Command() {}
};
}

#endif // ifndef COMMAND_H_
