#ifndef FREECELL_H_
#define FREECELL_H_

#include "LibCard/CardCollection.h"
#include "Constants.h"

namespace FREECELL
{
class Freecell : public LIBCARD::CardCollection<FREE_CELL_SIZE>
{
    public:
        Freecell() {}

        ~Freecell() {}

    private:
};
}

#endif // ifndef FREECELL_H_
