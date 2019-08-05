#ifndef HOMECELL_H_
#define HOMECELL_H_

#include "CardCollection.h"
#include "Constants.h"

namespace LIBCARD
{
class Homecell : public CardCollection<HOME_CELL_SIZE>
{
    public:
        Homecell() {}

        ~Homecell() {}

    private:
};
}

#endif // ifndef HOMECELL_H_
