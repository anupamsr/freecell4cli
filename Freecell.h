#ifndef FREECELL_H_
#define FREECELL_H_

#include "CardCollection.h"
#include "Constants.h"

namespace LIBCARD
{
class Freecell : public CardCollection<FREE_CELL_SIZE>
{
    public:
        Freecell() {}

        ~Freecell() {}

    private:
};
}

#endif // ifndef FREECELL_H_
