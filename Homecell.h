#ifndef HOMECELL_H_
#define HOMECELL_H_

#include "LibCard/CardCollection.h"
#include "Constants.h"

namespace FREECELL
{
class Homecell : public LIBCARD::CardCollection<HOME_CELL_SIZE>
{
    public:
        Homecell()
        {}

        ~Homecell()
        {}

    private:
};
}

#endif // ifndef HOMECELL_H_
